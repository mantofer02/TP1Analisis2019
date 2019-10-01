#ifndef Lista_Indexada_Mia2
#define Lista_Indexada_Mia2
#include <iostream>
#include <algorithm>
#include <array>
#define indiceNulo -1

// PREGUNTAR SI LOS INDICES PUEDEN NO ESTAR SECUENCIALES 2 4 6 7 12 

class Lista_Indexada_LSE{
    private:
        struct Celda{
            Celda(int indice);
            void setElemento(int elemento);
            int getElemento();
            int getIndice();
            int indice;
            int elemento;
            Celda* siguiente;
        };
        Celda* inicio;
        int contador;
        int m;
    public:
        Lista_Indexada_LSE();
        void iniciar(int m); 
        void vaciar();
        bool vacio();
        void crearCelda(int);
        void destruir();
        ~Lista_Indexada_LSE();
        void insertar(int, int);
        void borrar(int);
        int recuperar(int);
        void modificarElemento(int, int);
        void intercambiar(int indice1, int indice2);
        int numElem();
};
#endif