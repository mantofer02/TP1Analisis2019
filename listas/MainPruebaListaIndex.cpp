#include "lista_index_LSE.h"

int main(){
    Lista miLista;
    miLista.iniciar(90);
    for(int i = 0; i < 90; i++)
        miLista.insertar(i, i*i);
    miLista.imprimirLista();
    return 0;
}