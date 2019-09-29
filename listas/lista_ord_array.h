#ifndef LISTAORDENADAARRAY
#define LISTAORDENADAARRAY
#include <iostream>
#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

class ListaOrdenadaArray{
    private:
        int tamanoMaximo;
        int numeroElementos;
        int* array;
    public:
        ListaOrdenadaArray();
        ~ListaOrdenadaArray();
        void iniciar(int);
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
        void imprimir();
};

#endif
