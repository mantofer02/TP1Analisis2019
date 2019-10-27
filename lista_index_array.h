#ifndef Lista_Index_Indexada_Mia
#define Lista_Index_Indexada_Mia

#include <iostream>

class Lista_Index{
    public:
        Lista_Index();
        void iniciar();
        void iniciar(int); 
        // hacer un iniciar con una firma diferente
        void vaciar();
        int vacia();
        void destruir();
        ~Lista_Index();
        void agregar(int);
        void borrar(int);
        int recuperar(int);  
        void modificar(int, int);      
        void intercambiar(int indice1, int indice2);
        int numElem();
        void imprimirLista();
        int primerIndice();
        int ultimoIndice();
    
    private:
        int contador;
        int primerIndex;
        int ultimoIndex;
        int tamanyo;
        int* listaIndexada;
        
};
#endif