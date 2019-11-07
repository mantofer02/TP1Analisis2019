#include "tester.h"

tester :: tester(){
    setListasIndex();
    srand(time(NULL));
}

void tester :: setListasIndex(){
    listaIndexPerfecta.iniciar(SIZELISTAS);
    listaIndexMala.iniciar(SIZELISTAS);
    for(int i = 1; i <= SIZELISTAS; i++){
        listaIndexPerfecta.agregarAlFinal(i);
        listaIndexMala.agregarAlInicio(i);
    }
    int numero = 0;
    for(int j = 0; j < MUESTRA; j++){
        for(int k = 0; k < SIZELISTAS; k++){
            numero = rand() % SIZELISTAS + 1;
            vectorIndex[j].agregarAlInicio(numero);
        }
    }
}

void tester :: setListasPos(){
    listaPosPerfecta.iniciar(SIZELISTAS);
    listaPosMala.iniciar(SIZELISTAS);
    for(int i = 1; i <= SIZELISTAS; i++){
        listaPosPerfecta.agregarAlFinal(i);
        listaPosMala.agregarAlFinal(SIZELISTAS - i);
    }
    int numero = 0;
    for(int j = 0; j < MUESTRA; j++){
        for(int k = 0; k < SIZELISTAS; k++){
            numero = rand() % SIZELISTAS + 1;
            vectorPos[j].agregarAlFinal(numero);
        }
    }
}

void tester :: testBurbuja(){
    /* EMPIEZA PRUEBAS INDEX */

    misAlgoritmosIndex.burbuja(listaIndexPerfecta);
    
    misAlgoritmosIndex.burbuja(listaIndexMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        misAlgoritmosIndex.burbuja(vectorIndex[i]);
    }

    /* TERMINA PRUEBAS INDEX*/
} 