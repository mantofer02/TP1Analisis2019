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
    delete array;
    array = new int[tamanoMaximo];
    numeroElementos = 0;
    cout <<"La lista ha sido vaciada con exito.\n"<< endl;
}

int Lista::vacia(){
    return numeroElementos == 0;
}

void Lista::agregar(int elemento){
    if(!(this->tamanoMaximo==numeroElementos)){
        int agregue = 0;
        for(int i=0;i<=numeroElementos && !agregue;i++){
            if(array[i] == elemento){
                i = numeroElementos;
                agregue=1;
                numeroElementos--;
                cout << "El elemento "<< elemento << " ya esta en la lista.\n"<< endl;                
            }
            if(elemento<array[i]){
                for(int k = numeroElementos;k>i;k--){
                    array[k] = array[k-1];
                }
                array[i] = elemento;
                cout << "Se agrega el elemento "<< elemento << " con exito.\n"<< endl;
                agregue=1;
            }
        }
        if(!agregue){
            array[numeroElementos] = elemento;
            cout << "Se agrega el elemento "<< elemento << " con exito.\n"<< endl;
        }
        numeroElementos++;
    }
    else{
        cout << "La lista esta llena; no se pudo agregar el elemento deseado.\n"<< endl;
    }
}

void Lista::borrar(int elemento){
    if(!vacia()){
        int encontre = 0;
        for(int i=0;i<=numeroElementos && !encontre;i++){
            if(elemento == array[i]){
                encontre = 1;
                cout << "Se borra el elemento "<<elemento<<" con exito.\n"<< endl;
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
            cout << "No se pudo borrar el elemento deseado, ya que no estaba en la lista.\n"<< endl;     
        }
    }
    else{
        cout << "No se pudo borrar el elemento deseado, ya que la lista esta vacia.\n"<< endl;
    }
}

int Lista::primero(){
    int primero = 0;
    if(vacia()){
        cout << "La lista esta vacia.\n"<< endl;
        primero = -1;               
    }
    else{
        primero = array[0];
    }
    return primero;
}

int Lista::ultimo(){
    int ultimo = 0;
    if(vacia()){
        cout << "La lista esta vacia.\n"<< endl;
        ultimo = -1;
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
                cout << "El elemento deseado es el último en la lista.\n"<< endl; 
                resultado = -1;
            }
            encontro=1;             
        }
    }
    if(!encontro){
        cout << "El elemento deseado no esta en la lista.\n"<< endl;
        resultado=-1;
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
                cout << "El elemento deseado es el primero en la lista.\n"<< endl;
                resultado = -1;
            }
            encontro=1;             
        }
    }
    if(!encontro){
        cout << "El elemento deseado no esta en la lista.\n"<< endl;
        resultado=-1;
    }
    return resultado;
}
int Lista::numElem(){
    return numeroElementos;
}

void Lista::imprimir(){
    cout << "{"; 
    for(int i=0;i<numeroElementos;i++){
        if(array[i]!=0){
            cout << array[i] << " ";   
        }   
    }
    cout << "}"<< endl;
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
        if(0 < decision || 14 > decision){
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
                    decision=0;
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
                decision=0;
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
                decision=0;
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
                decision=0;
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
                decision=0;
                lista->imprimirMenu(lista);
            }
            if(decision == 11){
                decision = lista->numElem(); 
                cout << "El numero de elementos de la lista es " <<decision<<".\n"<< endl ;
                decision=0;
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
