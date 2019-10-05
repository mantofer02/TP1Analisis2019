#include "Interfaz.h"

#define Ordenada 1
#define Posicionada 2
#define Indexada 3


Interfaz :: Interfaz(){
    menu();
}

void Interfaz :: menu(){
    cout << "Bienvenido " << endl;
    cout << "Digite :" << endl;
    cout << "1: Si desea una lista Ordenada" << endl;
    cout << "2: Si desea una lista Posicionada" << endl;
    cout << "3: Si desea una lista Indexada" << endl;
    cin >> tipoDeLista;
}

void Interfaz :: escogioListaOrdenada(){
    int operacion = 0;
    cout << "1) iniciar(int);" << endl;
    cout << "2) destruir();" << endl;
    cout << "3) vaciar();" << endl;
    cout << "4) vacia();" << endl; 
    cout << "5) agregar(int)" << endl;
    cout << "6) borrar(int)" << endl;
    cout << "7) primero()" << endl;
    cout << "8) ultimo()" << endl;
    cout << "9) siguiente(int)" << endl;
    cout << "10) anterior(int)" << endl;
    cout << "11) numElem()" << endl;
    cin >> operacion;
    int parametro = 0;
    switch (operacion){
        case 1:
            cout << "Ingrese Parametro" << endl;
            // NO SIRVE PARA LA ORDENADA ENLAZADA
            miListaOrdena.iniciar();
            break;
        case 2:
            cout << "Se va a destruir la lista ordenada" << endl;
            miListaOrdena.destruir();
            break;
        case 3: 
            cout << "Se va a vaciar la lista ordenada" << endl;
            miListaOrdena.vaciar();
            break;
        case 4:
            if(miListaOrdena.vacia()){
            cout << "Esta Vacia" << endl;
            }else{
                cout << "No esta vacia" << endl;
            }
            break;
        case 5:
            cout << "Digite el elmento que desea agregar" << endl;
            cin >> parametro;
            miListaOrdena.agregar(parametro);
            break;
        case 6:
            cout << "Digite el elemento que desea borrar de la lista " << endl;
            cin >> parametro;
            miListaOrdena.borrar(parametro);
            break;
        case 7:
            cout << "Este es el primer elemento : " << miListaOrdena.primero() << endl;
            break;
        case 8:
            cout << "Este es el ultimo elemento : " << miListaOrdena.ultimo() << endl;
            break;
        case 9:
            cout << "Inserte un elemento " << endl;
            cin >> parametro;
            cout << "Este es el siguiente --->" << miListaOrdena.siguiente(parametro) << endl;
            break;
        case 10:
            cout << "Inserte un elemento " << endl;
            cin >> parametro;
            cout << "Este es el anterior ---> " << miListaOrdena.anterior(parametro) << endl;
        case 11:
            cout << "Hay " << miListaOrdena.numElem() << "elementos en la lista." << endl;
            break;
    }
    menu();
}


