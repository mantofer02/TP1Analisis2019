#include "algoritmos_lista_ord.h"


Algoritmos_Ordenada::Algoritmos_Ordenada(Lista_Ord & lista){
    this->lista = lista;
}

void Algoritmos_Ordenada::listar(){
    this->lista.imprimir();
}

int Algoritmos_Ordenada::iguales(Lista_Ord & otra){
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

void Algoritmos_Ordenada::copiar(Lista_Ord & otra){
    otra.vaciar();
    if(!lista.vacia()){
        int elemento = lista.primero();
        cout << elemento << endl;
        cout << lista.siguiente(lista.ultimo()) << endl;
        while(elemento != lista.siguiente(lista.ultimo())){
            otra.agregar(elemento);
            elemento = lista.siguiente(elemento);
        }
    }
}

int Algoritmos_Ordenada::contenida(Lista_Ord & otra){//falta terminar esto, pero tengo que estudiar jeje  
    int resultado = 1;
    if(this->lista.numElem() <= otra.numElem() && !otra.vacia()){
        int elemento1 = lista.primero();
        int elemento2 = otra.primero(); 
        while(elemento1 != elemento2 && elemento2 != otra.siguiente(otra.ultimo())){
            elemento2 = otra.siguiente(elemento2); 
        }
        if(elemento2 == otra.siguiente(otra.ultimo())){
            resultado = 0;
        }
        else{
            while(elemento1 != lista.siguiente(lista.ultimo()) && resultado == 1){
                if(elemento1 < elemento2){
                    resultado = 0;
                }
                else{
                    if(elemento1 == elemento2){
                        elemento1 = lista.siguiente(elemento1);                         
                    }
                    else{
                        elemento2 = otra.siguiente(elemento2);
                    }
                }
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

void Algoritmos_Ordenada::eliminarElementosRepetidos(Lista_Ord & otra){
    int elemento1 = lista.primero();
    int elemento2 = otra.primero();
    int enCasoDeBorrar = 0;
    cout << lista.siguiente(lista.ultimo()) << endl;
    cout << otra.siguiente(otra.ultimo()) << endl;
    while(elemento1 != lista.siguiente(lista.ultimo()) && elemento2 != otra.siguiente(otra.ultimo())){
        if(elemento1 == elemento2){            
            enCasoDeBorrar = lista.siguiente(elemento1);
            lista.borrar(elemento1);
            elemento1 = enCasoDeBorrar;
        }
        else{
            if(elemento1 < elemento2){
                elemento1 = lista.siguiente(elemento1);
            }
            else{
                elemento2 = otra.siguiente(elemento2);
            }
        }
    }
}

Lista_Ord Algoritmos_Ordenada::unionListas(Lista_Ord & otra){
    Lista_Ord respuesta;
    respuesta.iniciar();
    int elemento1 = lista.primero();
    int elemento2 = otra.primero();
    while(elemento1 != lista.siguiente(lista.ultimo()) && elemento2 != otra.siguiente(otra.ultimo())){
        if(elemento1 == elemento2){            
            respuesta.agregar(elemento1);
            elemento1 = lista.siguiente(elemento1);
            elemento2 = otra.siguiente(elemento2);   
        }
        else{
            if(elemento1 < elemento2){
                respuesta.agregar(elemento1);
                elemento1 = lista.siguiente(elemento1);
            }
            else{
                respuesta.agregar(elemento2);
                elemento2 = otra.siguiente(elemento2);
            }
        }
    }
    if(elemento1 != lista.siguiente(lista.ultimo())){
        while(elemento1 != lista.siguiente(lista.ultimo())){
            respuesta.agregar(elemento1);
            elemento1 = lista.siguiente(elemento1);
        }
    }
    if(elemento2 != otra.siguiente(otra.ultimo())){
        while(elemento2 != otra.siguiente(otra.ultimo())){
            respuesta.agregar(elemento2);
            elemento2 = otra.siguiente(elemento2);
        }
    }
    return respuesta;
}


Lista_Ord Algoritmos_Ordenada::interseccion(Lista_Ord & otra){
    Lista_Ord respuesta;
    respuesta.iniciar();
    int elemento1 = lista.primero();
    int elemento2 = otra.primero();
    while(elemento1 != lista.siguiente(lista.ultimo()) && elemento2 != otra.siguiente(otra.ultimo())){
        if(elemento1 == elemento2){            
            respuesta.agregar(elemento1);   
            elemento1 = lista.siguiente(elemento1);
            elemento2 = otra.siguiente(elemento2);
        }
        else{
            if(elemento1 < elemento2){
                elemento1 = lista.siguiente(elemento1);
            }
            else{
                elemento2 = otra.siguiente(elemento2);
            }
        }
    }
    return respuesta;
}
