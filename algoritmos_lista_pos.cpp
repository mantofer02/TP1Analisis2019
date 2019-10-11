#include "algoritmos_lista_pos.h"

Algoritmos_Pos :: Algoritmos_Pos(Lista_Pos lista){
    this->lista = lista;
}

int Algoritmos_Pos :: simetrica(Lista_Pos lista){
    int esSimetrica = 1;
    Pos pos1 = lista.primera();
    Pos pos2 = lista.ultima();
    while (pos1 != pos2 && lista.recuperar(pos1) == lista.recuperar(pos2)){
        pos1 = lista.siguiente(pos1);
        pos2 = lista.anterior(pos2);
    }
    
    if(pos1 != pos2)
        esSimetrica = 0;
    
    return esSimetrica;
}