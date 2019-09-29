#include "lista_ord_array.h"

ListaOrdenadaArray::ListaOrdenadaArray(){

}

ListaOrdenadaArray::~ListaOrdenadaArray(){
    delete array;
    numeroElementos = 0;
    tamanoMaximo = 0;
}

void ListaOrdenadaArray::iniciar(int tamanoMaximo){
    this->tamanoMaximo = tamanoMaximo;
    array = new int[tamanoMaximo];
    numeroElementos=0;
}

void ListaOrdenadaArray::destruir(){
    delete this;
}

void ListaOrdenadaArray::vaciar(){
    for(int i=0;i<numeroElementos;i++){
        array[i] = 0;    
    }
}

int ListaOrdenadaArray::vacia(){
    return numeroElementos == 0;
}

void ListaOrdenadaArray::agregar(int elemento){
    if(!(this->tamanoMaximo==numeroElementos)){
        int agregue = 0;
        for(int i=0;i<=numeroElementos && !agregue;i++){
            if(elemento<array[i]){
                for(int k = numeroElementos;k>i;k--){
                    array[k] = array[k-1];
                }
                array[i] = elemento;
                cout << "Se agrega el elemento "<< elemento << " con exito.\n";
                agregue=1;
            }
        }
        if(!agregue){
            array[numeroElementos] = elemento;
        }
        numeroElementos++;
    }
    else{
        cout << "La lista esta llena; no se pudo agregar el elemento deseado.\n";
    }
}

void ListaOrdenadaArray::borrar(int elemento){
    if(!vacia()){
        for(int i=0;i<=numeroElementos;i++){
            if(elemento == array[i]){
                cout << "Se borra el elemento con exito.\n";
                array[i] = 0;
                for(i;i<numeroElementos;i++){
                    array[i] = array[i+1];
                }
            }
        }
        array[numeroElementos-1]=0;
        numeroElementos--;
    }
    else{
       cout << "El elemento deseado no estaba en la lista.\n";
    }
}

int ListaOrdenadaArray::primero(){
    int primero = 0;
    if(vacia()){
        cout << "La lista esta vacia.\n";
    }
    else{
        primero = array[0];
    }
    return primero;
}

int ListaOrdenadaArray::ultimo(){
    int ultimo = 0;
    if(vacia()){
        cout << "La lista esta vacia.\n";
    }
    else{
        ultimo = array[0];
    }
    return ultimo;
}

int ListaOrdenadaArray::siguiente(int elemento){
    int resultado = 0;
    int encontro = 0; 
    for(int i=0; i<numeroElementos; i++){
        if(array[i] == elemento){
            if((i+1) != numeroElementos){
                resultado = array[i+1];
            } 
            else{
                resultado = -1;
                cout << "El elemento deseado es el último en la lista.\n"; 
            }
            encontro=1;             
        }
    }
    if(!encontro){
        cout << "El elemento deseado no esta en la lista\n";
    }
    return resultado;
}

int ListaOrdenadaArray::anterior(int elemento){
    int resultado = 0;
    int encontro=0;
    for(int i=0; i<numeroElementos; i++){
        if(array[i] == elemento){
            if(i!=0){
                resultado = array[i-1];
            }
            else{
                resultado = -1;
                cout << "El elemento deseado es el primero en la lista.\n";
            }
            encontro=1;             
        }
    }
    if(!encontro){
        cout << "El elemento deseado no esta en la lista\n";
    }
    return resultado;
}
int ListaOrdenadaArray::numElem(){
    return numeroElementos;
}

void ListaOrdenadaArray::imprimir(){
    cout << "{"; 
    for(int i=0;i<numeroElementos;i++){
        cout << array[i] << " ";   
    }
    cout << "}";
}