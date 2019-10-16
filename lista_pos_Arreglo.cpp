#include "lista_pos_Arreglo.h"

Lista_Pos::Lista_Pos(){
	
}


//Iniciar()
//Efecto: Este operador básico inicializa la Lista Posicionada, para poder empezar su uso, asignándole memoria. 
//Requiere:Este operador básico requiere de espacio disponible para inicializar la lista. 
//Modifica:Este operador básico modifica la memoria, en la cual almacena la lista y los elementos almacenados en las posiciones respectivas. 


void Lista_Pos::iniciar() {			//hay que cononcer M.
    this->longitud = length;  
    this->ListaPos = (int*)calloc(longitud, sizeof(int)); 
    this->numero_elementos = 0; 	
}


//Destruir() 
//Efecto: Este operador básico libera toda la memoria asignada a la lista, tanto los elementos como la lista en sí. 
//Requiere: Este operador básico requiere una Lista Posicionada previamente inicializada. 
//Modifica: Este operador básico modifica la memoria, en la cual liberaría toda la información referente a la lista. 


void Lista_Pos::destruir() {
	this->numero_elementos = 0; 
}



void intercambiar(int p_1, int p_2) {
	int temporal_value = this->listaPos[p_1]; 
	this->listaPos[p_1] = this->listaPos[p_2];
	this->listaPos[p_2] = temporal_value;  	
}


//Vaciar() 
//Efecto: Este operador básico se encarga de eliminar todos los elementos en todas las posiciones de la Lista Posicionada, sin necesariamente destruir la Lista Posicionada. 
//Requiere:Este operador básico requiere una Lista Posicionada previamente inicializada. 
//Modifica:Este operador básico modifica las posiciones de la lista, las cuales van a ser liberadas y borradas de la memoria asignada a la Lista Posicionada. 


void Lista_Pos::vaciar() {
	this->numero_elementos = 0; 
}


//Vacía() 
//Efecto: Este operador básico retorna un booleano para determinar si la ListaPosicionada no contiene elementos almacenados en ella. 
//Requiere: Este operador básico requiere una Lista Posicionada previamente inicializada. 
//Modifica: Este operador básico no modifica nada. 


bool Lista_Pos::vacia() {
	return (this->numero_elementos == 0); 
}



//Primera()
//Efecto: Este operador básico retorna la primera posición almacenada en la lista.
//Requiere:Este operador básico requiere de una Lista Posicionada previamente inicializada y una Lista Posicionada no vacía.
//Modifica: Este operador básico no modifica nada.


int Lista_Pos::primera() {
    return 0; 	
}

//Última()
//Efecto: Este operador básico retorna la última posición almacenada en la lista.
//Requiere:Este operador básico requiere una Lista Posicionada previamente inicializada y una Lista Posicionada no vacía.
//Modifica: Este operador básico no modifica nada.


int Lista_Pos::ultima() {
	return this->numero_elementos-1; 
}

//AgregarAlFinal(elemento) 
//Efecto: Este operador básico agrega un elemento al final de la Lista Posicionada. 
//Requiere: Este operador básico requiere una Lista Posicionada previamente inicializada. 
//Modifica:Este operador básico modifica la Lista, ya que agrega un nuevo último elemento. 


void Lista_Pos::agregarAlFinal(int valor) {
	this->ListaPos[numero_elementos] = valor; 
	++this->numero_elementos; 
}



int Lista_Pos::traducir(int posicion) {
	return posicion-1; 	
} 

//Recupera(posición)
//Efecto: Este operador básico retorna el valor de un tipo de elemento en una posición determinada.
//Requiere:Este operador básico requiere una Lista Posicionada previamente inicializada y la posición debe pertenecer a la Lista Posicionada. 
//Modifica: Este operador básico no modifica nada.


int Lista_Pos::recuperar(int posicion) {					//requiere que la posicion exista. 		
	return this->ListaPos[posicion]; 	
} 


//ModificarElemento(elemento, posición) 
//Efecto: Este operador básico modifica el elemento en una posición determinada, intercambiandolo por un nuevo valor de elemento.
//Requiere: Este operador básico requiere una Lista Posicionada previamente inicializada y la posición debe pertenecer a la Lista Posicionada. 
//Modifica: Este operador básico modifica una posición determinada, alterando el valor del elemento en esa posición.

void Lista_Pos::modificar(int posicion, int valor) {		//requiere que la posicion exista. 	
	this->ListaPos[posicion] = valor; 
}



//Siguiente(posición)
//Efecto: Este operador básico retorna la posición siguiente a una posición determinada.
//Requiere:Este operador básico requiere una Lista Posicionada previamente inicializada y la posición debe pertenecer a la Lista Posicionada. 
//Modifica: Este operador básico no modifica nada.


int Lista_Pos::siguiente(int posicion){	
    if (posicion < this->numero_elementos) {			//si es una posicion valida. 
		return posicion+1; 
    }
	 else {
		 return -1; 									//si retorna -1. esa posicion no es valida, no tiene siguiente. 
	 }	
}

//Anterior(posición)
//Efecto: Este operador básico retorna la posición anterior a una posición determinada.
//Requiere:Este operador básico requiere una Lista Posicionada previamente inicializada y la posición debe pertenecer a la Lista Posicionada. 
//Modifica: Este operador básico no modifica nada.


int Lista_Pos::anterior(int posicion) {
	if (posicion < this->numero_elementos && posicion-1 >= 0) {
		return posicion-1; 
	}
	else {
		return -1; 
	}
}


//Insertar(elemento, posición) 
//Efecto: Este operador básico inserta a la Lista Posicionada un determinado elemento enviado por los parámetros a una posición determinada. 
//Requiere:Este operador básico requiere una Lista Posicionada previamente inicializada y la posición debe ser válida en la Lista Posicionada. 
//Modifica:Este operador básico modifica las posiciones de la Lista Posicionada insertando un nuevo elemento y posición a la lista. 


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
            else{
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


//Borrar(posición)
//Efecto: Este operador básico se encarga de borrar un elemento de la Lista Posicionada ubicado en una posición específica.
//Requiere: Este operador básico requiere una Lista Posicionada previamente inicializada y la posición debe pertenecer a la Lista Posicionada. 
//Modifica: Este operador básico modifica la lista, ya que borra una posición de la misma, donde al elemento posterior a la posición eliminada, se le asignará una nueva posición.


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
