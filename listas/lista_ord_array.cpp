#include "lista_ord_array.h"

Lista::Lista(){

}

Lista::~Lista(){
    delete array;
    numeroElementos = 0;
    tamanoMaximo = 0;
}

void Lista::iniciar(int tamanoMaximo){
    this->tamanoMaximo = tamanoMaximo;
    array = new int[tamanoMaximo];
    numeroElementos=0;
}

void Lista::destruir(){
    delete this;
}

void Lista::vaciar(){
    for(int i=0;i<numeroElementos;i++){
        array[i] = 0;    
    }
}

int Lista::vacia(){
    return numeroElementos == 0;
}

void Lista::agregar(int elemento){
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
            cout << "Se agrega el elemento "<< elemento << " con exito.\n";
        }
        numeroElementos++;
    }
    else{
        cout << "La lista esta llena; no se pudo agregar el elemento deseado.\n";
    }
}

void Lista::borrar(int elemento){
    if(!vacia()){
        int encontre = 0;
        for(int i=0;i<=numeroElementos && encontre;i++){
            if(elemento == array[i]){
                cout << "Se borra el elemento con exito.\n";
                array[i] = 0;
                for(i;i<numeroElementos;i++){
                    array[i] = array[i+1];
                }
            }
        }
        if(encontre){
            array[numeroElementos-1]=0;
            numeroElementos--;
        }
        else{
            cout << "No se pudo borrar el elemento deseado, ya que no estaba en la lista.\n";     
        }
    }
    else{
        cout << "No se pudo borrar el elemento deseado, ya que la lista esta vacia.\n";
    }
}

int Lista::primero(){
    int primero = 0;
    if(vacia()){
        cout << "La lista esta vacia.\n";
    }
    else{
        primero = array[0];
    }
    return primero;
}

int Lista::ultimo(){
    int ultimo = 0;
    if(vacia()){
        cout << "La lista esta vacia.\n";
    }
    else{
        ultimo = array[0];
    }
    return ultimo;
}

int Lista::siguiente(int elemento){
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

int Lista::anterior(int elemento){
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
int Lista::numElem(){
    return numeroElementos;
}

void Lista::imprimir(){
    cout << "{"; 
    for(int i=0;i<numeroElementos;i++){
        cout << array[i] << " ";   
    }
    cout << "}";
}

void Lista::imprimirMenu(){
    //cout << "Bienvenido al programa de prueba de las implementaciones de los diferentes modelos de lista.\nPara seleccionar el modelo a utilizar, digite el numero correspondiente al modelo deseado y a su respectiva estructuda de datos:\n " << endl;
    //cout << "1. Lista posicionada usando un arrewglo.\n2. Lista posicionada usando una Lista Simplemente Enlazada." << endl;
    //cout << "3. Lista posicionada usando una Lista Doblemente Enlazada.\n4. Lista ordenada usando un arreglo." << endl;
    //cout << "5. Lista ordenada usando una Lista Simplemente Enlazada.\n6. Lista indexada usando un arreglo." << endl;
    //cout << "7. Lista indexada usando una Lista Simplemente Enlazada." << endl;
}