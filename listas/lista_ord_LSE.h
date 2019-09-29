#ifndef LISTAORDENADALSE
#define LISTAORDENADALSE
#include <iostream>
#include <algorithm>
#include <array>

class ListaOrdenadaLSE{
    
    class Elemento;
    
        private:
        
        int numElem;
        int M;//tamaño maximo 
        Elemento * lista;

        class Elemento{
            public:
                int elemento;
                Elemento * siguiente;
        };

    public:
        ListaOrdenadaLSE();
        ~ListaOrdenadaLSE();
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
