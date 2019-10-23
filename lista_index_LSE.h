#ifndef Lista_Index_Indexada_Mia2
#define Lista_Index_Indexada_Mia2
#include <iostream>

// PREGUNTAR SI LOS INDICES PUEDEN NO ESTAR SECUENCIALES 2 4 6 7 12 

class Lista_Index{
    private:
        struct Celda{
            Celda(int,int);
            int indice;
            int elemento;
            Celda* siguiente;
            ~Celda();
        };
        Celda* inicio;
        int contador;
    public:
        Lista_Index();
        void iniciar();
        //void iniciar(int); 
        void vaciar();
        bool vacia();
        void destruir();
        //~Lista_Index();
        void agregar(int, int);
        void borrar(int);
        int recuperar(int);
        void modificar(int, int);
        void intercambiar(int indice1, int indice2);
        int numElem();
        void imprimirLista();
        int primerIndice();
        int ultimoIndice();
};
#endif