#ifndef miInterfaz1
#define miInterfaz2

#include <iostream>

// #include "lista_index_LSE.h"
 #include "lista_index_array.h"
// #include "lista_pos_Arreglo.h"

#include "lista_ord_array.h"
// #include "lista_ord_LSE.h"

// #include "lista_pos_Arreglo.h"
// #include "lista_pos_LSE.h"
#include "lista_pos_LDE.h"

#include "algoritmos_lista_pos.h"



using namespace std;

class Interfaz{
    private:
        int tipoDeLista;
        Lista_Ord miListaOrdena;
        Lista_Index miListaIndex;
        Lista_Pos miListaPos; 
		Algoritmos_Pos algoritmos; 

    public: 
        Interfaz();
        void menu();
        void escogioListaOrdenada();
        void escogioListaIndexada();
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
