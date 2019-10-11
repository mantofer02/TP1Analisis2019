#ifndef ALGORITMO
#define ALGORITMO

#include "lista_pos_Arreglo.h"

// #include "lista_pos_LDE.h"

//#include "lista_pos_LSE.h"

class Algoritmos_Pos{
    private:
      // Ya tiene que venir inicializada
      Lista_Pos lista; 
   public:
      Algoritmos_Pos(Lista_Pos);
      int simetrica(Lista_Pos); // Se pueden cambiar las firmas y hacerlo por omision, pero hay que ver si se puede quitar
        
};
#endif