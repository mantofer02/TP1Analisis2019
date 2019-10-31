#include "Interfaz.h"

#define OrdenadaA 1
#define OrdenadaB 2
#define Posicionada 3
#define IndexadaA 4
#define IndexadaB 5
#define IndexadaC 6


Interfaz :: Interfaz(){
  //  miListaPos = new Lista_Pos();
    miListaPos.iniciar();
    tipoDeLista = 0;
    std::cout << "Bienvenido " << std::endl;
    menu();
}

void Interfaz :: menu(){
    std::cout << "Digite :" << std::endl;
    std::cout << "1: Si desea el menu de lista OrdenadaA" << std::endl;
    std::cout << "2: Si desea el menu de lista OrdenadaB" << std::endl;
    std::cout << "3: Si desea el menu de lista Posicionada" << std::endl;
	std::cout << "4: Si desea el menu de lista IndexadaA" << std::endl;
	std::cout << "5: Si desea el menu de lista IndexadaB" << std::endl;
	std::cout << "6: Si desea el menu de lista IndexadaC" << std::endl;
    std::cout << "7: Exit" << std::endl;
    std::cin >> tipoDeLista;
    if(tipoDeLista == OrdenadaA)
        std::cout << "---------------------------------------------" << std::endl;
		std::cout << "                LISTA ORDENADA A             " << std::endl;
		escogioListaOrdenada(miListaOrdenadaA);
	if(tipoDeLista == OrdenadaB)
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "                LISTA ORDENADA B             " << std::endl;
		escogioListaOrdenada(miListaOrdenadaB);
    if(tipoDeLista == IndexadaA)
        std::cout << "---------------------------------------------" << std::endl;
		std::cout << "                LISTA INDEXADA A             " << std::endl;
		escogioListaIndexada(miListaIndexA);
	if(tipoDeLista == IndexadaB)
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "                LISTA INDEXADA B             " << std::endl;
        escogioListaIndexada(miListaIndexB);
	if(tipoDeLista == IndexadaC)
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "                LISTA INDEXADA C             " << std::endl;
        escogioListaIndexada(miListaIndexC);
    if(tipoDeLista == Posicionada)
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "                LISTA POSICIONADA A             " << std::endl;
        escogioListaPosicionada();
}

void Interfaz :: escogioListaOrdenada(Lista_Ord miListaOrdena){
    int operacion = 0;
    std::cout << "Menu lista Ordenada" << std::endl;
    std::cout << "1) iniciar();" << std::endl;
    std::cout << "2) destruir();" << std::endl;
    std::cout << "3) vaciar();" << std::endl;
    std::cout << "4) vacia();" << std::endl; 
    std::cout << "5) agregar(int)" << std::endl;
    std::cout << "6) borrar(int)" << std::endl;
    std::cout << "7) primero()" << std::endl;
    std::cout << "8) ultimo()" << std::endl;
    std::cout << "9) siguiente(int)" << std::endl;
    std::cout << "10) anterior(int)" << std::endl;
    std::cout << "11) numElem()" << std::endl;
    std::cout << "12) imprimirLista()" << std::endl;
    std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "         Algoritmos         " << std::endl;
    std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "13) iguales(ListaOrdA, ListaOrdB)" << std::endl;
	std::cout << "14) copiar(lista, laOtraLista)" << std::endl;
	std::cout << "15) contenida(listaActual, laOtraLista)" << std::endl;
	std::cout << "16) pertenece(listaActual, laOtraLista)" << std::endl;
	std::cout << "17) eliminarElementosRepetidos(listaActual, otraLista)" << std::endl;
	std::cout << "18) unionListas(listaActual, laOtraLista)" << std::endl;
	std::cout << "19) interseccion(listaActual, laOtraLista)" << std::endl;
	std::cout << "20) EXIT" << std::endl;
    std::cin >> operacion;
    int parametro = 0;
    switch (operacion){
        case 1:
            std::cout << "Se inicio la lista" << std::endl;
            miListaOrdena.iniciar();
            escogioListaOrdenada(miListaOrdena);
            break;
        case 2:
            std::cout << "Se va a destruir la lista ordenada" << std::endl;
            miListaOrdena.destruir();
            escogioListaOrdenada(miListaOrdena);
            break;
        case 3: 
            std::cout << "Se va a vaciar la lista ordenada" << std::endl;
            miListaOrdena.vaciar();
            escogioListaOrdenada(miListaOrdena);
            break;
        case 4:
            if(miListaOrdena.vacia()){
            std::cout << "Esta Vacia" << std::endl;
            }else{
                std::cout << "No esta vacia" << std::endl;
            }
            escogioListaOrdenada(miListaOrdena);
            break;
        case 5:
            std::cout << "Digite el elmento que desea agregar" << std::endl;
            std::cin >> parametro;
            miListaOrdena.agregar(parametro);
            escogioListaOrdenada(miListaOrdena);
            break;
        case 6:
            std::cout << "Digite el elemento que desea borrar de la lista " << std::endl;
            std::cin >> parametro;
            miListaOrdena.borrar(parametro);
            escogioListaOrdenada(miListaOrdena);
            break;
        case 7:
            std::cout << "Este es el primer elemento : " << miListaOrdena.primero() << std::endl;
            escogioListaOrdenada(miListaOrdena);
            break;
        case 8:
            std::cout << "Este es el ultimo elemento : " << miListaOrdena.ultimo() << std::endl;
            escogioListaOrdenada(miListaOrdena);
            break;
        case 9:
            std::cout << "Inserte un elemento " << std::endl;
            std::cin >> parametro;
            std::cout << "Este es el siguiente --->" << miListaOrdena.siguiente(parametro) << std::endl;
            escogioListaOrdenada(miListaOrdena);
            break;
        case 10:
            std::cout << "Inserte un elemento " << std::endl;
            std::cin >> parametro;
            std::cout << "Este es el anterior ---> " << miListaOrdena.anterior(parametro) << std::endl;
            escogioListaOrdenada(miListaOrdena);
            break;
        case 11:
            std::cout << "Hay " << miListaOrdena.numElem() << "elementos en la lista." << std::endl;
            escogioListaOrdenada(miListaOrdena);
            break;
        
        case 12:
            std::cout << "------------------------" << std::endl;
            miListaOrdena.imprimir();
            std::cout << "------------------------" << std::endl;
			escogioListaOrdenada(miListaOrdena);
			break;
        case 13:
            int resultado = misAlgoritmosOrd.iguales(miListaOrdenadaA, miListaOrdenadaB);
			if(resultado)
				std::cout << "Son Iguales" << std::endl;
			else{
				std::cout << "No son iguales" << std::endl;
			}
			escogioListaOrdenada(miListaOrdena);
            break;
		case 14:
			if(tipoDeLista == OrdenadaA){
				misAlgoritmosOrd.copiar(miListaOrdena, miListaOrdenadaB);
			}else{
				misAlgoritmosOrd.copiar(miListaOrdena, miListaOrdenadaA);
			}
			escogioListaOrdenada(miListaOrdena);
			break;
		case 15:
			int resultado = 0;
			if(tipoDeLista == OrdenadaA){
				resultado = misAlgoritmosOrd.contenida(miListaOrdena, miListaOrdenadaB);
			}else{
				resultado = misAlgoritmosOrd.contenida(miListaOrdena, miListaOrdenadaA);
			}
			if(resultado)
				std::cout << "Esta Lista esta contenida en la segunda" << std::endl;
			else{
				std::cout << "No esta contenida" << std::endl;
			}
			escogioListaOrdenada(miListaOrdena);
			break;
		case 16:
			int resultado = 0;
			int elementoBuscado; 
			std::cout << "Escriba elmento" << std::endl;
			std::cin >> elementoBuscado;
			if(tipoDeLista == OrdenadaA){
				resultado = misAlgoritmosOrd.pertenece(miListaOrdena, elementoBuscado);
	
			if(resultado)
				std::cout << "Esta Lista esta" << std::endl;
			else{
				std::cout << "No esta contenida" << std::endl;
			}
			escogioListaOrdenada(miListaOrdena);
			break;
		case 17:
			if(tipoDeLista == OrdenadaA){
				misAlgoritmosOrd.contenida(miListaOrdena, miListaOrdenadaB);
			}else{
				resultado = misAlgoritmosOrd.contenida(miListaOrdena, miListaOrdenadaA);
			}
			if(resultado)
				std::cout << "Esta Lista esta contenida en la segunda" << std::endl;
			else{
				std::cout << "No esta contenida" << std::endl;
			}
			escogioListaOrdenada(miListaOrdena);
			break;
		case 18:
			misAlgoritmosOrd.unionListas(miListaOrdenadaA, miListaOrdenadaB);
			escogioListaOrdenada(miListaOrdena);
			break;
	}
}

void Interfaz :: escogioListaIndexada( Lista_Index miListaIndex){
    
    int operacion = 0;
    
    std::cout << "1) iniciar();" << std::endl;
    std::cout << "2) destruir();" << std::endl;
    std::cout << "3) vaciar();" << std::endl;
    std::cout << "4) vacia();" << std::endl; 
    std::cout << "5) agregar(int , int)" << std::endl;
    std::cout << "6) borrar(int)" << std::endl;
    std::cout << "7) recuperar(int)" << std::endl;
    std::cout << "8) modificarElemento(int, int)" << std::endl;
    std::cout << "9) intercambiar(int,int)" << std::endl;
    std::cout << "10) numElem()" << std::endl;
    std::cout << "11) imprimirLista()" << std::endl;
    std::cout << "12) EXIT" << std::endl;
    std::cin >> operacion;
    int parametro1 = 0;
    int parametro2 = 0;
    switch (operacion){
        case 1:
            std::cout << "Se inicio la lista" << std::endl;
            miListaIndex.iniciar();
            escogioListaIndexada(miListaIndex);
            break;
        case 2:
            std::cout << "Se va a destruir la lista indexada" << std::endl;
            miListaIndex.destruir();
            escogioListaIndexada(miListaIndex);
            break;
        case 3: 
            std::cout << "Se va a vaciar la lista indexada" << std::endl;
            miListaIndex.vaciar();
            escogioListaIndexada(miListaIndex);
            break;
        case 4:
            if(miListaIndex.vacia() == true){
            std::cout << "Esta Vacia" << std::endl;
            }else{
                std::cout << "No esta vacia" << std::endl;
            }
            escogioListaIndexada(miListaIndex);
            break;
        case 5:
			std::cout << "Digite el indice donde desea agregar el elemento " << std::endl; 
			std::cin >> parametro2; 
            std::cout << "Digite el elemento que desea insertar" << std::endl;
            std::cin >> parametro1;
            miListaIndex.agregar(parametro2, parametro1);
            escogioListaIndexada(miListaIndex);
            break;
        case 6:
            std::cout << "Digite el indice del elemento que desea borrar de la lista " << std::endl;
            std::cin >> parametro1;
            miListaIndex.borrar(parametro1);
            escogioListaIndexada(miListaIndex);
            break;
        case 7:
            std::cout << "¿Que indice desea ver ?" << std::endl;
            std::cin >> parametro1;
            if(miListaIndex.recuperar(parametro1) < 1){
                std::cout << "Este indice no posee elemento" << std::endl;
            }else{
                std::cout << "Indice : " << parametro1 << "Elemento :" << miListaIndex.recuperar(parametro1) << std::endl; 
            }
            escogioListaIndexada(miListaIndex);
            break;
        case 8:
            std::cout << "Digite un indice para la lista indexada" << std::endl;
            std::cin >> parametro1;
            std::cout << "Digite el elemento que desea modificar" << std::endl;
            std::cin >> parametro2;
            miListaIndex.modificar(parametro1, parametro2);
            escogioListaIndexada(miListaIndex);
            break;
        case 9:
            std::cout << "1er Indice : " << std::endl;
            std::cin >> parametro1;
            std::cout << "2ndo Indice : " << std::endl;
            std::cin >> parametro2;
            miListaIndex.intercambiar(parametro1, parametro2);
            escogioListaIndexada(miListaIndex);
            break;
        case 10:
            std::cout << "Hay " << miListaIndex.numElem() << "elementos en la lista." << std::endl;
            escogioListaIndexada(miListaIndex);
            break;
        case 11:
            std::cout << "------------------------" << std::endl;
            miListaIndex.imprimirLista();
            std::cout << "------------------------" << std::endl;
            escogioListaIndexada(miListaIndex);
            break;
        case 12:
            menu();
            break;    
        default: 
            std::cout << "La opcion seleccionada no es valida" << std::endl; 
            escogioListaIndexada(miListaIndex); 	
            break; 
        }
}

void Interfaz :: escogioListaPosicionada(){
    int option = 0; 
    int position = 0; 
    int value = 0; 
    int lista_id = -1;
    int esta = 0; 
    bool id_valido = false;  
    cout << "Puede trabajar con 3 listas, para utilizar los algoritmos " << endl; 	
    cout << "los algoritmos que requieren de 1 unica lista solo funcionan con la lista principal" << endl; 
    cout << "las listas secundarias son para los algoritmos que requiere mas de 1 lista, sin embargo se corren igualemente desde la lista principal" << endl; 
    while (!id_valido) {															
		std::cout << "1) lista del programa \n 2) lista auxiliar 1 \n 3) lista auxiliar 2" << std::endl;  
		std::cin >> lista_id; 
		if ( 0 < lista_id < 4) {
			id_valido = true; 
		}
	}
    
    std::cout <<"Menu de la Lista Posicionada" << std::endl;
    std::cout << "1) agregar(int , int)" << std::endl;	
    std::cout << "2) borrar(int)" << std::endl;
    std::cout << "3) modificarElemento(int, int)" << std::endl;
    std::cout << "4) recuperar(int)" << std::endl;	
    std::cout << "5) siguiente(int)" << std::endl; 
    std::cout << "6) anterior(int)" << std::endl; 
    std::cout << "7) primero()" << std::endl; 
    std::cout << "8) ultimo()" << std::endl;  
    std::cout << "9) iniciar();" << std::endl;	
    std::cout << "10) vaciar();" << std::endl;		    	
    std::cout << "11) destruir();" << std::endl;		
    std::cout << "12) imprimirLista()" << std::endl;
    std::cout << "13) agregarAlFinal()" << std::endl;				 
    std::cout << "15) Burbuja" << std::endl;  
    std::cout << "16) Seleccion" << std::endl; 
    std::cout << "17) Seleccion recursivo" << std::endl;
    std::cout << "18) Insercion" << std::endl; 
    std::cout << "19) QuickSort" << std::endl; 
    std::cout << "20) mergeSort" << std::endl; 
    std::cout << "21) UnionOrdenada" << std::endl; 
    std::cout << "22) UnionNoOrdenada" << std::endl;  
    std::cout << "23) InterseccionOrdenadaV1" << std::endl; 
    std::cout << "24) InterseccionNoOrdenadaV2" << std::endl; 
    std::cout << "25) Interseccion" << std::endl; 
    std::cout << "26) Buscar" << std::endl; 
    std::cout << "27) Invertir" << std::endl; 
    std::cout << "28) Simetrica" << std::endl; 
    std::cout << "29) QuickSort_Insercion" << std::endl; 
    std::cout << "30) Eliminar Repetidos" << std::endl; 
    std::cout << "31) Sublista" << std::endl; 
    std::cout << "32) burbujaBidireccional" << std::endl; 
    std::cout << "14) EXIT" << std::endl; 
    std::cin >>option; 
    switch (option){
	case 1: 
	
		    std::cout << "Digite una posicion para la lista posicionada" << std::endl;
			std::cin >> position; 

          
            std::cout << "Digite el elemento que desea insertar" << std::endl;
			std::cin >> value; 
			switch(lista_id) {
				
				case 1: 
				insertarPosicion(position, value, &miListaPos); 
				escogioListaPosicionada();	
		    
				break; 
				
				
				case 2: 
				insertarPosicion(position, value, &aux_1); 
				escogioListaPosicionada(); 
				
				break; 
				
				case 3: 
				insertarPosicion(position, value, &aux_2); 
				escogioListaPosicionada(); 
				break; 
		    
		    
			}
	    break;     
	case 2:      
       
       			switch(lista_id) {
				
					case 1: 
						std::cout << "Digite la posicion del elemento que desea borrar de la lista " << std::endl;
						std::cin >> position; 
						borrarPosicion(position, &miListaPos); 	
						escogioListaPosicionada();	
				
					break; 
					
					
					case 2: 
						std::cout << "Digite la posicion del elemento que desea borrar de la lista " << std::endl;
						std::cin >> position; 
						borrarPosicion(position, &aux_1); 	
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						std::cout << "Digite la posicion del elemento que desea borrar de la lista " << std::endl;
						std::cin >> position; 
						borrarPosicion(position, &aux_2); 	
						escogioListaPosicionada();
					break; 
				
		    
			} 
       
       
        break; 	
        
          
        
        
	case 3: 


		std::cout << "Digite la posicion del elemento que desea modificar de la lista" << std::endl; 
		std::cin >>position; 
		std::cout << "Digite el nuevo valor de la posicion que desea modificar" << std::endl; 
		std::cin >>value; 
	    
	    		switch(lista_id) {
				
					case 1: 
						modificarPosicion(position, value, &miListaPos); 
						escogioListaPosicionada();
				
					break; 
					
					
					case 2: 
						modificarPosicion(position, value, &aux_1); 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						modificarPosicion(position, value, &aux_2); 
						escogioListaPosicionada(); 
					break; 
		    
		    
			}
	    
        break; 
	case 4: 
		std::cout << "Digite la posicion del elemento que desea recuperar" << std::endl; 
		std::cin >> position; 	    
	    
	    	    		switch(lista_id) {
				
					case 1: 
						std::cout << "El elemento recuperado de dicha posicion corresponde al  : " <<  recuperarPosicion(position, &miListaPos) << std::endl; 
						escogioListaPosicionada();
				
					break; 
					
					
					case 2: 
						std::cout << "El elemento recuperado de dicha posicion corresponde al  : " <<  recuperarPosicion(position, &aux_1) << std::endl; 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						std::cout << "El elemento recuperado de dicha posicion corresponde al  : " <<  recuperarPosicion(position, &aux_2) << std::endl; 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
	    
	    
        break; 
	case 5: 
		std::cout << "Digite la posicion del elemento al que desea conocer su siguiente" << std::endl; 
		std::cin >>position; 

	    
	    
	    	  switch(lista_id) {
				
					case 1: 
						std::cout << "El elemento siguiente a la posicion ingresada corresponde al : " << siguientePosicion(position, &miListaPos) << std::endl; 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						std::cout << "El elemento siguiente a la posicion ingresada corresponde al : " << siguientePosicion(position, &aux_1) << std::endl; 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						std::cout << "El elemento siguiente a la posicion ingresada corresponde al : " << siguientePosicion(position, &aux_2) << std::endl; 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    	    
	    
        break; 
	case 6: 
		std::cout << "Digite la posicion del elemento al que desea conocer el anterior" << std::endl; 
		std::cin >>position; 

	    
	    	  switch(lista_id) {
				
					case 1: 
						std::cout << "El elemento anterior a la posicion ingresaada corresponde al : " << anteriorPosicion(position, &miListaPos) << std::endl; 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						std::cout << "El elemento anterior a la posicion ingresaada corresponde al : " << anteriorPosicion(position, &aux_1) << std::endl; 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						std::cout << "El elemento anterior a la posicion ingresaada corresponde al : " << anteriorPosicion(position, &aux_2) << std::endl; 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
	    
	    
        break; 
	case 7: 

	    
	    	  switch(lista_id) {
				
					case 1: 
						std::cout << "El primer elemento de la lista corresponde al  : " <<  primeraPosicion(&miListaPos) << std::endl; 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						std::cout << "El primer elemento de la lista corresponde al  : " <<  primeraPosicion(&aux_1) << std::endl; 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						std::cout << "El primer elemento de la lista corresponde al  : " <<  primeraPosicion(&aux_2) << std::endl; 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
        break; 
	case 8: 

	    
	    
	    	   switch(lista_id) {
				
					case 1: 
						std::cout << "El ultimo elemento de la lista corresponde al : " <<  ultimaPosicion(&miListaPos) << std::endl; 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						std::cout << "El ultimo elemento de la lista corresponde al : " <<  ultimaPosicion(&aux_1) << std::endl; 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						std::cout << "El ultimo elemento de la lista corresponde al : " <<  ultimaPosicion(&aux_2) << std::endl; 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
        break; 
	case 9: 

	    	    
	    	   switch(lista_id) {
				
					case 1: 
						std::cout << "Se inicio la lista posicionada" << std::endl; 
						iniciarLista(&miListaPos); 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						std::cout << "Se inicio la lista posicionada" << std::endl; 
						iniciarLista(&aux_1); 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						std::cout << "Se inicio la lista posicionada" << std::endl; 
						iniciarLista(&aux_2); 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
	    
        break; 
	case 10: 

	    
	    
	    	   switch(lista_id) {
				
					case 1: 
						std::cout << "Se va a vaciar la lista posicionada" << std::endl; 
						vaciarLista(&miListaPos); 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						std::cout << "Se va a vaciar la lista posicionada" << std::endl; 
						vaciarLista(&aux_1); 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						std::cout << "Se va a vaciar la lista posicionada" << std::endl; 
						vaciarLista(&aux_2); 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
	    
        break; 
	case 11: 

	    
	    
	    	   switch(lista_id) {
				
					case 1: 
						std::cout << "Se va a destruir la lista posicionada" << std::endl; 
						destruirLista(&miListaPos); 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						std::cout << "Se va a destruir la lista posicionada" << std::endl; 
						destruirLista(&aux_1); 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						std::cout << "Se va a destruir la lista posicionada" << std::endl; 
						destruirLista(&aux_2); 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
        break; 
	case 12: 
	
				switch(lista_id) {
				
				case 1: 
					std::cout << "Imprimiendo lista" << std::endl; 
					std::cout << "------------------------" << std::endl;
					std::cout << imprimirLista(&miListaPos) << std::endl; 
					std::cout << "------------------------" << std::endl;
					escogioListaPosicionada();
				break; 
				
				
				case 2: 
					std::cout << "Imprimiendo lista" << std::endl; 
					std::cout << "------------------------" << std::endl;
					std::cout << imprimirLista(&aux_1) << std::endl; 
					std::cout << "------------------------" << std::endl;
					escogioListaPosicionada();
				break; 
							
				
				case 3: 
					std::cout << "Imprimiendo lista" << std::endl; 
					std::cout << "------------------------" << std::endl;
					std::cout << imprimirLista(&aux_2) << std::endl; 
					std::cout << "------------------------" << std::endl;
					escogioListaPosicionada();
				break; 
		    	    
			}
			 
        break; 
	case 13: 
	
	
				switch(lista_id) {
				
				case 1: 
				
					std::cout << "Digite el elemento que desea ingresar al final de la lista" << std::endl; 
					std::cin >>value; 
					agregarPosicionAlFinal(value, &miListaPos);
					escogioListaPosicionada(); 		    
				break; 
				
				
				case 2: 
					std::cout << "Digite el elemento que desea ingresar al final de la lista" << std::endl; 
					std::cin >>value; 
					agregarPosicionAlFinal(value, &aux_1);
					escogioListaPosicionada(); 
				break; 
				
				case 3: 			
					std::cout << "Digite el elemento que desea ingresar al final de la lista" << std::endl; 
					std::cin >>value; 
					agregarPosicionAlFinal(value, &aux_2);
					escogioListaPosicionada(); 
				break; 
		    
		    
			}
	    
	break; 	
	
	case 14: 
		menu(); 	
	break; 
	
	
	case 15: 
		misAlgoritmosPos.burbuja(miListaPos); 			//probado y funciona
		escogioListaPosicionada(); 
	
	break; 
	
	case 16: 
		 misAlgoritmosPos.seleccion(miListaPos);					//probado y funciona. 
		escogioListaPosicionada();  
	break; 
	
	case 17: 
		 misAlgoritmosPos.seleccionRecursivo(miListaPos, miListaPos.primera()); 	//probado y funciona
		escogioListaPosicionada(); 
	
	break; 
	
	case 18: 
		 misAlgoritmosPos.insercion(miListaPos);		//probado y funciona. 
		escogioListaPosicionada();  
	
	break; 
	
	case 19: 
		misAlgoritmosPos.quickSort(miListaPos);		//probado y funciona
		escogioListaPosicionada();  
	
	break; 
	
	case 20: 
		misAlgoritmosPos.mergeSort(miListaPos);		//probado y funciona
		escogioListaPosicionada();  
	
	break; 
	
	
	case 21: //le agrega a l1, los elementos de l2, sin que en l1 queden elementos repetidos. 
			//requiere l1 y l2 ordenadas sin elementos repetidos. 
		misAlgoritmosPos.unionOrdenada(miListaPos, aux_1);	//probado y funciona.
		escogioListaPosicionada(); 
	break; 
	
	
	case 22: //requiere que l1 y l2 no tenga elementos repetidos. el orden no importa. 
		misAlgoritmosPos.unionNoOrdenada(miListaPos, aux_1); //probado y funciona
		escogioListaPosicionada(); 
	
	break; 
	
	case 23: //deja en l3, la interseccion de l1 y l2, 
			//si l3 poseía valores anteriormente se borran. 
		misAlgoritmosPos.interseccionOrdenada_v1(miListaPos, aux_1, aux_2); // probado y funciona. 
		escogioListaPosicionada(); 
	break; 
	
	
	
	case 24: //dela en l3, la interseccion de l1 y l2. 
		misAlgoritmosPos.interseccionOrdenada_v2(miListaPos, aux_1, aux_2);	//aún no programado
		escogioListaPosicionada(); 
	break; 
	
	
	case 25: //deja en l3, la interseccion de l1, y l2, requiere que no posean elementos repetidos. 
		misAlgoritmosPos.interseccion(miListaPos, aux_1, aux_2);	//probado y funciona. 
		escogioListaPosicionada(); 
	break; 
	
	
	case 26: 
	
			esta = 0; 
			value = 0; 
			std::cout << "digite el valor que desea buscar en la lista : "; 
			std::cin >>value; 
			
					switch(lista_id) {
						
						case 1: 
						esta = misAlgoritmosPos.buscar(miListaPos, value); 	    
						break; 
						
						
						case 2: 
						esta = misAlgoritmosPos.buscar(aux_1, value);			
						break; 
						
						case 3: 
						esta = misAlgoritmosPos.buscar(aux_2, value); 
						break; 
					
					
					}
				
			std::cout << std::endl; 

			if(esta != 0) {
				std::cout << "el valor ingresado se encuentra en la lista " << std::endl << std::endl; 
			}
			else {
				std::cout << "el valor ingresado no se encuentra en la lista" << std::endl << std::endl; 
			}
			
			escogioListaPosicionada();	
	
	
	
	break; 
	
	
	case 27:
	
	 
	
	switch(lista_id) {
		
		case 1:
		misAlgoritmosPos.invertir(miListaPos); 
		escogioListaPosicionada(); 
		break; 
 
		case 2:
		misAlgoritmosPos.invertir(aux_1);		
		escogioListaPosicionada(); 
		break; 
		
		case 3:
		misAlgoritmosPos.invertir(aux_2); 
		escogioListaPosicionada(); 
		break; 
		
		
	}

		
		
	
	
	break; 
	
	
	case 28: 
	
	option = 0; 
	
	switch(lista_id) {		
			case 1:
			option = misAlgoritmosPos.simetrica(miListaPos); 
			break; 
			
			
			case 2:
			option = misAlgoritmosPos.simetrica(aux_1); 
			break; 
			
			
			case 3: 
			option = misAlgoritmosPos.simetrica(aux_2); 
			break; 	
					
	}
	
	if (option != 0) {
		std::cout << std::endl << "la lista es simetrica " << std::endl << std::endl; 
	}
	else {
		std::cout << std::endl; 
		std::cout << "la lista no es simetrica " << std::endl << std::endl; 
	}
	
	escogioListaPosicionada(); 
	
	
	
	break; 
	
	
	case 29: 
		misAlgoritmosPos.quickSort_insercion(miListaPos); 
		escogioListaPosicionada(); 
	break; 
	
	
	case 30: 
		misAlgoritmosPos.eliminarRepetidos(miListaPos); 
		escogioListaPosicionada(); 
	break; 
	
	
	case 31:
		if(misAlgoritmosPos.subLista(miListaPos, aux_1)) {
			std::cout << "si esta contenida" << std::endl; 
		} 
		else {
			std::cout << "no esta contenida" << std::endl; 
		}
		
		escogioListaPosicionada(); 
		
	break; 
	
	
	case 32: 
		misAlgoritmosPos.burbujaBidireccional(miListaPos);
		escogioListaPosicionada();  
	
	
	break; 
	
	
	default: 
		std::cout << "La opcion seleccionada no es valida" << std::endl; 
		escogioListaPosicionada(); 	
	break; 
    }
}	
			 

void Interfaz ::iniciarLista(Lista_Pos* lista) {
	lista->iniciar(); 
}


void Interfaz ::agregarPosicionAlFinal(int valor, Lista_Pos* lista) {
	lista->agregarAlFinal(valor); 
}


string Interfaz :: imprimirLista(Lista_Pos* lista) {
	return lista->imprimirLista(); 
}

void Interfaz :: vaciarLista(Lista_Pos* lista) {
	lista->vaciar(); 
}

void Interfaz ::destruirLista(Lista_Pos* lista) {
	lista->destruir(); 
}


int  Interfaz :: primeraPosicion(Lista_Pos* lista) {
	
	Pos primera = lista->primera(); 
	int pos = 0; 
	
	if (primera != PosNula) {
		pos = lista->recuperar(primera); 
	}
	return pos; 
}


int Interfaz :: ultimaPosicion(Lista_Pos* lista) {
	Pos ultima = lista->ultima(); 
	int pos = 0; 
	if (ultima != PosNula) {
		pos = lista->recuperar(ultima); 
	}
	return pos; 
}



int Interfaz :: anteriorPosicion(int indice, Lista_Pos* lista) {
	Pos temporal = lista->traducir(indice);
	Pos before_one = lista->anterior(temporal);
	int value = 0; 
	if (before_one != PosNula) {
		value = lista->recuperar(before_one); 
	} 
	else {
		std::cout << "la posición que desea ingresar no es valida " << std::endl; 
	}
	return value;  
}


int Interfaz :: siguientePosicion(int indice, Lista_Pos* lista) {	
	Pos temporal = lista->traducir(indice);
	Pos next_one = lista->siguiente(temporal);
	int value = 0; 
	if (next_one != PosNula) {
		value = lista->recuperar(next_one); 
	} 
	 
	return value; 
}



void Interfaz :: insertarPosicion(int indice, int valor, Lista_Pos* lista) {
	Pos temporal = lista->traducir(indice);
	lista->insertar(temporal, valor);  	
}


void  Interfaz :: borrarPosicion(int indice, Lista_Pos* lista) {
	Pos temporal = lista->traducir(indice);
	lista->borrar(temporal);  
}


void Interfaz :: modificarPosicion(int indice, int valor, Lista_Pos* lista) {
	Pos temporal = lista->traducir(indice);
	if (temporal != PosNula) {
		lista->modificar(temporal, valor); 
	} 
}


int Interfaz :: recuperarPosicion(int indice, Lista_Pos* lista) {
	int value = 0; 
	Pos temporal = lista->traducir(indice);
	if (temporal != PosNula) {
		value = lista->recuperar(temporal); 
	}
	return value;  	
}

Interfaz :: ~Interfaz(){
    //delete miListaPos;
    miListaPos.destruir(); 
}
