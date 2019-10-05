#include <iostream>
#include <sstream>
using namespace std; 


#define length 20
#define PosNula -1

typedef int Pos; 

class Lista_Pos{
	private: 
		int* ListaPos; 
		int numero_elementos; 
		int longitud; 	
		
	public: 
		Lista_Pos(); 
		void iniciar(); 								//O.B
		void destruir(); 								//0.B
		bool vacia(); 									//O.B
		void vaciar(); 									//O.B
		int primera(); 									//O.B
		int NumElem(); 									//0.B
		int ultima(); 									//0.B
		int recuperar(int posicion); 					//O.B
		void modificar(int posicion, int valor); 		//O.B
		int siguiente(int posicion); 					//O.B
		void insertar(int posicion, int valor); 		//O.B	
		void agregarAlFinal(int valor); 				//O.B
		void borrar(int posicion); 						//O.B
		int anterior(int posicion); 					//O.B
		int traducir(int posicion); 					//Algoritmo.		//traduce el indice del usuario al indice de la Lista_Pos. osea de 1 a 0 o de 2 a 1. 							
		string imprimirLista(); 
}; 


Lista_Pos::Lista_Pos() {
	
}

void Lista_Pos::iniciar() {			//hay que cononcer M.
 this->longitud = length;  
 this->ListaPos = (int*)calloc(longitud, sizeof(int)); 
 this->numero_elementos = 0; 	
}


void Lista_Pos::destruir() {
	this->numero_elementos = 0; 
}

void Lista_Pos::vaciar() {
	this->numero_elementos = 0; 
}

bool Lista_Pos::vacia() {
	return (this->numero_elementos == 0); 
}


int Lista_Pos::primera() {
 return 0; 	
}


int Lista_Pos::ultima() {
	return this->numero_elementos-1; 
}

void Lista_Pos::agregarAlFinal(int valor) {
	this->ListaPos[numero_elementos] = valor; 
	++this->numero_elementos; 
}



int Lista_Pos::traducir(int posicion) {
	return posicion-1; 	
} 

int Lista_Pos::recuperar(int posicion) {					//requiere que la posicion exista. 		
	return this->ListaPos[posicion]; 	
} 


void Lista_Pos::modificar(int posicion, int valor) {		//requiere que la posicion exista. 	
	this->ListaPos[posicion] = valor; 
}


int Lista_Pos::siguiente(int posicion) {	
	 if (posicion < this->numero_elementos) {			//si es una posicion valida. 
		return posicion+1; 
	 }
	 else {
		 return -1; 									//si retorna -1. esa posicion no es valida, no tiene siguiente. 
	 }	
}

int Lista_Pos::anterior(int posicion) {
	if (posicion < this->numero_elementos && posicion-1 >= 0) {
		return posicion-1; 
	}
	else {
		return -1; 
	}
}


void Lista_Pos::insertar(int posicion, int valor) {  
	if (this->numero_elementos < this->longitud) {		//si no esta lleno el array
			
		if (posicion <= numero_elementos && posicion < this->longitud && posicion >= 0) {	//y es una posicion valida. 
		 if (posicion < numero_elementos) {
			for (int position = numero_elementos-1; position != posicion-1; --position) {		//realizo un corrimiento para insertar. 
				this->ListaPos[position+1] = this->ListaPos[position]; 		
			}
			this->ListaPos[posicion] = valor; 		 
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



string Lista_Pos::imprimirLista() {
stringstream ss; 
for (int iteration = 0; iteration < this->numero_elementos; ++iteration) {
 ss << this->ListaPos[iteration] << " "; 	
}
ss << "\n"; 	
	
return ss.str(); 	
}


void Lista_Pos::borrar(int posicion) {
 if (posicion < this->numero_elementos) {
	 
	for (int position = posicion+1; position < this->numero_elementos; ++position) {
		this->ListaPos[position-1] = this->ListaPos[position]; 
	}
	--this->numero_elementos;  	 
 }	
}

int Lista_Pos::NumElem() {
	return this->numero_elementos; 
}


