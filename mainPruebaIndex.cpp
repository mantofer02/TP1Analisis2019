// #include "lista_index_array.h"

#include "lista_index_LSE.h"

int main(){

    Lista_Index miLista;
    miLista.iniciar();

    for(int i = 1; i < 5; i++)
        miLista.agregarAlFinal(i*2);

    // std :: cout << miLista.numElem() << std :: endl;
    miLista.imprimirLista();

    // miLista.borrar(14);
    miLista.agregar(3, 99);
    miLista.imprimirLista();

    return 0;
}