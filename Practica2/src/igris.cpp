/**
 * @file igris.cpp
 * @author Marcos Romero Martín (marcos2001@correo.ugr.es)
 * @brief 
 * @version 0.1
 * @date 2020-10-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
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


    if(Igris(origen, destino))
        cout << "Operacion completada con exito" << endl;
    else
        cerr << "ERROR: La imagen esta dañada" << endl;
}