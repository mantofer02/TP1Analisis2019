#include "algoritmos_lista_pos.h"
/*
Algoritmos_Pos :: Algoritmos_Pos(Lista_Pos &lista){
    this->lista = lista;
}
*/

Algoritmos_Pos::Algoritmos_Pos() {
	
}

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
		 }
	 }
	 p_1 = lista.siguiente(p_1); 
 }



}




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


void Algoritmos_Pos::quickSort(Lista_Pos &lista) {
 
 if (lista.NumElem() >= 2) {
	  quickSortRecursivo(lista, lista.primera(), lista.ultima());  
 }
 else { 
		//no hay nada que modificar. 
 }		
	
}


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
	else {
		pivote_position = low; 
		//pivote_position = lista.siguiente(p_1); 
	}
}

#if 0
if (pivote_position != PosNula) {
cout << "el pivote seleccionado corresponde a : " << lista.recuperar(pivote_position) << endl; 
}
else {
		cout << "no hay pivote uyuyuyu " << endl;  
}
#endif

return pivote_position; 	
} 


void Algoritmos_Pos::insercion(Lista_Pos &lista) {
 if (lista.NumElem() >= 2) {
	Pos p_1 = lista.primera();  
	Pos p_2; 
	Pos aux_p_1;  
	
	/*
	int amount_elements = lista.NumElem(); 
	for (int current_index = 0; current_index < amount_elements; ++current_index) {
		aux_p_1 = p_1; 
		p_2 = lista.anterior(p_1); 
		for (int index = current_index; index != 0; --index) {
			if (lista.recuperar(p_2) > lista.recuperar(p_1)) {
				lista.intercambiar(p_1, p_2);
				p_1 = p_2;  
			}
			p_2 = lista.anterior(p_2); 
		}
	}
	
	*/	
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



void Algoritmos_Pos::quickSort_insercion(Lista_Pos &lista) {
	if (lista.NumElem() < 100) {
		
		insercion(lista); 
				
	}
	else {
		quickSort(lista); 	
	}
		
}



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


void Algoritmos_Pos::interseccionOrdenada_v2(Lista_Pos &l1, Lista_Pos &l2, Lista_Pos &l3) {

Pos pos1 = l1.primera(); 
while (pos1 != PosNula) {
 if (buscar(l2, l1.recuperar(pos1))) {
	 l3.agregarAlFinal(l1.recuperar(pos1)); 
 }
 pos1 = l1.siguiente(pos1); 	
}		  



}



void Algoritmos_Pos::interseccion(Lista_Pos&l1, Lista_Pos&l2, Lista_Pos&l3) {
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




void Algoritmos_Pos::mergeSort_v2(Lista_Pos &lista) {
	
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
		
	 mergeSort_v2(primeraMitad);
	 mergeSort_v2(segundaMitad);
	 merge_v2(primeraMitad, segundaMitad, lista);   	
		
	}
	else {
		//condicion de parada. 
	}
	
}



void Algoritmos_Pos::merge_v2(Lista_Pos&lista_1, Lista_Pos&lista_2, Lista_Pos&lista) {
	
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



Lista_Pos Algoritmos_Pos::mergeSort(Lista_Pos lista){
    cout << "Aqui esta la lista" << endl;
	lista.imprimirLista();
	if(lista.NumElem() == 1){
        return lista;
    }else{
        Lista_Pos primeraMitad;
        primeraMitad.iniciar();
        Lista_Pos segundaMitad;
        segundaMitad.iniciar();
        Pos posActual = lista.primera();
        int i;
        for (i = 0; i < lista.NumElem()/2; i++){
            primeraMitad.insertar(posActual, lista.recuperar(posActual));
            posActual = lista.siguiente(posActual);
        }
        
        for (i = lista.NumElem()/2; i < lista.NumElem(); i++){
            segundaMitad.insertar(posActual, lista.recuperar(posActual));
            posActual = lista.siguiente(posActual);
        }
        cout << "1" << endl;
		// primeraMitad.imprimirLista();
        primeraMitad = mergeSort(primeraMitad);
		cout << "2" << endl;
        segundaMitad = mergeSort(segundaMitad);
		cout << "3" << endl;
        return merge(primeraMitad, segundaMitad);
    }
}





Lista_Pos Algoritmos_Pos::merge(Lista_Pos listaA, Lista_Pos listaB){
    Lista_Pos listaC;
    listaC.iniciar();
    while (listaA.NumElem() && listaB.NumElem()){
        if(listaA.recuperar(listaA.primera()) > listaB.recuperar(listaB.primera())){
            listaC.insertar(listaC.ultima(), listaB.recuperar(listaB.primera()));
            listaB.borrar(listaB.primera());
        }else{
            listaC.insertar(listaC.ultima(), listaA.recuperar(listaA.primera()));
            listaB.borrar(listaA.primera());
        }
    }
    while (listaA.NumElem()){
        listaC.insertar(listaC.ultima(), listaA.recuperar(listaA.primera()));
        listaA.borrar(listaA.primera());
    }

    while (listaB.NumElem()){
        listaC.insertar(listaC.ultima(), listaB.recuperar(listaB.primera()));
        listaB.borrar(listaB.primera());
    }
    return listaC;
}
