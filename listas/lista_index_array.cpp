#include "lista_index_array.h"

Lista::Lista(){
    this->m = 0;
}

void Lista::iniciar(int m){
    this->m = m;
    listaIndexa = new int[m];
    contador = 0;
}

void Lista::vaciar(){
    for(int i = 0; i < m; i++)
        borrar(i);
}

bool Lista::vacio(){
    bool estaVacio = false;
    if(contador == 0)
        estaVacio = true;
    return estaVacio;
}

void Lista::destruir(){
    delete[] listaIndexa;
    contador = 0;
    
}

Lista :: ~Lista(){
    delete[] listaIndexa;
}

void Lista::insertar(int indice, int elemento){
    if(indice < m)
        listaIndexa[indice] = elemento;
        contador++;
}

void Lista::borrar(int indice){
    if(indice < m)
        if(listaIndexa[indice]!= elementoNulo){
            listaIndexa[indice] = elementoNulo;
            contador--;
        }
}

int Lista::recuperar(int indice){
    int elementoAdevolver = 0;
    if(indice < m)
        elementoAdevolver = listaIndexa[indice];
    return elementoAdevolver;
}

void Lista::modificarElemento(int indice, int elemento){
    if(indice < m)
        listaIndexa[indice] = elemento;
}

void Lista::intercambiar(int indice1, int indice2){
    int elementoAux = 0;
    if(indice1, indice2 < m){
        elementoAux = listaIndexa[indice1];
        listaIndexa[indice1] = listaIndexa[indice2];
        listaIndexa[indice2] = elementoAux;
    }
}

int Lista::numElem(){
    return contador;
}

void Lista::imprimirLista(){
    for(int i = 0; i < m; i++){
        if(listaIndexa[i] == elementoNulo){
            std::cout << "Indice : " << i << " Sin Elemento" << std:: endl;
        }else{    
            std::cout << "Indice : " << i << " Elemento : " << listaIndexa[i] << std:: endl;
        }
    }
}