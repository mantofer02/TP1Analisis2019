#ifndef ALGORITMO2
#define ALGORITMO2

#include "lista_index_array.h"

// #include "lista_index_LSE.h"

class Algoritmos_Index{
    private:
      // Ya tiene que venir inicializada
      Lista_Index lista; 
   public:
      Algoritmos_Index(Lista_Index);
      int simetrica(Lista_Index); // Se pueden cambiar las firmas y hacerlo por omision, pero hay que ver si se puede quitar
      void invertir(Lista_Index); //Ver si tiene que devolver una lista nueva o modifica la misma
      int buscar(Lista_Index, int);
      void eliminarRepetidos(Lista_Index);  // Falta
      void burbuja(Lista_Index);
      void seleccion(Lista_Index);
      void seleccionRecursivo(Lista_Index, int);
      Lista_Index mergeSort(Lista_Index);
      Lista_Index merge(Lista_Index, Lista_Index);
};
#endif