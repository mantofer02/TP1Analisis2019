#include "algoritmos_lista_ord.h"


Algoritmos_Ordenada::Algoritmos_Ordenada(Lista_Ord lista){
    this->lista = lista;
}

void Algoritmos_Ordenada::listar(){
    this->lista.imprimir();
}

int Algoritmos_Ordenada::iguales(Lista_Ord otra){
    int resultado = 1;
    if(this->lista.numElem() == otra.numElem() && this->lista.numElem()!=0 && otra.numElem()!=0){
        int elemento1 = this->lista.primero();
        int elemento2 = otra.primero(); 
        while(elemento1 >= 0 && elemento2 >= 0 && resultado){
            if(elemento1 != elemento2){
                resultado = 0;
            }
            else{
                elemento1 = lista.siguiente(elemento1);
                elemento2 = otra.siguiente(elemento2);
            }
        }
    }
    else{
        resultado=0;
    }
    return resultado;
}

void Algoritmos_Ordenada::copiar(Lista_Ord otra){
    otra.vaciar();
    if(!lista.vacia()){
        int elemento = lista.primero();
        for(int i = 0; i < lista.numElem();i++){
            otra.agregar(elemento);
        }
    }
}

int Algoritmos_Ordenada::contenida(Lista_Ord otra){//falta terminar esto, pero tengo que estudiar jeje  
    int resultado = 1;
    if(this->lista.numElem() <= otra.numElem() && !otra.vacia()){
        int elemento1 = lista.primero;
        int elemento2 = otra.primero; 
        while(elemento1 != elemento2 && elemento2 != otra.siguiente(otra.ultimo())){
            elemento2 = otra.siguiente(elemento2); 
        }
        if(elemento2 == otra.siguiente(otra.ultimo())){
            resultado = 0;
        }
        else{
            while(elemento2 != otra.siguiente(otra.ultimo())){

            }
        }
    }
    else{
        if(!lista.vacia()){
            resultado = 0;
        }
    }
    return resultado;       
}

int Algoritmos_Ordenada::pertenece(int elemento){
    int resultado = 0;
    if(lista.numElem() > 0){
        int numero = lista.primero();
        int encontre = 0;
        while(numero != lista.siguiente(lista.ultimo()) && !encontre){
            if(numero == elemento){
                encontre = 1;
                resultado = 1;
            }
            else{
                numero = lista.siguiente(numero);
            }
        }
    }
    return resultado;
}

void Algoritmos_Ordenada::eliminarElementosRepetidos(Lista_Ord){
    
}

Lista_Ord Algoritmos_Ordenada::unionListas(Lista_Ord){
    
}

Lista_Ord Algoritmos_Ordenada::interseccion(Lista_Ord){

}
