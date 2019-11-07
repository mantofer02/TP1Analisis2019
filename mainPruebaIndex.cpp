#include "lista_index_array.h"

// #include "lista_index_LSE.h"


void seleccion(Lista_Index &lista) {
    for(int i = lista.primerIndice(); i <=lista.ultimoIndice(); i++){
        int minActual = i;
        for(int j = minActual + 1; minActual < lista.ultimoIndice(); j++){
            if(lista.recuperar(j) < lista.recuperar(minActual)){
                minActual = j;
            }
            if(minActual != i){
                lista.intercambiar(i, minActual);
            }
        }
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

	seleccion(miLista);

	miLista.imprimirLista();

    return 0;
}
