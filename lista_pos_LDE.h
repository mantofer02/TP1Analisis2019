#ifndef CCCC
#define CCCC

#include <iostream>
#include <sstream>
using namespace std; 
#define PosNula nullptr

class Posicion {	
		private: 	
			Posicion* sucesor; 
			Posicion* antecesor; 
			int valor; 
		public: 
			Posicion() : sucesor(nullptr), antecesor(nullptr) {}
			Posicion(int valor) : valor(valor), sucesor(nullptr), antecesor(nullptr) {}
			Posicion(Posicion* anterior, int valor) : antecesor(anterior), valor(valor), sucesor(nullptr) {} 
			Posicion(Posicion* anterior, Posicion*siguiente, int valor) : antecesor(anterior), sucesor(siguiente), valor(valor) {}	
			int recuperar() {return this->valor;}
			void modificar(int valor) {this->valor = valor; }
			Posicion* siguiente() {return this->sucesor; }
			Posicion* anterior()  {return this->antecesor;}
			void establecerSiguiente(Posicion* siguiente) {this->sucesor = siguiente; }
			void establecerAnterior(Posicion* anterior) {this->antecesor = anterior; } 	
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
	void destruir(); 										//O.B
	void vaciar();											//O.B 
	bool vacia(); 											//O.B
	void insertar(Posicion* posicion, int valor); 			//O.B
	void agregarAlFinal(int valor); 						//O.B
	void borrar(Posicion * posicion); 						//0.B
	Posicion* primera(); 									//O.B
	Posicion* ultima();		 								//0.B
	int NumElem(); 											//O.B
	Posicion* siguiente(Posicion* posicion);				//O.B 
	Posicion* anterior(Posicion* posicion); 				//O.B
	void modificar(Posicion* posicion, int valor); 			//O.B
	int recuperar(Posicion* posicion);						//O.B 
	void intercambiar(Posicion* p_1, Posicion* p_2);		//O.B 
	Posicion* traducir(int indice);							//Algoritmo
	string imprimirLista(); 								//Algoritmo. 
	string imprimirListaRevez();  							//Algoritmo.
};
#endif
