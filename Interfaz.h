#ifndef miInterfaz1
#define miInterfaz2

//#include <iostream>


#include "algoritmos_lista_pos.h"
#include "algoritmos_lista_index.h"
#include "algoritmos_lista_ord.h"



// using namespace std;

class Interfaz{
    private:
        int tipoDeLista;
        Lista_Ord miListaOrdenadaA;
        Lista_Ord miListaOrdenadaB;
        // Lista_Index miListaIndex;
        Lista_Index miListaIndexA;
        Lista_Index miListaIndexB;
        Lista_Index miListaIndexC;
        Lista_Pos miListaPos; 
        Lista_Pos aux_1; 		//se necesitan para los algoritmos de uniones e intersecciones. 
        Lista_Pos aux_2; 
        Algoritmos_Pos misAlgoritmosPos;
        Algoritmos_Index misAlgoritmosInd;
        Algoritmos_Ordenada misAlgoritmosOrd; 

    public: 
        Interfaz();
        void menu();
        void escogioListaOrdenada(Lista_Ord&, int);
        void escogioListaIndexada(Lista_Index&);
        void escogioListaPosicionada();
        ~Interfaz();
        
        
        void insertarPosicion(int indice, int valor, Lista_Pos* lista); 
        void borrarPosicion(int indice, Lista_Pos* lista); 						 
        void modificarPosicion(int indice, int valor, Lista_Pos* lista);			
        int recuperarPosicion(int indice, Lista_Pos* lista);	
        int siguientePosicion(int indice, Lista_Pos* lista); 		
        int anteriorPosicion(int indice, Lista_Pos* lista); 
        int primeraPosicion(Lista_Pos* lista); 
        int ultimaPosicion(Lista_Pos* lista); 
        void iniciarLista(Lista_Pos* lista); 
        void vaciarLista(Lista_Pos* lista); 
        void destruirLista(Lista_Pos* lista); 
        string imprimirLista(Lista_Pos* lista); 
        void agregarPosicionAlFinal(int valor, Lista_Pos* lista); 
};
#endif
