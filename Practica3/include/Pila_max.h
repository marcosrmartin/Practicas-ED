/**
 * @file Pila_max.h
 *
 * @brief Fichero cabecera del TDA Pila_max_cola
 *
 * @date 2020-11-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#ifndef PILA_MAX_H
#define PILA_MAX_H


#include <ostream>

using namespace std;

/**
 * @brief T.D.A Elemento
 *
 * Una instancia de @e ele del TDA @c elemento es un objeto el cual
 * gestiona un par de numero que serán usados en un TDA @c Pila_max
 * el @e ele es un elemento cualquiera y @e maximo es el @e ele maximo 
 * del objeto @c Pila_max hasta este @c elemento.
 *
 * @tparam T Tipo de dato sobre el que se va a trabajar.
 */
template<typename T>
struct elemento{
    T   ele,    ///< Elemento cualquiera
        maximo; ///< Elemento maximo

    /**
     * @brief Constructor por parametros
     * 
     * @param elem elemento a insertar en @c elemento
     */
    elemento(T & elem){
        this->ele = elem;
        this->maximo = elem;
    }
};

/**
 * @brief Sobrecarga del metodo de salida
 * 
 * @tparam T Tipo de dato sobre el que se va a trabajar.
 * @param os se encarga de la salida de datos.
 * @param elem @c elemento del cual se mostraran los datos.
 * @return ostream& 
 */
template<typename T>
ostream & operator<<(ostream & os, const elemento<T> & elem){
    return os << elem.ele << "          " <<  elem.maximo << endl;
}

//#include "pila.h"
#define CUAL_COMPILA 1
#if CUAL_COMPILA==1
#include <pila_max_vd.h>
#elif CUAL_COMPILA==2
#include <pila_max_cola.h>
#endif 

#endif