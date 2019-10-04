#ifndef Lista_Indexada_Mia
#define Lista_Indexada_Mia
#include <iostream>
#include <algorithm>
#include <array>
#define elementoNulo -99999

class Lista{
    public:
        Lista();
        void iniciar(int); 
        void vaciar();
        bool vacio();
        void destruir();
        ~Lista();
        void insertar(int, int);
        void borrar(int);
        int recuperar(int);
        void modificarElemento(int, int);
        void intercambiar(int indice1, int indice2);
        int numElem();
        void imprimirLista();
    
    private:
        int contador;
        int m;
        int* listaIndexa;
        // No puede ser atributo, necesita tamaño fijo
        //std :: array <int, M> miArray;
};
#endif