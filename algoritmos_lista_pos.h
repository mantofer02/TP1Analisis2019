#ifndef ALGORITMO
#define ALGORITMO

// #include "lista_pos_Arreglo.h"

#include "lista_pos_LDE.h"

//#include "lista_pos_LSE.h"

class Algoritmos_Pos{
    private:
   //   Lista_Pos lista;		//modifica la misma lista, que se le manda por referencia, no necesita tener la lista como atributo, aunque podría, solo que 
   public:						//crearía una al inicio y luego se remplazaría por otra que tiene la interfaz, y para que.  
	  Algoritmos_Pos(); 		//así todo es void y no hay que retornar nada. 
     // Algoritmos_Pos(Lista_Pos &lista);
      int simetrica(Lista_Pos &lista); 
      void invertir(Lista_Pos &lista); 
      int buscar(Lista_Pos &lista, int elemento);
      void eliminarRepetidos(Lista_Pos &lista);  // Falta
      void burbuja(Lista_Pos &lista);
      void insercion(Lista_Pos &lista); 
      void seleccion(Lista_Pos &lista);
      void seleccionRecursivo(Lista_Pos &lista, Pos pos);
      void quickSort(Lista_Pos &lista); 
      void quickSortRecursivo(Lista_Pos &lista, Pos low, Pos high); 
      void quickSort_insercion(Lista_Pos &lista); 
      Pos buscarPivote(Lista_Pos &lista, Pos low, Pos high); 
      void unionOrdenada(Lista_Pos &l1, Lista_Pos &l2); 
      void unionNoOrdenada(Lista_Pos &l1, Lista_Pos &l2); 
      Lista_Pos mergeSort(Lista_Pos &lista);
      Lista_Pos merge(Lista_Pos &, Lista_Pos &);
};
#endif
