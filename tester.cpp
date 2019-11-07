#include "tester.h"

tester :: tester(){
    setListasIndex();
    srand(time(NULL));
    
    setListasIndex();
    setListasPos();
    
    testBurbuja();
    
    setListasIndex();
    setListasPos();
    
    testInsercion();
    
    setListasIndex();
    setListasPos();
    
    testSeleccion();
    
    setListasIndex();
    setListasPos();
    
    testSeleccionR();
    
    setListasIndex();
    setListasPos();
    
    testQuickSort();
    
    setListasIndex();
    setListasPos();
    
    testMergeSort();
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

    misAlgoritmosPos.burbuja(listaPosPerfecta);
    misAlgoritmosPos.burbuja(listaPosMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        misAlgoritmosPos.burbuja(vectorPos[i]);
    }
}

void tester :: testInsercion(){
    /* EMPIEZA PRUEBAS INDEX */

    misAlgoritmosIndex.insercion(listaIndexPerfecta);
    misAlgoritmosIndex.insercion(listaIndexMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        misAlgoritmosIndex.insercion(vectorIndex[i]);
    }

    /* TERMINA PRUEBAS INDEX*/

    misAlgoritmosPos.insercion(listaPosPerfecta);
    misAlgoritmosPos.insercion(listaPosMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        misAlgoritmosPos.insercion(vectorPos[i]);
    }
}

void tester :: testSeleccion(){
    /* EMPIEZA PRUEBAS INDEX */

    misAlgoritmosIndex.seleccion(listaIndexPerfecta);
    misAlgoritmosIndex.seleccion(listaIndexMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        misAlgoritmosIndex.seleccion(vectorIndex[i]);
    }

    /* TERMINA PRUEBAS INDEX*/

    misAlgoritmosPos.seleccion(listaPosPerfecta);
    misAlgoritmosPos.seleccion(listaPosMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        misAlgoritmosPos.seleccion(vectorPos[i]);
    }
}

void tester :: testSeleccionR(){
    /* EMPIEZA PRUEBAS INDEX */

    misAlgoritmosIndex.seleccionRecursivo(listaIndexPerfecta);
    misAlgoritmosIndex.seleccionRecursivo(listaIndexMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        misAlgoritmosIndex.seleccionRecursivo(vectorIndex[i]);
    }

    /* TERMINA PRUEBAS INDEX*/

    misAlgoritmosPos.seleccionRecursivo(listaPosPerfecta, listaPosPerfecta.primera());
    misAlgoritmosPos.seleccionRecursivo(listaPosMala, listaPosMala.primera());

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        misAlgoritmosPos.seleccionRecursivo(vectorPos[i], vectorPos[i].primera());
    }
}

void tester :: testQuickSort(){
    /* EMPIEZA PRUEBAS INDEX */

    misAlgoritmosIndex.quickSort(listaIndexPerfecta);
    misAlgoritmosIndex.quickSort(listaIndexMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        misAlgoritmosIndex.quickSort(vectorIndex[i]);
    }

    /* TERMINA PRUEBAS INDEX*/

    misAlgoritmosPos.quickSort(listaPosPerfecta);
    misAlgoritmosPos.quickSort(listaPosMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        misAlgoritmosPos.quickSort(vectorPos[i]);
    }
}

void tester :: testMergeSort(){
    /* EMPIEZA PRUEBAS INDEX */

    misAlgoritmosIndex.mergeSort(listaIndexPerfecta);
    misAlgoritmosIndex.mergeSort(listaIndexMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        misAlgoritmosIndex.mergeSort(vectorIndex[i]);
    }

    /* TERMINA PRUEBAS INDEX*/

    misAlgoritmosPos.mergeSort(listaPosPerfecta);
    misAlgoritmosPos.mergeSort(listaPosMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        misAlgoritmosPos.mergeSort(vectorPos[i]);
    }
}