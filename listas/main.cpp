#include <iostream>
//#include "lista_pos_LSE.h"
//#include "lista_pos_Arreglo.h"
#include "lista_pos_LDE.h"
using namespace std; 


// Hola

int main (int argc, char* argv[]) {
		
	Lista* lista = new Lista(); 
	lista->iniciar(); 
	//lista->iniciar(10); 
	
	bool end = true; 
	int answer = -1; 
	int option = -1; 
	int value = 0;
	int position = 0; 

	do {
		
	cout << "1) Insertar, 2) Borrar" << endl; 
	cin >>option; 	

	if (option == 1) {
		cout << "ingrese la posicion a ingresar : " << endl; 
		cin>>position; 
		cout << "ingrese el valor :" << endl; 
		cin>>value; 

		lista->agregarPosicion(position, value); 
		cout << lista->imprimirLista() << " NumElem: " << lista->NumElem() << "\n" << endl; 	
		
	//	cout << "revez : " << endl; 
	//	cout << lista->imprimirListaRevez() << "NumElem: " << lista->NumElem() << "\n" << endl;  
	}
	else {
		cout << "ingrese la posicion a borrar : " << endl; 
		cin >>position; 
		lista->borrarPosicion(position); 
		cout << lista->imprimirLista() << " NumElem: " << lista->NumElem() << "\n" << endl; 
	}	
		
			
		
	cout << "continuar : 1) SI - 2) NO\n"; 
	cin>>answer; 
	if (answer != 2) {
		end = false; 
	}	
	else {
		end = true; 
	}
		
	}while(!end); 	


	return 0; 	
}
