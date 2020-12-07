/**
 * @file codificar.h
 * @author Marcos Romero Martín (marcos2001@correo.ugr.es)
 * @brief Fichero cabecera para el modulo codificar.
 * @version 0.1
 * @date 2020-11-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CODIFICAR_H
#define CODIFICAR_H

#include "imagen.h"

/**
 * @brief 
 * 
 * @param entrada 
 * @param array 
 * @param numarray 
 * @return true 
 * @return false 
 */
bool ocultar(const char * entrada, byte * array, const int & numarray);

/**
 * @brief 
 * 
 * @param entrada 
 * @param numentr 
 * @param array 
 * @param numarray 
 * @return true 
 * @return false 
 */
byte * revelar(const char * entrada, int & num);
#endif