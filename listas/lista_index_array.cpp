#include "lista_index_array.h"

        Lista_Indexada_Array::Lista_Indexada_Array(){
            this->m = 0;
        }

        void Lista_Indexada_Array::iniciar(int m){
            this->m = m;
            listaIndexa = new int[m];
            contador = 0;
        }

        void Lista_Indexada_Array::vaciar(){
            for(int i = 0; i < m; i++)
                borrar(i);
        }

        bool Lista_Indexada_Array::vacio(){
            bool estaVacio = false;
            if(contador == 0)
                estaVacio = true;
            return estaVacio;
        }

        void Lista_Indexada_Array::destruir(){
            delete[] listaIndexa;
            contador = 0;
            
        }
        
        Lista_Indexada_Array :: ~Lista_Indexada_Array(){
            delete[] listaIndexa;
        }

        void Lista_Indexada_Array::insertar(int indice, int elemento){
            if(indice < m)
                listaIndexa[indice] = elemento;
                contador++;
        }

        void Lista_Indexada_Array::borrar(int indice){
            if(indice < m)
                listaIndexa[indice] = 0;
                contador--;
        }

        int Lista_Indexada_Array::recuperar(int indice){
            int elementoAdevolver = 0;
            if(indice < m)
                elementoAdevolver = listaIndexa[indice];
            return elementoAdevolver;
        }

        void Lista_Indexada_Array::modificarElemento(int indice, int elemento){
            if(indice < m)
                listaIndexa[indice] = elemento;
        }

        void Lista_Indexada_Array::intercambiar(int indice1, int indice2){
            int elementoAux = 0;
            if(indice1, indice2 < m){
                elementoAux = listaIndexa[indice1];
                listaIndexa[indice1] = listaIndexa[indice2];
                listaIndexa[indice2] = elementoAux;
            }
        }
        int Lista_Indexada_Array::numElem(){
            return contador;
        }
        // No puede ser atributo, necesita tamaño fijo
        //std :: array <int, M> miArray;