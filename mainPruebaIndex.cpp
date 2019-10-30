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

void insercion(Lista_Index &lista) {
	
	if(lista.numElem()>= 2){
		int indiceAct = lista.primerIndice() + 1;
		for(indiceAct; indiceAct <= lista.ultimoIndice(); indiceAct++){
			if(lista.recuperar(indiceAct) < lista.recuperar(indiceAct - 1)){
				for(int j = indiceAct; j - 1 >= lista.primerIndice(); j--){
					// if(lista.recuperar(j) > lista.recuperar(j - 1))
						lista.intercambiar(j, j-1);
				}
			}
		}
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
    miLista.agregar(3, 99);
    miLista.imprimirLista();


    std :: cout << "----------------" << std :: endl;
    // std :: cout << algs.simetrica(miLista) << std :: endl;

    miLista.agregarAlFinal(6);

    eliminarRepetidos(miLista);

    // miLista.borrar(miLista.primerIndice());

    insercion(miLista);

    miLista.imprimirLista();

    

    return 0;
}