#include "lista_pos_LSE.h"


Lista_Pos::Lista_Pos() : numero_elementos(0), primera_posicion(nullptr), ultima_posicion(nullptr) {	
    } 


//Iniciar()
//Efecto: Este operador básico inicializa la Lista Posicionada, para poder empezar su uso, asignándole memoria. 
//Requiere:Este operador básico requiere de espacio disponible para inicializar la lista. 
//Modifica:Este operador básico modifica la memoria, en la cual almacena la lista y los elementos almacenados en las posiciones respectivas. 

void Lista_Pos::iniciar(){	
	numero_elementos = 0; 
	primera_posicion = nullptr; 
	ultima_posicion = nullptr; 
}


//Anterior(posición)
//Efecto: Este operador básico retorna la posición anterior a una posición determinada.
//Requiere:Este operador básico requiere una Lista Posicionada previamente inicializada y la posición debe pertenecer a la Lista Posicionada. 
//Modifica: Este operador básico no modifica nada.


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



//Última()
//Efecto: Este operador básico retorna la última posición almacenada en la lista.
//Requiere:Este operador básico requiere una Lista Posicionada previamente inicializada y una Lista Posicionada no vacía.
//Modifica: Este operador básico no modifica nada.


Lista_Pos :: Posicion* Lista_Pos::ultima() {
	return this->ultima_posicion; 
}


//Vacía() 
//Efecto: Este operador básico retorna un booleano para determinar si la ListaPosicionada no contiene elementos almacenados en ella. 
//Requiere: Este operador básico requiere una Lista Posicionada previamente inicializada. 
//Modifica: Este operador básico no modifica nada. 



bool Lista_Pos::vacia() {
	return (this->numero_elementos == 0); 
}


//Vaciar() 
//Efecto: Este operador básico se encarga de eliminar todos los elementos en todas las posiciones de la Lista Posicionada, sin necesariamente destruir la Lista Posicionada. 
//Requiere:Este operador básico requiere una Lista Posicionada previamente inicializada. 
//Modifica:Este operador básico modifica las posiciones de la lista, las cuales van a ser liberadas y borradas de la memoria asignada a la Lista Posicionada. 


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

//Destruir() 
//Efecto: Este operador básico libera toda la memoria asignada a la lista, tanto los elementos como la lista en sí. 
//Requiere: Este operador básico requiere una Lista Posicionada previamente inicializada. 
//Modifica: Este operador básico modifica la memoria, en la cual liberaría toda la información referente a la lista. 

void Lista_Pos::destruir() {	
	vaciar(); 
}


//Primera()
//Efecto: Este operador básico retorna la primera posición almacenada en la lista.
//Requiere:Este operador básico requiere de una Lista Posicionada previamente inicializada y una Lista Posicionada no vacía.
//Modifica: Este operador básico no modifica nada.


Lista_Pos :: Posicion* Lista_Pos::primera() {
	return this->primera_posicion; 
}


//Siguiente(posición)
//Efecto: Este operador básico retorna la posición siguiente a una posición determinada.
//Requiere:Este operador básico requiere una Lista Posicionada previamente inicializada y la posición debe pertenecer a la Lista Posicionada. 
//Modifica: Este operador básico no modifica nada.

Lista_Pos::Posicion* Lista_Pos::siguiente(Posicion* posicion) {
	return posicion->siguiente(); 
}


//ModificarElemento(elemento, posición) 
//Efecto: Este operador básico modifica el elemento en una posición determinada, intercambiandolo por un nuevo valor de elemento.
//Requiere: Este operador básico requiere una Lista Posicionada previamente inicializada y la posición debe pertenecer a la Lista Posicionada. 
//Modifica: Este operador básico modifica una posición determinada, alterando el valor del elemento en esa posición.


void Lista_Pos::modificar(Posicion* posicion, int valor) {
	posicion->modificar(valor); 
}


//Recupera(posición)
//Efecto: Este operador básico retorna el valor de un tipo de elemento en una posición determinada.
//Requiere:Este operador básico requiere una Lista Posicionada previamente inicializada y la posición debe pertenecer a la Lista Posicionada. 
//Modifica: Este operador básico no modifica nada.


int Lista_Pos::recuperar(Posicion* posicion) {
	return posicion->recuperar(); 
}



//Insertar(elemento, posición) 
//Efecto: Este operador básico inserta a la Lista Posicionada un determinado elemento enviado por los parámetros a una posición determinada. 
//Requiere:Este operador básico requiere una Lista Posicionada previamente inicializada y la posición debe ser válida en la Lista Posicionada. 
//Modifica:Este operador básico modifica las posiciones de la Lista Posicionada insertando un nuevo elemento y posición a la lista. 



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


//AgregarAlFinal(elemento) 
//Efecto: Este operador básico agrega un elemento al final de la Lista Posicionada. 
//Requiere: Este operador básico requiere una Lista Posicionada previamente inicializada. 
//Modifica:Este operador básico modifica la Lista, ya que agrega un nuevo último elemento. 


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


//Borrar(posición)
//Efecto: Este operador básico se encarga de borrar un elemento de la Lista Posicionada ubicado en una posición específica.
//Requiere: Este operador básico requiere una Lista Posicionada previamente inicializada y la posición debe pertenecer a la Lista Posicionada. 
//Modifica: Este operador básico modifica la lista, ya que borra una posición de la misma, donde al elemento posterior a la posición eliminada, se le asignará una nueva posición.


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
