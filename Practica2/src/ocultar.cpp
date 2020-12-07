/**
 * @file ocultar.cpp
 * @author Marcos Romero Martín (marcos2001@correo.ugr.es)
 * @brief 
 * @version 0.1
 * @date 2020-11-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>
#include "codificar.h"

using namespace std;

int main(int argc, char *argv[]){

    char *origen; // nombres del fichero

    // Comprobar validez de la llamada
    if (argc != 2){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal>\n";
    exit (1);
    }

    origen  = argv[1];

    cout << endl;
    cout << "Fichero origen: " << origen << endl;

    string mensaje;
    cout << "Introduzca el mensaje: ";
    getline(cin, mensaje);

    byte codigo[mensaje.size()];
    for(int i = 0; i < mensaje.size(); i++)
        *(codigo + i) = mensaje[i];

    *(codigo + mensaje.size()) = '\0';

    if(ocultar(origen, codigo, mensaje.size()))
        cout << "Operacion completada con exito" << endl;
    else
        cerr << "ERROR: La imagen esta dañada" << endl;
}
