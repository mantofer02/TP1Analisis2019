#ifndef Lista_Index_Indexada_Mia2
#define Lista_Index_Indexada_Mia2
#include <iostream>
#include <algorithm>
#include <array>
#define elemntoNulo -9999999

// PREGUNTAR SI LOS INDICES PUEDEN NO ESTAR SECUENCIALES 2 4 6 7 12 

class Lista_Index{
    private:
        struct Celda{
            Celda(int indice);
            int indice;
            int elemento;
            Celda* siguiente;
            ~Celda();
        };
        Celda* inicio;
        int contador;
        int m;
    public:
        Lista_Index();
        void iniciar(); 
        void vaciar();
        bool vacio();
        void crearCelda(int);
        void destruir();
        ~Lista_Index();
        void agregar(int, int);
        void borrar(int);
        int recuperar(int);
        void modificar(int, int);
        void intercambiar(int indice1, int indice2);
        int numElem();
        void imprimirLista();
};
#endif