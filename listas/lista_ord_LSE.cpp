#include "lista_ord_LSE.h"

Lista::Elemento::Elemento(int elemento){
    this->elemento = elemento;
    siguiente = 0;
}

Lista::Elemento::~Elemento(){
    if(siguiente){
        delete siguiente;
    }
}

Lista::Lista(){

}
Lista::~Lista(){
    delete primeraPosicion;
    numeroElementos = 0;
    tamanoMaximo = 0;
}

void Lista::iniciar(int tamanoMaximo){
    this->tamanoMaximo = tamanoMaximo;
}

void Lista::destruir(){
    delete this;
}

void Lista::vaciar(){
    delete  primeraPosicion;
    this->primeraPosicion = 0;
    this->ultimaPosicion = 0;
}

int Lista::vacia(){
    return primeraPosicion == 0;
}

void Lista::agregar(int elemento){
    Elemento * nuevo = new Elemento(elemento);
    if(!vacia()){
        Elemento * temp = primeraPosicion;
        int agregue = 0;  
        while(temp!=nullptr && !agregue){
            if(temp->siguiente){
                if(temp->siguiente->elemento > nuevo->elemento){
                    nuevo->siguiente = temp->siguiente;
                    temp->siguiente = nuevo;
                    agregue = 1;
                }
                else{
                temp = temp->siguiente;
                }
            }
            else{
                temp = temp->siguiente;
            }
        }
        if(!agregue){
            ultimaPosicion->siguiente = nuevo;
            ultimaPosicion = nuevo;
        }
    }
    else{
        primeraPosicion = nuevo;
        ultimaPosicion = nuevo;
        cout << "Se agrega el elemento "<< elemento << " con exito.\n";
    }
    numeroElementos++;
}

void Lista::borrar(int elemento){
    if(!vacia()){
        Elemento * temp = primeraPosicion;
        int borre = 0;
        if(temp->elemento == elemento){//caso en el que se borrara el primer elemento
            primeraPosicion = temp->siguiente;
            temp->siguiente = 0;
            delete temp;
            borre = 1;        
        }
        while(temp != nullptr && !borre){
            if(temp->siguiente->elemento == elemento){
                Elemento * victima = temp->siguiente;
                temp->siguiente = victima->siguiente;
                victima->siguiente = 0;
                temp = victima;
                delete victima;
                borre=1; 
            }
            else{
                temp = temp->siguiente;
            }
        }
        numeroElementos--;
        if(!borre){
            cout << "No se pudo borrar el elemento deseado, ya que el elemento no esta en la lista.\n";    
        }
    }
    else{
       cout << "No se pudo borrar el elemento deseado, ya que la lista esta vacia.\n";
    }
}

int Lista::primero(){
    int resultado = -1;
    if (primeraPosicion){
        resultado = primeraPosicion->elemento;
    }
    else{
        cout << "La lista esta vacia, por lo que no se puede devolver un primer elemento.\n";
    }
    return resultado;
}

int Lista::ultimo(){
    int resultado = -1;
    if (ultimaPosicion){
        resultado = ultimaPosicion->elemento;
    }
    else{
        cout << "La lista esta vacia, por lo que no se puede devolver un primer elemento.\n";
    }
    return resultado;
}

int Lista::siguiente(int elemento){
    Elemento * temp = primeraPosicion;
    int resultado = 0;
    if(ultimaPosicion->elemento == elemento){
        resultado = -1;
        cout << "El elemento deseado es el ultimo de la lista.\n";
    }
    else{
        int encontre = 0;
        while(temp!=nullptr && !encontre){
            if(temp->elemento == elemento){
                resultado = temp->siguiente->elemento;
                encontre = 1;
            }
            else{
                temp = temp->siguiente;
            }
        }
        if(!encontre){
            cout << "El elemento deseado no esta en la lista\n";
        }
    }
    return resultado;
}

int Lista::anterior(int elemento){
    Elemento * temp = primeraPosicion;
    int resultado = 0;
    if(temp->elemento == elemento){
        resultado = -1;
        cout << "El elemento deseado es el primero de la lista.\n";
    }
    else{
        int encontre = 0;
        while(temp!=nullptr && !encontre){
            if(temp->siguiente->elemento == elemento){
                resultado = temp->elemento;
                encontre = 1;
            }
            else{
                temp = temp->siguiente;
            }
        }
        if(!encontre){
            cout << "El elemento deseado no esta en la lista\n";
        }
    }
    return resultado;
}

int Lista::numElem(){
    return numeroElementos;
}

void Lista::imprimir(){
    cout << "{";
    if(primeraPosicion){
        primeraPosicion->imprimir();
    }
    cout << "}\n";
}

void Lista::Elemento::imprimir(){
    cout << elemento;
    if(siguiente){
        cout << " ";
        siguiente->imprimir();
    }
}