#include <iostream>
#include <sstream>
using namespace std; 


#define PosNula nullptr

class Posicion {		
	private: 	
		Posicion* sucesor; 
		int valor; 

	public: 
		Posicion() : sucesor(nullptr) {}
		Posicion(int valor) : valor(valor), sucesor(nullptr) {}
		Posicion(Posicion*siguiente, int valor) : sucesor(siguiente), valor(valor) {}	
		int recuperar() {return this->valor;}
		void modificar(int valor) {this->valor = valor; }
		Posicion* siguiente() {return this->sucesor; }
		void establecerSiguiente(Posicion* siguiente) {this->sucesor = siguiente; }
};

typedef Posicion* Pos; 

class Lista {	
	private: 	
		int numero_elementos; 
		Posicion* primera_posicion; 
		Posicion* ultima_posicion; 
	public: 
		Lista();
		void iniciar(); 										//O.B
		Posicion* siguiente(Posicion* posicion); 				//O.B
		Posicion* anterior(Posicion* posicion);					//0.B 
		void modificar(Posicion* posicion, int valor); 			//O.B
		int recuperar(Posicion* posicion);						//O.B 										
		void insertar(Posicion* posicion, int valor); 			//O.B
		void agregarAlFinal(int valor); 						//O.B
		void borrar(Posicion * posicion); 						//0.B
		Posicion* primera(); 									//0.B
		Posicion* ultima(); 									//O.B
		bool vacia(); 											//0.B
		void vaciar(); 											//O.B
		void destruir(); 										//O.B
		int NumElem(); 											//O.B
		string imprimirLista(); 								//Algoritmo. 
		Posicion* traducir(int indice); 						//Algoritmo. 
};


Lista::Lista() : numero_elementos(0), primera_posicion(nullptr), ultima_posicion(nullptr) {	
} 


void Lista::iniciar(){	
	numero_elementos = 0; 
	primera_posicion = nullptr; 
	ultima_posicion = nullptr; 
}


Posicion* Lista::anterior(Posicion* posicion) {
	Posicion* temporal = nullptr; 
	
	if (posicion != nullptr) {
	
		temporal = primera(); 
		while (temporal->siguiente() != posicion) {
			temporal = temporal->siguiente(); 
		}
	
	}
	
	return temporal; 	
}


Posicion* Lista::ultima() {
	return this->ultima_posicion; 
}

bool Lista::vacia() {
	return (this->numero_elementos == 0); 
}


void Lista::vaciar() {
	Posicion* current_position = primera(); 
	Posicion*temp; 
	for (int index_lista = 0; index_lista < this->numero_elementos; ++index_lista) {
		temp = current_position; 
		current_position = current_position->siguiente(); 
		delete temp; 	
	}
	//current_position tiene que quedar en nullptr
	
	this->primera_posicion = nullptr; 
	this->ultima_posicion = nullptr; 
	this->numero_elementos = 0; 
	
}

void Lista::destruir() {	
	vaciar(); 
}


Posicion* Lista::primera() {
	return this->primera_posicion; 
}


Posicion* Lista::siguiente(Posicion* posicion) {
	return posicion->siguiente(); 
}


void Lista::modificar(Posicion* posicion, int valor) {
	posicion->modificar(valor); 
}


int Lista::recuperar(Posicion* posicion) {
	return posicion->recuperar(); 
}


<<<<<<< HEAD
void Lista::modificarPosicion(int indice, int valor) {
	Posicion* temp = traducir(indice); 
	if (temp != nullptr) {
		temp->modificar(valor); 
	}
	else {
			//la posición ingresada no fue valida. 
	}
	
} 



int Lista::recuperarPosicion(int indice) {
	Posicion* temp = traducir(indice);
	int value = 0; 
	if (temp != nullptr) {
		value = temp->recuperar(); 
	}
	else {
		//la posición ingresada es invalida. 
	} 
	
return value; 
} 

void Lista::agregarPosicion(int indice, int valor) {				
	Posicion *temporal;
	if (indice >= 1) {
		if (indice <= NumElem()) {						//si se puede agregar a ese indice. 
			
			if (indice != 1) {						
				temporal = traducir(indice); 
				(temporal, valor); 				//quiero insertar despues de la posicion temporal. 
			}
			else {										//quiero agregar al inicio de la lista.
				 if (primera() != nullptr) {				//si ya existe algo. 
					Posicion* nueva_posicion = new Posicion(primera(), valor);
					this->primera_posicion = nueva_posicion;
					++this->numero_elementos;    
				 }
				 else {										//la lista esta vacia. 
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
	else {
			//la posición ingresada no es valida. 
	}
}


=======
>>>>>>> b2e8069a9cea519cac82ea023379fed625c28b59
void Lista::insertar(Posicion* posicion, int valor) {
 if (posicion != nullptr) {
	if (posicion != primera()) {
		
	 if (posicion->siguiente() != nullptr) {

	  Posicion* nueva_posicion = new Posicion(posicion->siguiente(), posicion->recuperar()); 
	  posicion->modificar(valor);
	  posicion->establecerSiguiente(nueva_posicion);
	  ++this->numero_elementos; 
   	 
	}
	else {
	  Posicion* nueva_posicion = new Posicion(posicion->recuperar()); 
	  posicion->establecerSiguiente(nueva_posicion); 
	  posicion->modificar(valor); 
	  this->ultima_posicion = nueva_posicion; 
	  ++this->numero_elementos; 
	}
		
		
		
	} 
	else {
		
		if (primera() != nullptr) {				//si ya existe algo. 
			Posicion* nueva_posicion = new Posicion(primera(), valor);
			this->primera_posicion = nueva_posicion;
			++this->numero_elementos;    
		}
		else {										//la lista esta vacia. 
			Posicion* nueva_posicion = new Posicion(valor);
			this->primera_posicion = nueva_posicion; 
			++this->numero_elementos;  
		}	
				
	}
	 	 
 }
 else {
	 
	agregarAlFinal(valor); 
	 
 }
	
	
}


void Lista::agregarAlFinal(int valor) {
	if (this->numero_elementos != 0) {
		Posicion* nueva_posicion = new Posicion(valor); 
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
			
			Posicion* position = primera(); 
			while (position->siguiente() != posicion) {
				position = position->siguiente(); 
			}
			
			if (position->siguiente()->siguiente() != nullptr) {		//si no quiero eliminar al ultimo. 
				Posicion * temporal = position->siguiente(); 
				position->establecerSiguiente(temporal->siguiente()); 
				delete temporal; 	
				--this->numero_elementos; 				
			}
			else {														//quiero eliminar al ultimo. 
				Posicion* temporal = posicion->siguiente(); 
				posicion->establecerSiguiente(nullptr);
				--this->numero_elementos; 
				delete temporal;  
				this->ultima_posicion = posicion; 		
			}
					
		}
		else {		
			Posicion* temp = primera(); 
			
			if (temp->siguiente() != nullptr) {
				this->primera_posicion = temp->siguiente(); 
				delete temp; 
				--this->numero_elementos; 
			}
			else {			
				this->primera_posicion = nullptr; 
				this->ultima_posicion = nullptr; 
				this->numero_elementos = 0; 
				delete temp;
				
			}					
		}				
	}
	else {
		//no hay nada que borrar. 
	}	
}


Posicion* Lista::traducir(int indice) {
	
	Posicion* temp = nullptr; 
	
	if (indice >= 1) {

		temp = primera(); 
		int indice_actual = 2; 

		while (indice_actual <= indice) {
			temp = temp->siguiente(); 
			++indice_actual; 
		}
	
	}
return temp; 
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


int Lista::NumElem() {
	return this->numero_elementos; 
}


