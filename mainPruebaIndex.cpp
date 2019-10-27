#include "lista_index_LSE.h"

int main(){

    Lista_Index miLista;
    miLista.iniciar();

    for(int i = 1; i < 20; i++)
        miLista.agregar(i*2);

    std :: cout << miLista.numElem() << std :: endl;
    miLista.imprimirLista();

    miLista.borrar(14);

    miLista.imprimirLista();

    return 0;
}