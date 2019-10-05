#include "Interfaz.h"

#define Ordenada 1
#define Posicionada 2
#define Indexada 3


Interfaz :: Interfaz(){
    miListaPos = new Lista_Pos();
    miListaPos->iniciar();
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
    if(tipoDeLista == Posicionada)
        escogioListaPosicionada();
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

void Interfaz :: escogioListaPosicionada(){
    int option = 0; 
    int position = 0; 
    int value = 0; 
    cout << " 1) Agregar Elemento \n 2) Borrar Elemento \n 3) Modificar Elemento \n 4) Recuperar Elemento \n 5) Siguiente Elemento \n 6) Anterior Elemento \n 7) Primer Elemento \n 8) Ultimo Elemento \n 9) Iniciar Lista \n 10) Vaciar Lista \n 11) Destruir Lista \n 12 Imprimir Lista \n 13) Agregar Al Final" << endl; 
    cin >>option; 
    switch (option){
	case 1: 
		cout << "Posicion : "; 
		cin >> position; 
		cout << "Valor : "; 
		cin >> value; 
		insertarPosicion(position, value, miListaPos); 
	    break; 
	case 2: 
		cout << "Posicicon : "; 
		cin >> position; 
		borrarPosicion(position, miListaPos); 	
        break; 	
	case 3: 
		cout << "Posicion : "; 
		cin >>position; 
		cout << "Valor : "; 
		cin >>value; 
		modificarPosicion(position, value, miListaPos); 
	    break; 
	case 4: 
		cout << "Posicion : "; 
		cin >> position; 
		cout << "elemento : " <<  recuperarPosicion(position, miListaPos) << endl; 
	    break; 
	case 5: 
		cout << "Posicion : "; 
		cin >>position; 
		cout << "siguiente : " << siguientePosicion(position, miListaPos) << endl; 
	    break; 
	case 6: 
		cout << "Posicion :"; 
		cin >>position; 
		cout << "Anterior : " << anteriorPosicion(position, miListaPos) << endl; 
	    break; 
	case 7: 
		cout << "Primero : " <<  primeraPosicion(miListaPos) << endl; 
	    break; 
	case 8: 
		cout << "Ultimo : " <<  ultimaPosicion(miListaPos) << endl; 
	    break; 
	case 9: 
		iniciarLista(miListaPos); 
	    break; 
	case 10: 
		vaciarLista(miListaPos); 
	    break; 
	case 11: 
		destruirLista(miListaPos); 
	    break; 
	case 12: 
		cout << imprimirLista(miListaPos) << endl; 
	    break; 
	case 13: 
		cout << "Valor : " << endl; 
		cin >>value; 
		agregarPosicionAlFinal(value, miListaPos); 
	break; 	
    }
    escogioListaPosicionada();
}	
			 

void Interfaz ::iniciarLista(Lista_Pos* lista) {
	lista->iniciar(); 
}


void Interfaz ::agregarPosicionAlFinal(int valor, Lista_Pos* lista) {
	lista->agregarAlFinal(valor); 
}


string Interfaz :: imprimirLista(Lista_Pos* lista) {
	return lista->imprimirLista(); 
}

void Interfaz :: vaciarLista(Lista_Pos* lista) {
	lista->vaciar(); 
}

void Interfaz ::destruirLista(Lista_Pos* lista) {
	lista->destruir(); 
}


int  Interfaz :: primeraPosicion(Lista_Pos* lista) {
	
	Pos primera = lista->primera(); 
	int pos = 0; 
	
	if (primera != PosNula) {
		pos = lista->recuperar(primera); 
	}
	return pos; 
}


int Interfaz :: ultimaPosicion(Lista_Pos* lista) {
	Pos ultima = lista->ultima(); 
	int pos = 0; 
	if (ultima != PosNula) {
		pos = lista->recuperar(ultima); 
	}
	return pos; 
}



int Interfaz :: anteriorPosicion(int indice, Lista_Pos* lista) {
	Pos temporal = lista->traducir(indice);
	Pos before_one = lista->anterior(temporal);
	int value = 0; 
	if (before_one != PosNula) {
		value = lista->recuperar(before_one); 
	} 
	return value;  
}


int Interfaz :: siguientePosicion(int indice, Lista_Pos* lista) {	
	Pos temporal = lista->traducir(indice);
	Pos next_one = lista->siguiente(temporal);
	int value = 0; 
	if (next_one != PosNula) {
		value = lista->recuperar(next_one); 
	} 
	 
	return value; 
}



void Interfaz :: insertarPosicion(int indice, int valor, Lista_Pos* lista) {
	Pos temporal = lista->traducir(indice);
	lista->insertar(temporal, valor);  	
}


void  Interfaz :: borrarPosicion(int indice, Lista_Pos* lista) {
	Pos temporal = lista->traducir(indice);
	lista->borrar(temporal);  
}


void Interfaz :: modificarPosicion(int indice, int valor, Lista_Pos* lista) {
	Pos temporal = lista->traducir(indice);
	if (temporal != PosNula) {
		lista->modificar(temporal, valor); 
	} 
}


int Interfaz :: recuperarPosicion(int indice, Lista_Pos* lista) {
	int value = 0; 
	Pos temporal = lista->traducir(indice);
	if (temporal != PosNula) {
		value = lista->recuperar(temporal); 
	}
	return value;  	
}

Interfaz :: ~Interfaz(){
    delete miListaPos;
}
