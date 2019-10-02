#ifndef LISTAORDENADAARRAY
#define LISTAORDENADAARRAY
#include <iostream>
#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
using namespace std;

class Lista{
    private:
        int tamanoMaximo;
        int numeroElementos;
        int* array;
    public:
        Lista();
        ~Lista();
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
        void imprimirMenu(Lista *);        
};

#endif
