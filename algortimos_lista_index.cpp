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


void Algoritmos_Index::unionOrdenada(Lista_Index&l1, Lista_Index&l2) {
int p_1 = l1.primerIndice(); 
int p_2 = l2.primerIndice(); 

int amount_elements_l1 = l1.NumElem(); 
int amount_elements_l2 = l2.NumElem(); 


//while (p_1 != PosNula && p_2 != PosNula) {		//no estoy seguro de esto. 
while (p_1 <= amount_elements_l1 && p_2 <= amount_elements_l2) {	//este creo si sirve.
	if (l1.recuperar(p_1) < l2.recuperar(p_2)) {
		p_1 = l1.siguiente(p_1); 	
	}
	else {
		if (l1.recuperar(p_1) == l2.recuperar(p_2)) {
			p_1 = l1.siguiente(p_1);
			p_2 = l2.siguiente(p_2);  
		}
		else {	//tengo que agregar p_2 a l1
			l1.insertar(p_1, l2.recuperar(p_2));
			 p_1 = l1.siguiente(p_1); 
			 p_2 = l2.siguiente(p_2); 					
		}
	}
	
	
}	
//}


while (p_2 <= amount_elements_l2) {
	l1.agregarAlFinal(l2.recuperar(p_2));
	p_2 = l2.siguiente(p_2);  	
}
	
	
}


void Algoritmos_Index::unionNoOrdenada(Lista_Index&l1, Lista_Index&l2) {
	
int p_2 = l2.primerIndice(); 
int p_1; 

bool is_it_there = false; 

//while (p_2 != PosNula) {

while (p_2 <= l2.NumElem()) {
	p_1 = l1.primerIndice(); 
	//while (p_1 != PosNula) {
	  while (p_1 <= l1.NumElem()) {
		if (l2.recuperar(p_2) == l1.recuperar(p_1)) {
			is_it_there = true; 
			//p_1 = PosNula; 
			p_1 = l1.NumElem()+1;	// me salgo del while.  
		}
		else {
			p_1 = l1.siguiente(p_1); 
		}	
	  }
	//}
	if (!is_it_there) {
		l1.agregarAlFinal(l2.recuperar(p_2)); 
	}	

	p_2 = l2.siguiente(p_2); //no estoy seguro de si esto realmente funciona, si la lista tiene 7 elementos, y le digo deme el siguiente del 7	
							 //deberia darme el 8, aunque no sea un indice valido, para eso esta el numElem, porque sino, no se saldría del while. 
}							 //o si se define una posNula, pues se podría utilizar eso, deme el siguiente del 7, y le da posNula. 
//}	

	
}



void Algoritmos_Index::interseccion(Lista_Index &l1, Lista_Index &l2, Lista_Index &l3) {

	int p_1 = l1.primerIndice(); 
	int p_2 = -1; 
	
	//while (p_1 != PosNula) {
	while (p_1 <= l1.NumElem()) {
		p_2 = l2.primerIndice(); 
		//while (p_2 != PosNula) {
		while (p_2 <= l2.NumElem()) {	//si esto no funciona, se puede cambiar por el for. 
			if (l1.recuperar(p_1) == l2.recuperar(p_2)) {
				l3.agregarAlFinal(l1.recuperar(p_1));
				p_2 = l2.NumElem()+1;	//para salirme del while.   
			}
			else {
				p_2 = l2.siguiente(p_2);  
			}	
		}	
		//}
		
		p_1 = l1.siguiente(p_1); 
	}
	//}			
}



void Algoritmos_Index::interseccionOrdenada_v1(Lista_Index &l1, Lista_Index &l2,Lista_Index &l3) {

	//PREGUNTA 
	//QUE PASA SI LE DIGO QUE ME DE EL SIGUIENTE DEL ULTIMO, ME DA UN INDICE SIGUIENTE AUNQUE NO ESTE OCUPADO ? . 

	l3.vaciar();
	l3.iniciar(); 
	int p_1 = l1.primerIndice(); 
	int p_2 = l2.primerIndice(); 


	//while (p_1 != PosNula && p_2 != PosNula) {
	while (p_1 <= l1.NumElem() && p_2 <= l2.NumElem()) {
		if (l1.recuperar(p_1) < l2.recuperar(p_2)) {
			p_1 = l1.siguiente(p_1); 
		}
		else {
		  if (l1.recuperar(p_1) > l2.recuperar(p_2)) {
			  p_2 = l2.siguiente(p_2); 
		  }
		  else { //son iguales. 
			 l3.agregarAlFinal(l1.recuperar(p_1));
			 p_1 = l1.siguiente(p_1); 
			 p_2 = l2.siguiente(p_2);  	  
		  }	
		}
	}
	//}	
	
}



void Algoritmos_Index::interseccionOrdenada_v2(Lista_Index &l1, Lista_Index &l2, Lista_Index &l3) {


int pos1 = l1.primerIndice(); 
//while (pos1 != PosNula) {
while (pos1 <= l1.NumElem()) {
	 if (buscar(l2, l1.recuperar(pos1))) {
		 l3.agregarAlFinal(l1.recuperar(pos1)); 
	 }
	 pos1 = l1.siguiente(pos1); 
}	
//}		  

	
	
} 

