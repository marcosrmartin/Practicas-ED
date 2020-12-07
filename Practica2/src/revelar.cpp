/**
 * @file revelar.cpp
 * @author Marcos Romero Martín (marcos2001@correo.ugr.es)
 * @brief 
 * @version 0.1
 * @date 2020-10-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include "codificar.h"

using namespace std;

int main(int argc, char *argv[]){
 
    char *origen, *destino; // nombres de los ficheros

    // Comprobar validez de la llamada
    if (argc != 2){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal>\n";
    exit (1);
    }

    origen  = argv[1];


    cout << endl;
    cout << "Fichero origen: " << origen << endl;

    int num;
    unsigned char * mensaje = revelar(origen, num);
    if(mensaje != 0){
        cout << "Operacion completada con exito\nEl mensaje oculto es: ";
        for(int i = 0; i < num; i++)
            cout << *(mensaje + i);
        cout<<endl;
    }
    else
        cerr << "ERROR: La imagen esta dañada" << endl; 
}