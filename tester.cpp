#include "tester.h"

Tester :: Tester(){
    srand(time(NULL));
  
    setListasIndex();
//    setListasPos();
    
    testBurbuja();
    
    //setListasIndex();
    //setListasPos();
    
   // testInsercion();
    
    //setListasIndex();
    //setListasPos();
    
   // testSeleccion();
    
    //setListasIndex();
    //setListasPos();
    
   // testSeleccionR();
    
    //setListasIndex();
   // setListasPos();
    
   // testQuickSort();
    
 //   setListasIndex();
//    setListasPos();
    
//    testMergeSort();
}

void Tester :: setListasIndex(){
    listaIndexPerfecta.iniciar(SIZELISTAS);
    listaIndexMala.iniciar(SIZELISTAS);
    for(int i = 1; i <= SIZELISTAS; i++){
        listaIndexPerfecta.agregarAlFinal(i);
        listaIndexMala.agregarAlInicio(i);
    }
    
    int numero = 0;
    for(int j = 0; j < MUESTRA; j++){
        vectorIndex[j].iniciar();
        for(int k = 0; k < SIZELISTAS; k++){
            numero = rand() % SIZELISTAS + 1;
            vectorIndex[j].agregarAlInicio(numero);
        }
    }
    
}

void Tester :: setListasPos(){
    listaPosPerfecta.iniciar(SIZELISTAS);
    listaPosMala.iniciar(SIZELISTAS);
    for(int i = 1; i <= SIZELISTAS; i++){
        listaPosPerfecta.agregarAlFinal(i);// ESTO ESTÁ MAL, MARCO DICE CAMBIAR CONSTRUCTOR
        std::cout << "LLEGO ACA" << endl;
        listaPosMala.agregarAlFinal(SIZELISTAS - i);
        std::cout << "LLEGO ACA" << endl;    
    }
    int numero = 0;
    std::cout << "LLEGO ACA" << endl;
    for(int j = 0; j < MUESTRA; j++){
        vectorPos[j].iniciar(SIZELISTAS);
        for(int k = 0; k < SIZELISTAS; k++){
            numero = rand() % SIZELISTAS + 1;
            vectorPos[j].agregarAlFinal(numero);
        }
    }
}

void Tester :: testBurbuja(){
    /* EMPIEZA PRUEBAS INDEX */
    struct timespec start_time;
    struct timespec finish_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    misAlgoritmosIndex.burbuja(listaIndexPerfecta);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    double elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de burbuja con la mejor lista es indexada: " << elapsed_seconds << " s." <<endl;

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    misAlgoritmosIndex.burbuja(listaIndexMala);

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de burbuja con la peor lista indexada es: " << elapsed_seconds << " s." <<endl;

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);

        misAlgoritmosIndex.burbuja(vectorIndex[i]);

        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec + 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);

    }
    elapsed_seconds/=(double)MUESTRA;    
    std::cout << "El tiempo de duración promedio de burbuja con listas indexadas aleatorias es: " << elapsed_seconds << " s." << endl;

    /* TERMINA PRUEBAS INDEX*/
    
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
   // misAlgoritmosPos.burbuja(listaPosPerfecta);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de burbuja con la mejor lista posicionada es: " << elapsed_seconds << " s." <<endl;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //misAlgoritmosPos.burbuja(listaPosMala);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de burbuja con la peor lista posicionada es: " << elapsed_seconds << " s." <<endl;


    /* En este for se mide los tiempos de cada lista aleatoria*/
    //for(int i = 0; i < MUESTRA; i++){
    //    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
     //   misAlgoritmosPos.burbuja(vectorPos[i]);
    
    //    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    //    elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    //}
    //elapsed_seconds/=(double)MUESTRA;    
    //std::cout << "El tiempo de duración promedio de burbuja con listas posicionadas aleatorias es: " << elapsed_seconds << " s." << endl;

}

void Tester :: testInsercion(){
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

void Tester :: testSeleccion(){
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

void Tester :: testSeleccionR(){
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

void Tester :: testQuickSort(){
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

void Tester :: testMergeSort(){
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