/**
 * @file imagen.h
 * @author Marcos Romero Martín (marcos2001@correo.ugr.es)
 * @brief Fichero de cabecera para el modulo imagen.
 * 
 * Implementacion del TDA imagen (imagen digital en niveles de gris).
 * 
 * @version 0.1
 * @date 2020-10-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef IMAGEN_H
#define IMAGEN_H

typedef unsigned char byte;

class Imagen{
    private:
        int cols;   /**< Numero de columas de la imagen*/
        int filas;  /**< Numero de filas de la imagen*/
        byte **img;    /**< La imagen en si: una matriz dinamica 2D de bytes*/
    public:
        /**
         * @brief Construye un nuevo objeto de tipo imagen.
         * @return Imagen, la imagen creada.
         */
        Imagen();

        /**
         * @brief Crear una imagen en memoria igual a J.
         * Reserva memoria para alojar la imagen copiada de J.
         * 
         * @param J Imagen a copiar.
         * @return Imagen, la imagen creada.
         */
        Imagen(const Imagen & J);

        /**
         * @brief Crear una imagen en memoria con "filas" filas y "cols" columnas.
         * 
         * Reserva memoria para alojar la imagen de "filas" x "cols" pixeles.
         * 
         * @param filas Numero de filas de la imagen.
         * @param cols Numero de columnas de la imagen.
         * @return Imagen, la imagen creada.
         */
        Imagen(int filas, int cols);

        /**
         * @brief Liberar los recursos ocupados por la imagen.
         */
        ~Imagen();

        /**
         * @brief Calcular el número de filas de la imagen.
         * @return El numero de filas de la imagen.
         */
        inline int num_filas () const;

        /**
         * @brief Calcular el número de columnas de la imagen.
         * @return El numero de columnas de la imagen.
        */
        inline int num_columnas () const;

        /**
         * @brief Asignar el valor "valor" al pixel ("fila", "col") de la imagen.
         * @pre 1. 0 <= "fila" < i.num_filas().
         * 2. 0 <= "col" < i.num_columnas().
         * 3. 0 <= valor <= 255.

         * 
         * @param fila fila de la imagen "i".
         * @param col columna de la imagen "i".
         * @param valor valor a escribir.
         * 
         * @post 1. "i"("fil","col") == "valor".
         * 2. Los restantes píxeles no se modifican.
         */
        inline void asigna_pixel(int fila, int col, byte valor);

        /**
         * @brief Consultar el valor de la casilla ("fila", "col") de la imagen.
         * @pre 1. 0 <= "fila" < i.num_filas().
         * 2. 0 <= "col" < i.num_columnas().
         * 
         * @param fila fila de la imagen "i".
         * @param col columna de la imagen "i".
         * @return byte, valor de "i"("fila", "col"). 
         */
        inline byte valor_pixel(int fila, int col) const;

};


//Funciones

/**
 * @brief Cambia una imagen rgb de tipo .ppm a escala de grises .pgm
 * 
 * @param i nombre del fichero que contiene la imagen original.
 * @param j nombre del fichero que contedrá el resultado de la transformación.
 * @return true si se ha realizado correctamente.
 * @return false si no se ha podido realizar.
 */
bool Igris(const char * i, const char * j);

/**
 * @brief Se umbraliza una imagen de tipo
 * 
 * @pre 0 <= t1 < t2 <= 255
 * 
 * @param entrada  nombre del fichero que contiene la imagen original.
 * @param salida nombre del fichero que contedrá el resultado de la transformación.
 * @param t1 umbral menor del intervalo de la umbralización (T1 < T2).
 * @param t2 umbral mayor del intervalo de la umbralización (T1 < T2).
 * @return true si se ha umbralizado correctamente.
 * @return false si no se ha conseguido umbralizar.
 */
bool umbralizar(const char * entrada, const char * salida, const byte & t1, const byte & t2);

/**
 * @brief Hace zoom en la imagen dada
 * 
 * @param entrada  nombre del fichero que contiene la imagen original.
 * @param salida nombre del fichero que contedrá el resultado del zoom.
 * @param x1 fila de la coordenada de arriba a la izquierda.
 * @param y1 columna de la coordenada de arriba a la izquierda.
 * @param x2 fila de la coordenada de abajo a la derecha.
 * @param y2 columna de la coordenada de abajo a la derecha.
 * @return true si se ha aumentado correctamente.
 * @return false si no se ha conseguido aumentar.
 */
bool zoom(const char * entrada, const char * salida, int x1, int y1, int x2, int y2);

/**
 * @brief Crea un icono de la imagen dada de tamano @param ifilas x @param icols
 * 
 * @param entrada  nombre del fichero que contiene la imagen original.
 * @param salida nombre del fichero que contedrá el resultado de la transformación.
 * @param ifilas numero de filas del icono.
 * @param icols numero de columnas del icono.
 * @return true si se ha realizado correctamente.
 * @return false si no se ha podido realizar.
 */
bool icono(const char * entrada, const char * salida, int & ifilas, int & icols);

/**
 * @brief Contrasta la imagen con un rango [min, max]
 * 
 * @pre 0 <= min < max <= 255
 * 
 * @param entrada  nombre del fichero que contiene la imagen original.
 * @param salida nombre del fichero que contedrá el resultado del contraste.
 * @param min 
 * @param max 
 * @return true si se ha contrastado correctamente.
 * @return false si no se ha conseguido contrastar.
 */
bool contraste(const char * entrada, const char * salida, const byte & min, const byte & max);

#endif

/* Fin Fichero: imagen.h */