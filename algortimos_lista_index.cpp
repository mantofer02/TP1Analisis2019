#include "algoritmos_lista_index.h"

Algoritmos_Index :: Algoritmos_Index(Lista_Index &lista){
    this->lista = lista;
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

void Algoritmos_Index :: invertir(Lista_Index &lista){
    int indice1 = lista.primerIndice();
    int indice2 = lista.ultimoIndice();
    int elemento1;
    while (indice1 < indice2 && indice1 != indice2){
        elemento1 = lista.recuperar(indice1);
        lista.modificar(indice1, lista.recuperar(indice2));
        lista.modificar(indice2, elemento1);
        indice1++;
        indice2--;
    }
}

int Algoritmos_Index::buscar(Lista_Index &lista, int elemento){
    int esta = 0;
    int stop = 0;
    int indiceActual = lista.primerIndice();
    while (indiceActual <= lista.ultimoIndice() && !stop){
        if (lista.recuperar(indiceActual) == elemento){
            esta = 1;
            stop = 1;
        }
        indiceActual++;
    }
    return esta;
}

void Algoritmos_Index::eliminarRepetidos(Lista_Index &lista){

}

void Algoritmos_Index::burbuja(Lista_Index &lista) {	
 int amount_elements = lista.numElem(); 
 int indice1 = 0; 
 int indice2 = 0; 
 int temp_value = 0;  
 
 if (amount_elements >= 2) {

 
	 for (int iteration = 0; iteration < amount_elements; ++iteration) {
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
    for(int i = lista.primerIndice(); i < lista.ultimoIndice; i++){
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
    
}
