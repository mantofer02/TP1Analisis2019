#ifndef Lista_Indexida
#define Lista_Indexida
#include <iostream>
#include <algorithm>
#include <array>

// Se planea Emplantillar

class Lista_Indexada_Array{
    public:
        Lista_Indexada_Array();
        void Iniciar(int M); 
        void Vaciar();
        bool Vacio();
        void Destruir();
        ~Lista_Indexada_Array();
        void Insertar();
        void Borrar();
        int Recuperar(int indice);
        void ModificarElemento(int indice, int elemento);
        void Intercambiar(int indice1, int indice2);
        int getNumElem();
    private:
        int numElem;
        static int M;
        // No puede ser atributo, necesita tamaño fijo
        //std :: array <int, M> miArray;
};
#endif