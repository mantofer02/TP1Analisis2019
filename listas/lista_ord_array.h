#ifndef LISTAORDENADAARRAY
#define LISTAORDENADAARRAY
#include <iostream>
#include <algorithm>
#include <array>

class ListaOrdenadaArray{
    private:
        int numElem;
        int* array;
    public:
        ListaOrdenadaArray();
        ~ListaOrdenadaArray();
        void iniciar();
        void destruir();
        void vaciar();
        int vacia();
        void agregar(int);
        void borrar(int);
        int primero();
        int ultimo();
        int siguiente(int);
        int anterior(int);
        int numElem();
};

#endif
