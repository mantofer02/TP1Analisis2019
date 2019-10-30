// #include "lista_index_array.h"

#include "lista_index_LSE.h"

// #include "algoritmos_lista_index.h"

void eliminarRepetidos(Lista_Index &lista){
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

void insercion(Lista_Index &lista){
	
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


int buscarPivote(Lista_Index &lista, int low, int high) {
	 	
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

void quickSortRecursivo(Lista_Index &lista, int low, int high) {
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


void quickSort(Lista_Index &lista) {
	if (lista.numElem() >= 2) {
		quickSortRecursivo(lista, lista.primerIndice(), lista.ultimoIndice());  
	}
	else { 
		
	}		
}

      
      
      
      


void unionOrdenada(Lista_Index&l1, Lista_Index&l2) {				//probado y funciona. 
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


void unionNoOrdenada(Lista_Index&l1, Lista_Index&l2) {			//probado y funciona. 
	
	int p_2 = l2.primerIndice(); 
	int p_1; 

	bool is_it_there = false; 

	while (p_2 <= l2.ultimoIndice()) {
		p_1 = l1.primerIndice(); 
		  while (p_1 <= l1.ultimoIndice()) {
				if (l2.recuperar(p_2) == l1.recuperar(p_1)) {
					is_it_there = true; 
					p_1 = l1.ultimoIndice()+1;	// me salgo del while.  
				}
				else {
					++p_1; 
				}	
		  }
		if (!is_it_there) {
			l1.agregarAlFinal(l2.recuperar(p_2)); 
		}	

		++p_2; 					
	}							

	
}


void interseccion(Lista_Index &l1, Lista_Index &l2, Lista_Index &l3) {			//probado y funciona. 
	
	l3.vaciar(); 
	int p_1 = l1.primerIndice(); 
	int p_2 = -1; 
	

	while (p_1 <= l1.ultimoIndice()) {
		p_2 = l2.primerIndice(); 
		while (p_2 <= l2.ultimoIndice()) {	//si esto no funciona, se puede cambiar por el for. 
			if (l1.recuperar(p_1) == l2.recuperar(p_2)) {
				l3.agregarAlFinal(l1.recuperar(p_1));
				p_2 = l2.ultimoIndice()+1;	//para salirme del while.   
			}
			else {
				++p_2; 
			}	
		}	
		
		++p_1; 
	}		
}




void invertir(Lista_Index &lista){				//probado y funciona. 
    int indice1 = lista.primerIndice();
    int indice2 = lista.ultimoIndice();
    while (indice1 < indice2 && indice1 != indice2){
        lista.intercambiar(indice1, indice2);
        indice1++;
        indice2--;
    }
}

void merge(Lista_Index &lista_1, Lista_Index &lista_2, Lista_Index &lista) {
	
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

void mergeSort(Lista_Index &lista){

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



int main(){

    Lista_Index miLista;
    miLista.iniciar();
    Lista_Index aux; 
    aux.iniciar(); 
    Lista_Index aux_1; 
    aux_1.iniciar(); 

    for(int i = 1; i < 5; i++)
        miLista.agregarAlInicio(i*2);
        
    // for (int j = 1; j < 10; j++)
	// 	aux.agregarAlInicio(j*2); 
	
	// for (int k = 0; k < 15; ++k) 
	// 	aux_1.agregarAlInicio(k*2);
		 
	//invertir(miLista); 
	//invertir(aux); 
	
	

    std::cout << "imprimiendo la primera lista" << std::endl; 
    miLista.imprimirLista();
	std::cout << "imprimiendo la segunda lista" << std::endl; 
	aux.imprimirLista();
	std::cout << "imprimiendo la tercera lista" << std::endl;  
	aux_1.imprimirLista(); 
	
	
	//unionOrdenada(miLista, aux); 
	//unionNoOrdenada(miLista, aux); 
	// interseccion(miLista, aux, aux_1); 
	
	// std::cout << "imprimiendo la primera lista" << std::endl; 
    // miLista.imprimirLista();
	// std::cout << "imprimiendo la segunda lista" << std::endl; 
	// aux.imprimirLista(); 
	// std::cout << "imprimiendo la tercera lista" << std::endl;  
	// aux_1.imprimirLista(); 
	
	
	
    // Algoritmos_Index algs(miLista);

    // miLista.borrar(14);
    miLista.agregar(3, 99);
    miLista.imprimirLista();


   std :: cout << "----------------" << std :: endl;
    // std :: cout << algs.simetrica(miLista) << std :: endl;

    // miLista.agregarAlFinal(6);
	mergeSort(miLista);
	miLista.imprimirLista();
    // eliminarRepetidos(miLista);

    // miLista.borrar(miLista.primerIndice());

    // insercion(miLista);

    //quickSort(miLista);

    // miLista.intercambiar(1,2);

    //miLista.imprimirLista();

    

    return 0;
}
