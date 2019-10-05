#ifndef miInterfazota
#define miInterfazota

#include <iostream>

//#include "lista_index_LSE.h"
 #include "lista_index_array.h"

// #include "lista_pos_Arreglo.h"

#include "lista_ord_array.h"
// #include "lista_ord_LSE.h"


using namespace std;

class Interfaz{
    private:
        int tipoDeLista;
        Lista_Ord miListaOrdena;
        Lista_Index miListaIndex;

    public:
        Interfaz();
        void menu();
        void escogioListaOrdenada();
        void escogioListaIndexada();
};
#endif