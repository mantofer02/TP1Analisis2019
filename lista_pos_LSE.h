#ifndef BBBBB
#define BBBBB

#include <iostream>
#include <sstream>
using namespace std; 
#define PosNula nullptr

class Posicion {		
			private: 	
				Posicion* sucesor; 
				int valor; 
			public: 
				Posicion() : sucesor(nullptr) {}
				Posicion(int valor) : valor(valor), sucesor(nullptr) {}
				Posicion(Posicion*siguiente, int valor) : sucesor(siguiente), valor(valor) {}	
				int recuperar() {return this->valor;}
				void modificar(int valor) {this->valor = valor; }
				Posicion* siguiente() {return this->sucesor; }
				void establecerSiguiente(Posicion* siguiente) {this->sucesor = siguiente; }
		};
typedef Posicion* Pos;

class Lista_Pos {	
	private:
		int numero_elementos; 
		Posicion* primera_posicion; 
		Posicion* ultima_posicion; 
	public: 
		Lista_Pos();
		void iniciar(); 										//O.B
		Posicion* siguiente(Posicion* posicion); 				//O.B
		Posicion* anterior(Posicion* posicion);					//0.B 
		void modificar(Posicion* posicion, int valor); 			//O.B
		int recuperar(Posicion* posicion);						//O.B 										
		void insertar(Posicion* posicion, int valor); 			//O.B
		void agregarAlFinal(int valor); 						//O.B
		void borrar(Posicion * posicion); 						//0.B
		Posicion* primera(); 									//0.B
		Posicion* ultima(); 									//O.B
		bool vacia(); 											//0.B
		void vaciar(); 											//O.B
		void destruir(); 										//O.B
		int NumElem(); 											//O.B
		void intercambiar(Posicion* p_1, Posicion* p_2);		//O.B 
		string imprimirLista(); 								//Algoritmo. 
		Posicion* traducir(int indice); 						//Algoritmo. 
};

#endif
