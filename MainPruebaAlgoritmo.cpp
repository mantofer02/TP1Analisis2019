//#include "algoritmos_lista_pos.h"
//#include "lista_pos_LDE.h"
#include "lista_pos_LSE.h"



void insercion(Lista_Pos &lista) {
 //std::cout << "la cantidad de elementos es: " << lista.NumElem() << std::endl; 	
 if (lista.NumElem() >= 2) {
	Pos p_1 = lista.primera();  
	Pos p_2; 
	Pos aux_p_1;  	
	while (p_1 != PosNula) {
		aux_p_1 = p_1; 
		Pos p_2 = lista.anterior(p_1); 
		if (p_2 != PosNula) {
			std::cout << "p1 es : " << lista.recuperar(p_1) << " p2 es : " << lista.recuperar(p_2) << std::endl; 
		}
		else {
			std::cout << "p1 es : " << lista.recuperar(p_1) << " p2 es : NULO " << std::endl; 
		}
		while (p_2 != PosNula) {
			if (lista.recuperar(p_2) > lista.recuperar(p_1)) {
				lista.intercambiar(p_1,p_2); 	
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




int main(){
Lista_Pos lista; 
lista.iniciar(); 

	lista.agregarAlFinal(5);
		lista.agregarAlFinal(9); 
		lista.agregarAlFinal(3);
		lista.agregarAlFinal(0);  
		lista.agregarAlFinal(2*2);  
			lista.agregarAlFinal(3*2); 


std::cout << lista.imprimirLista() << std::endl; 

insercion(lista);

std::cout << "ya hice insercion" << std::endl;

std::cout << lista.imprimirLista() << std::endl;  

 


    
    return 0;
}
