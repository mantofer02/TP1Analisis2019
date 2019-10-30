#include "algoritmos_lista_index.h"

//FALTA EL O.B anterior. 

Algoritmos_Index :: Algoritmos_Index(Lista_Index &lista){
    this->lista = lista;
}

void Algoritmos_Index :: listar(Lista_Index &lista){
    if(!lista.vacia()){
        for(int i = lista.primerIndice(); i <= lista.ultimoIndice(); i++){
            std :: cout << "Indice -> " << i << " | Elemento -> " << lista.recuperar(i) << std::endl;
        }
    }
}

int Algoritmos_Index::simetrica(Lista_Index &lista){
    int esSimetrica = 0;
    int indice1 = lista.primerIndice();
    int indice2 = lista.ultimoIndice();
    while (indice1 < indice2 && indice1 != indice2 && (lista.recuperar(indice1) == lista.recuperar(indice2))){
        indice1++;
        indice2--;
    }
    
    if (indice1 == indice2 || indice1 > indice2){
			esSimetrica = 1; 		
	}
    
    return esSimetrica;
}

int Algoritmos_Index :: buscar(Lista_Index &lista, int elementoDeseado){
    int esta = 0;
    int stop = 0;
    for(int i = lista.primerIndice(); i <= lista.ultimoIndice() && !stop; i++){
        if(elementoDeseado == lista.recuperar(i)){
            esta = 1;
            stop = 1;
        }
    }
    return esta;
}

void Algoritmos_Index :: invertir(Lista_Index &lista){
    int indice1 = lista.primerIndice();
    int indice2 = lista.ultimoIndice();
    while (indice1 < indice2 && indice1 != indice2){
        lista.intercambiar(indice1, indice2);
        indice1++;
        indice2--;
    }
}


void Algoritmos_Index::eliminarRepetidos(Lista_Index &lista){
    int elementoAct;
    for(int i = lista.primerIndice(); i <= lista.ultimoIndice(); i++){
        elementoAct = lista.recuperar(i);
        for(int j = i + 1; j <= lista.ultimoIndice(); j++){
            if(lista.recuperar(j) == elementoAct){
                lista.borrar(j);
            }
        }
    }
}

int Algoritmos_Index :: subLista(Lista_Index &listaA, Lista_Index &listaB){
	int estaContenida = 1;
	int indiceListaA = listaA.primerIndice();
	// Averigua si ListaA esta contenida en Lista B
	for(int i = listaB.primerIndice(); i <= listaB.ultimoIndice() && estaContenida && indiceListaA <= listaA.ultimoIndice(); i++){
		if(listaA.recuperar(indiceListaA) == listaB.recuperar(i))
			indiceListaA++;
		if(listaA.recuperar(indiceListaA) < listaB.recuperar(i))
			estaContenida = 0;
	}

	return estaContenida;

}


void Algoritmos_Index::burbuja(Lista_Index &lista){	
    int amount_elements = lista.numElem(); 
    int indice1 = 0; 
    int indice2 = 0; 
    int temp_value = 0;  
 
    if (amount_elements >= 2){
        for(int iteration = 0; iteration < amount_elements; ++iteration){
            indice1 = lista.primerIndice(); 
            indice2 = indice1 + 1; 	
		
            while (indice1 <= lista.ultimoIndice()) {
                if (lista.recuperar(indice1) > lista.recuperar(indice2)) {
                    temp_value = lista.recuperar(indice1);
                    lista.modificar(indice1, lista.recuperar(indice2));
                    lista.modificar(indice2, temp_value);   
                }
                indice1++;
                indice2++;  		
            }	
        }
    }
    else {
	//no hay nada que ordenar. 	
    }	
}


void Algoritmos_Index::seleccion(Lista_Index &lista) {
    for(int i = lista.primerIndice(); i < lista.ultimoIndice(); i++){
        int minActual = i;
        for(int j = i + 1; i <= lista.ultimoIndice(); j++){
            if(lista.recuperar(j) < lista.recuperar(minActual)){
                minActual = j;
            }
            if(minActual != i){
                lista.intercambiar(i, minActual);
            }
        }
    }
}


void Algoritmos_Index :: seleccionRecursivo(Lista_Index &lista){
    if(lista.numElem() > 1){
        seleccionRecursivo(lista, lista.primerIndice());
    }
}

void Algoritmos_Index :: seleccionRecursivo(Lista_Index &lista, int i){
    if(i < lista.ultimoIndice()){
       int minActual = i; 
       for(int j = i + 1; i <= lista.ultimoIndice(); j++){
            if(lista.recuperar(j) < lista.recuperar(minActual)){
                minActual = j;
            }
            if(minActual != i){
                lista.intercambiar(i, minActual);
            }
        }
    }
    seleccionRecursivo(lista, i++);
}



void Algoritmos_Index::insercion(Lista_Index &lista) {
    int i = lista.primerIndice() + 1;
    int j;
    for(i; i <= lista.ultimoIndice(); i++){
        j = i;
        while (j > lista.primerIndice() && lista.recuperar(j-1) > lista.recuperar(j)){
            lista.intercambiar(j , j -1);
            j--;
        }
    }
}
      
      
      

void Algoritmos_Index::quickSort(Lista_Index &lista) {
	if (lista.numElem() >= 2) {
		quickSortRecursivo(lista, lista.primerIndice(), lista.ultimoIndice());  
	}
	else { 
		
	}		
}

      
void Algoritmos_Index::quickSortRecursivo(Lista_Index &lista, int low, int high) {
	if (low != high) {	
		int pivote_position = buscarPivote(lista, low, high); 
		if (pivote_position >= lista.primerIndice() && pivote_position <= lista.ultimoIndice()) {
		int p_1 = low; 
		int p_2 = high; 
			while (/*lista.siguiente(p_2) != p_1*/ p_2 != p_1--) {	
				if(p_1 != pivote_position && p_2 != pivote_position) { //FALTABA ESTO
					lista.intercambiar(p_2, p_1);	 
				}														//FALTABA ESTO
				
				while (lista.recuperar(p_1) < lista.recuperar(pivote_position)) {		// p_1 != PosNula? 
					p_1++; 
				}
				while (lista.recuperar(p_2) >= lista.recuperar(pivote_position)) {
					p_2--; 		
				}	
			}
			quickSortRecursivo(lista, low, p_2);
			quickSortRecursivo(lista, p_1, high);  	
		}			
	}
}
      
      
      
int Algoritmos_Index::buscarPivote(Lista_Index &lista, int low, int high) {
	 	
	int pivote_position = 0; 
	int p_1 = low; 

	while (p_1 != high && lista.recuperar(p_1) == lista.recuperar(p_1++)){
		p_1++; 	
	}

	if (p_1 != high) {
		if (lista.recuperar(p_1) < lista.recuperar(p_1++)) {
			//pivote_position = low; 
			pivote_position = p_1++; 
		}
		else{
			pivote_position = low; 
		//pivote_position = lista.siguiente(p_1); 
		}
	}
	return pivote_position; 	
}


void Algoritmos_Index::unionOrdenada(Lista_Index&l1, Lista_Index&l2) {
int p_1 = l1.primerIndice(); 
int p_2 = l2.primerIndice(); 
 
	while (p_1 <= l1.ultimoIndice() && p_2 <= l2.ultimoIndice()) {	
		if (l1.recuperar(p_1) < l2.recuperar(p_2)) {
			p_1++; 	
		}
		else {
			if (l1.recuperar(p_1) == l2.recuperar(p_2)) {
				p_1++;
				p_2++;  
			}
			else {	//tengo que agregar p_2 a l1
				l1.agregar(p_1, l2.recuperar(p_2));
				p_1++; 
				p_2++; 					
			}
		}
		
		
	}	
	
	while (p_2 <= l2.ultimoIndice()) {
		l1.agregarAlFinal(l2.recuperar(p_2));
		p_2++;  	
	}
}


void Algoritmos_Index::unionNoOrdenada(Lista_Index&l1, Lista_Index&l2) {
	
	int p_2 = l2.primerIndice(); 
	int p_1; 

	bool is_it_there = false; 

	//while (p_2 != PosNula) {

	while (p_2 <= l2.ultimoIndice()) {
	p_1 = l1.primerIndice(); 
	//while (p_1 != PosNula) {
	  while (p_1 <= l1.ultimoIndice()) {
		if (l2.recuperar(p_2) == l1.recuperar(p_1)) {
			is_it_there = true; 
			p_1 = l1.ultimoIndice()+1;	// me salgo del while.  
		}
		else {
			++p_1; 
		}	
	  }
	//}
	if (!is_it_there) {
		l1.agregarAlFinal(l2.recuperar(p_2)); 
	}	

	++p_2; 					
}							
//}	

	
}



void Algoritmos_Index::interseccion(Lista_Index &l1, Lista_Index &l2, Lista_Index &l3) {

	int p_1 = l1.primerIndice(); 
	int p_2 = -1; 
	
	//while (p_1 != PosNula) {
	while (p_1 <= l1.ultimoIndice()) {
		p_2 = l2.primerIndice(); 
		//while (p_2 != PosNula) {
		while (p_2 <= l2.ultimoIndice()) {	//si esto no funciona, se puede cambiar por el for. 
			if (l1.recuperar(p_1) == l2.recuperar(p_2)) {
				l3.agregarAlFinal(l1.recuperar(p_1));
				p_2 = l2.ultimoIndice()+1;	//para salirme del while.   
			}
			else {
				++p_2; 
			}	
		}	
		//}
		
		++p_1; 
	}
	//}			
}



void Algoritmos_Index::interseccionOrdenada_v1(Lista_Index &l1, Lista_Index &l2,Lista_Index &l3) {

	//PREGUNTA 
	//QUE PASA SI LE DIGO QUE ME DE EL SIGUIENTE DEL ULTIMO, ME DA UN INDICE SIGUIENTE AUNQUE NO ESTE OCUPADO ? . 

	l3.vaciar();
	l3.iniciar(); 
	int p_1 = l1.primerIndice(); 
	int p_2 = l2.primerIndice(); 


	//while (p_1 != PosNula && p_2 != PosNula) {
	while (p_1 <= l1.ultimoIndice() && p_2 <= l2.ultimoIndice()) {
		if (l1.recuperar(p_1) < l2.recuperar(p_2)) {
			++p_1; 
		}
		else {
		  if (l1.recuperar(p_1) > l2.recuperar(p_2)) {
			 ++p_2; 
		  }
		  else { //son iguales. 
			 l3.agregarAlFinal(l1.recuperar(p_1));
			 ++p_1;
			 ++p_2; 	  
		  }	
		}
	}
	//}	
	
}



void Algoritmos_Index::interseccionOrdenada_v2(Lista_Index &l1, Lista_Index &l2, Lista_Index &l3) {
	int pos1 = l1.primerIndice(); 
	//while (pos1 != PosNula) {
	while (pos1 <= l1.ultimoIndice()) {
		if (buscar(l2, l1.recuperar(pos1))) {
			l3.agregarAlFinal(l1.recuperar(pos1)); 
		}
	pos1++; 
	}		
} 
                  
void Algoritmos_Index::mergeSort(Lista_Index &lista){

	if (lista.numElem() > 1) {
		int mid = lista.numElem()/2; 
		int indiceActual = lista.primerIndice(); 
		
		Lista_Index primeraMitad;
		primeraMitad.iniciar();  
		Lista_Index segundaMitad;
		segundaMitad.iniciar();  

		for (int i = lista.primerIndice(); i < mid; i++) {
			primeraMitad.agregarAlFinal(lista.recuperar(indiceActual)); 
			indiceActual = lista.siguiente(indiceActual);  
		}
		
		for (int j = mid; j < lista.ultimoIndice(); j++) {
			segundaMitad.agregarAlFinal(lista.recuperar(indiceActual));
			indiceActual = lista.siguiente(indiceActual);  
		}
		
	 mergeSort(primeraMitad);
	 mergeSort(segundaMitad);
	 merge(primeraMitad, segundaMitad, lista);   	
		
	}
	else {
		//condicion de parada. 
	}
	
}


void Algoritmos_Index ::merge(Lista_Index &lista_1, Lista_Index &lista_2, Lista_Index &lista) {
	
	lista.vaciar(); 
	int current_1 = lista_1.primerIndice(); 
	int current_2 = lista_2.primerIndice(); 
	
	while (current_1 <= lista_1.ultimoIndice() && current_2 <= lista_2.ultimoIndice()) {
		if (lista_1.recuperar(current_1) < lista_2.recuperar(current_2)) {
			lista.agregarAlFinal(lista_1.recuperar(current_1)); 
			current_1 = lista_1.siguiente(current_1);  
		}
		else {
			lista.agregarAlFinal(lista_2.recuperar(current_2));
			current_2 = lista_2.siguiente(current_2);  
		}
		
	}
	while (current_1 <= lista_1.ultimoIndice()) {
		lista.agregarAlFinal(lista_1.recuperar(current_1));
		current_1 = lista_1.siguiente(current_1);  		
	}
	while (current_2 <= lista_2.ultimoIndice()) {
		lista.agregarAlFinal(lista_2.recuperar(current_2));
		current_2 = lista_2.siguiente(current_2);  	
	}
	lista_1.destruir(); 
	lista_2.destruir(); 
}