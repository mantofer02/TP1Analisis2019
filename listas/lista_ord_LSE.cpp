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

void Lista::imprimirMenu(Lista * lista){
    cout << "Bienvenido al programa de prueba de la lista ordenada implementada a través de un array. Digite los dígitos correspondientes a los operadores básicos que desea usar:\n" << endl;
    cout << "1. Iniciar.\n2. Destruir.\n3. Vaciar.\n4. Vacia.\n5. Agregar.\n6. Borrar.\n7. Primero.\n8. Ultimo.\n9. Siguiente.\n10. Anterior.\n11. NumElem\n12. Imprimir.\n13. Salir." << endl;
    int decision = 0;
    if(!(cin >> decision)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
        imprimirMenu(lista);
    }
    else{
        if(0 < decision || 14 < decision){
            if(decision == 1){
                decision = 0;
                cout << "Ingrese un valor valido para M (tamano maximo de la lista)" << endl;
                if(!(cin >> decision)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
                if(decision>0){
                    lista->iniciar(decision);
                    imprimirMenu(lista);
                }  
                else{
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
            }
            if(decision == 2){
                cout << "CUIDADO! Si destruye la lista, debera reiniciar el programa. Esta seguro?\n1. Si.\n2. No.\n" << endl; 
                if(!(cin >> decision)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
                if(decision == 2){
                    imprimirMenu(lista);
                }
            }
            if(decision == 3){
                lista->vaciar();
                imprimirMenu(lista);           
            }
            if(decision == 4){
                int vacia = lista->vacia();
                if(vacia){
                    cout << "La lista esta vacia.\n" << endl;
                }
                else{
                    cout << "La lista no esta vacia.\n" << endl;
                }
                imprimirMenu(lista);
            }
            if(decision == 5){
                decision = 0;
                cout << "Digite el numero que desea agregar:\n" << endl;
                if(!(cin >> decision)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
                lista->agregar(decision);
                imprimirMenu(lista); 
            }
            if(decision == 6){
                decision = 0;
                cout << "Digite el numero que desea borrar:\n" << endl;
                if(!(cin >> decision)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
                lista->borrar(decision);
                imprimirMenu(lista);
            }
            if(decision == 7){
                int primero = lista->primero();
                if(primero>-1){
                    cout << "El primer elemento de la lista es "<< primero << ".\n" << endl;
                }
                lista->imprimirMenu(lista);
            }
            if(decision == 8){
                int ultimo = lista->ultimo();
                if(ultimo>-1){
                    cout << "El ultimo elemento de la lista es "<< ultimo << ".\n" << endl;
                }
                lista->imprimirMenu(lista);
            }
            if(decision == 9){
                decision = 0;
                cout << "Digite el numero del cual desea averiguar:\n" << endl;
                if(!(cin >> decision)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
                int resultado = lista->siguiente(decision);
                if(resultado != -1){
                    cout << "El elemento siguiente a "<< decision <<" es " << resultado << ".\n"<< endl;
                }
                lista->imprimirMenu(lista);
            }
            if(decision == 10){
                decision = 0;
                cout << "Digite el numero del cual desea averiguar:\n" << endl;
                if(!(cin >> decision)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
                int resultado = lista->anterior(decision);
                if(resultado != -1){
                    cout << "El elemento anterior a "<< decision <<" es " << resultado << ".\n"<< endl;
                }
                lista->imprimirMenu(lista);
            }
            if(decision == 11){
                decision = lista->numElem(); 
                cout << "El numero de elementos de la lista es " <<decision<<".\n"<< endl ;
                lista->imprimirMenu(lista);
            }
            if(decision == 12){
                cout << "L:";
                lista->imprimir();
                imprimirMenu(lista);
            }
        }
        else{
            cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
            imprimirMenu(lista);
        }
    }
}