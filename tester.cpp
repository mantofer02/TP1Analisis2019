#include "tester.h"

Tester :: Tester(){
    srand(time(NULL));
  
    //setListasIndex();
     setListasPos();		//ya funciona setListaPos
     
	std::cout << "ya se inicializo todo" << std::endl; 
    
     testBurbuja();

    // destruirListasIndex();
    // destruirListasPos();
    
    //setListasIndex();
    //setListasPos();
    
   // testInsercion();
    
    // destruirListasIndex();
    // destruirListasPos();

    //setListasIndex();
    //setListasPos();
    
   //testSeleccion();
    
    //destruirListasIndex();
    // destruirListasPos();

    //setListasIndex();
    //setListasPos();
    
//    testSeleccionR();
    
    // destruirListasIndex();
    // destruirListasPos();

    //setListasIndex();
   // setListasPos();
    
    // destruirListasIndex();
    // destruirListasPos();

//    testQuickSort();
    
    // destruirListasIndex();
    // destruirListasPos();

    //setListasIndex();
    //setListasPos();
    
    // testMergeSort();

    // destruirListasIndex();
    // destruirListasPos();

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

void Tester :: destruirListasIndex(){
    listaIndexPerfecta.destruir();
    listaIndexMala.destruir();
    for(int j = 0; j < MUESTRA; j++){
        vectorIndex[j].destruir();
    }
}


void Tester :: destruirListasPos(){
    listaPosPerfecta.destruir();
    listaPosMala.destruir();
    for(int j = 0; j < MUESTRA; j++){
        vectorPos[j].destruir();
    }
}

void Tester :: setListasPos(){
	
    listaPosPerfecta.iniciar();		//iniciar no recibe parametro. 
    listaPosMala.iniciar();
    for(int i = 1; i <= SIZELISTAS; i++){
        listaPosPerfecta.agregarAlFinal(i);// mejor tipo de entrada
        //std::cout << "LLEGO ACA" << endl;
        listaPosMala.agregarAlFinal(SIZELISTAS - i);	//peor tipo de entrada. 
        //std::cout << "LLEGO ACA" << endl;    
    }
    
    int numero = 0;
    //std::cout << "LLEGO ACA" << endl;
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

}

void Tester :: testInsercion(){
	
	#if 0
    /* EMPIEZA PRUEBAS INDEX */

    misAlgoritmosIndex.insercion(listaIndexPerfecta);
    misAlgoritmosIndex.insercion(listaIndexMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    for(int i = 0; i < MUESTRA; i++){
        misAlgoritmosIndex.insercion(vectorIndex[i]);
    }

    /* TERMINA PRUEBAS INDEX*/
	#endif
	
	#if 0 

    // misAlgoritmosPos.insercion(listaPosPerfecta);
    // misAlgoritmosPos.insercion(listaPosMala);

    // /* En este for se mide los tiempos de cada lista aleatoria*/
    // for(int i = 0; i < MUESTRA; i++){
    //     misAlgoritmosPos.insercion(vectorPos[i]);
    // }
    
    #endif
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

    // misAlgoritmosPos.seleccion(listaPosPerfecta);
    // misAlgoritmosPos.seleccion(listaPosMala);

    // /* En este for se mide los tiempos de cada lista aleatoria*/
    // for(int i = 0; i < MUESTRA; i++){
    //     misAlgoritmosPos.seleccion(vectorPos[i]);
    // }
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

    // misAlgoritmosPos.seleccionRecursivo(listaPosPerfecta, listaPosPerfecta.primera());
    // misAlgoritmosPos.seleccionRecursivo(listaPosMala, listaPosMala.primera());

    // /* En este for se mide los tiempos de cada lista aleatoria*/
    // for(int i = 0; i < MUESTRA; i++){
    //     misAlgoritmosPos.seleccionRecursivo(vectorPos[i], vectorPos[i].primera());
    // }
}

void Tester :: testQuickSort(){
    /* EMPIEZA PRUEBAS INDEX */

    misAlgoritmosIndex.quickSort(listaIndexPerfecta);
    misAlgoritmosIndex.quickSort(listaIndexMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    // for(int i = 0; i < MUESTRA; i++){
    //     misAlgoritmosIndex.quickSort(vectorIndex[i]);
    // }

    /* TERMINA PRUEBAS INDEX*/

    // misAlgoritmosPos.quickSort(listaPosPerfecta);
    // misAlgoritmosPos.quickSort(listaPosMala);

    // /* En este for se mide los tiempos de cada lista aleatoria*/
    // for(int i = 0; i < MUESTRA; i++){
    //     misAlgoritmosPos.quickSort(vectorPos[i]);
    // }
}

void Tester :: testMergeSort(){
    /* EMPIEZA PRUEBAS INDEX */

    misAlgoritmosIndex.mergeSort(listaIndexPerfecta);
    misAlgoritmosIndex.mergeSort(listaIndexMala);

    /* En este for se mide los tiempos de cada lista aleatoria*/
    // for(int i = 0; i < MUESTRA; i++){
    //     misAlgoritmosIndex.mergeSort(vectorIndex[i]);
    // }

    /* TERMINA PRUEBAS INDEX*/

    // misAlgoritmosPos.mergeSort(listaPosPerfecta);
    // misAlgoritmosPos.mergeSort(listaPosMala);

    // /* En este for se mide los tiempos de cada lista aleatoria*/
    // for(int i = 0; i < MUESTRA; i++){
    //     misAlgoritmosPos.mergeSort(vectorPos[i]);
    // }
}
