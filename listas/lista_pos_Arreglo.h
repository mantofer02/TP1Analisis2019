#include <iostream>
#include <sstream>
using namespace std; 


#define length 20;

typedef int Posicion; 

class Lista{
	private: 
		int* lista; 
		int numero_elementos; 
		int longitud; 	
		
	public: 
		Lista(); 
		void iniciar(); 								//O.B
		void destruir(); 								//0.B
		bool vacia(); 									//O.B
		void vaciar(); 									//O.B
		int primera(); 									//O.B
		int NumElem(); 									//0.B
		int recuperar(int posicion); 					//O.B
		void modificar(int posicion, int valor); 		//O.B
		int siguiente(int posicion); 					//O.B
		void insertar(int posicion, int valor); 		//O.B	
		void agregarAlFinal(int valor); 				//O.B
		void borrar(int posicion); 						//O.B
		int traducir(int posicion); 					//Algoritmo.		//traduce el indice del usuario al indice de la lista. osea de 1 a 0 o de 2 a 1. 					
		void borrarPosicion(int posicion); 				//Algoritmo. 
		void agregarPosicion(int posicion, int valor); 	//Algoritmo. 
		void modificarPosicion(int indice, int valor);	//Algoritmo. 
		int recuperarPosicion(int indice);  			//Algoritmo. 
		
		string imprimirLista(); 
}; 


Lista::Lista() {
	
}

void Lista::iniciar() {			//hay que cononcer M.
 this->longitud = length;  
 this->lista = (int*)calloc(longitud, sizeof(int)); 
 this->numero_elementos = 0; 	
}


void Lista::destruir() {
	this->numero_elementos = 0; 
}

void Lista::vaciar() {
	this->numero_elementos = 0; 
}

bool Lista::vacia() {
	return (this->numero_elementos == 0); 
}


int Lista::primera() {
 return 0; 	
}

void Lista::agregarAlFinal(int valor) {
	this->lista[numero_elementos] = valor; 
	++this->numero_elementos; 
}


void Lista::modificarPosicion(int indice, int valor) {
	int position = traducir(indice);
	modificar(position, valor);  
}


int Lista::recuperarPosicion(int indice) {
	int position = traducir(indice);
	int value = 0; 
	if (position != -1) {
		value = recuperar(position); 
	}
	else {
		// la posición es invalida. 
	} 
	return value; 
}

int Lista::traducir(int posicion) {
	return posicion-1; 	
} 

int Lista::recuperar(int posicion) {					//requiere que la posicion exista. 		
	return this->lista[posicion]; 	
} 


void Lista::modificar(int posicion, int valor) {		//requiere que la posicion exista. 	
	this->lista[posicion] = valor; 
}


int Lista::siguiente(int posicion) {	
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


void Lista::borrar(int posicion) {
 if (posicion < this->numero_elementos) {
	 
	for (int position = posicion+1; position < this->numero_elementos; ++position) {
		this->lista[position-1] = this->lista[position]; 
	}
	--this->numero_elementos;  	 
 }	
}

int Lista::NumElem() {
	return this->numero_elementos; 
}


void Lista::borrarPosicion(int posicion) {
   posicion = traducir(posicion);
   borrar(posicion);  
}

