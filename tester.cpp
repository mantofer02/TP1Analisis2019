#include "tester.h"

Tester :: Tester(){
    srand(time(NULL));
  
<<<<<<< HEAD
    setListasIndex();
//    setListasPos();
    
    testBurbuja();
=======
    //setListasIndex();
     setListasPos();		//ya funciona setListaPos
     
	std::cout << "ya se inicializo todo" << std::endl; 
    
     testBurbuja();

    // destruirListasIndex();
    // destruirListasPos();
>>>>>>> f0aae051b8fd4d7b8880c9041a4c471692e965fe
    
    setListasIndex();
    //setListasPos();
    
    testInsercion();
    
    setListasIndex();
    //setListasPos();
    
<<<<<<< HEAD
    testSeleccion();
    
    setListasIndex();
=======
   //testSeleccion();
    
    //destruirListasIndex();
    // destruirListasPos();

    //setListasIndex();
>>>>>>> f0aae051b8fd4d7b8880c9041a4c471692e965fe
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
	
    listaPosPerfecta.iniciar();		//iniciar no recibe parametro. 
    listaPosMala.iniciar();
    for(int i = 1; i <= SIZELISTAS; i++){
<<<<<<< HEAD
        listaPosPerfecta.agregarAlFinal(i);// ESTO ESTÁ MAL, MARCO DICE CAMBIAR CONSTRUCTOR
        listaPosMala.agregarAlFinal(SIZELISTAS - i);
=======
        listaPosPerfecta.agregarAlFinal(i);// mejor tipo de entrada
        //std::cout << "LLEGO ACA" << endl;
        listaPosMala.agregarAlFinal(SIZELISTAS - i);	//peor tipo de entrada. 
        //std::cout << "LLEGO ACA" << endl;    
>>>>>>> f0aae051b8fd4d7b8880c9041a4c471692e965fe
    }
    
    int numero = 0;
<<<<<<< HEAD
=======
    //std::cout << "LLEGO ACA" << endl;
>>>>>>> f0aae051b8fd4d7b8880c9041a4c471692e965fe
    for(int j = 0; j < MUESTRA; j++){
        vectorPos[j].iniciar();
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
    double elapsed_seconds = 0.0; 
    
    #if 0 					//el compilador se brinca el codigo, solo cambiar 0 por 1. 
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    misAlgoritmosIndex.burbuja(listaIndexPerfecta);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de burbuja con la mejor lista es indexada: " << elapsed_seconds << " s." <<endl;

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    misAlgoritmosIndex.burbuja(listaIndexMala);

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de burbuja con la peor lista indexada es: " << elapsed_seconds << " s." <<endl;

    /* En este for se mide los tiempos de cada lista aleatoria*/
    elapsed_seconds = 0.0; 
    for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);

        misAlgoritmosIndex.burbuja(vectorIndex[i]);

        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec + 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
        std::cout << "listas ordenadas : " << i << std::endl; 

    }
    elapsed_seconds/=(double)MUESTRA;    
    std::cout << "El tiempo de duración promedio de burbuja con listas indexadas aleatorias es: " << elapsed_seconds << " s." << endl;

    /* TERMINA PRUEBAS INDEX*/
    #endif 
    
    
    #if 1			
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    misAlgoritmosPos.burbuja(listaPosPerfecta);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de burbuja con la mejor lista posicionada es: " << elapsed_seconds << " s." <<endl;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    misAlgoritmosPos.burbuja(listaPosMala);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de burbuja con la peor lista posicionada es: " << elapsed_seconds << " s." <<endl;


<<<<<<< HEAD
    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //   misAlgoritmosPos.burbuja(vectorPos[i]);
    
        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    }
    elapsed_seconds/=(double)MUESTRA;    
    std::cout << "El tiempo de duración promedio de burbuja con listas posicionadas aleatorias es: " << elapsed_seconds << " s." << endl;
=======
     //En este for se mide los tiempos de cada lista aleatoria*/
     elapsed_seconds = 0.0; 
    for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);
    
        misAlgoritmosPos.burbuja(vectorPos[i]);
    
        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
        std::cout << "listas ordenadas : " << i << std::endl; 
    }
    elapsed_seconds/=(double)MUESTRA;    
    std::cout << "El tiempo de duración promedio de burbuja con listas posicionadas aleatorias es: " << elapsed_seconds << " s." << endl;


	#endif
>>>>>>> f0aae051b8fd4d7b8880c9041a4c471692e965fe

}

void Tester :: testInsercion(){
	
	#if 0
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
	#endif
	
	#if 0 

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //misAlgoritmosPos.insercion(listaPosPerfecta);
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de insercion con la mejor lista posicionada es : " << elapsed_seconds << " s." <<endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //misAlgoritmosPos.insercion(listaPosMala);

<<<<<<< HEAD
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
    
=======
    // /* En este for se mide los tiempos de cada lista aleatoria*/
    // for(int i = 0; i < MUESTRA; i++){
    //     misAlgoritmosPos.insercion(vectorPos[i]);
    // }
    
    #endif
>>>>>>> f0aae051b8fd4d7b8880c9041a4c471692e965fe
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

<<<<<<< HEAD
    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    //    misAlgoritmosPos.mergeSort(vectorPos[i]);
    
        clock_gettime(CLOCK_MONOTONIC, &finish_time);
        elapsed_seconds += finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    }
    elapsed_seconds/=MUESTRA;
    std::cout << "El tiempo de duración promedio de mergesort con lista indexadas aleatorias es : " << elapsed_seconds << " s." <<endl;

=======
    // /* En este for se mide los tiempos de cada lista aleatoria*/
    // for(int i = 0; i < MUESTRA; i++){
    //     misAlgoritmosPos.mergeSort(vectorPos[i]);
    // }
>>>>>>> f0aae051b8fd4d7b8880c9041a4c471692e965fe
}
