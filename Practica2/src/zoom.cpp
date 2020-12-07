/**
 * @file zoom.cpp
 * @author Marcos Romero Martín (marcos2001@correo.ugr.es)
 * @brief 
 * @version 0.1
 * @date 2020-11-02
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

    int x1, x2, y1, y2;

    cout << "Introduzca las coordenadas de la esquina superior izquierda [x1, y1]: ";
    cin >> x1 >> y1;
    cout << "Introduzca las coordenadas de la esquina superior izquierda [x2, y2]: ";
    cin >> x2 >> y2;
    
    if(zoom(origen, destino, x1, y1, x2, y2))
        cout << "Operacion completada con exito" << endl;
    else
        cerr << "ERROR: La imagen esta dañada" << endl;
}