#include <iostream>
using namespace std; 
#include "lista_pos_Arreglo.h"
//#include "lista_pos_LDE.h"
//#include "lista_pos_LSE.h"

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
		
		lista->agregarPosicion(position, value); 
		cout << lista->imprimirLista() << endl; 
	break; 
	
	
	
	case 2: 
	
		cout << "Posicicon : "; 
		cin >> position; 
		lista->borrarPosicion(position); 
		cout << lista->imprimirLista() << endl; 	
	break; 	
	
	
	case 3: 
		cout << "Posicion : "; 
		cin >>position; 
		cout << "Valor : "; 
		cin >>value; 
		lista->modificarPosicion(position, value); 
		cout << lista->imprimirLista() << endl; 
	break; 
	
	
	case 4: 
		cout << "Posicion : "; 
		cin >> position; 
		cout << "elemento : " << lista->recuperarPosicion(position) << endl;
	
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
