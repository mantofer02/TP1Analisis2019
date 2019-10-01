#ifndef Lista_Indexada_Mia
#define Lista_Indexada_Mia
#include <iostream>
#include <algorithm>
#include <array>

class Lista_Indexada_Array{
    public:
        Lista_Indexada_Array();
        void iniciar(int); 
        void vaciar();
        bool vacio();
        void destruir();
        ~Lista_Indexada_Array();
        void insertar(int, int);
        void borrar(int);
        int recuperar(int);
        void modificarElemento(int, int);
        void intercambiar(int indice1, int indice2);
        int numElem();
    private:

        int contador;
        int m;
        int* listaIndexa;
        // No puede ser atributo, necesita tamaño fijo
        //std :: array <int, M> miArray;
};
#endif