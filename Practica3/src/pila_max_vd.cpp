template<class T>
Pila_max<T>::Pila_max(){
    pila = vector<elemento<T>>();
}

template<class T>
void Pila_max<T>::poner(T & entrada){
    elemento<T> elem(entrada);
    if(pila.size() == 0)
        pila.push_back(elem);
    else{
        T temp = (pila.back()).maximo;
        pila.push_back(elem);
        if(temp > elem.maximo)
            (pila.back()).maximo = temp;
    }
}

template<class T>
const elemento<T> & Pila_max<T>::tope() const{
    return pila.back();
}

template<class T>
void Pila_max<T>::quitar(){
    pila.pop_back();
}

template<class T>
bool Pila_max<T>::vacia(){
    return (pila.size()) == 0;
}