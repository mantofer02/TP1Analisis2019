#ifndef AAA
#define AAA

#include <iostream>
#include <sstream>
using namespace std; 


#define length 100
#define PosNula -1

typedef int Pos; 

class Lista_Pos{
	private: 
		int* ListaPos; 
		int numero_elementos; 
		int longitud; 		
	public: 
		Lista_Pos(); 
		// Lista_Pos(int); 
		void iniciar(); 								//O.B
		void iniciar(int);
		void destruir(); 								//0.B
		bool vacia(); 									//O.B
		void vaciar(); 									//O.B
		int primera(); 									//O.B
		int NumElem(); 									//0.B
		int ultima(); 									//0.B
		int recuperar(int posicion); 					//O.B
		void modificar(int posicion, int valor); 		//O.B
		int siguiente(int posicion); 					//O.B
		void insertar(int posicion, int valor); 		//O.B	
		void agregarAlFinal(int valor); 				//O.B
		void borrar(int posicion); 						//O.B
		int anterior(int posicion); 					//O.B
		void intercambiar(int p_1, int p_2);			//O.B 
		int traducir(int posicion); 					//Algoritmo.		//traduce el indice del usuario al indice de la Lista_Pos. osea de 1 a 0 o de 2 a 1. 							
		string imprimirLista(); 
}; 
#endif
