// #include "lista_index_array.h"

#include "algoritmos_lista_index.h"

int main(){

    Lista_Index miLista;
    miLista.iniciar();

    for(int i = 1; i < 5; i++)
        miLista.agregarAlFinal(i*2);

    // std :: cout << miLista.numElem() << std :: endl;
    miLista.imprimirLista();

    Algoritmos_Index algs(miLista);

    // miLista.borrar(14);
    miLista.agregar(3, 99);
    miLista.imprimirLista();


    std :: cout << "----------------" << std :: endl;
    // std :: cout << algs.simetrica(miLista) << std :: endl;

    miLista.agregarAlFinal(6);

    algs.eliminarRepetidos(miLista);

    miLista.imprimirLista();

    return 0;
}