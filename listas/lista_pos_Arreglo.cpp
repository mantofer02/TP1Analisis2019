#include <iostream>
#include <sstream>
using namespace std; 


class Lista {
	
private: 
int* lista; 
int numero_elementos; 
int longitud; 	
	
public: 
Lista(); 
void iniciar(int longitud); 
void destruir(); 
int recuperar(int posicion); 
void modificar(int posicion, int valor); 
int siguiente(int posicion); 
void insertar(int posicion, int valor); 
void agregarAlFinal(int valor); 
int traducir(int posicion); 
void agregarPosicion(int posicion, int valor); 
void borrar(int posicion); 
void borrarPosicion(int posicion); 
int primera(); 
int numElem(); 
string imprimirLista(); 


	
}; 


Lista::Lista() {
	
}

void Lista::iniciar(int longitud) {			//hay que cononcer M.
 this->longitud = longitud;  
 this->lista = (int*)calloc(longitud, sizeof(int)); 
 this->numero_elementos = 0; 	
}


void Lista::destruir() {
	
}


int Lista::primera() {
 return 0; 	
}

void Lista::agregarAlFinal(int valor) {
	this->lista[numero_elementos] = valor; 
	++this->numero_elementos; 
}


int Lista::traducir(int posicion) {
	return posicion-1; 	
} 

int Lista::recuperar(int posicion) {		//requiere que la posicion exista. 	
	posicion = traducir(posicion); 	
	return this->lista[posicion]; 	
} 


void Lista::modificar(int posicion, int valor) {		//requiere que la posicion exista. 
	posicion = traducir(posicion); 	
	this->lista[posicion] = valor; 
}


int Lista::siguiente(int posicion) {
	 posicion = traducir(posicion); 	
	 if (posicion < this->numero_elementos) {			//si es una posicion valida. 
		return posicion+1; 
	 }
	 else {
		 return -1; 									//si retorna -1. esa posicion no es valida, no tiene siguiente. 
	 }	
}


void Lista::insertar(int posicion, int valor) {  
	if (this->numero_elementos < this->longitud) {		//si no esta lleno el array
			
		if (posicion <= numero_elementos && posicion < this->longitud && posicion >= 0) {	//y es una posicion valida. 
		 if (posicion < numero_elementos) {
			for (int position = numero_elementos-1; position != posicion-1; --position) {		//realizo un corrimiento para insertar. 
				this->lista[position+1] = this->lista[position]; 		
			}
			this->lista[posicion] = valor; 		 
			++this->numero_elementos; 
		 }
		 else {
			 agregarAlFinal(valor); 		 															// o se inserta al final. 
		 }		
		}		
	}	
	else {
						//esta lleno no se puede ingresar nada mas. 
	}
}


void Lista::agregarPosicion(int posicion, int valor) {
	posicion = traducir(posicion); 	//el array posee posición 0, por eso se le reduce 1.  
	insertar(posicion, valor);						
}

string Lista::imprimirLista() {
stringstream ss; 
for (int iteration = 0; iteration < this->numero_elementos; ++iteration) {
 ss << this->lista[iteration] << " "; 	
}
ss << "\n"; 	
	
return ss.str(); 	
}


int main (int argc, char* argv[]) {
	

	Lista* lista = new Lista(); 
	lista->iniciar(10); 

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
		cout << lista->imprimirLista() << "\n" << endl; 	
	}
	else {
		cout << "ingrese la posicion a borrar : " << endl; 
		cin >>position; 
		//lista->borrarPosicion(position); 
		cout << lista->imprimirLista() << "\n" << endl; 
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
		
	
}



