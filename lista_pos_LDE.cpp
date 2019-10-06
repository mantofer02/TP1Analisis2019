#include "lista_pos_LDE.h"

Lista_Pos::Lista_Pos() : numero_elementos(0), primera_posicion(nullptr), ultima_posicion(nullptr) {	
} 

void Lista_Pos::iniciar(){	
	numero_elementos = 0; 
	primera_posicion = nullptr; 
	ultima_posicion = nullptr; 
}

void Lista_Pos::destruir() {	
	vaciar(); 
}

bool Lista_Pos::vacia() {
	return (this->numero_elementos == 0); 
}

void Lista_Pos::vaciar() {
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

int Lista_Pos::NumElem() {
	return this->numero_elementos; 
}

Posicion* Lista_Pos::traducir(int indice) {
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

Posicion* Lista_Pos::primera() {
	return this->primera_posicion; 
}

Posicion* Lista_Pos::siguiente(Posicion* posicion) {
	return posicion->siguiente(); 
} 

Posicion* Lista_Pos::anterior(Posicion* posicion) {
	return posicion->anterior(); 
}


void Lista_Pos::modificar(Posicion* posicion, int valor) {
	posicion->modificar(valor); 
}

int Lista_Pos::recuperar(Posicion* posicion) {
	return posicion->recuperar(); 
} 

Posicion* Lista_Pos::ultima() {
	return this->ultima_posicion; 
}


void Lista_Pos::insertar(Posicion* posicion, int valor) {
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
				 cout << "probando uno dos tres probando " << endl; 										//la Lista_Pos esta vacia. 		 
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


void Lista_Pos::agregarAlFinal(int valor) {	
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


void Lista_Pos::borrar(Posicion* posicion) {
	
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
string Lista_Pos::imprimirLista() {
    stringstream ss; 
    Posicion* temporal = primera(); 

    for (int iteration = 0; iteration < this->numero_elementos; ++iteration) {
        ss << temporal->recuperar() << " "; 
        temporal = temporal->siguiente(); 
    } 
    ss << "\n"; 
    return ss.str(); 	
}
string Lista_Pos::imprimirListaRevez() {
    stringstream ss; 
    Posicion* temp = ultima();
    for (int iteration = this->numero_elementos; iteration != 0; --iteration) {
        ss << temp->recuperar() << " "; 
        temp = temp->anterior(); 	
    }
    ss << "\n"; 
    return ss.str(); 		
}