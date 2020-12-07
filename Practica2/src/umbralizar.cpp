/**
 * @file umbralizar.cpp
 * @author Marcos Romero Martín (marcos2001@correo.ugr.es)
 * @brief 
 * @version 0.1
 * @date 2020-10-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>
#include "imagen.h"

using namespace std;

int main (int argc, char *argv[]){
 
    char *origen, *destino; // nombres de los ficheros

    // Comprobar validez de la llamada
    if (argc != 3){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
    exit (1);
    }

    origen  = argv[1];
    destino = argv[2];


    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;


    int t1, t2;
    cout << "Introduzca los valores de t1 y t2 [t1 < t2] [0 - 255]: ";
    cin >> t1 >> t2;

    if(t1 > t2)             //Correccion de posibles valores erróneos (sin abortar el programa)
        swap(t1, t2);
    if(t1 < 0)
        t1 = 0;
    if(t2 > 255)
        t2 = 255;

    if(umbralizar(origen, destino, t1, t2))
        cout << "Operacion completada con exito" << endl;
    else
        cerr << "ERROR: La imagen esta dañada" << endl;
}