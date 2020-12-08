#include <iostream>
#include "pila_max.h"

using namespace std;

int main(){
    

    Pila_max <int> p;
    int i;
    for ( i=10; i>=0 ; i--)
        p.poner(i);

    cout << "Elem       Maximo" << endl;
    while (!p.vacia() ){
        elemento<int> x = p.tope();
        cout << x <<endl;
        p.quitar();
    }
    return 0;
}