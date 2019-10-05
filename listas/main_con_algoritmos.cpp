#include <iostream>
using namespace std; 
//#include "lista_pos_Arreglo.h"
//#include "lista_pos_LDE.h"
#include "lista_pos_LSE.h"


void insertarPosicion(int indice, int valor, Lista_Pos* lista); 
void borrarPosicion(int indice, Lista_Pos* lista); 						 
void modificarPosicion(int indice, int valor, Lista_Pos* lista);			
int recuperarPosicion(int indice, Lista_Pos* lista);	
int siguientePosicion(int indice, Lista_Pos* lista); 		
int anteriorPosicion(int indice, Lista_Pos* lista); 
int primeraPosicion(Lista_Pos* lista); 
int ultimaPosicion(Lista_Pos* lista); 
void iniciarLista(Lista_Pos* lista); 
void vaciarLista(Lista_Pos* lista); 
void destruirLista(Lista_Pos* lista); 
string imprimirLista(Lista_Pos* lista); 
void agregarPosicionAlFinal(int valor, Lista_Pos* lista); 



void iniciarLista(Lista_Pos* lista) {
	lista->iniciar(); 
}


void agregarPosicionAlFinal(int valor, Lista_Pos* lista) {
	lista->agregarAlFinal(valor); 
}


string imprimirLista(Lista_Pos* lista) {
	return lista->imprimirLista(); 
}

void vaciarLista(Lista_Pos* lista) {
	lista->vaciar(); 
}

void destruirLista(Lista_Pos* lista) {
	lista->destruir(); 
}


int primeraPosicion(Lista_Pos* lista) {
	
	Pos primera = lista->primera(); 
	int pos = 0; 
	
	if (primera != PosNula) {
		pos = lista->recuperar(primera); 
	}
	return pos; 
}


int ultimaPosicion(Lista_Pos* lista) {
	Pos ultima = lista->ultima(); 
	int pos = 0; 
	if (ultima != PosNula) {
		pos = lista->recuperar(ultima); 
	}
	return pos; 
}



int anteriorPosicion(int indice, Lista_Pos* lista) {
	Pos temporal = lista->traducir(indice);
	Pos before_one = lista->anterior(temporal);
	int value = 0; 
	if (before_one != PosNula) {
		value = lista->recuperar(before_one); 
	} 
	return value;  
}


int siguientePosicion(int indice, Lista_Pos* lista) {	
	Pos temporal = lista->traducir(indice);
	Pos next_one = lista->siguiente(temporal);
	int value = 0; 
	if (next_one != PosNula) {
		value = lista->recuperar(next_one); 
	} 
	 
	return value; 
}



void insertarPosicion(int indice, int valor, Lista_Pos* lista) {
	Pos temporal = lista->traducir(indice);
	lista->insertar(temporal, valor);  	
}


void borrarPosicion(int indice, Lista_Pos* lista) {
	Pos temporal = lista->traducir(indice);
	lista->borrar(temporal);  
}


void modificarPosicion(int indice, int valor, Lista_Pos* lista) {
	Pos temporal = lista->traducir(indice);
	if (temporal != PosNula) {
		lista->modificar(temporal, valor); 
	} 
}


int recuperarPosicion(int indice, Lista_Pos* lista) {
	int value = 0; 
	Pos temporal = lista->traducir(indice);
	if (temporal != PosNula) {
		value = lista->recuperar(temporal); 
	}
	return value;  	
}


int main (int argc, char*argv[]) {
	
Lista_Pos *lista = new Lista_Pos(); 
lista->iniciar(); 


int option = 0; 
int position = 0; 
int value = 0; 

bool end = false; 

do {
	
cout << " 1) Agregar Elemento \n 2) Borrar Elemento \n 3) Modificar Elemento \n 4) Recuperar Elemento \n 5) Siguiente Elemento \n 6) Anterior Elemento \n 7) Primer Elemento \n 8) Ultimo Elemento \n 9) Iniciar Lista \n 10) Vaciar Lista \n 11) Destruir Lista \n 12 Imprimir Lista \n 13) Agregar Al Final" << endl; 
cin >>option; 


switch (option) {
	
	case 1: 
	
		cout << "Posicion : "; 
		cin >> position; 
		cout << "Valor : "; 
		cin >> value; 
		
		insertarPosicion(position, value, lista); 
		
	break; 
	
	
	
	case 2: 
	
		cout << "Posicicon : "; 
		cin >> position; 
		
		borrarPosicion(position, lista); 	

	break; 	
	
	
	case 3: 
		cout << "Posicion : "; 
		cin >>position; 
		cout << "Valor : "; 
		cin >>value; 
		
		modificarPosicion(position, value, lista); 

	break; 
	
	
	case 4: 
		cout << "Posicion : "; 
		cin >> position; 
		cout << "elemento : " <<  recuperarPosicion(position, lista) << endl; 
	
	break; 
	
	
	case 5: 
		cout << "Posicion : "; 
		cin >>position; 
		cout << "siguiente : " << siguientePosicion(position, lista) << endl; 
	
	break; 
	
	case 6: 
	
		cout << "Posicion :"; 
		cin >>position; 
		cout << "Anterior : " << anteriorPosicion(position, lista) << endl; 
	
	break; 
	
	
	case 7: 
	
		cout << "Primero : " <<  primeraPosicion(lista) << endl; 
	
	
	break; 
	
	
	case 8: 
		
		cout << "Ultimo : " <<  ultimaPosicion(lista) << endl; 
	
	break; 
	
	
	case 9: 
	
		iniciarLista(lista); 
	
	break; 
	
	
	case 10: 
	
		vaciarLista(lista); 
		
	break; 
	
	
	case 11: 
	
		destruirLista(lista); 

	break; 
	
	
	case 12: 
		cout << imprimirLista(lista) << endl; 
		
	break; 
	
	
	case 13: 
		cout << "Valor : " << endl; 
		cin >>value; 
	
		agregarPosicionAlFinal(value, lista); 
	
	break; 
	
	default:
	
	
	break; 
	
}	
	

cout << "Continuar 1) SI, 2) NO" << endl; 
cin >>option; 

if (option == 2) {
	end = true; 
}
	
	
}while(!end); 	
	
	
	
} 
