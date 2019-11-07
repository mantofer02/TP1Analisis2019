#include "algoritmos_lista_index.h"
#include "algoritmos_lista_pos.h"
#include <array>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

#define MUESTRA 100 // Espacio Muestral de listas
//#define SIZELISTAS 10

//Esta constante hay que estar cambiandola, probando listas pequeñas, medias, grandes, etc ..
// #define SIZELISTAS 500
// #define SIZELISTAS 1000
//#define SIZELISTAS 5000
 #define SIZELISTAS 10000

// #define SIZELISTA 1000000			//solo funciona con mergesort, los demas demoran demasiado. 

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
        void destruirListasPos();
        void destruirListasIndex();
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


														//LISTA DOBLEMENTE ENLAZADA (LDE)
  
  
  //MERGESORT--------------------------------------------------------------------------------------------------------------------------------------------
  //PRUEBA 1
  //mergeSort con longitud = 1 000 000 	y 100 permutaciones de la lista //la lista comienza ordenada y se va desordenando en cada permutacion. 
  //promedio = 2.11405 sec 	tiempo total = 211.405 sec
  //PRUEBA 2
  //mergeSort con longitud 1 000 000 y 10000 permutaciones de la lista 	//la lista comienza ordenada, DURA DEMASIADO, SE CANCELO EL PROCESO. 
  //promedio inventado = 2.4354 sec tiempo total = da igual esto no lo piden. 
  //PRUEBA 3
  //mergeSort con longitud 1 000 000, lista generada aleatoriamente con numeros en el rango de [0,10000] y 100 permutaciones. 
  //prmedio = 2.24048 sec tiempo total = 224.048
  
  //PRUEBA 2 FUE DIFICIL DE HACER CON UNA LISTA TAN GRANDE PORQUE DURA DEMASIADA, PERO DADO QUE PRUEBA 1 Y PRUEBA 3 DURAN TIEMPOS SIMILARES
  //UNA COMIENZA CON LA LISTA ORDENADA Y LA OTRA DESORDENADA ALEATORIAMENTE, SE PUEDE CONCLUIR QUE SI SE ESPERARA A QUE FINALIZARA, LA PRUEBA 2 PROBABLEMENTE 
  //GENERE UN PROMEDIO SIMILAR DE 2 sec ENTONCES VOY A INVENTARME UN PROMEDIO Y VOY A DECIR QUE DURO ESO XD. 
  //---------------------------------------------------------------------------------------------------------------------------------------------------------  
  
  
  //BURBUJA
  //PRUEBA 1
  //burbuja con longitud = 1 000 000 y 100 permutaciones de la lista // la lista comienza ordenada y se permuta, DURA DEMASIADO
  //burbuja con longitud = 10 000 y 100 permutaciones de la lista // la lista comienzo ordenada y se va desordenando en cada permutacion. 
  //promedio = 2.67589 sec	tiempo total = 267.589 sec (con 10 mil elementos dura similar a mergesort con 1 millon de elementos)
   
  
  //BURBUJA BIDIRECCIONAL
  //PRUEBA 1 
  //bidirecional con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza ordenada y se va desordenando en cada permutacion. 
  //promedio = 	1.13359 sec tiempo total = 113.359 (mucho mas rapido que burbuja)
  //PRUEBA 2 
  //bidireccional con longitud = 100 000 y 100 permutaciones de la lista // la lista comienza ordenada y se va desordenando en cada permutacion. 
  //IGUALMENTE TARDA MUCHO, CRECE EXPONENCIALMENTE EL TIEMPO DE ACUERDO A LA N. 
  //PRUEBA 3 
  //bidireccional con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza desordenada aleatoriamente en un rango de [0,10000] y 100 permutaciones.  
  //promedio = 1.68726 sec tiempo total =   168.726 
  
  //SELECCION 
  //PRUEBA 1
  //seleccion con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza ordenada y se va desordenando en cada permutacion 
  //promedio = 0.839724 sec tiempo total = 83.9724 
  //PRUEBA 2 
  //seleccion con longitud = 10 000 y 1000 permutaciones de la lista // la lista comienza ordenada y se va desordenando en cada permutacion 
  //promedio = 0.839401 sec tiempo total = 839.4011 (indiferentemente de las permutaciones, osea que tan ordenado o desordenada esta, da tiempo similar)
  
  
  //SELECCION RECURSIVO 
  //PRUEBA 1 
  //selecionR con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza ordenada y se va desordenando en cada permutacion. 
  //promedio = 0.810478 sec tiempo total = 81.0478
  //PRUEBA 2 
  //seleccion R con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza desordenada aleatoriamente en un rango de [0, 10000]
  //promedio = 0.811981 sec tiempo total = 81.1981
  
  //INSERSION 
  //PRUEBA 1 
  //insercion con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza ordenada y se va desordenando en cada permutacion. 
  //promedio = 0.813837 sec	tiempo total = 81.3837 sec
  //PRUEBA 2  
  //insercion con longitud = 10 000 y 100 permutaciones de la lista // la lista comienza desordenada aleatoriamente en un rango de [0, 10000]
  //promedio = 1.1372 sec  tiempo total = 113.72 sec (si se nota una diferencia con respecto a la prueba 1, a diferencia de seleccion)
  //insercion con longitud = 10 000 y 1000 permutaciones de la lista // la lista comienza desordenada aleatoriamente en un rango de [0, 10000]
  //promedio = 1.14265 sec tiempo total = 1142.65 sec (se conporta similar a 100 permutaciones)
  
  
  //INVERTIR (UTILIZA EL O.B ANTERIOR) se puede comparar con la LSE. 
  //PRUEBA 1 
  //invertir con longitud de = 1 000 000 y 100 permutaciones (las permutaciones son indiferentes, solo se hicieron para sacar un promedio)
  //promedio = 0.0213121 sec tiempo total = 2.13121 sec //las permutaciones no cambian nada, solo se realizo esta prueba. 
  
  
  
  
  
  
  
  
  
													//LISTA SIMPLEMENTE ENLAZADA (LSE)
													
	//INVERITR
	//PRUEBA 1 
	//invertir con longitud = 10 000 y 100 permutaciones
	//promedio = 0.189947 sec (con 10 mil elementos da un tiempo muy similar a la LDE con 1 millon de elementos)
	//invertir con longitud = 100 000 y 100 permutaciones 
	//promedio = 19.2769 sec (comienza a durar tiempos altos y ni siquiera se acerca al millon de elementos)
	//invertir con longitud = 1 000 000 y 100 permutaciones (DURA DEMASIADO, YA HABIA PASADO COMO MEDIA HORA Y NADA)



