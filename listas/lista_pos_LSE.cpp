#include <iostream>
#include <sstream>
using namespace std; 


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
Posicion* primera(); 									//0.B
//Posicion* siguiente(Posicion* posicion); 
int NumElem(); 											//O.B
void AgregarPosicion(int indice, int valor); 			//Algoritmo. //convierte el indice que manda el usuario final a una posicion, para despues insertar
void borrarPosicion(int indice); 						//Algoritmo. //parecido a AgregarPosicion e insertar. 
string imprimirLista(); 								//Algoritmo. para probar la lista. 
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


Posicion* Lista::primera() {
	return this->primera_posicion; 
}


void Lista::AgregarPosicion(int indice, int valor) {				
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


void Lista::insertar(Posicion* posicion, int valor) {
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


void Lista::borrar(Posicion* posicion) {							//se entiende que no es el primero. 
	if (posicion->siguiente() != nullptr) {
		
		if (posicion->siguiente()->siguiente() != nullptr) {		//si no quiero eliminar al ultimo. 
			Posicion * temporal = posicion->siguiente(); 
			posicion->establecerSiguiente(temporal->siguiente()); 
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
																	// se quiere eliminar algo que no existe. 	
	}	
}



void Lista::borrarPosicion(int indice) {
 if (numero_elementos != 0) {	
	
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
			// la lista esta vacia. 
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


int Lista::NumElem() {
	return this->numero_elementos; 
}



int main (int argc, char* argv[]) {
		
	Lista* lista = new Lista(); 
	lista->iniciar(); 

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

		lista->AgregarPosicion(position, value); 
		cout << lista->imprimirLista() << " NumElem: " << lista->NumElem() << "\n" << endl; 	
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
