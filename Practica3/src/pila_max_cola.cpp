template<class T>
Pila_max<T>::Pila_max(){
    pila = Cola<elemento<T>>();
}

template<class T>
void Pila_max<T>::poner( T & entrada){
    elemento <T> elem(entrada);
    if(pila.vacia())
        pila.poner(elem);
    else{
        T temp = (pila.frente()).maximo;
        Cola<elemento<T>> aux;
        if(elem.maximo < temp)
            elem.maximo = temp;

        aux.poner(elem);
        while(!pila.vacia()){
            aux.poner(pila.frente());
            pila.quitar();
        }

        pila = aux;

        if(temp > (pila.frente()).maximo)
            (pila.frente()).maximo = temp;
    }
}

template<class T>
const elemento<T> & Pila_max<T>::tope() const {
    return pila.frente();
}

template<class T>
void Pila_max<T>::quitar(){
    pila.quitar();
}

template<class T>
bool Pila_max<T>::vacia(){
    return pila.vacia();
}