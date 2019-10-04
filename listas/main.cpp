#include <iostream>
using namespace std; 
//#include "lista_pos_Arreglo.h"
//#include "lista_pos_LDE.h"
#include "lista_pos_LSE.h"


void insertarPosicion(int indice, int valor, Lista* lista); 
void borrarPosicion(int indice, Lista* lista); 						 
void modificarPosicion(int indice, int valor, Lista* lista);			
int recuperarPosicion(int indice, Lista* lista);			


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
	
cout << "1) Agregar Elemento \n 2) Borrar Elemento \n 3) Modificar Elemento \n 4) Recuperar Elemento" << endl; 
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
