#ifndef Lista_Index_Indexada_Mia
#define Lista_Index_Indexada_Mia
#include <iostream>
#include <algorithm>
#include <array>
#define elementoNulo -99999

class Lista_Index{
    public:
        Lista_Index();
        void iniciar(int); 
        void vaciar();
        bool vacio();
        void destruir();
        ~Lista_Index();
        void insertar(int, int);
        // void insertar(int*);
        void borrar(int);
        // void borrar(int*);
        int recuperar(int);
        // int recuperar(int*);
        void modificarElemento(int, int);
        // void modificarElemento(int*);
        void intercambiar(int indice1, int indice2);
        // void intercambiar(int*);
        int numElem();
        void imprimirLista_Index();
    
    private:
        int contador;
        int m;
        int* listaIndexa;
        // No puede ser atributo, necesita tamaño fijo
        //std :: array <int, M> miArray;
};
#endif