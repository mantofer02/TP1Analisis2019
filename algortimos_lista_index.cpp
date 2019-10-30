#include "algoritmos_lista_index.h"

Algoritmos_Index :: Algoritmos_Index(Lista_Index &lista){
    this->lista = lista;
}

void Algoritmos_Index :: listar(Lista_Index &lista){
    if(!lista.vacia()){
        for(int i = lista.primerIndice(); i <= lista.ultimoIndice(); i++){
            std :: cout << "Indice -> " << i << " | Elemento -> " << lista.recuperar(i) << std::endl;
        }
    }
}

int Algoritmos_Index::simetrica(Lista_Index &lista){
    int esSimetrica = 0;
    int indice1 = lista.primerIndice();
    int indice2 = lista.ultimoIndice();
    while (indice1 < indice2 && indice1 != indice2 && (lista.recuperar(indice1) == lista.recuperar(indice2))){
        indice1++;
        indice2--;
    }
    
    if (indice1 == indice2 || indice1 > indice2){
			esSimetrica = 1; 		
	}
    
    return esSimetrica;
}

int Algoritmos_Index :: buscar(Lista_Index &lista, int elementoDeseado){
    int esta = 0;
    int stop = 0;
    for(int i = lista.primerIndice(); i <= lista.ultimoIndice() && !stop; i++){
        if(elementoDeseado == lista.recuperar(i)){
            esta = 1;
            stop = 1;
        }
    }
    return esta;
}

void Algoritmos_Index :: invertir(Lista_Index &lista){
    int indice1 = lista.primerIndice();
    int indice2 = lista.ultimoIndice();
    while (indice1 < indice2 && indice1 != indice2){
        lista.intercambiar(indice1, indice2);
        indice1++;
        indice2--;
    }
}

int Algoritmos_Index::buscar(Lista_Index &lista, int elemento){
    int esta = 0;
    int stop = 0;
    int indiceActual = lista.primerIndice();
    while (indiceActual <= lista.ultimoIndice() && !stop){
        if (lista.recuperar(indiceActual) == elemento){
            esta = 1;
            stop = 1;
        }
        indiceActual++;
    }
    return esta;
}

void Algoritmos_Index::eliminarRepetidos(Lista_Index &lista){
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

void Algoritmos_Index::burbuja(Lista_Index &lista){	
    int amount_elements = lista.numElem(); 
    int indice1 = 0; 
    int indice2 = 0; 
    int temp_value = 0;  
 
    if (amount_elements >= 2){
        for(int iteration = 0; iteration < amount_elements; ++iteration){
            indice1 = lista.primerIndice(); 
            indice2 = indice1 + 1; 	
		
            while (indice1 <= lista.ultimoIndice()) {
                if (lista.recuperar(indice1) > lista.recuperar(indice2)) {
                    temp_value = lista.recuperar(indice1);
                    lista.modificar(indice1, lista.recuperar(indice2));
                    lista.modificar(indice2, temp_value);   
                }
                indice1++;
                indice2++;  		
            }	
        }
    }
    else {
	//no hay nada que ordenar. 	
    }	
}


void Algoritmos_Index::seleccion(Lista_Index &lista) {
    for(int i = lista.primerIndice(); i < lista.ultimoIndice; i++){
        int minActual = i;
        for(int j = i + 1; i <= lista.ultimoIndice(); j++){
            if(lista.recuperar(j) < lista.recuperar(minActual)){
                minActual = j;
            }
            if(minActual != i){
                lista.intercambiar(i, minActual);
            }
        }
    }
}


void Algoritmos_Index :: seleccionRecursivo(Lista_Index &lista){
    if(lista.numElem() > 1){
        seleccionRecursivo(lista, lista.primerIndice());
    }
}

void Algoritmos_Index :: seleccionRecursivo(Lista_Index &lista, int i){
    if(i < lista.ultimoIndice()){
       int minActual = i; 
       for(int j = i + 1; i <= lista.ultimoIndice(); j++){
            if(lista.recuperar(j) < lista.recuperar(minActual)){
                minActual = j;
            }
            if(minActual != i){
                lista.intercambiar(i, minActual);
            }
        }
    }
    seleccionRecursivo(lista, i++);
}



void Algoritmos_Index::insercion(Lista_Index &lista) {
	
 if (lista.NumElem() >= 2) {
	int p_1 = lista.primerIndice();  
	int p_2; 
	int aux_p_1;  
	
	
	int amount_elements = lista.NumElem(); 
	for (int current_index = 0; current_index < amount_elements; ++current_index) {
		aux_p_1 = p_1; 
		p_2 = lista.anterior(p_1); 		//este O.B no esta, seria bueno que ademas se definiera una posNula, como -1, porque claramente el primero no tiene anterior. 
		for (int index = current_index; index != 0; --index) { // while(p_2 != PosNula, en este caso -1.)
			if (lista.recuperar(p_2) > lista.recuperar(p_1)) {	//porque sino no debería de dejar recuperar. 
				lista.intercambiar(p_1, p_2);
				p_1 = p_2;  
			}
			p_2 = lista.anterior(p_2); 
		}
	}
		


	
}
else {
		//no hay nada que ordenar. 
} 
  
} 
      
      
      
void Algoritmos_Index::quickSort(Lista_Index &lista) {
	
}

      
void Algoritmos_Index::quickSortRecursivo(Lista_Index &lista) {
	
}
      
      
      
int Algoritmos_Index::buscarPivote(Lista_Inde&lista, int low, int high) {
	
	
}


void Algoritmos_Index::unionNoOrdenada(Lista_Index&l1, Lista_Index&l2) {
	
}



void Algoritmos_Index::interseccion(Lista_Index &l1, Lista_Index &l2, Lista_Index &l3) {
	
	
}


void Algoritmos_Index::interseccionOrdenada_v1(Lista_Index &l1, Lista_Index &l2,Lista_Index &l3) {
	
	
}



void Algoritmos_Index::interseccionOrdenada_v2(Lista_Index &l1, Lista_Index &l2, Lista_Index &l3) {
	
	
} 

