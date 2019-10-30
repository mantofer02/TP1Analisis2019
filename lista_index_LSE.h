#ifndef Lista_Index_Indexada_Mia2
#define Lista_Index_Indexada_Mia2

#include <iostream>

class Lista_Index{
    
    private:
        struct Celda{
            Celda(int);
            Celda * siguiente;
            ~Celda();
            int elemento;
        };
        int contador;
        int primerIndex;
        int ultimoIndex;
        Celda * primera;
        Celda * ultima;
    public:
        Lista_Index();
        void iniciar();
        void vaciar();
        int vacia();
        void destruir();
        ~Lista_Index();
        void agregarAlFinal(int);
        void agregarAlInicio(int);
        void agregar(int, int);
        void borrar(int);
        int recuperar(int);  
        void modificar(int, int);      
        void intercambiar(int indice1, int indice2);
        int numElem();
        void imprimirLista();
        int primerIndice();
        int ultimoIndice();
        int siguiente(int);
        int anterior(int);
    
        
};
#endif