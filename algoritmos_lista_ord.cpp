#include "algoritmos_lista_ord.h"

Algoritmos_Ordenada::Algoritmos_Ordenada(/*Lista_Ord & lista*/){
    // this->lista = lista;
}

//
//Efecto: Este algoritmo 
//Requiere: Este algoritmo 
//Modifica: Este algoritmo

//Listar(L1)
//Efecto: Este algoritmo imprime en pantalla la lista L1.  
//Requiere: Este algoritmo requiere que la lista esté inicializada.
//Modifica: Este algoritmo no modifica nada.
void Algoritmos_Ordenada::listar(Lista_Ord & lista){
    lista.imprimir();
}

//Iguales(L1,L2) -> entero
//Efecto: Este algoritmo determina si las listas L1 y L2 son iguales.
//Requiere: Este algoritmo requiere que ambas listas estén inicializadas. 
//Modifica: Este algoritmo únicamente devuelve un 1 si las listas son iguales y un 0 si no.
int Algoritmos_Ordenada::iguales(Lista_Ord & lista, Lista_Ord & otra){
    int resultado = 1;
    if(lista.numElem() == otra.numElem() && lista.numElem()!=0 && otra.numElem()!=0){
        int elemento1 = lista.primero();
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

// Copiar(L1,L2)
//Efecto: Este algoritmo modifica a L2 para que sea igual a L1.
//Requiere: Este algoritmo requiere que ambas listas sean inicializadas.
//Modifica: Este algoritmo modifica a L2, haciendola igual a L1.
void Algoritmos_Ordenada::copiar(Lista_Ord & lista, Lista_Ord & otra){
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

//Contenida(L1,L2)-> entero
//Efecto: Este algoritmo determina si L2 está contenida en L1.
//Requiere: Este algoritmo requiere que ambas listas estén previamente inicializadas. 
//Modifica: Este algoritmo únicamente devuelve un 1 si L2 está contenida o un 0 si no.
int Algoritmos_Ordenada::contenida(Lista_Ord & lista, Lista_Ord & otra){
    int resultado = 1;
    if(lista.numElem() <= otra.numElem() && !otra.vacia()){
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

//Pertenece(L1, elemento) -> entero
//Efecto: Este algoritmo determina si un elemento pertenece a una lista determinada.
//Requiere: Este algoritmo requiere que la lista esté inicializada.
//Modifica: Este algoritmo únicamente devuelve un 1 si el elemento está en la lista o un 0 si no.
int Algoritmos_Ordenada::pertenece(Lista_Ord & lista, int elemento){
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

//EliminarElementosRepetidos(L1,L2)
//Efecto: Este algoritmo elimina los elementos repetidos entre L1 y L2 de L1. 
//Requiere: Este algoritmo requiere que ambas listas estén inicializadas.
//Modifica: Este algoritmo modifica L1, eliminando los elementos en común entre L1 y L2.
void Algoritmos_Ordenada::eliminarElementosRepetidos(Lista_Ord & lista, Lista_Ord & otra){
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

//Union(L1,L2)-> L3
//Efecto: Este algoritmo realiza una unión de dos listas ordenadas L1 y L2 y la almacena y devuelve en una nueva lista L3.
//Requiere: Este algoritmo requiere que ambas listas estén inicializadas. 
//Modifica: Este algoritmo genera una nueva Lista Ordenada, que será la unión de L1 y L2.
Lista_Ord Algoritmos_Ordenada::unionListas(Lista_Ord & lista, Lista_Ord & otra){
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
    respuesta.imprimir(); 
    return respuesta;
}

//Interseccion(L1,L2) -> L3
//Efecto: Este algoritmo realiza la intersección entre dos listas L1 y L2 para almacenarla y devolverla en una nueva lista ordenada L3.
//Requiere: Este algoritmo requiere que ambas listas estén inicializadas.
//Modifica: Este algoritmo genera una nueva lista L3, que será la intersección entre L1 y L2.
Lista_Ord Algoritmos_Ordenada::interseccion(Lista_Ord & lista, Lista_Ord & otra){
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
