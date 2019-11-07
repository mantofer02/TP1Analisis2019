#include "algoritmos_lista_index.h"
#include "algoritmos_lista_pos.h"
#include <array>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

#define MUESTRA 100 // Espacio Muestral de listas
#define SIZELISTAS 100

//Esta constante hay que estar cambiandola, probando listas pequeñas, medias, grandes, etc ..
// #define SIZELISTAS 500
// #define SIZELISTAS 1000
// #define SIZELISTAS 5000
// #define SIZELISTAS 10000

class Tester{
    private:
        array<Lista_Pos, MUESTRA> vectorPos;
        Lista_Pos listaPosPerfecta;
        Lista_Pos listaPosMala;
        array<Lista_Index, MUESTRA> vectorIndex;
        Lista_Index listaIndexPerfecta;
        Lista_Index listaIndexMala;
        Algoritmos_Index misAlgoritmosIndex;
        Algoritmos_Pos misAlgoritmosPos;
    public:
        Tester();
        void setListasPos();
        void setListasIndex();
        void testBurbuja();
        void testInsercion();
        void testSeleccion();
        void testSeleccionR();
        void testQuickSort();
        void testMergeSort();
};

/*
    void burbuja(Lista_Pos &lista);
    void insercion(Lista_Pos &lista); 
    void seleccion(Lista_Pos &lista);
     void mergeSort(Lista_Index &lista);
    void seleccionRecursivo(Lista_Pos &lista, Pos pos);
    void quickSort(Lista_Pos &lista);
*/


