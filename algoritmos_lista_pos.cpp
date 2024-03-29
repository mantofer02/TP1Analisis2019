#include "algoritmos_lista_pos.h"
/*
Algoritmos_Pos :: Algoritmos_Pos(Lista_Pos &lista){
    this->lista = lista;
}
*/

Algoritmos_Pos::Algoritmos_Pos() {
	
}



//Efecto: Ordena los elementos de la lista de forma ascendente. 
//Requiere: que la lista se encuentre inicializada. 
//Modifica: las etiquetas correspondientes a las posiciones de la lista. 


void Algoritmos_Pos::burbujaBidireccional(Lista_Pos&lista) {
	  Pos flag_1 = lista.primera(); 
	  Pos flag_2 = lista.ultima(); 
	  
	  while (lista.siguiente(flag_2) != flag_1 && flag_2 != flag_1) {		  
	   Pos p_1 = flag_1;
	   while (p_1 != flag_2) {
			if (lista.recuperar(p_1) > lista.recuperar(lista.siguiente(p_1))) {
			 lista.intercambiar(p_1, lista.siguiente(p_1)); 
			}
			p_1 = lista.siguiente(p_1); 
		}
		
		  
		while (p_1 != flag_1) {
			 if (lista.recuperar(p_1) < lista.recuperar(lista.anterior(p_1))) {
				lista.intercambiar(p_1, lista.anterior(p_1)); 
			 }
			 p_1 = lista.anterior(p_1); 
		}

		flag_1 = lista.siguiente(flag_1); 
		flag_2 = lista.anterior(flag_2); 
	   
	  }
	  

 }


//Efecto: retorna un booleano si la listaA se encuentra contenida en cualquier parte de  la listaB
//Requiere: que ambas listas se encuentren inicializadas. 
//Modifica: no modifica nada, solo retorna información correspondiente a las listas. 



bool Algoritmos_Pos::subLista(Lista_Pos &listaA, Lista_Pos &listaB){
	bool estaContenida = true; 
	int match_counter = 0; 
	Pos posListaA = listaA.primera(); 
	Pos posListaB = listaB.primera(); 
	
	while (posListaB != PosNula && posListaA != PosNula) {	
		
		if(listaA.recuperar(posListaA) == listaB.recuperar(posListaB)) {
			posListaA = listaA.siguiente(posListaA); 
			estaContenida = true; 
			++match_counter; 
		}
		else {
			estaContenida = false; 
			posListaA = listaA.primera(); 
		}
		
			if (estaContenida || match_counter == 0) {
				posListaB = listaB.siguiente(posListaB);
			}
			else {
				match_counter = 0; 	
			}
				
	}
	
	if (match_counter != listaA.NumElem()) {
		estaContenida = false; 
	}

	return estaContenida;

}


//Efecto: Retorna un valor de 0 o 1 correspondiente a si la lista ingresada como parametro es simetrica o no. 
//Requiere: Que la lista se encuentre inicializada. 
//Modifica: no modifica nada, solo retorna información de la lista. 

int Algoritmos_Pos::simetrica(Lista_Pos &lista){
    int esSimetrica = 0;
    Pos pos1 = lista.primera();
    Pos pos2 = lista.ultima();
    while (lista.siguiente(pos2) != pos1 && pos1 != pos2 && lista.recuperar(pos1) == lista.recuperar(pos2)){
        pos1 = lista.siguiente(pos1);
        pos2 = lista.anterior(pos2);
    }
    
    if (pos1 != pos2) {
		if (lista.siguiente(pos2) == pos1) {
			esSimetrica = 1; 
		}

			
	}
	else {
			esSimetrica = 1; 
	}
    
    return esSimetrica;
}



//Efecto: Invierte los elementos correspondientes a la lista, de manera que los deja al revez. 
//Requiere: Que la lista se encuentre inicializada y que no este vacia. 
//Modifica: Las etiquetas de todas las posiciones de la lista inviertiendo los elementos. 

void Algoritmos_Pos::invertir(Lista_Pos &lista){
    Pos pos1 = lista.primera();
    Pos pos2 = lista.ultima();
    int elemento1;
    while (lista.siguiente(pos2) != pos1 && pos1 != pos2){
        elemento1 = lista.recuperar(pos1);
        lista.modificar(pos1, lista.recuperar(pos2));
        lista.modificar(pos2, elemento1);
        pos1 = lista.siguiente(pos1);
        pos2 = lista.anterior(pos2);
    }
}


//Efecto: retorna un valor de 0 o 1 avisando si el elemento ingresado como parametro se encuentra en la dicha lista. 
//Requiere: que la lista se encuentre inicializada. 
//Modifica: no modifica nada, solo retorna información de la lista. 

int Algoritmos_Pos::buscar(Lista_Pos &lista, int elemento){
    int esta = 0;
    int stop = 0;
    Pos posActual = lista.primera();
    while (posActual != PosNula && !stop){
        if (lista.recuperar(posActual) == elemento){
            esta = 1;
            stop = 1;
        }
        posActual = lista.siguiente(posActual);
    }
    return esta;
}



//Efecto: Elimina todas las posiciones de la lista que poseen etiquetas repetidas. 
//Requiere: Que la lista se encuentre incializada. 
//Modifica: Las posiciones de la lista, eliminando posiciones en caso de que sea necesario. 

void Algoritmos_Pos::eliminarRepetidos(Lista_Pos &lista){
 Pos p_1 = lista.primera(); 
 Pos aux = p_1; 
 bool esta = false; 
 Pos aux_aux = PosNula; 
 
 while (p_1 != PosNula) {
	 aux = lista.siguiente(p_1); 
	 while (aux != PosNula) {
		 if (lista.recuperar(p_1) == lista.recuperar(aux)) {
			 aux_aux = lista.siguiente(aux); 
			 lista.borrar(aux);
			 esta = true; 
		 } 
		 if (!esta) {
			 aux = lista.siguiente(aux); 
		 }
		 else {
			 aux = aux_aux;  
			 esta = false; 
		 }
	 }
	 p_1 = lista.siguiente(p_1); 
 }



}



//Efecto: Ordena los elementos de la lista de forma ascendente. 
//Requiere: Que la lista se encuentre inicializada. 
//Modifica: las etiquetas correspondientes a las posiciones de la lista. 

void Algoritmos_Pos::burbuja(Lista_Pos &lista) {	
	int amount_elements = lista.NumElem(); 
	Pos p_1 = PosNula; 
	Pos p_2 = PosNula; 
	int temp_value = 0;  
 
	if (amount_elements >= 2) {
		for (int iteration = 0; iteration < amount_elements; ++iteration) {
			p_1 = lista.primera(); 
			p_2 = lista.siguiente(p_1); 	
		
			while (lista.siguiente(p_1) != PosNula) {
				if (lista.recuperar(p_1) > lista.recuperar(p_2)) {
					temp_value = lista.recuperar(p_1);
					lista.modificar(p_1, lista.recuperar(p_2));
					lista.modificar(p_2, temp_value);   
				}
				p_1 = lista.siguiente(p_1);
				p_2 = lista.siguiente(p_2);  		
			}	
			 
		}
			
	}
	else {
	//no hay nada que ordenar. 	
	}
		
}


//Efecto: ordena la lista de forma ascendente. 
//Requiere: que la lista se encuentre inicializada. 
//Modifica: las etiquetas correspondientes a las posiciones de la lista. 

void Algoritmos_Pos::seleccion(Lista_Pos &lista) {
int amount_elements = lista.NumElem();  
Pos p_1 = lista.primera();  
Pos p_2 = lista.primera(); 
Pos lower_pos = PosNula;  
int temp_value = 0; 
    for (int iteration = 0; iteration < amount_elements; ++iteration) {
        lower_pos = p_1; 
        p_2 = lista.siguiente(p_1); 
        for (int find_lower = iteration+1; find_lower < amount_elements; ++find_lower) {
            if (lista.recuperar(p_2) < lista.recuperar(lower_pos)) {
                lower_pos = p_2; 
            }
        p_2 = lista.siguiente(p_2); 		 
        }
        if (p_1 != lower_pos) {
            temp_value = lista.recuperar(p_1);
            lista.modificar(p_1, lista.recuperar(lower_pos));
            lista.modificar(lower_pos, temp_value);   
        }
        p_1 = lista.siguiente(p_1); 
    }	
}

//Efecto: ordena los elementos de la lista de forma ascendente. 
//Requiere: que la lista se encuentre inicializada. 
//Modifica: las etiquetas correspondientes a las posiciones de la lista. 

void Algoritmos_Pos::seleccionRecursivo(Lista_Pos &lista, Pos pos) {
 
  if (lista.siguiente(pos) != PosNula) {
	  Pos p_2 = lista.siguiente(pos);
	  Pos lower_pos = pos; 
	  while (p_2 != PosNula) {
		 if (lista.recuperar(p_2) < lista.recuperar(lower_pos)) {
			 lower_pos = p_2;  
		 }
		 p_2 = lista.siguiente(p_2); 	  
	  }
	  if (pos != lower_pos) {
		  int temp_value = lista.recuperar(pos);
		  lista.modificar(pos, lista.recuperar(lower_pos));
		  lista.modificar(lower_pos, temp_value);   
	  } 
	  seleccionRecursivo(lista, lista.siguiente(pos));  
  }
  else {
	//condicion de parada.  
  }
		
}


//Efecto: ordena los elementos de la lista de forma ascendente. 
//Requiere: que la lista se encuentre inicializada. 
//Modifica: las etiquetas correspondientes a las posiciones de la lista. 

void Algoritmos_Pos::quickSort(Lista_Pos &lista) {
	if (lista.NumElem() >= 2) {
		quickSortRecursivo(lista, lista.primera(), lista.ultima());  
	}
	else { 
		//no hay nada que modificar. 
	}		
}

//FORMA PARTE DE QUICKSORT
void Algoritmos_Pos::quickSortRecursivo(Lista_Pos &lista, Pos low, Pos high) {

	//cout << "low : " << lista.recuperar(low) << " high : " << lista.recuperar(high) << endl; 

	if (low != high) {	
		
		Pos pivote_position = buscarPivote(lista, low, high); 

		if (pivote_position != PosNula) {

		Pos p_1 = low; 
		Pos p_2 = high; 
			
			while (/*lista.siguiente(p_2) != p_1*/ p_2 != lista.anterior(p_1)) {	
				if(p_1 != pivote_position && p_2 != pivote_position) { //FALTABA ESTO
					lista.intercambiar(p_2, p_1);	 
				}														//FALTABA ESTO
				
				while (lista.recuperar(p_1) < lista.recuperar(pivote_position)) {		// p_1 != PosNula? 
					p_1 = lista.siguiente(p_1); 
				}


				while (lista.recuperar(p_2) >= lista.recuperar(pivote_position)) {
					p_2 = lista.anterior(p_2); 		
				}	

				
			}
			
			quickSortRecursivo(lista, low, p_2);
			quickSortRecursivo(lista, p_1, high);  	
			
		}	
			
	}
}


//FORMA PARTE DE QUICKSORT. 
Pos Algoritmos_Pos::buscarPivote(Lista_Pos &lista, Pos low, Pos high) {
	cout << lista.imprimirLista(); 	
	Pos pivote_position = PosNula; 
	Pos p_1 = low; 
	while (p_1 != high && lista.recuperar(p_1) == lista.recuperar(lista.siguiente(p_1))) {
		p_1 = lista.siguiente(p_1); 	
	}
	if (p_1 != high) {
		if (lista.recuperar(p_1) < lista.recuperar(lista.siguiente(p_1))) {
			//pivote_position = low; 
			pivote_position = lista.siguiente(p_1); 
		}
		else{
			pivote_position = low; 
		//pivote_position = lista.siguiente(p_1); 
		}
	}
	return pivote_position; 	
} 



//Efecto: ordena los elementos de la lista de forma ascendente. 
//Requiere: que la lista se encuentre inicializada. 
//Modifica: las etiquetas de las posiciones correspondientes a la lista. 


void Algoritmos_Pos::insercion(Lista_Pos &lista) {
 if (lista.NumElem() >= 2) {
	Pos p_1 = lista.primera();  
	Pos p_2; 
	Pos aux_p_1;  	
	while (p_1 != PosNula) {
		aux_p_1 = p_1; 
		Pos p_2 = lista.anterior(p_1); 
		while (p_2 != PosNula) {
			if (lista.recuperar(p_2) > lista.recuperar(p_1)) {
				lista.intercambiar(p_2,p_1); 	
				p_1 = p_2; 	
			}
			p_2 = lista.anterior(p_2); 
		}
		p_1 = aux_p_1; 
		p_1 = lista.siguiente(p_1); 		
	}	 
 }
 else {
		//no hay nada que ordenar. 
 }		
}



//Efecto: ordena los elementos de la lista de forma ascendente. 
//Requiere: que la lista se encuentre inicializada. 
//Modifica: las etiquetas de las posiciones correspondientes a la lista. 


void Algoritmos_Pos::quickSort_insercion(Lista_Pos &lista) {
	if (lista.NumElem() < 100) {
		
		insercion(lista); 
				
	}
	else {
		quickSort(lista); 	
	}
		
}




//Efecto: agrega a l1, los elementos de l2, que no se encuentren en dicha lista. 
//Requiere: que ambas listas se encuentren inicializadas. 
//Modifica: la lista l1, que entra como primer parametro. 

void Algoritmos_Pos::unionOrdenada(Lista_Pos &l1, Lista_Pos &l2) {

Pos p_1 = l1.primera(); 
Pos p_2 = l2.primera(); 

while (p_1 != PosNula && p_2 != PosNula) {
	if (l1.recuperar(p_1) < l2.recuperar(p_2)) {
		p_1 = l1.siguiente(p_1); 	
	}
	else {
		if (l1.recuperar(p_1) == l2.recuperar(p_2)) {
			p_1 = l1.siguiente(p_1);
			p_2 = l2.siguiente(p_2);  
		}
		else {	//tengo que agregar p_2 a l1
			l1.insertar(p_1, l2.recuperar(p_2));
			 p_1 = l1.siguiente(p_1); 
			 p_2 = l2.siguiente(p_2); 					
		}
	}
	
}


while (p_2 != PosNula) {
	l1.agregarAlFinal(l2.recuperar(p_2));
	p_2 = l2.siguiente(p_2);  	
}
	
}



//Efecto: agrega a l1, los elementos de l2, que no se encuentren en dicha lista. 
//Requiere: que ambas listas se encuentren inicializadas. 
//Modifica: la lista l1, que entra como primer parametro. 

void Algoritmos_Pos::unionNoOrdenada(Lista_Pos &l1, Lista_Pos &l2) {
	
Pos p_2 = l2.primera(); 
Pos p_1; 

bool is_it_there = false; 

while (p_2 != PosNula) {
	p_1 = l1.primera(); 
	while (p_1 != PosNula) {
		if (l2.recuperar(p_2) == l1.recuperar(p_1)) {
			is_it_there = true; 
			p_1 = PosNula; 
		}
		else {
			p_1 = l1.siguiente(p_1); 
		}	
	}
	if (!is_it_there) {
		l1.agregarAlFinal(l2.recuperar(p_2)); 
	}	

	p_2 = l2.siguiente(p_2); 	
		
}	

	
	
}



//Efecto: deja en l3 unicamente los elementos que posean en comun las listas l1 y l2. 
//Requiere: que ambas listas se encuentre inicializadas. 
//Modifica: la lista l3, de poseer elementos anteriormente se eliminaran y se procedera a agregar únicamente la intersección de las otras 2 listas. 


void Algoritmos_Pos::interseccionOrdenada_v1(Lista_Pos &l1, Lista_Pos &l2,Lista_Pos &l3) {	//no deja nada en miListaPos y borra aux_2
	l3.vaciar();
	l3.iniciar(); 
	Pos p_1 = l1.primera(); 
	Pos p_2 = l2.primera(); 


	while (p_1 != PosNula && p_2 != PosNula) {
		if (l1.recuperar(p_1) < l2.recuperar(p_2)) {
			p_1 = l1.siguiente(p_1); 
		}
		else {
		  if (l1.recuperar(p_1) > l2.recuperar(p_2)) {
			  p_2 = l2.siguiente(p_2); 
		  }
		  else { //son iguales. 
			 l3.agregarAlFinal(l1.recuperar(p_1));
			 p_1 = l1.siguiente(p_1); 
			 p_2 = l2.siguiente(p_2);  	  
		  }	
		}
	}
		 
}



//Efecto: deja en l3 unicamente los elementos que posean en comun las listas l1 y l2. 
//Requiere: que ambas listas se encuentre inicializadas. 
//Modifica: la lista l3, de poseer elementos anteriormente se eliminaran y se procedera a agregar únicamente la intersección de las otras 2 listas. 

void Algoritmos_Pos::interseccionOrdenada_v2(Lista_Pos &l1, Lista_Pos &l2, Lista_Pos &l3) {
	l3.vaciar(); 
	l3.iniciar(); 
	Pos pos1 = l1.primera(); 
	while (pos1 != PosNula) {
		if (buscar(l2, l1.recuperar(pos1))) {
		l3.agregarAlFinal(l1.recuperar(pos1)); 
	}
	pos1 = l1.siguiente(pos1); 	
	}		  
}



//Efecto: deja en l3 unicamente los elementos que posean en comun las listas l1 y l2. 
//Requiere: que ambas listas se encuentre inicializadas. 
//Modifica: la lista l3, de poseer elementos anteriormente se eliminaran y se procedera a agregar únicamente la intersección de las otras 2 listas. 



void Algoritmos_Pos::interseccion(Lista_Pos&l1, Lista_Pos&l2, Lista_Pos&l3) {
	l3.vaciar(); 
	l3.iniciar(); 
	Pos p_1 = l1.primera(); 
	Pos p_2 = PosNula; 
	
	while (p_1 != PosNula) {
		p_2 = l2.primera(); 
		while (p_2 != PosNula) {
			if (l1.recuperar(p_1) == l2.recuperar(p_2)) {
				l3.agregarAlFinal(l1.recuperar(p_1));
				p_2 = PosNula;  
			}
			else {
				p_2 = l2.siguiente(p_2);  
			}		
		}
		
		p_1 = l1.siguiente(p_1); 
	}	
}



//Efecto: ordena los elementos de la lista de forma ascendente. 
//Requiere: que la lista se encuentre inicializada. 
//Modifica: las etiquetas de las posiciones correspondientes a la lista. 


void Algoritmos_Pos::mergeSort(Lista_Pos &lista) {
	
	if (lista.NumElem() > 1) {
		int mid = lista.NumElem()/2; 
		Pos current_pos = lista.primera(); 
		
		Lista_Pos primeraMitad;
		primeraMitad.iniciar();  
		Lista_Pos segundaMitad;
		segundaMitad.iniciar();  
		
		for (int first_half = 0; first_half < mid; ++first_half) {
			primeraMitad.agregarAlFinal(lista.recuperar(current_pos)); 
			current_pos = lista.siguiente(current_pos);  
		}
		
		for (int second_half = mid; second_half < lista.NumElem(); ++second_half) {
			segundaMitad.agregarAlFinal(lista.recuperar(current_pos));
			current_pos = lista.siguiente(current_pos);  
		}
		
	 mergeSort(primeraMitad);
	 mergeSort(segundaMitad);
	 merge(primeraMitad, segundaMitad, lista);   	
		
	}
	else {
		//condicion de parada. 
	}
	
}



//FORMA PARTE DE MERGE_SORT.
void Algoritmos_Pos::merge(Lista_Pos &lista_1, Lista_Pos &lista_2, Lista_Pos &lista) {
	
	lista.vaciar(); 
	Pos current_1 = lista_1.primera(); 
	Pos current_2 = lista_2.primera(); 
	
	while (current_1 != PosNula && current_2 != PosNula) {
		if (lista_1.recuperar(current_1) < lista_2.recuperar(current_2)) {
			lista.agregarAlFinal(lista_1.recuperar(current_1)); 
			current_1 = lista_1.siguiente(current_1);  
		}
		else {
			lista.agregarAlFinal(lista_2.recuperar(current_2));
			current_2 = lista_2.siguiente(current_2);  
		}
		
	}
	
	while (current_1 != PosNula) {
		lista.agregarAlFinal(lista_1.recuperar(current_1));
		current_1 = lista_1.siguiente(current_1);  		
	}
	
	
	while (current_2 != PosNula) {
		lista.agregarAlFinal(lista_2.recuperar(current_2));
		current_2 = lista_2.siguiente(current_2);  	
	}
	lista_1.destruir(); 
	lista_2.destruir(); 
}
