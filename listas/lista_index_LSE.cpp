#include "lista_index_LSE.h"

Lista_Indexada_LSE::Lista_Indexada_LSE(){
    this->inicio = 0;
    this->contador = 0;
    this->m = 0;
}

void Lista_Indexada_LSE::iniciar(int m){
    this->m = m;
    for(int i = 0; i < m; i++){
        crearCelda(i);
    }
}

void Lista_Indexada_LSE::crearCelda(int indice){
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

Lista_Indexada_LSE::Celda::Celda(int indice){
    this->indice = indice;
    elemento = 0;
    this->siguiente = 0;
}

void Lista_Indexada_LSE::insertar(int indice, int elemento){
    if(indice < m){
        
    }
}