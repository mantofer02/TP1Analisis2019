#include <iostream>
#include <sstream>
using namespace std; 


typedef Posicion* Pos; 


class Posicion {
	
private: 	
Posicion* sucesor; 
Posicion* antecesor; 
int valor; 

public: 
Posicion() : sucesor(nullptr), antecesor(nullptr) {}
Posicion(int valor) : valor(valor), sucesor(nullptr), antecesor(nullptr) {}
Posicion(Posicion* anterior, int valor) : antecesor(anterior), valor(valor), sucesor(nullptr) {} 
Posicion(Posicion* anterior, Posicion*siguiente, int valor) : antecesor(anterior), sucesor(siguiente), valor(valor) {}	
int recuperar() {return this->valor;}
void modificar(int valor) {this->valor = valor; }
Posicion* siguiente() {return this->sucesor; }
Posicion* anterior()  {return this->antecesor;}
void establecerSiguiente(Posicion* siguiente) {this->sucesor = siguiente; }
void establecerAnterior(Posicion* anterior) {this->antecesor = anterior; } 	
};


class Lista {
	
private: 	
int numero_elementos; 
Posicion* primera_posicion; 
Posicion* ultima_posicion; 


public: 
Lista();
void iniciar(); 										//O.B
void destruir(); 										//O.B
void vaciar();											//O.B 
bool vacia(); 											//O.B
void insertar(Posicion* posicion, int valor); 			//O.B
void agregarAlFinal(int valor); 						//O.B
void borrar(Posicion * posicion); 						//0.B
Posicion* primera(); 									//O.B
Posicion* ultima();		 								//0.B
int NumElem(); 											//O.B
Posicion* siguiente(Posicion* posicion);				//O.B 
Posicion* anterior(Posicion* posicion); 				//O.B
void modificar(Posicion* posicion, int valor); 			//O.B
int recuperar(Posicion* posicion);						//O.B 
Posicion* traducir(int indice);							//Algoritmo
void agregarPosicion(int indice, int valor); 			//Algoritmo. //convierte el indice que manda el usuario final a una posicion, para despues insertar
void borrarPosicion(int indice); 						//Algoritmo. //parecido a AgregarPosicion e insertar. 
void modificarPosicion(int indice, int valor);			//Algoritmo. 
int recuperarPosicion(int indice, int valor);			//Algoritmo.  
string imprimirLista(); 								//Algoritmo. para probar la lista. 
string imprimirListaRevez();  							//Algoritmo.
};


Lista::Lista() : numero_elementos(0), primera_posicion(nullptr), ultima_posicion(nullptr) {	
} 

void Lista::iniciar(){	
	numero_elementos = 0; 
	primera_posicion = nullptr; 
	ultima_posicion = nullptr; 
}

void Lista::destruir() {	
	vaciar(); 
}

bool Lista::vacia() {
	return (this->numero_elementos == 0); 
}

void Lista::vaciar() {
	Posicion* current_position = primera(); 
	Posicion* temp; 
	while (current_position != nullptr) {
		temp = current_position; 
		current_position = current_position->siguiente(); 
		delete temp; 
	}
	this->primera_posicion = nullptr; 
	this->ultima_posicion = nullptr; 
	this->numero_elementos = 0; 

}

int Lista::NumElem() {
	return this->numero_elementos; 
}

Posicion* Lista::traducir(int indice) {
	Posicion* temp = nullptr; 
	
	if (indice >= 1) {
		temp = primera();  
		int current_index = 2; 
		while (current_index <= indice && temp != nullptr) {
			temp = temp->siguiente(); 
			++current_index; 
		}			
	}
	
	return temp; 
}

Posicion* Lista::primera() {
	return this->primera_posicion; 
}

Posicion* Lista::siguiente(Posicion* posicion) {
	return posicion->siguiente(); 
} 

Posicion* Lista::anterior(Posicion* posicion) {
	return posicion->anterior(); 
}


void Lista::modificar(Posicion* posicion, int valor) {
	posicion->modificar(valor); 
}

int Lista::recuperar(Posicion* posicion) {
	return posicion->recuperar(); 
} 

Posicion* Lista::ultima() {
	return this->ultima_posicion; 
}



void Lista::modificarPosicion(int indice, int valor) {
	Posicion* posicion = traducir(indice); 
	if (posicion != nullptr) {
		posicion->modificar(valor); 
	}
	else {
		//la posición que se quiere modificar no existe. 
	}	
}
	

int Lista::recuperarPosicion(int indice, int valor) {
	Posicion* posicion = traducir(indice);	
	int value = 0; 
	if (posicion != nullptr) {
		value = posicion->recuperar(); 
	}
	else {
		//la posición de la que se quiere recuperar no existe. 
	} 
	
return value; 
}		


void Lista::agregarPosicion(int indice, int valor) {
	Posicion* temporal = traducir(indice); 
	insertar(temporal, valor); 
}



void Lista::insertar(Posicion* posicion, int valor) {
	
	if (posicion != nullptr) {
		
		if (posicion != primera()) {
			
			 if (posicion->siguiente() != nullptr) {

			  Posicion* nueva_posicion = new Posicion(posicion, posicion->siguiente(), posicion->recuperar()); 
			  Posicion* temp = posicion->siguiente(); 
			  temp->establecerAnterior(nueva_posicion); 
			  posicion->modificar(valor);
			  posicion->establecerSiguiente(nueva_posicion);
			  ++this->numero_elementos; 
			 
			  }
			 else {
			  Posicion* nueva_posicion = new Posicion(posicion, posicion->recuperar()); 
			  posicion->establecerSiguiente(nueva_posicion); 
			  posicion->modificar(valor); 
			  this->ultima_posicion = nueva_posicion; 
			  ++this->numero_elementos; 
			 }
		 			
		}
		else {
			if (primera() != nullptr) {				//si ya existe algo. 
			 		 
				Posicion* nueva_posicion = new Posicion(nullptr, primera(), valor);
				primera()->establecerAnterior(nueva_posicion); 	
				this->primera_posicion = nueva_posicion;
				++this->numero_elementos; 		   
			}
			else {
				 cout << "probando uno dos tres probando " << endl; 										//la lista esta vacia. 		 
				 Posicion* nueva_posicion = new Posicion(valor);
				 this->primera_posicion = nueva_posicion; 
				 ++this->numero_elementos;  
			}				
		}		
			
	}
	
	else {
		//la posicion ingresada no es valida. 	
	}
		
}


void Lista::agregarAlFinal(int valor) {	
	if (this->numero_elementos != 0) {
		Posicion* nueva_posicion = new Posicion(ultima(), valor); 
		this->ultima_posicion->establecerSiguiente(nueva_posicion); 
		this->ultima_posicion = nueva_posicion; 
		++this->numero_elementos; 
	}
	else {		
		Posicion* nueva_posicion = new Posicion(valor); 
		this->primera_posicion = nueva_posicion; 
		this->ultima_posicion = nueva_posicion; 
		++this->numero_elementos; 
	}
}


void Lista::borrar(Posicion* posicion) {
	
	if (this->numero_elementos != 0 && posicion != nullptr) {
		if (posicion != primera()) {
			if (posicion->siguiente() != nullptr) {
				Posicion* temp = posicion->anterior(); 
				temp->establecerSiguiente(posicion->siguiente()); 
				posicion->siguiente()->establecerAnterior(temp);
				temp = posicion; 
				delete temp;  
				--this->numero_elementos; 		
			}
			else {
				Posicion* temp = ultima(); 
				Posicion* before_temp = ultima()->anterior(); 
				before_temp->establecerSiguiente(nullptr);
				this->ultima_posicion = before_temp; 
				--this->numero_elementos; 
				delete temp;  																	// se quiere eliminar el ultimo elemento.
			}			
		}
		else {
			if (primera()->siguiente() != nullptr) {			//no hay solo un element. 
				
				Posicion* temp = primera(); 	
				this->primera_posicion = temp->siguiente(); 
				primera()->establecerAnterior(nullptr); 
				delete temp; 
				--this->numero_elementos; 
				
			}
			else {											//solo hay un elemento. 
				Posicion* temp = primera(); 
				delete temp; 	
				this->ultima_posicion = nullptr; 
				this->primera_posicion = nullptr;
				this->numero_elementos = 0;  	
			}
			
			
		}
			
	}
		
}

void Lista::borrarPosicion(int indice) {
	Posicion* temporal = traducir(indice);
	borrar(temporal);  	
}


string Lista::imprimirLista() {
stringstream ss; 

Posicion* temporal = primera(); 

for (int iteration = 0; iteration < this->numero_elementos; ++iteration) {
	ss << temporal->recuperar() << " "; 
	temporal = temporal->siguiente(); 
} 
ss << "\n"; 

return ss.str(); 	
}


string Lista::imprimirListaRevez() {
stringstream ss; 
Posicion* temp = ultima();

for (int iteration = this->numero_elementos; iteration != 0; --iteration) {
 ss << temp->recuperar() << " "; 
 temp = temp->anterior(); 	
}

ss << "\n"; 

return ss.str(); 		
}

