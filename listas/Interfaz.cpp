#include "Interfaz.h"

#define Ordenada 1
#define Posicionada 2
#define Indexada 3


Interfaz :: Interfaz(){
    tipoDeLista = 0;
    cout << "Bienvenido " << endl;
    menu();
}

void Interfaz :: menu(){
    cout << "Digite :" << endl;
    cout << "1: Si desea el menu de lista Ordenada" << endl;
    cout << "2: Si desea el menu Posicionada" << endl;
    cout << "3: Si desea el menu Indexada" << endl;
    cout << "4: Exit" << endl;
    cin >> tipoDeLista;
    if(tipoDeLista == Ordenada)
        escogioListaOrdenada();
    if(tipoDeLista == Indexada)
        escogioListaIndexada();
}

void Interfaz :: escogioListaOrdenada(){
    int operacion = 0;
    cout << "1) iniciar();" << endl;
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
            cout << "Se inicio la lista" << endl;
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

void Interfaz :: escogioListaIndexada(){
    /*

    void iniciar(); 
        // hacer un iniciar con una firma diferente
        bool vacio();
        void destruir();
        ~Lista_Index();
        void insertar(int, int);
        void borrar(int);

        int recuperar(int);  
        
        void modificarElemento(int, int);      
        
        void intercambiar(int indice1, int indice2);
        int numElem();
        
        void imprimirLista_Index();

    */
    
    
    int operacion = 0;
    cout << "1) iniciar();" << endl;
    cout << "2) destruir();" << endl;
    cout << "3) vaciar();" << endl;
    cout << "4) vacia();" << endl; 
    cout << "5) agregar(int , int)" << endl;
    cout << "6) borrar(int)" << endl;
    cout << "7) recuperar(int)" << endl;
    cout << "8) modificarElemento(int, int)" << endl;
    cout << "9) intercambiar(int,int)" << endl;
    cout << "10) numElem()" << endl;
    cout << "11) imprimirLista()" << endl;
    cin >> operacion;
    int parametro1 = 0;
    int parametro2 = 0;
    switch (operacion){
        case 1:
            cout << "Se inicio la lista" << endl;
            miListaIndex.iniciar();
            break;
        case 2:
            cout << "Se va a destruir la lista indexada" << endl;
            miListaIndex.destruir();
            break;
        case 3: 
            cout << "Se va a vaciar la lista indexada" << endl;
            miListaIndex.vaciar();
            break;
        case 4:
            if(miListaIndex.vacia() == true){
            cout << "Esta Vacia" << endl;
            }else{
                cout << "No esta vacia" << endl;
            }
            break;
        case 5:
            cout << "Digite un indice para la lista indexada" << endl;
            cin >> parametro1;
            cout << "Digite el elemento que desea insertar" << endl;
            cin >> parametro2;
            miListaIndex.agregar(parametro1, parametro2);
            break;
        case 6:
            cout << "Digite el indice del elemento que desea borrar de la lista " << endl;
            cin >> parametro1;
            miListaIndex.borrar(parametro1);
            break;
        case 7:
            cout << "¿Que indice desea ver ?" << endl;
            cin >> parametro1;
            if(miListaIndex.recuperar(parametro1) == elementoNulo){
                cout << "Este indice no posee elemento" << endl;
            }else{
                cout << "Indice : " << parametro1 << "Elemento :" << miListaIndex.recuperar(parametro1) << endl; 
            }
            break;
        case 8:
            cout << "Digite un indice para la lista indexada" << endl;
            cin >> parametro1;
            cout << "Digite el elemento que desea modificar" << endl;
            cin >> parametro2;
            miListaIndex.modificarElemento(parametro1, parametro2);
            break;
        case 9:
            cout << "1er Indice : " << endl;
            cin >> parametro1;
            cout << "2ndo Indice : " << endl;
            cin >> parametro2;
            miListaIndex.intercambiar(parametro1, parametro2);
            break;
        case 10:
            cout << "Hay " << miListaIndex.numElem() << "elementos en la lista." << endl;
            break;
        case 11:
            miListaIndex.imprimirLista();
    }
    menu();
}


