/**
 * @file codificar.cpp
 * @author Marcos Romero Martín (marcos2001@correo.ugr.es)
 * @brief Fichero con las definiciones para el modulo codificar.
 * @version 0.1
 * @date 2020-11-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>
#include "imagenES.h"
#include "imagen.h"


using namespace std;


byte * formato(const char * entrada, byte * img, const TipoImagen & tipo, int & filast, int & colst){

    if(tipo == IMG_PGM){
        img = LeerImagenPGM(entrada, filast, colst);
        if(img == 0)
            cerr << "ERROR: No se pudo leer la imagen .pgm" << endl;
        
    }else{
        if(tipo == IMG_PPM){
            img = LeerImagenPPM(entrada, filast, colst);
            if(img == 0)
                cerr << "ERROR: No se pudo leer la imagen .ppm" << endl;
            
            colst *= 3;
        }else{
            img = 0;
            cerr << "ERROR: La imagen esta en un formato desconocido." << endl;
        }
    }
    return img;
}

bool ocultar(const char * entrada, byte * array, const int & numarray){
    
    const int BITS = 8;
    TipoImagen tipo = LeerTipoImagen(entrada);
    int filast, colst;
    byte * img;
    string salida;

    cout << "Introduzca la imagen de salida: ";
    cin >> salida;
    cout << "Ocultando..." << endl;

    img = formato(entrada, img, tipo, filast, colst);
    if(img == 0)
        return false;
    
    if(filast * colst < numarray + BITS){       //Se suma bits para tener en cuenta el /0
        delete [] img;
        cerr << "ERROR: La cadena que se intenta codificar es demasiado grande para la imagen dada." << endl;
        return false;
    }

    int mensaje;
    int BIT = 128;

    for(int i = 0; i < numarray; i++)
        for(int j = 0; j < BITS; j++){
            mensaje = (*(array + i) & BIT);
            if(*(img + i * BITS + j) % 2 == 1 && mensaje == 0)
                img[i * BITS + j]--;              //ARREGLAR
            else{
                if(*(img + i * BITS + j) % 2 == 0 && mensaje == BIT)
                    img[i * BITS + j]++;
            }
            *(array + i) = (*(array + i) << 1);
        }
    
    for(int i = 0; i < BITS; i++)           //Se añade el /0
        if(*(img + numarray * BITS + i) % 2 == 1)
            img[i + numarray * BITS]--;
        

    char * temp;      
    switch (tipo){
        case IMG_PPM:
            salida.append(".ppm");
            temp = new char[salida.size()];
            for(int i = 0; i < salida.size(); i++)
                *(temp + i) = salida[i];

            *(temp + salida.size()) = '\0';

            if(!EscribirImagenPPM(temp, img, filast, colst/3)){
                cerr << "ERROR: No se pudo escribir la imagen .ppm" << endl;
                delete [] img;
                return false;
            }
            break;
        case IMG_PGM:               //Mirar cambia de formato
            salida.append(".pgm");
            temp = new char[salida.size()];
            for(int i = 0; i < salida.size(); i++)
                *(temp + i) = salida[i];

            *(temp + salida.size()) = '\0';

            if(!EscribirImagenPGM(temp, img, filast, colst)){
                delete [] img;
                cerr << "ERROR: No se pudo escribir la imagen .pgm" << endl;
                return false;
            }   
            break;
            default:
            cerr << "ERROR: La salida tiene un formato desconocido" << endl;
            break;
    }
    delete [] img;
    return true;
}

byte * revelar(const char * entrada, int & num){

    const int BITS = 8;
    TipoImagen tipo = LeerTipoImagen(entrada);
    int filast, colst;
    byte * img;
    string salida;

    img = formato(entrada, img, tipo, filast, colst);
    if(img == 0)
        return 0;
    
    int pixel = 0;
    const int BIT = 1;
    byte mensaje, * temp = new byte[filast * colst];
    bool parar = false; 

    while(!parar && pixel * BITS < filast * colst){
        mensaje = 0;
        for(int i = 0; i < BITS; i++){
            mensaje = mensaje << 1;
            mensaje = (mensaje | (*(img + i + pixel * BITS) & BIT));
        }
        *(temp + pixel) = mensaje;
        if(mensaje == 0)
            parar = true;
        pixel++;
    }

    delete [] img;
    if(!parar){
        delete [] temp;
        cerr << "ERROR: La imagen no contiene terminador de cadena \0"<<endl;
        return 0;
    }

    num = pixel;
    byte * array = new byte[pixel];

    for(int i = 0; i < pixel; i++)
        *(array + i) = *(temp + i);
    
    delete [] temp;
    return array;
}