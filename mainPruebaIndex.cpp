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

void quickSort(Lista_Index &lista) {
	if (lista.numElem() >= 2) {
		quickSortRecursivo(lista, lista.primerIndice(), lista.ultimoIndice());  
	}
	else { 
		
	}		
}



int main(){

    Lista_Index miLista;
    miLista.iniciar();

    for(int i = 1; i < 5; i++)
        miLista.agregarAlInicio(i*2);

    // std :: cout << miLista.numElem() << std :: endl;
    miLista.imprimirLista();

    // Algoritmos_Index algs(miLista);

    // miLista.borrar(14);
    // miLista.agregar(3, 99);
    // miLista.imprimirLista();


    std :: cout << "----------------" << std :: endl;
    // std :: cout << algs.simetrica(miLista) << std :: endl;

    // miLista.agregarAlFinal(6);

    // eliminarRepetidos(miLista);

    // miLista.borrar(miLista.primerIndice());

    // insercion(miLista);

    quickSort(miLista);

    // miLista.intercambiar(1,2);

    miLista.imprimirLista();

    

    return 0;
}