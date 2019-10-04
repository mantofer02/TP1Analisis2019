#include "lista_index_LSE.h"

Lista::Lista(){
    this->inicio = 0;
    this->contador = 0;
    this->m = 0;
}

void Lista::iniciar(int m){
    this->m = m;
    for(int i = 0; i < m; i++){
        crearCelda(i);
    }
} // void setElemento(int elemento);
            // int getElemento();
            // int getIndice();

void Lista::crearCelda(int indice){
    if(!inicio){
        Celda* nueva = new Celda(indice);
        inicio = nueva;
    }else{
        Celda* actual = inicio;
        while(actual->siguiente){
            actual = actual->siguiente;
        }
        Celda* nueva = new Celda(indice);
        actual->siguiente = nueva;
    }
}

Lista::Celda::Celda(int indice){
    this->indice = indice;
    this->elemento = 0;
    this->siguiente = 0;
}

void Lista::insertar(int indice, int elemento){
    //Se asume que ya se inicializo
    if(indice < m){
        Celda* actual = inicio;
            while(indice != actual->indice){
                actual = actual->siguiente;
            }
        actual->elemento = elemento;
        contador++;
    }
}

void Lista::modificarElemento(int indice, int elemento){
    if(indice < m){
        Celda* actual = inicio;
        while(indice != actual->indice){
            actual = actual->siguiente;
        }
        actual->elemento = elemento;
    }
}

void Lista::borrar(int indice){
    if(indice < m){
        Celda* actual = inicio;
        while(indice != actual->indice){
            actual = actual->siguiente;
        }
        if(actual->elemento != elemntoNulo){
            actual->elemento = elemntoNulo;
            contador--;
        }
    }
}

int Lista::numElem(){
    return contador;
}

int Lista::recuperar(int indice){
    int elementoADevolver = 0;
    if(indice < m){
        Celda* actual = inicio;
        while(indice != actual->indice){
            actual = actual->siguiente;
        }
        elementoADevolver = actual->elemento;
    }
    return elementoADevolver;
}

void Lista::intercambiar(int indice1, int indice2){
    if(indice1, indice2  < m){
        int elemento3 = 0;
        Celda* actual1 = inicio;
        Celda* actual2 = inicio;
        while(indice1 != actual1->indice){
            actual1 = actual1->siguiente;
        }
        while(indice2 != actual2->indice){
            actual2 = actual2->siguiente;
        }
        elemento3 = actual2->elemento;
        actual2->elemento = actual1->elemento;
        actual1->elemento = elemento3;
    }
}

bool Lista::vacio(){
    bool estaVacio = true;
        if(inicio)
            estaVacio = false;
    return estaVacio;
}

void Lista::vaciar(){
    for(int i = 0; i < m; i++)
        borrar(i);
}

Lista :: ~Lista(){
    if(inicio)
        delete inicio;
}

void Lista :: imprimirLista(){
    if(inicio){
        Celda* actual = inicio;
        while(actual){
            if(actual->indice == elemntoNulo){
                std::cout << "Indice : " << actual->indice << " Sin Elemento" << std:: endl;
            }else{
                std::cout << "Indice : " << actual->indice << " Elemento : " <<actual->elemento << std:: endl;
                }
            actual = actual->siguiente;
        }
    }
}

Lista :: Celda :: ~Celda(){
    if(this->siguiente)
        delete this->siguiente;
}