#include "lista_pos_LSE.h"


Lista_Pos::Lista_Pos() : numero_elementos(0), primera_posicion(nullptr), ultima_posicion(nullptr) {	
    } 


void Lista_Pos::iniciar(){	
	numero_elementos = 0; 
	primera_posicion = nullptr; 
	ultima_posicion = nullptr; 
}


Lista_Pos::Posicion* Lista_Pos::anterior(Posicion* posicion) {
	Posicion* temporal = nullptr; 
	
	if (posicion != nullptr) {
	
		temporal = primera(); 
		while (temporal->siguiente() != posicion) {
			temporal = temporal->siguiente(); 
		}
	
	}
	
	return temporal; 	
}


Lista_Pos :: Posicion* Lista_Pos::ultima() {
	return this->ultima_posicion; 
}

bool Lista_Pos::vacia() {
	return (this->numero_elementos == 0); 
}


void Lista_Pos::vaciar() {
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

void Lista_Pos::destruir() {	
	vaciar(); 
}


Lista_Pos :: Posicion* Lista_Pos::primera() {
	return this->primera_posicion; 
}


Lista_Pos::Posicion* Lista_Pos::siguiente(Posicion* posicion) {
	return posicion->siguiente(); 
}


void Lista_Pos::modificar(Posicion* posicion, int valor) {
	posicion->modificar(valor); 
}


int Lista_Pos::recuperar(Posicion* posicion) {
	return posicion->recuperar(); 
}


void Lista_Pos::insertar(Posicion* posicion, int valor) {
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
            else {										//la Lista_Pos esta vacia. 
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


void Lista_Pos::borrar(Posicion* posicion) {
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


Lista_Pos::Posicion* Lista_Pos::traducir(int indice) {
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

int Lista_Pos::NumElem() {
	return this->numero_elementos; 
}
