#ifndef LISTAORDENADALSE
#define LISTAORDENADALSE
#include <iostream>
#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
using namespace std;

class Lista_Ord{
    
    class Elemento;
    
    private:
        
        int numeroElementos;
        int tamanoMaximo; 
        Elemento * primeraPosicion;
        Elemento * ultimaPosicion;

        class Elemento{
            public:
                int elemento;
                Elemento * siguiente;
                Elemento(int);
                ~Elemento();
                void imprimir();
        };

    public:
        Lista_Ord();
        ~Lista_Ord();
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
        void imprimir();
        void imprimirMenu(Lista_Ord *);
};

#endif
