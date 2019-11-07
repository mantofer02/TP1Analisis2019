// #include "lista_index_array.h"

#include "lista_index_LSE.h"


void seleccionRecursivo(Lista_Index &lista, int i){
    if(i < lista.ultimoIndice()){
       int minActual = i; 
       for(int j = minActual + 1; minActual < lista.ultimoIndice(); j++){
            if(lista.recuperar(j) < lista.recuperar(minActual)){
                minActual = j;
            }
            if(minActual != i){
                lista.intercambiar(i, minActual);
            }
        }
    seleccionRecursivo(lista, lista.siguiente(i));
    }
    
}


void seleccionRecursivo(Lista_Index &lista){
    if(lista.numElem() > 1){
        seleccionRecursivo(lista, lista.primerIndice());
    }
}

int main(){

    Lista_Index miLista;
    // miLista.iniciar();
	miLista.iniciar(50);
    for(int i = 1; i <= 50; i++){
		miLista.agregarAlInicio(i);
        // listaIndexMala.agregarAlInicio(i);
    }
    
	miLista.imprimirLista();

	seleccionRecursivo(miLista);

	miLista.imprimirLista();

    return 0;
}
