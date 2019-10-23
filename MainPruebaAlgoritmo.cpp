#include "algoritmos_lista_pos.h"
#include "lista_pos_LDE.h"

int main(){
    Lista_Pos lista1, lista2;
    Algoritmos_Pos calcu;
    lista1.iniciar();
    lista2.iniciar();
    lista1.agregarAlFinal(9);
    lista1.agregarAlFinal(8);
    lista1.imprimirLista();
    // lista1.agregarAlFinal(1);

    lista2.agregarAlFinal(88);
    lista2.agregarAlFinal(99);
    // lista2.agregarAlFinal(1);
// Se esta cayendo el mergeSort
    // Lista_Pos lista3Ordenada = calcu.mergeSort(lista1); 

    // lista3Ordenada.imprimirLista(); 
    
    return 0;
}