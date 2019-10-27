#include "algoritmos_lista_ord.h"

int main(){
    Lista_Ord lista1;
    Lista_Ord lista2;
    lista1.iniciar();
    lista2.iniciar();
    for(int i=2; i<45; i++){
        lista1.agregar(i);
    }
    lista1.agregar(100);
    for(int i=1; i<76; i++){
        lista2.agregar(i);
    }
    
    Algoritmos_Ordenada algoritmos(lista2);
    
    Lista_Ord lista3 = algoritmos.interseccion(lista1);
    lista3.imprimir();
    cout << endl << endl;


    return 0;
}
