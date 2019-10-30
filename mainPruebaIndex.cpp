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


int main(){

    Lista_Index miLista;
    miLista.iniciar();

    for(int i = 1; i < 5; i++)
        miLista.agregarAlFinal(i*2);

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

    // miLista.borrar(miLista.ultimoIndice());

    miLista.imprimirLista();

    return 0;
}