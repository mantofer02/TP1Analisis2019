#include "tester.h"

Tester :: Tester(){
    srand(time(NULL));
  
    setListasIndex();
//    setListasPos();
    
    testBurbuja();
    
    setListasIndex();
    //setListasPos();
    
    testInsercion();
    
    setListasIndex();
    //setListasPos();
    
    testSeleccion();
    
    setListasIndex();
    //setListasPos();
    
    testSeleccionR();
    
    setListasIndex();
    //setListasPos();
    
    testQuickSort();
    
    setListasIndex();
//    setListasPos();
    
    testMergeSort();
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
        listaPosMala.agregarAlFinal(SIZELISTAS - i);
    }
    int numero = 0;
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
    for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //   misAlgoritmosPos.burbuja(vectorPos[i]);
    
        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    }
    elapsed_seconds/=(double)MUESTRA;    
    std::cout << "El tiempo de duración promedio de burbuja con listas posicionadas aleatorias es: " << elapsed_seconds << " s." << endl;

}

void Tester :: testInsercion(){
    /* EMPIEZA PRUEBAS INDEX */
    struct timespec start_time;
    struct timespec finish_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    misAlgoritmosIndex.insercion(listaIndexPerfecta);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    double elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de insercion con la mejor lista indexada es : " << elapsed_seconds << " s." <<endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    misAlgoritmosIndex.insercion(listaIndexMala);

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de insercion con la peor lista indexada es: " << elapsed_seconds << " s." <<endl;
    
    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        
        clock_gettime(CLOCK_MONOTONIC, &start_time);

        misAlgoritmosIndex.insercion(vectorIndex[i]);
    
        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    }
    elapsed_seconds/=MUESTRA;
    std::cout << "El tiempo de duración promedio de insercion con listas indexadas aleatorias es: " << elapsed_seconds << " s." <<endl;

    /* TERMINA PRUEBAS INDEX*/

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //misAlgoritmosPos.insercion(listaPosPerfecta);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de insercion con la mejor lista posicionada es : " << elapsed_seconds << " s." <<endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //misAlgoritmosPos.insercion(listaPosMala);

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de insercion con la peor lista posicionada es : " << elapsed_seconds << " s." <<endl;
    
    
    /* En este for se mide los tiempos de cada lista aleatoria*/
    //for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        //misAlgoritmosPos.insercion(vectorPos[i]);
        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
        //}
    std::cout << "El tiempo de duración de insercion con listas posicionadas aleatorias es: " << elapsed_seconds << " s." <<endl;
    
}

void Tester :: testSeleccion(){
    /* EMPIEZA PRUEBAS INDEX */
    struct timespec start_time;
    struct timespec finish_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    misAlgoritmosIndex.seleccion(listaIndexPerfecta);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    double elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de seleccion con la mejor lista indexada es : " << elapsed_seconds << " s." <<endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    misAlgoritmosIndex.seleccion(listaIndexMala);

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de seleccion con la peor lista indexada es: " << elapsed_seconds << " s." <<endl;
        
    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);

        misAlgoritmosIndex.seleccion(vectorIndex[i]);
    
        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    }
    elapsed_seconds/=MUESTRA;
    std::cout << "El tiempo de duración promedio de seleccion con listas indexadas aleatorias es: " << elapsed_seconds << " s." <<endl;

    /* TERMINA PRUEBAS INDEX*/

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //misAlgoritmosPos.seleccion(listaPosPerfecta);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de seleccion con la mejor lista posicionada es : " << elapsed_seconds << " s." <<endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //misAlgoritmosPos.seleccion(listaPosMala);

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de seleccion con la peor lista posicionada es : " << elapsed_seconds << " s." <<endl;
        
    /* En este for se mide los tiempos de cada lista aleatoria*/
    //for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        //misAlgoritmosPos.seleccion(vectorPos[i]);
        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    //}
    std::cout << "El tiempo de duración promedio de seleccion con listas posicionadas aleatorias es: " << elapsed_seconds << " s." <<endl;
}

void Tester :: testSeleccionR(){
    /* EMPIEZA PRUEBAS INDEX */
    struct timespec start_time;
    struct timespec finish_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    misAlgoritmosIndex.seleccionRecursivo(listaIndexPerfecta);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    double elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de seleccion recursivo con la mejor lista indexada es : " << elapsed_seconds << " s." <<endl;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    misAlgoritmosIndex.seleccionRecursivo(listaIndexMala);
        clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de seleccion recursivo con la peor lista indexada es : " << elapsed_seconds << " s." <<endl;

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);
    
        misAlgoritmosIndex.seleccionRecursivo(vectorIndex[i]);

        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    }
    elapsed_seconds/=MUESTRA;
    std::cout << "El tiempo de duración promedio de seleccion recursivo con listas indexadas aleatorias es : " << elapsed_seconds << " s." <<endl;

    /* TERMINA PRUEBAS INDEX*/

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //misAlgoritmosPos.seleccionRecursivo(listaPosPerfecta, listaPosPerfecta.primera());
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de seleccion recursivo con la mejor lista posicinada es : " << elapsed_seconds << " s." <<endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //misAlgoritmosPos.seleccionRecursivo(listaPosMala, listaPosMala.primera());

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de seleccion recursivo con la peor lista posicinada es : " << elapsed_seconds << " s." <<endl;
    
    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);
    
        //misAlgoritmosPos.seleccionRecursivo(vectorPos[i], vectorPos[i].primera());

        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    }
    elapsed_seconds/=MUESTRA;
    std::cout << "El tiempo de duración promedio de seleccion recursivo con listas posicinadas aleatorias es : " << elapsed_seconds << " s." <<endl;
    
}

void Tester :: testQuickSort(){
    /* EMPIEZA PRUEBAS INDEX */
    struct timespec start_time;
    struct timespec finish_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    misAlgoritmosIndex.quickSort(listaIndexPerfecta);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    double elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de quicksort con la mejor lista indexada es : " << elapsed_seconds << " s." <<endl;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    misAlgoritmosIndex.quickSort(listaIndexMala);

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de quicksort con la peor lista indexada es : " << elapsed_seconds << " s." <<endl;

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);
    
        misAlgoritmosIndex.quickSort(vectorIndex[i]);
        
        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    }
    elapsed_seconds/=MUESTRA;
    std::cout << "El tiempo de duración promedio de quicksort con la peor lista indexada es : " << elapsed_seconds << " s." <<endl;

    /* TERMINA PRUEBAS INDEX*/
    
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //misAlgoritmosPos.quickSort(listaPosPerfecta);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de quicksort con la mejor lista posicionada es : " << elapsed_seconds << " s." <<endl;

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    //misAlgoritmosPos.quickSort(listaPosMala);

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de quicksort con la peor lista posicionada es : " << elapsed_seconds << " s." <<endl;

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);

        //misAlgoritmosPos.quickSort(vectorPos[i]);

        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    }
    elapsed_seconds/=MUESTRA;
    std::cout << "El tiempo de duración promedio de quicksort con listas posicionadas aleatorias es : " << elapsed_seconds << " s." <<endl;
    
}

void Tester :: testMergeSort(){
    /* EMPIEZA PRUEBAS INDEX */
    struct timespec start_time;
    struct timespec finish_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    misAlgoritmosIndex.mergeSort(listaIndexPerfecta);

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    double elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de mergesort con la mejor lista indexada es : " << elapsed_seconds << " s." <<endl;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    misAlgoritmosIndex.mergeSort(listaIndexMala);

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de mergesort con la peor lista indexada es : " << elapsed_seconds << " s." <<endl;

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);
    
        misAlgoritmosIndex.mergeSort(vectorIndex[i]);

        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    }
    elapsed_seconds/=MUESTRA;
    std::cout << "El tiempo de duración promedio de mergesort con lista indexadas aleatorias es : " << elapsed_seconds << " s." <<endl;


    /* TERMINA PRUEBAS INDEX*/
    
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //misAlgoritmosPos.mergeSort(listaPosPerfecta);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de mergesort con la mejor lista posicionada es : " << elapsed_seconds << " s." <<endl;
  
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //misAlgoritmosPos.mergeSort(listaPosMala);

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de mergesort con la peor lista posicionada es : " << elapsed_seconds << " s." <<endl;

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //    misAlgoritmosPos.mergeSort(vectorPos[i]);
    
        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    }
    elapsed_seconds/=MUESTRA;
    std::cout << "El tiempo de duración promedio de mergesort con lista indexadas aleatorias es : " << elapsed_seconds << " s." <<endl;

}
