#include "algoritmos_lista_index.h"

Algoritmos_Index :: Algoritmos_Index(Lista_Index lista){
    this->lista = lista;
}

int Algoritmos_Index :: simetrica(Lista_Index lista){
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

void Algoritmos_Index :: invertir(Lista_Index lista){
    int pos1 = 0;
    int pos2 = lista.numElem() - 1;
    int elemento1;
    while (pos1 < pos2){
        elemento1 = lista.recuperar(pos1);
        lista.modificar(pos1, lista.recuperar(pos2));
        lista.modificar(pos2, elemento1);
        pos1 = lista.siguiente(pos1);
        pos2 = lista.anterior(pos2);
    }
}

int Algoritmos_Index::buscar(Lista_Index lista, int elemento){
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

void Algoritmos_Index::eliminarRepetidos(Lista_Index lista){

}

void Algoritmos_Index::burbuja(Lista_Index lista) {	
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


void Algoritmos_Index::seleccion(Lista_Index lista) {
int amount_elements = lista.NumElem();  
Pos p_1 = lista.primera();  
Pos p_2 = lista.primera(); 
Pos lower_pos = PosNula;  
int temp_value = 0; 
    for (int iteration = 0; iteration < amount_elements; ++iteration) {
        lower_pos = p_1; 
        p_2 = lista.siguiente(p_1); 
        for (int find_lower = iteration+1; find_lower < amount_elements; ++find_lower) {
            if (lista.recuperar(p_2) < lista.recuperar(lower_pos)) {
                lower_pos = p_2; 
            }
        p_2 = lista.siguiente(p_2); 		 
        }
        if (p_1 != lower_pos) {
            temp_value = lista.recuperar(p_1);
            lista.modificar(p_1, lista.recuperar(lower_pos));
            lista.modificar(lower_pos, temp_value);   
        }
        p_1 = lista.siguiente(p_1); 
    }	
}

void Algoritmos_Index::seleccionRecursivo(Lista_Index lista, Pos pos) {
 
  if (lista.siguiente(pos) != PosNula) {
	  Pos p_2 = lista.siguiente(pos);
	  Pos lower_pos = pos; 
	  while (p_2 != PosNula) {
		 if (lista.recuperar(p_2) < lista.recuperar(lower_pos)) {
			 lower_pos = p_2;  
		 }
		 p_2 = lista.siguiente(p_2); 	  
	  }
	  if (pos != lower_pos) {
		  int temp_value = lista.recuperar(pos);
		  lista.modificar(pos, lista.recuperar(lower_pos));
		  lista.modificar(lower_pos, temp_value);   
	  } 
	  seleccionRecursivo(lista, lista.siguiente(pos));  
  }
  else {
	//condicion de parada.  
  }
		
}

Lista_Index Algoritmos_Index::mergeSort(Lista_Index lista){
    if(lista.NumElem() == 1){
        return lista;
    }else{
        Lista_Index primeraMitad;
        primeraMitad.iniciar();
        Lista_Index segundaMitad;
        segundaMitad.iniciar();
        Pos posActual = lista.primera();
        int i;
        for (i = 0; i < lista.NumElem()/2; i++){
            primeraMitad.insertar(posActual, lista.recuperar(posActual));
            posActual = lista.siguiente(posActual);
        }
        
        for (i = lista.NumElem()/2; i < lista.NumElem(); i++){
            segundaMitad.insertar(posActual, lista.recuperar(posActual));
            posActual = lista.siguiente(posActual);
        }
        
        primeraMitad = mergeSort(primeraMitad);
        segundaMitad = mergeSort(segundaMitad);
        return merge(primeraMitad, segundaMitad);
    }
}

Lista_Index Algoritmos_Index::merge(Lista_Index listaA, Lista_Index listaB){
    Lista_Index listaC;
    listaC.iniciar();
    while (listaA.NumElem() && listaB.NumElem()){
        if(listaA.recuperar(listaA.primera) > listaB.recuperar(listaB.primera)){
            listaC.insertar(listaC.ultima(), listaB.recuperar(listaB.primera()));
            listaB.borrar(listaB.primera());
        }else{
            listaC.insertar(listaC.ultima(), listaA.recuperar(listaA.primera()));
            listaB.borrar(listaA.primera());
        }
    }
    while (listaA.NumElem()){
        listaC.insertar(listaC.ultima(), listaA.recuperar(listaA.primera()));
        listaA.borrar(listaA.primera());
    }

    while (listaB.NumElem()){
        listaC.insertar(listaC.ultima(), listaB.recuperar(listaB.primera()));
        listaB.borrar(listaB.primera());
    }
    return listaC;
}