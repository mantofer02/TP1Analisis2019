//#include "algoritmos_lista_pos.h"
//#include "lista_pos_LDE.h"
//#include "lista_pos_LSE.h"

#include "lista_pos_Arreglo.h"

void invertir(Lista_Pos &lista){
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


void insercion(Lista_Pos &lista) {
 //std::cout << "la cantidad de elementos es: " << lista.NumElem() << std::endl; 	
 if (lista.NumElem() >= 2) {
	Pos p_1 = lista.primera();  
	Pos p_2; 
	Pos aux_p_1;  	
	while (p_1 != PosNula) {
		aux_p_1 = p_1; 
		Pos p_2 = lista.anterior(p_1); 
		while (p_2 != PosNula) {
			if (lista.recuperar(p_2) > lista.recuperar(p_1)) {
				lista.intercambiar(p_1,p_2); 	
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
 


//FORMA PARTE DE QUICKSORT. 
Pos buscarPivote(Lista_Pos &lista, Pos low, Pos high) {
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


void quickSortRecursivo(Lista_Pos &lista, Pos low, Pos high) {

	//cout << "low : " << lista.recuperar(low) << " high : " << lista.recuperar(high) << endl; 
	std::cout << "el low es : " << lista.recuperar(low) << " el high es : " << lista.recuperar(high) << std::endl; 
	if (low != high) {	
		
		Pos pivote_position = buscarPivote(lista, low, high); 
		std::cout << "el pivote es : " << lista.recuperar(pivote_position) << std::endl;  

		if (pivote_position != PosNula) {

		Pos p_1 = low; 
		Pos p_2 = high; 
			
			std::cout << "voy a entrar al fucking while " << std::endl; 
			while (p_2 != lista.anterior(p_1)) {	
				if(p_1 != pivote_position && p_2 != pivote_position) { //FALTABA ESTO
					lista.intercambiar(p_1, p_2);	 
				}	
				std::cout << lista.imprimirLista() << std::endl; 
					
				while (lista.recuperar(p_1) < lista.recuperar(pivote_position)) {		// p_1 != PosNula? 
					p_1 = lista.siguiente(p_1); 
				}

				while (lista.recuperar(p_2) >= lista.recuperar(pivote_position)) {
					p_2 = lista.anterior(p_2); 		
				}	

				std::cout << "p1 es : " << lista.recuperar(p_1) << " p2 es : " << lista.recuperar(p_2) << std::endl; 
			}
			std::cout << "sali del fucking while " << std::endl; 
			
			quickSortRecursivo(lista, low, p_2);
			quickSortRecursivo(lista, p_1, high);  				
		}				
	}
}

void quickSort(Lista_Pos &lista) {
	if (lista.NumElem() >= 2) {
		std::cout << "el primer elemento es : " << lista.recuperar(lista.primera()) << " el ultimo elemento es : " << lista.recuperar(lista.ultima()) << std::endl; 
		quickSortRecursivo(lista, lista.primera(), lista.ultima());  
	}
	else { 
		//no hay nada que modificar. 
	}		
}



//FORMA PARTE DE MERGE_SORT.
void merge(Lista_Pos &lista_1, Lista_Pos &lista_2, Lista_Pos &lista) {
	
	std::cout << "la lista 1 es : " << lista_1.imprimirLista() << std::endl; 
	std::cout << "la lista 2 es : " << lista_2.imprimirLista() << std::endl; 
	
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
	
	std::cout << "el resultado final fue : " << lista.imprimirLista() << std::endl; 
	lista_1.destruir(); 
	lista_2.destruir(); 
}



void mergeSort(Lista_Pos &lista) {
	
	std::cout << "la lista es : " << lista.imprimirLista() << std::endl; 
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
	
	 std::cout << "Primera Mitad" << std::endl; 	
	 mergeSort(primeraMitad);
	 std::cout << "Segunda Mitad" << std::endl; 
	 mergeSort(segundaMitad);
	 std::cout << "UYUYUYUYUYUYUYUYUY" << std::endl; 
	 merge(primeraMitad, segundaMitad, lista);   	
		
	}
	else {
		//condicion de parada. 
	}
	
}









int main(){
Lista_Pos lista; 
lista.iniciar(); 


	lista.agregarAlFinal(5);
		lista.agregarAlFinal(9); 
		lista.agregarAlFinal(3);
		lista.agregarAlFinal(0);  
		lista.agregarAlFinal(2*2);  
			lista.agregarAlFinal(10); 
	




std::cout << lista.imprimirLista() << std::endl; 

//insercion(lista);
//quickSort(lista); 
mergeSort(lista); 

std::cout << "ya hice quicksort" << std::endl;

std::cout << lista.imprimirLista() << std::endl;  

 


    
    return 0;
}
