#ifndef Lista_Index_Indexada_Mia
#define Lista_Index_Indexada_Mia
#include <iostream>
#include <algorithm>
#include <array>
#define elementoNulo -99999

class Lista_Index{
    public:
        Lista_Index();
        void iniciar(); 
        // hacer un iniciar con una firma diferente
        void vaciar();
        bool vacia();
        void destruir();
        ~Lista_Index();
        void agregar(int, int);
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