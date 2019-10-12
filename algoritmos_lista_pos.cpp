#include "algoritmos_lista_pos.h"

Algoritmos_Pos :: Algoritmos_Pos(Lista_Pos lista){
    this->lista = lista;
}

int Algoritmos_Pos :: simetrica(Lista_Pos lista){
    int esSimetrica = 1;
    Pos pos1 = lista.primera();
    Pos pos2 = lista.ultima();
    while (pos1 < pos2 && lista.recuperar(pos1) == lista.recuperar(pos2)){
        pos1 = lista.siguiente(pos1);
        pos2 = lista.anterior(pos2);
    }
    
    if(pos1 < pos2)
        esSimetrica = 0;
    
    return esSimetrica;
}

void Algoritmos_Pos :: invertir(Lista_Pos lista){
    Pos pos1 = lista.primera();
    Pos pos2 = lista.ultima();
    int elemento1;
    while (pos1 < pos2){
        elemento1 = lista.recuperar(pos1);
        lista.modificar(pos1, lista.recuperar(pos2));
        lista.modificar(pos2, elemento1);
        pos1 = lista.siguiente(pos1);
        pos2 = lista.anterior(pos2);
    }
}

int Algoritmos_Pos::buscar(Lista_Pos lista, int elemento){
    int esta = 0;
    int stop = 0;
    Pos posActual = lista.primera();
    while (posActual != PosNula && !stop){
        if (lista.recuperar(posActual) == elemento){
            esta = 1;
            stop = 1;
        }
        posActual = lista.siguiente(posActual);
    }
    return esta;
}

void Algoritmos_Pos::eliminarRepetidos(Lista_Pos lista){

}

void Algoritmos_Pos::burbuja(Lista_Pos lista) {	
 int amount_elements = lista.NumElem(); 
 Pos p_1 = PosNula; 
 Pos p_2 = PosNula; 
 int temp_value = 0;  
 
 if (amount_elements >= 2) {

 
	 for (int iteration = 0; iteration < amount_elements; ++iteration) {
		p_1 = lista.primera(); 
		p_2 = lista.siguiente(p_1); 	
		
		while (lista.siguiente(p_1) != PosNula) {
			if (lista.recuperar(p_1) > lista.recuperar(p_2)) {
				temp_value = lista.recuperar(p_1);
				lista.modificar(p_1, lista.recuperar(p_2));
				lista.modificar(p_2, temp_value);   
			}
			p_1 = lista.siguiente(p_1);
			p_2 = lista.siguiente(p_2);  		
		}	
			 
	 }
			
}
else {
	//no hay nada que ordenar. 	
}
		
}






