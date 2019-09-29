#include <iostream>
#include <sstream>
using namespace std; 


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
void insertar(Posicion* posicion, int valor); 			//O.B
void agregarAlFinal(int valor); 						//O.B
void borrar(Posicion * posicion); 						//0.B
Posicion* primera(); 	
Posicion* ultima();		 								//0.B
//Posicion* siguiente(Posicion* posicion); 
int NumElem(); 											//O.B
void agregarPosicion(int indice, int valor); 			//Algoritmo. //convierte el indice que manda el usuario final a una posicion, para despues insertar
void borrarPosicion(int indice); 						//Algoritmo. //parecido a AgregarPosicion e insertar. 
string imprimirLista(); 								//Algoritmo. para probar la lista. 
string imprimirListaRevez(); 
};


Lista::Lista() : numero_elementos(0), primera_posicion(nullptr), ultima_posicion(nullptr) {	
} 

void Lista::iniciar(){	
	numero_elementos = 0; 
	primera_posicion = nullptr; 
	ultima_posicion = nullptr; 
}

void Lista::destruir() {	

}

int Lista::NumElem() {
	return this->numero_elementos; 
}

Posicion* Lista::primera() {
	return this->primera_posicion; 
}

Posicion* Lista::ultima() {
	return this->ultima_posicion; 
}

void Lista::agregarPosicion(int indice, int valor) {				
	Posicion *temporal = primera(); 
	if (indice <= NumElem()) {						//si se puede agregar a ese indice. 
		
			if (indice != 1) {						//si no quiero agregar al inicio de la lista
			int indice_actual = 2; 
			while (indice_actual <= indice) {
				temporal = temporal->siguiente(); 	
				++indice_actual; 
			}	
			insertar(temporal, valor); 				//quiero insertar despues de la posicion temporal. 
		}
		else {										//quiero agregar al inicio de la lista.
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
	else {		 									 //de lo contrario agrega al final. 
		agregarAlFinal(valor); 
	}
}


void Lista::insertar(Posicion* posicion, int valor) {
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


void Lista::borrar(Posicion* posicion) {							//se entiende que no es el primero. 
	if (posicion->siguiente() != nullptr) {
		Posicion * temporal = posicion->siguiente(); 
		posicion->establecerSiguiente(temporal->siguiente()); 
		delete temporal; 	
		++this->numero_elementos; 			
	}
	else {
																	// se quiere eliminar algo que no existe. 	
	}	
}



void Lista::borrarPosicion(int indice) {
if (indice != 1) {
	Posicion *current_position = primera(); 
	int indice_actual = 2; 
	while (indice_actual < indice) {
		++indice_actual; 
		current_position = current_position->siguiente(); 
	}
	borrar(current_position); 	
}
else {
	Posicion* temp = primera(); 
	this->primera_posicion = temp->siguiente(); 
	delete temp; 	
}	
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

