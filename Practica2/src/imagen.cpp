/**
 * @file imagen.cpp
 * @author Marcos Romero Martín (marcos2001@correo.ugr.es)
 * @brief Fichero con las definiciones para la biblioteca libimg.a
 * @version 0.1
 * @date 2020-10-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "imagen.h"
#include "imagenES.h"
#include <iostream>

using namespace std;

Imagen::Imagen(){
    cols = 0;
    filas = 0;
    img = 0;    //NULL
}

Imagen::Imagen(const Imagen & J){
    cols = J.cols;
    filas = J.filas;

    img = new byte*[filas];
    for(int i = 0; i < filas; i++)
        *(img + i) = new byte[cols];

    for(int i = 0; i < filas; i++)
        for(int j = 0; j < cols; j++)
            *(*(img + i) + j) = *(*(J.img + i) + j);
}

Imagen::Imagen(int filas, int cols){
    this->filas = filas;
    this->cols = cols;
    img = new byte*[filas];
    for(int i = 0; i < filas; i++)
        *(img + i) = new byte[cols];
}

Imagen::~Imagen(){
    filas = 0;
    cols = 0;
    for(int i = 0; i < filas; i++)
        delete [] *(img + i);
    delete [] img;
}

inline int Imagen::num_filas() const{
    return filas;
}

inline int Imagen::num_columnas() const{
    return cols;
}

inline void Imagen::asigna_pixel(int fila, int col, byte valor){
    *(*(img + fila) + col) = valor;
}

inline byte Imagen::valor_pixel(int fila, int col) const{
    return *(*(img + fila) + col);
}

//Funciones

/**
 * @brief Pasa un array de bytes (unsigned char) a tipo imagen.
 * 
 * @pre array no nulo y filas y columnas >= 0
 * 
 * @param imagen imagen a escribir la cual se saca por referencia.
 * @param array Array con la imagen a copiar.
 * @param filas Numero de filas de la imagen.
 * @param columnas Numero de columnas de la imagen.
 */
Imagen * escribirImagen(const byte * array, const int & filas, const int &cols){

    Imagen * imagen = new Imagen(filas, cols);
    for(int i = 0; i < filas; i++)
            for(int j = 0; j < cols; j++)
                imagen->asigna_pixel(i, j, *(array + j + i * cols));
    return imagen;
}

/**
 * @brief Pasa un tipo imagen a array de bytes (unsigned char).
 * 
 * @param imagen imagen a leer.
 * @return byte* 
 */
byte * leerImagen(Imagen * imagen){
    byte * temp =  new byte[imagen->num_filas() * imagen->num_columnas()];

    for(int c = 0; c < imagen->num_filas(); c++)
        for(int k = 0; k < imagen->num_columnas(); k++)                   
            *(temp + c * imagen->num_columnas() + k) = imagen->valor_pixel(c, k);
    return temp;
}

/**
 * @brief Redondea a tipo entero.
 * 
 * @param temp numero a redondear
 * @return int resultado del redondeo
 */
int redondear(double temp){
    if((temp - int(temp)) >= 0.5)
        temp += 0.5;
    return int(temp);
}

bool Igris(const char * i, const char * j){ 

    int filast, colst;
    byte * img = LeerImagenPPM(i, filast, colst);
    if(img != 0){

        float R = 0.2989,  G = 0.587, B = 0.114;
        const int FONDO = 3;
        Imagen imagen(filast, colst);

        for(int c = 0; c < filast; c++)
            for(int k = 0; k < colst; k++)
                imagen.asigna_pixel(c, k, byte(*(img + FONDO*(k + c*colst))*R + *(img + FONDO*(k + c*colst) + 1)*G + *(img + FONDO*(k + c*colst) + 2)*B));
        
        delete [] img;                                                      //Eliminamos la imagen de tipo ppm del array
        img =  new byte[filast * colst]; 

        for(int c = 0; c < filast; c++)
            for(int k = 0; k < colst; k++)
                *(img + c * colst + k) = imagen.valor_pixel(c, k);

        imagen.~Imagen();
        if(EscribirImagenPGM(j, img, filast, colst)){
            delete [] img;
            return true;
        }
        cerr << "ERROR: No se puedo escribir la imagen pgm" << endl;
        delete [] img;
    }
    cerr << "ERROR: La imagen no es de tipo .ppm" << endl;
    return false;
}


bool umbralizar(const char * entrada, const char * salida, const byte &t1, const byte &t2){
 
    int filast, colst;
    const byte UMBRAL = 255;
    byte * img = LeerImagenPGM(entrada, filast, colst);

    if(img != 0){
        Imagen * imagen = escribirImagen(img, filast, colst);

        for(int i = 0; i < filast; i++)
            for(int j = 0; j < colst; j++)
                if(imagen->valor_pixel(i, j) >=  t2 || imagen->valor_pixel(i, j) <= t1)
                    imagen->asigna_pixel(i, j, UMBRAL);

        delete [] img;
        img = leerImagen(imagen);
        imagen->~Imagen();
        if(EscribirImagenPGM(salida, img, filast, colst)){
            delete [] img;                                                  //Eliminamos el contenido anterior de img
            return true;
        }else
            cerr << "ERROR: No se puedo escribir la imagen .pgm" << endl;
    }else
        cerr << "ERROR: La imagen no es de tipo .pgm" << endl;
    delete [] img;
    return false;
}


bool zoom(const char * entrada, const char * salida, int x1, int y1, int x2, int y2){

    int filast, colst;
    byte * img = LeerImagenPGM(entrada, filast, colst);

    if(img != 0){

        Imagen * imagen = escribirImagen(img, filast, colst);

        if(x2 < x1)                                                         //Se ajusta las coordenadas para que no se salgan del marco de la foto
            swap(x2,x1);
        if(y1 > y2)
            swap(y1, y2);

        if(x1 < 0)
            x1 = 0;
        if(x2 > filast)
            x2 = filast - 1;
        if(y1 < 0)
            y1 = 0;
        if(y2 > colst)
            y2 = colst - 1;

        int f = x1, c , filaszoom = 2 * (x2 - x1 + 1) - 1, colszoom = 2 * (y2 - y1 + 1) - 1;
        double temp;
        Imagen * zoom = new Imagen(filaszoom, colszoom);

        for(int i = 0; i < filaszoom; i++){
            c = y1;
            for(int j = 0; j < colszoom; j++){
                if(j % 2 == 0 && i % 2 == 0)
                    temp = imagen->valor_pixel(f, c++);
                else{
                    if(i % 2 == 0)
                        temp = (imagen->valor_pixel(f, c-1) + imagen->valor_pixel(f, c)) / 2;
                    else{
                        if(j % 2 == 0)
                            temp =  (imagen->valor_pixel(f-1, c) + imagen->valor_pixel(f, c++)) / 2;
                        else
                            temp = (imagen->valor_pixel(f-1, c) + imagen->valor_pixel(f, c) + imagen->valor_pixel(f, c-1) + imagen->valor_pixel(f-1, c-1)) / 4;     //Interpolacion de los 4 pixeles mas proximos para mayor precisión.
                    }
                }
                zoom->asigna_pixel(i, j, redondear(temp));
            }
            if(i % 2 == 0)f++;
        }

        delete [] img;                                                     //Eliminamos el contenido anterior de img
        img = leerImagen(zoom);
        imagen->~Imagen();

        if(EscribirImagenPGM(salida, img, filaszoom, colszoom)){
            zoom->~Imagen();
            delete [] img;
            return true;
        }else
            cerr << "ERROR: No se puedo escribir la imagen .pgm" << endl;
        zoom->~Imagen();
    }else
        cerr << "ERROR: La imagen no es de tipo .pgm" << endl;

    delete [] img;
    return false;
}

bool icono(const char * entrada, const char * salida, int & ifilas, int & icols){

    int filast, colst;
    byte * img = LeerImagenPGM(entrada, filast, colst);

    if(img != 0){

        Imagen * imagen = escribirImagen(img, filast, colst),
        * icono = new Imagen(ifilas, icols);       
        
        if(ifilas < 1)                                                   //Corrección de valores para que se pueda dibujar la imagen
            ifilas = 1;
        if(icols < 1)
            icols = 1;
        if(ifilas > filast)
            ifilas = filast;
        if(icols > colst)
            icols = colst;


        int pixvcols[icols], pixvfils[ifilas],
        pixcols, pixfils, rescols, resfils;

        pixcols = colst/icols;                                          //Se subdivida la imagen original en filas y columnas como tenga el icono.
        for(int i = 0; i < icols; i++)
            *(pixvcols + i) = pixcols;

        rescols = colst % icols;
        if(rescols != 0)
            for(int i = 0; i < rescols; i++)
                pixvcols[i % icols]++;

        pixfils = filast / ifilas;
        for(int i = 0; i < ifilas; i++)
            *(pixvfils + i) = pixfils;

        resfils = filast % ifilas;
        if(resfils != 0)
            for(int i = 0; i < resfils; i++)
                pixvfils[i % ifilas]++;

        int denominador, f = 0, c;
        resfils = 0, rescols = 0;
        double temp;

        for(int i = 0; i < ifilas; i++){                                 //se hace cada pixel con cada submatriz de la imagen original
            c = 0;  resfils += *(pixvfils + i);
            for(int j = 0; j < icols; j++){

                temp = 0;
                denominador = *(pixvcols + j) * *(pixvfils + i);
                rescols += *(pixvcols + j);
                for(int k = f; k < resfils; k++)
                    for(int l = c; l < rescols; l++)
                        temp += imagen->valor_pixel(k, l);
                    
                temp /= denominador;
                icono->asigna_pixel(i, j, redondear(temp));
                c += *(pixvcols + j);
            }
            f += *(pixvfils + i);
            rescols = 0;
        }

        delete [] img;                                                  //Eliminamos el contenido anterior de img
        img = leerImagen(icono);
        imagen->~Imagen();

        if(EscribirImagenPGM(salida, img, icono->num_filas(), icono ->num_columnas())){

            icono->~Imagen();
            delete [] img;
            return true;
        }else
            cerr << "ERROR: No se puedo escribir la imagen .pgm" << endl;
        icono->~Imagen();
    }else
        cerr << "ERROR: La imagen no es de tipo .pgm" << endl;

    delete [] img;
    return false;
    
}

bool contraste(const char * entrada, const char * salida, const byte & min, const byte & max){
    int filast, colst;
    byte * img = LeerImagenPGM(entrada, filast, colst);

    if(img != 0){

        const short int MAX = 256;
        byte valores[MAX];
        bool existe[MAX] = { false };
        Imagen * imagen = escribirImagen(img, filast, colst);
        byte a = MAX - 1, b = 0, temp;

        for(int i = 0; i < filast; i++)                                 //Se busca el menor y mayor valor de la imagen.
            for(int j = 0; j < colst; j++){
                temp = imagen->valor_pixel(i, j);
                if(temp > b)
                    b = temp;
                if(temp < a)
                    a = temp;
            }

        if(a == b){
            cerr << "ERROR: La imagen es plana y no se puede contrastar" << endl;
            exit(1);
        }

        const double COCIENTE = int(max - min) / double(b - a);
        double valor;

        for(int i = 0; i < filast; i++)
            for(int j = 0; j < colst; j++){
                temp = imagen->valor_pixel(i, j);
                if(*(existe + temp))
                    imagen->asigna_pixel(i, j, *(valores + temp));
                else{
                    valor = min + COCIENTE * (temp - a);
                    *(valores + temp) = redondear(valor);
                    imagen->asigna_pixel(i, j, *(valores + temp));
                    *(existe + temp) = true;
                }
            }

        delete [] img;                                                 //Eliminamos el contenido anterior de img
        img = leerImagen(imagen);
        imagen->~Imagen();
        if(EscribirImagenPGM(salida, img, filast, colst)){

            delete [] img;
            return true;
        }else
            cerr << "ERROR: No se puedo escribir la imagen .pgm" << endl;
    }else
        cerr << "ERROR: La imagen no es de tipo .pgm" << endl;

    delete [] img;
    return false;
    
}