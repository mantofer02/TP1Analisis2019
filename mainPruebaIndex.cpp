#include "lista_index_array.h"

// #include "lista_index_LSE.h"

void merge(Lista_Index &lista_1, Lista_Index &lista_2, Lista_Index &lista) {
	lista.vaciar();  
	int current_1 = lista_1.primerIndice(); 
	int current_2 = lista_2.primerIndice(); 
	
	while (current_1 <= lista_1.ultimoIndice() && current_2 <= lista_2.ultimoIndice()) {
		if (lista_1.recuperar(current_1) < lista_2.recuperar(current_2)) {
			lista.agregarAlFinal(lista_1.recuperar(current_1));  
			current_1 = lista_1.siguiente(current_1); 
			// lista_1.borrar(current_1);
		}
		else {
			lista.agregarAlFinal(lista_2.recuperar(current_2));
			 current_2 = lista_2.siguiente(current_2);
		}
		
	}
	while (current_1 <= lista_1.ultimoIndice() /*!lista_1.vacia()*/) {
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
	if (lista.ultimoIndice() > lista.primerIndice()) {
		int mid = lista.ultimoIndice()/2; 
		Lista_Index primeraMitad;
		primeraMitad.iniciar();  
		Lista_Index segundaMitad;
		segundaMitad.iniciar();  
		for (int i = lista.primerIndice(); i < mid; i++) {
			primeraMitad.agregarAlFinal(lista.recuperar(i)); 
		}
		
		for (int j = mid; j <= lista.ultimoIndice(); j++) {
			segundaMitad.agregarAlFinal(lista.recuperar(j)); 
		}	
		// std :: cout << "EStoy bien" << std :: endl;
		
		mergeSort(primeraMitad);
		mergeSort(segundaMitad);
		merge(primeraMitad, segundaMitad, lista);   	
	}else {
		
		//condicion de parada. 
	}
	
}


int main(){

    Lista_Index miLista;
    // miLista.iniciar();
	miLista.iniciar(49);
    for(int i = 1; i <= 49; i++){
		miLista.agregarAlInicio(i);
        // listaIndexMala.agregarAlInicio(i);
    }
    
	miLista.imprimirLista();

	mergeSort(miLista);

	miLista.imprimirLista();

    return 0;
}
