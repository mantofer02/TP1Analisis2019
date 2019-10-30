#ifndef ALGORITMO2
#define ALGORITMO2

#include "lista_index_array.h"

// #include "lista_index_LSE.h"

class Algoritmos_Index{
    private:
      // Ya tiene que venir inicializada
      Lista_Index lista; 
   public:
      Algoritmos_Index(Lista_Index &lista);
      int simetrica(Lista_Index &lista); // Se pueden cambiar las firmas y hacerlo por omision, pero hay que ver si se puede quitar
      void invertir(Lista_Index &lista); //Ver si tiene que devolver una lista nueva o modifica la misma
      int buscar(Lista_Index &lista, int);
      void eliminarRepetidos(Lista_Index &lista);  // Falta
      void burbuja(Lista_Index &lista);
      void seleccion(Lista_Index &lista);
      void listar(Lista_Index &lista);
      void seleccionRecursivo(Lista_Index &lista);
      void seleccionRecursivo(Lista_Index &lista, int);	//que diferencia hay ? 
      Lista_Index mergeSort(Lista_Index &lista);
      Lista_Index merge(Lista_Index &lista1, Lista_Index &lista2);
      void insercion(Lista_Index &lista); 
      void quickSort(Lista_Index &lista); 
      void quickSortRecursivo(Lista_Index &lista);
      int buscarPivote(Lista_Inde&lista, int low, int high);
      void unionNoOrdenada(Lista_Index&l1, Lista_Index&l2);
      void interseccion(Lista_Index &l1, Lista_Index &l2, Lista_Index &l3); 
      void interseccionOrdenada_v1(Lista_Index &l1, Lista_Index &l2,Lista_Index &l3); 
      void interseccionOrdenada_v2(Lista_Index &l1, Lista_Index &l2, Lista_Index &l3);    
};
#endif
