#ifndef ALGORITMOS_ORDENADA
#define ALGORITMOS_ORDENADA
#include "lista_ord_array.h"
//#include "lista_ord_LSE.h"

class Algoritmos_Ordenada{
    private:
        Lista_Ord lista;
    public:
        Algoritmos_Ordenada(Lista_Ord &);
        void listar();
        int iguales(Lista_Ord &);
        void copiar(Lista_Ord &);
        int contenida(Lista_Ord &);
        int pertenece(int elemento);
        void eliminarElementosRepetidos(Lista_Ord &);
        Lista_Ord unionListas(Lista_Ord &);
        Lista_Ord interseccion(Lista_Ord &);
};
#endif
