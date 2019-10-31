#ifndef ALGORITMOS_ORDENADA
#define ALGORITMOS_ORDENADA
#include "lista_ord_array.h"
//#include "lista_ord_LSE.h"

class Algoritmos_Ordenada{
    private:
        // Lista_Ord lista;
    public:
        Algoritmos_Ordenada();
        void listar(Lista_Ord &);
        int iguales(Lista_Ord &, Lista_Ord &);
        void copiar(Lista_Ord &, Lista_Ord &);
        int contenida(Lista_Ord &, Lista_Ord &);
        int pertenece(Lista_Ord &, int elemento);
        void eliminarElementosRepetidos(Lista_Ord &l1, Lista_Ord &l2);
        Lista_Ord unionListas(Lista_Ord &l1, Lista_Ord &l2);
        Lista_Ord interseccion(Lista_Ord &l1, Lista_Ord &l2);
};
#endif