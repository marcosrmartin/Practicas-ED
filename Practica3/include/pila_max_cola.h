/**
 * @brief Fichero cabecera del TDA Pila_max_cola
 * 
 * @file pila_max_cola.h
 * @date 2020-11-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef PILA_MAX_COLA_H
#define PILA_MAX_COLA_H


#include "cola.h"

/**
 * @brief T.D.A Pila_max
 *
 * Una instancia de @e p del TDA @c Pila_max es un objeto el cual
 * gestiona una secuencia de elementos con facilidades para la insercion y
 * borrado de elementos en un extremo @e (Pila) con una @e cola.
 *
 * Un ejemplo de su uso:
 * @example usospilas_max.cpp
 * @tparam T Tipo de dato sobre el que se va a trabajar.
 *
 * @author Marcos Romero Martín (marcos2001@correo.ugr.es)
 */
template<class T>
class Pila_max{

    private:
        Cola <elemento<T>> pila;    ///< Cola la cual guardara los @e elementos
    public:

        /**
         * @brief Constructor por defecto
         * 
         */
        Pila_max();

        /**
         * @brief Constructor de copias
         * 
         * @param elem cola la cual copiamos
         */
        void poner(T & elem);

        /**
         * @brief Devuelve el elemento del tope de la pila
         * 
         * @return const elemento<T>& elemento el cual esta en el tope
         */
        const elemento<T> & tope() const;

        /**
         * @brief Quita el @e elemento de la pila
         * 
         */
        void quitar();

        /**
         * @brief Nos muestra si la pila esta vacia o no.
         * 
         * @return true si la pila esta vacia.
         * @return false si la pila no esta vacia.
         */
        bool vacia();
};

#include <pila_max_cola.cpp>
#endif