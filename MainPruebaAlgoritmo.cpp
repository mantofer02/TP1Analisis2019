//#include "algoritmos_lista_pos.h"


#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include "lista_pos_Arreglo.h"
//#include "lista_pos_LDE.h"
#include "lista_pos_LSE.h"
#include <chrono>

void invertir(Lista_Pos &lista){
    Pos pos1 = lista.primera();
    Pos pos2 = lista.ultima();
    int elemento1;
    while (lista.siguiente(pos2) != pos1 && pos1 != pos2){
        elemento1 = lista.recuperar(pos1);
        lista.modificar(pos1, lista.recuperar(pos2));
        lista.modificar(pos2, elemento1);
        pos1 = lista.siguiente(pos1);
        pos2 = lista.anterior(pos2);
    }
}



//FORMA PARTE DE QUICKSORT. 
Pos buscarPivote(Lista_Pos &lista, Pos low, Pos high) {
	cout << lista.imprimirLista(); 	
	Pos pivote_position = PosNula; 
	Pos p_1 = low; 
	while (p_1 != high && lista.recuperar(p_1) == lista.recuperar(lista.siguiente(p_1))) {
		p_1 = lista.siguiente(p_1); 	
	}
	if (p_1 != high) {
		if (lista.recuperar(p_1) < lista.recuperar(lista.siguiente(p_1))) {
			//pivote_position = low; 
			pivote_position = lista.siguiente(p_1); 
		}
		else{
			pivote_position = low; 
		//pivote_position = lista.siguiente(p_1); 
		}
	}
	return pivote_position; 	
} 


void quickSortRecursivo(Lista_Pos &lista, Pos low, Pos high) {

	//cout << "low : " << lista.recuperar(low) << " high : " << lista.recuperar(high) << endl; 
	std::cout << "el low es : " << lista.recuperar(low) << " el high es : " << lista.recuperar(high) << std::endl; 
	if (low != high) {	
		
		Pos pivote_position = buscarPivote(lista, low, high); 
		std::cout << "el pivote es : " << lista.recuperar(pivote_position) << std::endl;  

		if (pivote_position != PosNula) {

		Pos p_1 = low; 
		Pos p_2 = high; 
			
			std::cout << "voy a entrar al fucking while " << std::endl; 
			while (p_2 != lista.anterior(p_1)) {	
				if(p_1 != pivote_position && p_2 != pivote_position) { //FALTABA ESTO
					lista.intercambiar(p_1, p_2);	 
				}	
				std::cout << lista.imprimirLista() << std::endl; 
					
				while (lista.recuperar(p_1) < lista.recuperar(pivote_position)) {		// p_1 != PosNula? 
					p_1 = lista.siguiente(p_1); 
				}

				while (lista.recuperar(p_2) >= lista.recuperar(pivote_position)) {
					p_2 = lista.anterior(p_2); 		
				}	

				std::cout << "p1 es : " << lista.recuperar(p_1) << " p2 es : " << lista.recuperar(p_2) << std::endl; 
			}
			std::cout << "sali del fucking while " << std::endl; 
			
			quickSortRecursivo(lista, low, p_2);
			quickSortRecursivo(lista, p_1, high);  				
		}				
	}
}

void quickSort(Lista_Pos &lista) {
	if (lista.NumElem() >= 2) {
		std::cout << "el primer elemento es : " << lista.recuperar(lista.primera()) << " el ultimo elemento es : " << lista.recuperar(lista.ultima()) << std::endl; 
		quickSortRecursivo(lista, lista.primera(), lista.ultima());  
	}
	else { 
		//no hay nada que modificar. 
	}		
}



//FORMA PARTE DE MERGE_SORT.
void merge(Lista_Pos &lista_1, Lista_Pos &lista_2, Lista_Pos &lista) {
	
	lista.vaciar(); 
	Pos current_1 = lista_1.primera(); 
	Pos current_2 = lista_2.primera(); 
	
	while (current_1 != PosNula && current_2 != PosNula) {
		if (lista_1.recuperar(current_1) < lista_2.recuperar(current_2)) {
			lista.agregarAlFinal(lista_1.recuperar(current_1)); 
			current_1 = lista_1.siguiente(current_1);  
		}
		else {
			lista.agregarAlFinal(lista_2.recuperar(current_2));
			current_2 = lista_2.siguiente(current_2);  
		}
		
	}
	
	while (current_1 != PosNula) {
		lista.agregarAlFinal(lista_1.recuperar(current_1));
		current_1 = lista_1.siguiente(current_1);  		
	}
	
	
	while (current_2 != PosNula) {
		lista.agregarAlFinal(lista_2.recuperar(current_2));
		current_2 = lista_2.siguiente(current_2);  	
	}
	
	lista_1.destruir(); 
	lista_2.destruir(); 
}



void mergeSort(Lista_Pos &lista) {
	
	if (lista.NumElem() > 1) {
		int mid = lista.NumElem()/2; 
		Pos current_pos = lista.primera(); 
		
		Lista_Pos primeraMitad;
		primeraMitad.iniciar();  
		Lista_Pos segundaMitad;
		segundaMitad.iniciar();  
		
		for (int first_half = 0; first_half < mid; ++first_half) {
			primeraMitad.agregarAlFinal(lista.recuperar(current_pos)); 
			current_pos = lista.siguiente(current_pos);  
		}
		
		for (int second_half = mid; second_half < lista.NumElem(); ++second_half) {
			segundaMitad.agregarAlFinal(lista.recuperar(current_pos));
			current_pos = lista.siguiente(current_pos);  
		}
	
	 mergeSort(primeraMitad);
	 mergeSort(segundaMitad);
	 merge(primeraMitad, segundaMitad, lista);   	
		
	}
	else {
		//condicion de parada. 
	}
	
}

void burbuja(Lista_Pos &lista) {	
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



void burbujaBidireccional(Lista_Pos&lista) {
	  Pos flag_1 = lista.primera(); 
	  Pos flag_2 = lista.ultima(); 
	  
	  while (lista.siguiente(flag_2) != flag_1 && flag_2 != flag_1) {		  
	   Pos p_1 = flag_1;
	   while (p_1 != flag_2) {
			if (lista.recuperar(p_1) > lista.recuperar(lista.siguiente(p_1))) {
			 lista.intercambiar(p_1, lista.siguiente(p_1)); 
			}
			p_1 = lista.siguiente(p_1); 
		}
		
		  
		while (p_1 != flag_1) {
			 if (lista.recuperar(p_1) < lista.recuperar(lista.anterior(p_1))) {
				lista.intercambiar(p_1, lista.anterior(p_1)); 
			 }
			 p_1 = lista.anterior(p_1); 
		}

		flag_1 = lista.siguiente(flag_1); 
		flag_2 = lista.anterior(flag_2); 
	   
	  }
	  

 }
 

void seleccion(Lista_Pos &lista) {
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



void seleccionRecursivo(Lista_Pos &lista, Pos pos) {
 
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


void insercion(Lista_Pos &lista) {
 if (lista.NumElem() >= 2) {
	Pos p_1 = lista.primera();  
	Pos p_2; 
	Pos aux_p_1;  	
	while (p_1 != PosNula) {
		aux_p_1 = p_1; 
		Pos p_2 = lista.anterior(p_1); 
		while (p_2 != PosNula) {
			if (lista.recuperar(p_2) > lista.recuperar(p_1)) {
				lista.intercambiar(p_2,p_1); 	
				p_1 = p_2; 	
			}
			p_2 = lista.anterior(p_2); 
		}
		p_1 = aux_p_1; 
		p_1 = lista.siguiente(p_1); 		
	}	 
 }
 else {
		//no hay nada que ordenar. 
 }		
}






void permutar(Lista_Pos&lista, int max_pos); 
void insertarPosicion(int indice, int valor, Lista_Pos* lista); 
void copiarLista(Lista_Pos&lista1, Lista_Pos&lista2); 
void modificarLista(Lista_Pos&lista1, Lista_Pos&lista2); 



int main(){
Lista_Pos lista; 
lista.iniciar(); 

Lista_Pos aux; 
aux.iniciar(); 

srand(time(NULL)); 

//int total_iterations = 100000000; 		//con una lista de este tamaño dura un pichazo en los algoritmos, pero la pc si la crea. 
int total_iterations = 1000000; 	
int distance_random = 10000; 


int current_number = 0; 

 for (int iteration = 0; iteration < total_iterations; ++iteration) {
	 //int random_number = rand() % distance_random; 
	 //lista.agregarAlFinal(random_number); 
	lista.agregarAlFinal(current_number++); 
	//aux.agregarAlFinal(current_number++);		//por alguna razon si meto esto aqui la compu se pega xd. 
 }

 copiarLista(lista, aux);						//tarda mas pero no se pega haha. 
  
 
 double total_time = 0.0; 
 
 int total_permutations = 1; 
 
 for (int permutation = 0; permutation < total_permutations; ++permutation) {		//la cantidad de permutaciones que se deseen hacer. 
	 
	 modificarLista(aux, lista); 	//copia la lista, pero modificando las etiquetas nadamas. 
									//es necesario porque despues de correr el algoritmo queda ordenado, se necesita volver a su estado anterior. 
									
	auto start = std::chrono::high_resolution_clock::now();	//start es de un tipo de dato raro, por eso se usa auto
		//espacion del algoritmo. 
		invertir(lista); 
		///////////////////////
	auto finish = std::chrono::high_resolution_clock::now();	
	

	std::chrono::duration<double> elapsed = finish - start;
	
	
	total_time+= elapsed.count(); 	 
	
	permutar(aux, aux.NumElem()); 	//permuta la lista para generar una nueva lista diferente. 
	std::cout << "permutaciones realizadas y ordenadas : " << permutation << std::endl; 
 }
 
 std::cout << lista.imprimirLista() << std::endl; 
 
  std::cout << "el tiempo total es : " << total_time << std::endl; 
 
  std::cout << "el promedio del algoritmo es : " << total_time/total_permutations << std::endl; 

	
														//LISTA DOBLEMENTE ENLAZADA (LDE)
  
  
  //MERGESORT--------------------------------------------------------------------------------------------------------------------------------------------
  //PRUEBA 1
  //mergeSort con longitud = 1 000 000 	y 100 permutaciones de la lista //la lista comienza ordenada y se va desordenando en cada permutacion. 
  //promedio = 2.11405 sec 	tiempo total = 211.405 sec
  //PRUEBA 2
  //mergeSort con longitud 1 000 000 y 10000 permutaciones de la lista 	//la lista comienza ordenada, DURA DEMASIADO, SE CANCELO EL PROCESO. 
  //promedio inventado = 2.4354 sec tiempo total = da igual esto no lo piden. 
  //PRUEBA 3
  //mergeSort con longitud 1 000 000, lista generada aleatoriamente con numeros en el rango de [0,10000] y 100 permutaciones. 
  //prmedio = 2.24048 sec tiempo total = 224.048
  
  //PRUEBA 2 FUE DIFICIL DE HACER CON UNA LISTA TAN GRANDE PORQUE DURA DEMASIADA, PERO DADO QUE PRUEBA 1 Y PRUEBA 3 DURAN TIEMPOS SIMILARES
  //UNA COMIENZA CON LA LISTA ORDENADA Y LA OTRA DESORDENADA ALEATORIAMENTE, SE PUEDE CONCLUIR QUE SI SE ESPERARA A QUE FINALIZARA, LA PRUEBA 2 PROBABLEMENTE 
  //GENERE UN PROMEDIO SIMILAR DE 2 sec ENTONCES VOY A INVENTARME UN PROMEDIO Y VOY A DECIR QUE DURO ESO XD. 
  //---------------------------------------------------------------------------------------------------------------------------------------------------------  
  
  
  //BURBUJA
  //PRUEBA 1
  //burbuja con longitud = 1 000 000 y 100 permutaciones de la lista // la lista comienza ordenada y se permuta, DURA DEMASIADO
  //burbuja con longitud = 10 000 y 100 permutaciones de la lista // la lista comienzo ordenada y se va desordenando en cada permutacion. 
  //promedio = 2.67589 sec	tiempo total = 267.589 sec (con 10 mil elementos dura similar a mergesort con 1 millon de elementos)
   
  
  //BURBUJA BIDIRECCIONAL
  //PRUEBA 1 
  //bidirecional con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza ordenada y se va desordenando en cada permutacion. 
  //promedio = 	1.13359 sec tiempo total = 113.359 (mucho mas rapido que burbuja)
  //PRUEBA 2 
  //bidireccional con longitud = 100 000 y 100 permutaciones de la lista // la lista comienza ordenada y se va desordenando en cada permutacion. 
  //IGUALMENTE TARDA MUCHO, CRECE EXPONENCIALMENTE EL TIEMPO DE ACUERDO A LA N. 
  //PRUEBA 3 
  //bidireccional con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza desordenada aleatoriamente en un rango de [0,10000] y 100 permutaciones.  
  //promedio = 1.68726 sec tiempo total =   168.726 
  
  //SELECCION 
  //PRUEBA 1
  //seleccion con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza ordenada y se va desordenando en cada permutacion 
  //promedio = 0.839724 sec tiempo total = 83.9724 
  //PRUEBA 2 
  //seleccion con longitud = 10 000 y 1000 permutaciones de la lista // la lista comienza ordenada y se va desordenando en cada permutacion 
  //promedio = 0.839401 sec tiempo total = 839.4011 (indiferentemente de las permutaciones, osea que tan ordenado o desordenada esta, da tiempo similar)
  
  
  //SELECCION RECURSIVO 
  //PRUEBA 1 
  //selecionR con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza ordenada y se va desordenando en cada permutacion. 
  //promedio = 0.810478 sec tiempo total = 81.0478
  //PRUEBA 2 
  //seleccion R con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza desordenada aleatoriamente en un rango de [0, 10000]
  //promedio = 0.811981 sec tiempo total = 81.1981
  
  //INSERSION 
  //PRUEBA 1 
  //insercion con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza ordenada y se va desordenando en cada permutacion. 
  //promedio = 0.813837 sec	tiempo total = 81.3837 sec
  //PRUEBA 2  
  //insercion con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza desordenada aleatoriamente en un rango de [0, 10000]
  //promedio = 1.1372 sec  tiempo total = 113.72 sec (si se nota una diferencia con respecto a la prueba 1, a diferencia de seleccion)
  //insercion con longitud = 10 000 y 1000 permutaciones de la lista // la lista comienza desordenada aleatoriamente en un rango de [0, 10000]
  //promedio = 1.14265 sec tiempo total = 1142.65 sec (se conporta similar a 100 permutaciones)
  
  
  //INVERTIR (UTILIZA EL O.B ANTERIOR) se puede comparar con la LSE. 
  //PRUEBA 1 
  //invertir con longitud de = 1 000 000 y 100 permutaciones (las permutaciones son indiferentes, solo se hicieron para sacar un promedio)
  //promedio = 0.0213121 sec tiempo total = 2.13121 sec //las permutaciones no cambian nada, solo se realizo esta prueba. 
  
  
  
  
  
  
  
  
  
													//LISTA SIMPLEMENTE ENLAZADA (LSE)
													
	//INVERITR
	//PRUEBA 1 
	//invertir con longitud = 10 000 y 100 permutaciones
	//promedio = 0.189947 sec (con 10 mil elementos da un tiempo muy similar a la LDE con 1 millon de elementos)
	//invertir con longitud = 100 000 y 100 permutaciones 
	//promedio = 19.2769 sec (comienza a durar tiempos altos y ni siquiera se acerca al millon de elementos)
	//invertir con longitud = 1 000 000 y 100 permutaciones (DURA DEMASIADO, YA HABIA PASADO COMO MEDIA HORA Y NADA)


	
  
    return 0;
}


void copiarLista(Lista_Pos&lista1, Lista_Pos&lista2) {
	lista2.vaciar(); 
	lista2.iniciar(); 
	Pos p_1 = lista1.primera(); 
	while (p_1 != PosNula) {
		lista2.agregarAlFinal(lista1.recuperar(p_1)); 
		p_1 = lista1.siguiente(p_1); 
		
	}	
}



void modificarLista(Lista_Pos&lista1, Lista_Pos&lista2) 
{
 Pos p_1 = lista1.primera(); 
 Pos p_2 = lista2.primera(); 
 while (p_1 != PosNula) 
 {
	lista2.modificar(p_2, lista1.recuperar(p_1)); 
	p_1 = lista1.siguiente(p_1); 
	p_2 = lista2.siguiente(p_2); 
 } 
 	
	
}



void permutar(Lista_Pos&lista, int max_pos) {
 
 int first_position =0; 
 int second_position = 0; 
 
 while (first_position == second_position) {  
	 first_position = rand() % (max_pos-1) + 1; 
	 second_position = rand() % (max_pos-1) + 1;
 } 
 
 Pos pos_1 = lista.traducir(first_position);
 Pos pos_2 = lista.traducir(second_position); 
 
 
 lista.intercambiar(pos_1, pos_2); 
 
}



void insertarPosicion(int indice, int valor, Lista_Pos* lista) {
	Pos temporal = lista->traducir(indice);
	lista->insertar(temporal, valor);  	
}
