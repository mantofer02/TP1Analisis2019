#include <iostream>
using namespace std; 
#include "lista_pos_Arreglo.h"
//#include "lista_pos_LDE.h"
//#include "lista_pos_LSE.h"


void insertarPosicion(int indice, int valor, Lista* lista); 
void borrarPosicion(int indice, Lista* lista); 						 
void modificarPosicion(int indice, int valor, Lista* lista);			
int recuperarPosicion(int indice, Lista* lista);	
int siguientePosicion(int indice, Lista* lista); 		
int anteriorPosicion(int indice, Lista* lista); 
int primeraPosicion(Lista* lista); 
int ultimaPosicion(Lista* lista); 
void iniciarLista(Lista* lista); 
void vaciarLista(Lista* lista); 
void destruirLista(Lista* lista); 



void iniciarLista(Lista* lista) {
	lista->iniciar(); 
}

void vaciarLista(Lista* lista) {
	lista->vaciar(); 
}

void destruirLista(Lista* lista) {
	lista->destruir(); 
}


int primeraPosicion(Lista* lista) {
	
	Pos primera = lista->primera(); 
	int pos = 0; 
	
	if (primera != PosNula) {
		pos = lista->recuperar(primera); 
	}
	return pos; 
}


int ultimaPosicion(Lista* lista) {
	Pos ultima = lista->ultima(); 
	int pos = 0; 
	if (ultima != PosNula) {
		pos = lista->recuperar(ultima); 
	}
	return pos; 
}



int anteriorPosicion(int indice, Lista* lista) {
	Pos temporal = lista->traducir(indice);
	Pos before_one = lista->anterior(temporal);
	int value = 0; 
	if (before_one != PosNula) {
		value = lista->recuperar(before_one); 
	} 
	return value;  
}


int siguientePosicion(int indice, Lista* lista) {	
	Pos temporal = lista->traducir(indice);
	Pos next_one = lista->siguiente(temporal);
	int value = 0; 
	if (next_one != PosNula) {
		value = lista->recuperar(next_one); 
	} 
	 
	return value; 
}



void insertarPosicion(int indice, int valor, Lista* lista) {
	Pos temporal = lista->traducir(indice);
	lista->insertar(temporal, valor);  	
}


void borrarPosicion(int indice, Lista* lista) {
	Pos temporal = lista->traducir(indice);
	lista->borrar(temporal);  
}


void modificarPosicion(int indice, int valor, Lista* lista) {
	Pos temporal = lista->traducir(indice);
	if (temporal != PosNula) {
		lista->modificar(temporal, valor); 
	} 
}


int recuperarPosicion(int indice, Lista* lista) {
	int value = 0; 
	Pos temporal = lista->traducir(indice);
	if (temporal != PosNula) {
		value = lista->recuperar(temporal); 
	}
	return value;  	
}


int main (int argc, char*argv[]) {
	
Lista *lista = new Lista(); 
lista->iniciar(); 


int option = 0; 
int position = 0; 
int value = 0; 

bool end = false; 

do {
	
cout << "1) Agregar Elemento \n 2) Borrar Elemento \n 3) Modificar Elemento \n 4) Recuperar Elemento \n 5) Siguiente Elemento \n 6) Anterior Elemento \n 7) Primer Elemento \n 8) Ultimo Elemento \n 9) Iniciar Lista \n 10) Vaciar Lista \n 11) Destruir Lista" << endl; 
cin >>option; 


switch (option) {
	
	case 1: 
	
		cout << "Posicion : "; 
		cin >> position; 
		cout << "Valor : "; 
		cin >> value; 
		
		insertarPosicion(position, value, lista); 
		
		cout << lista->imprimirLista() << endl; 
	break; 
	
	
	
	case 2: 
	
		cout << "Posicicon : "; 
		cin >> position; 
		
		borrarPosicion(position, lista); 	
		cout << lista->imprimirLista() << endl; 	
	break; 	
	
	
	case 3: 
		cout << "Posicion : "; 
		cin >>position; 
		cout << "Valor : "; 
		cin >>value; 
		
		modificarPosicion(position, value, lista); 
		cout << lista->imprimirLista() << endl; 
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
