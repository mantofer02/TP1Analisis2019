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
    cout << "Bienvenido " << endl;
    menu();
}

void Interfaz :: menu(){
    cout << "Digite :" << endl;
    cout << "1: Si desea el menu de lista OrdenadaA" << endl;
    cout << "2: Si desea el menu de lista OrdenadaB" << endl;
    cout << "3: Si desea el menu de lista Posicionada" << endl;
	cout << "4: Si desea el menu de lista IndexadaA" << endl;
	cout << "5: Si desea el menu de lista IndexadaB" << endl;
	cout << "6: Si desea el menu de lista IndexadaC" << endl;
    cout << "7: Exit" << endl;
    cin >> tipoDeLista;
    if(tipoDeLista == OrdenadaA)
        cout << "---------------------------------------------" << endl;
		cout << "                LISTA ORDENADA A             " << endl;
		escogioListaOrdenada(miListaOrdenadaA);
	if(tipoDeLista == OrdenadaB)
		cout << "---------------------------------------------" << endl;
		cout << "                LISTA ORDENADA B             " << endl;
		escogioListaOrdenada(miListaOrdenadaB);
    if(tipoDeLista == IndexadaA)
        cout << "---------------------------------------------" << endl;
		cout << "                LISTA INDEXADA A             " << endl;
		escogioListaIndexada(miListaIndexA);
	if(tipoDeLista == IndexadaB)
		cout << "---------------------------------------------" << endl;
		cout << "                LISTA INDEXADA B             " << endl;
        escogioListaIndexada(miListaIndexB);
	if(tipoDeLista == IndexadaC)
		cout << "---------------------------------------------" << endl;
		cout << "                LISTA INDEXADA C             " << endl;
        escogioListaIndexada(miListaIndexC);
    if(tipoDeLista == Posicionada)
		cout << "---------------------------------------------" << endl;
		cout << "                LISTA POSICIONADA A             " << endl;
        escogioListaPosicionada();
}

void Interfaz :: escogioListaOrdenada(Lista_Ord miListaOrdena){
    int operacion = 0;
    cout << "Menu lista Ordenada" << endl;
    cout << "1) iniciar();" << endl;
    cout << "2) destruir();" << endl;
    cout << "3) vaciar();" << endl;
    cout << "4) vacia();" << endl; 
    cout << "5) agregar(int)" << endl;
    cout << "6) borrar(int)" << endl;
    cout << "7) primero()" << endl;
    cout << "8) ultimo()" << endl;
    cout << "9) siguiente(int)" << endl;
    cout << "10) anterior(int)" << endl;
    cout << "11) numElem()" << endl;
    cout << "12) imprimirLista()" << endl;
    cout << "13) EXIT" << endl;
    cin >> operacion;
    int parametro = 0;
    switch (operacion){
        case 1:
            cout << "Se inicio la lista" << endl;
            miListaOrdena.iniciar();
            escogioListaOrdenada(miListaOrdena);
            break;
        case 2:
            cout << "Se va a destruir la lista ordenada" << endl;
            miListaOrdena.destruir();
            escogioListaOrdenada(miListaOrdena);
            break;
        case 3: 
            cout << "Se va a vaciar la lista ordenada" << endl;
            miListaOrdena.vaciar();
            escogioListaOrdenada(miListaOrdena);
            break;
        case 4:
            if(miListaOrdena.vacia()){
            cout << "Esta Vacia" << endl;
            }else{
                cout << "No esta vacia" << endl;
            }
            escogioListaOrdenada(miListaOrdena);
            break;
        case 5:
            cout << "Digite el elmento que desea agregar" << endl;
            cin >> parametro;
            miListaOrdena.agregar(parametro);
            escogioListaOrdenada(miListaOrdena);
            break;
        case 6:
            cout << "Digite el elemento que desea borrar de la lista " << endl;
            cin >> parametro;
            miListaOrdena.borrar(parametro);
            escogioListaOrdenada(miListaOrdena);
            break;
        case 7:
            cout << "Este es el primer elemento : " << miListaOrdena.primero() << endl;
            escogioListaOrdenada(miListaOrdena);
            break;
        case 8:
            cout << "Este es el ultimo elemento : " << miListaOrdena.ultimo() << endl;
            escogioListaOrdenada(miListaOrdena);
            break;
        case 9:
            cout << "Inserte un elemento " << endl;
            cin >> parametro;
            cout << "Este es el siguiente --->" << miListaOrdena.siguiente(parametro) << endl;
            escogioListaOrdenada(miListaOrdena);
            break;
        case 10:
            cout << "Inserte un elemento " << endl;
            cin >> parametro;
            cout << "Este es el anterior ---> " << miListaOrdena.anterior(parametro) << endl;
            escogioListaOrdenada(miListaOrdena);
            break;
        case 11:
            cout << "Hay " << miListaOrdena.numElem() << "elementos en la lista." << endl;
            escogioListaOrdenada(miListaOrdena);
            break;
        
        case 12:
            cout << "------------------------" << endl;
            miListaOrdena.imprimir();
            cout << "------------------------" << endl;
        case 13:
            menu();
            break;
      }
}

void Interfaz :: escogioListaIndexada( Lista_Index miListaIndex){
    
    int operacion = 0;
    
    cout << "1) iniciar();" << endl;
    cout << "2) destruir();" << endl;
    cout << "3) vaciar();" << endl;
    cout << "4) vacia();" << endl; 
    cout << "5) agregar(int , int)" << endl;
    cout << "6) borrar(int)" << endl;
    cout << "7) recuperar(int)" << endl;
    cout << "8) modificarElemento(int, int)" << endl;
    cout << "9) intercambiar(int,int)" << endl;
    cout << "10) numElem()" << endl;
    cout << "11) imprimirLista()" << endl;
    cout << "12) EXIT" << endl;
    cin >> operacion;
    int parametro1 = 0;
    int parametro2 = 0;
    switch (operacion){
        case 1:
            cout << "Se inicio la lista" << endl;
            miListaIndex.iniciar();
            escogioListaIndexada(miListaIndex);
            break;
        case 2:
            cout << "Se va a destruir la lista indexada" << endl;
            miListaIndex.destruir();
            escogioListaIndexada(miListaIndex);
            break;
        case 3: 
            cout << "Se va a vaciar la lista indexada" << endl;
            miListaIndex.vaciar();
            escogioListaIndexada(miListaIndex);
            break;
        case 4:
            if(miListaIndex.vacia() == true){
            cout << "Esta Vacia" << endl;
            }else{
                cout << "No esta vacia" << endl;
            }
            escogioListaIndexada(miListaIndex);
            break;
        case 5:
			cout << "Digite el indice donde desea agregar el elemento " << endl; 
			cin >> parametro2; 
            cout << "Digite el elemento que desea insertar" << endl;
            cin >> parametro1;
            miListaIndex.agregar(parametro2, parametro1);
            escogioListaIndexada(miListaIndex);
            break;
        case 6:
            cout << "Digite el indice del elemento que desea borrar de la lista " << endl;
            cin >> parametro1;
            miListaIndex.borrar(parametro1);
            escogioListaIndexada(miListaIndex);
            break;
        case 7:
            cout << "¿Que indice desea ver ?" << endl;
            cin >> parametro1;
            if(miListaIndex.recuperar(parametro1) < 1){
                cout << "Este indice no posee elemento" << endl;
            }else{
                cout << "Indice : " << parametro1 << "Elemento :" << miListaIndex.recuperar(parametro1) << endl; 
            }
            escogioListaIndexada(miListaIndex);
            break;
        case 8:
            cout << "Digite un indice para la lista indexada" << endl;
            cin >> parametro1;
            cout << "Digite el elemento que desea modificar" << endl;
            cin >> parametro2;
            miListaIndex.modificar(parametro1, parametro2);
            escogioListaIndexada(miListaIndex);
            break;
        case 9:
            cout << "1er Indice : " << endl;
            cin >> parametro1;
            cout << "2ndo Indice : " << endl;
            cin >> parametro2;
            miListaIndex.intercambiar(parametro1, parametro2);
            escogioListaIndexada(miListaIndex);
            break;
        case 10:
            cout << "Hay " << miListaIndex.numElem() << "elementos en la lista." << endl;
            escogioListaIndexada(miListaIndex);
            break;
        case 11:
            cout << "------------------------" << endl;
            miListaIndex.imprimirLista();
            cout << "------------------------" << endl;
            escogioListaIndexada(miListaIndex);
            break;
        case 12:
            menu();
            break;    
        default: 
            cout << "La opcion seleccionada no es valida" << endl; 
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
		cout << "1) lista del programa \n 2) lista auxiliar 1 \n 3) lista auxiliar 2" << endl;  
		cin >> lista_id; 
		if ( 0 < lista_id < 4) {
			id_valido = true; 
		}
	}
    
    cout <<"Menu de la Lista Posicionada" << endl;
    cout << "1) agregar(int , int)" << endl;	
    cout << "2) borrar(int)" << endl;
    cout << "3) modificarElemento(int, int)" << endl;
    cout << "4) recuperar(int)" << endl;	
    cout << "5) siguiente(int)" << endl; 
    cout << "6) anterior(int)" << endl; 
    cout << "7) primero()" << endl; 
    cout << "8) ultimo()" << endl;  
    cout << "9) iniciar();" << endl;	
    cout << "10) vaciar();" << endl;		    	
    cout << "11) destruir();" << endl;		
    cout << "12) imprimirLista()" << endl;
    cout << "13) agregarAlFinal()" << endl;				 
    cout << "15) Burbuja" << endl;  
    cout << "16) Seleccion" << endl; 
    cout << "17) Seleccion recursivo" << endl;
    cout << "18) Insercion" << endl; 
    cout << "19) QuickSort" << endl; 
    cout << "20) mergeSort" << endl; 
    cout << "21) UnionOrdenada" << endl; 
    cout << "22) UnionNoOrdenada" << endl;  
    cout << "23) InterseccionOrdenadaV1" << endl; 
    cout << "24) InterseccionNoOrdenadaV2" << endl; 
    cout << "25) Interseccion" << endl; 
    cout << "26) Buscar" << endl; 
    cout << "27) Invertir" << endl; 
    cout << "28) Simetrica" << endl; 
    cout << "29) QuickSort_Insercion" << endl; 
    cout << "30) Eliminar Repetidos" << endl; 
    cout << "31) Sublista" << endl; 
    cout << "32) burbujaBidireccional" << endl; 
    cout << "14) EXIT" << endl; 
    cin >>option; 
    switch (option){
	case 1: 
	
		    cout << "Digite una posicion para la lista posicionada" << endl;
			cin >> position; 

          
            cout << "Digite el elemento que desea insertar" << endl;
			cin >> value; 
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
						cout << "Digite la posicion del elemento que desea borrar de la lista " << endl;
						cin >> position; 
						borrarPosicion(position, &miListaPos); 	
						escogioListaPosicionada();	
				
					break; 
					
					
					case 2: 
						cout << "Digite la posicion del elemento que desea borrar de la lista " << endl;
						cin >> position; 
						borrarPosicion(position, &aux_1); 	
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						cout << "Digite la posicion del elemento que desea borrar de la lista " << endl;
						cin >> position; 
						borrarPosicion(position, &aux_2); 	
						escogioListaPosicionada();
					break; 
				
		    
			} 
       
       
        break; 	
        
          
        
        
	case 3: 


		cout << "Digite la posicion del elemento que desea modificar de la lista" << endl; 
		cin >>position; 
		cout << "Digite el nuevo valor de la posicion que desea modificar" << endl; 
		cin >>value; 
	    
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
		cout << "Digite la posicion del elemento que desea recuperar" << endl; 
		cin >> position; 	    
	    
	    	    		switch(lista_id) {
				
					case 1: 
						cout << "El elemento recuperado de dicha posicion corresponde al  : " <<  recuperarPosicion(position, &miListaPos) << endl; 
						escogioListaPosicionada();
				
					break; 
					
					
					case 2: 
						cout << "El elemento recuperado de dicha posicion corresponde al  : " <<  recuperarPosicion(position, &aux_1) << endl; 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						cout << "El elemento recuperado de dicha posicion corresponde al  : " <<  recuperarPosicion(position, &aux_2) << endl; 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
	    
	    
        break; 
	case 5: 
		cout << "Digite la posicion del elemento al que desea conocer su siguiente" << endl; 
		cin >>position; 

	    
	    
	    	  switch(lista_id) {
				
					case 1: 
						cout << "El elemento siguiente a la posicion ingresada corresponde al : " << siguientePosicion(position, &miListaPos) << endl; 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						cout << "El elemento siguiente a la posicion ingresada corresponde al : " << siguientePosicion(position, &aux_1) << endl; 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						cout << "El elemento siguiente a la posicion ingresada corresponde al : " << siguientePosicion(position, &aux_2) << endl; 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    	    
	    
        break; 
	case 6: 
		cout << "Digite la posicion del elemento al que desea conocer el anterior" << endl; 
		cin >>position; 

	    
	    	  switch(lista_id) {
				
					case 1: 
						cout << "El elemento anterior a la posicion ingresaada corresponde al : " << anteriorPosicion(position, &miListaPos) << endl; 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						cout << "El elemento anterior a la posicion ingresaada corresponde al : " << anteriorPosicion(position, &aux_1) << endl; 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						cout << "El elemento anterior a la posicion ingresaada corresponde al : " << anteriorPosicion(position, &aux_2) << endl; 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
	    
	    
        break; 
	case 7: 

	    
	    	  switch(lista_id) {
				
					case 1: 
						cout << "El primer elemento de la lista corresponde al  : " <<  primeraPosicion(&miListaPos) << endl; 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						cout << "El primer elemento de la lista corresponde al  : " <<  primeraPosicion(&aux_1) << endl; 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						cout << "El primer elemento de la lista corresponde al  : " <<  primeraPosicion(&aux_2) << endl; 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
        break; 
	case 8: 

	    
	    
	    	   switch(lista_id) {
				
					case 1: 
						cout << "El ultimo elemento de la lista corresponde al : " <<  ultimaPosicion(&miListaPos) << endl; 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						cout << "El ultimo elemento de la lista corresponde al : " <<  ultimaPosicion(&aux_1) << endl; 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						cout << "El ultimo elemento de la lista corresponde al : " <<  ultimaPosicion(&aux_2) << endl; 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
        break; 
	case 9: 

	    	    
	    	   switch(lista_id) {
				
					case 1: 
						cout << "Se inicio la lista posicionada" << endl; 
						iniciarLista(&miListaPos); 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						cout << "Se inicio la lista posicionada" << endl; 
						iniciarLista(&aux_1); 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						cout << "Se inicio la lista posicionada" << endl; 
						iniciarLista(&aux_2); 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
	    
        break; 
	case 10: 

	    
	    
	    	   switch(lista_id) {
				
					case 1: 
						cout << "Se va a vaciar la lista posicionada" << endl; 
						vaciarLista(&miListaPos); 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						cout << "Se va a vaciar la lista posicionada" << endl; 
						vaciarLista(&aux_1); 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						cout << "Se va a vaciar la lista posicionada" << endl; 
						vaciarLista(&aux_2); 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
	    
        break; 
	case 11: 

	    
	    
	    	   switch(lista_id) {
				
					case 1: 
						cout << "Se va a destruir la lista posicionada" << endl; 
						destruirLista(&miListaPos); 
						escogioListaPosicionada();
								
					break; 
					
					
					case 2: 
						cout << "Se va a destruir la lista posicionada" << endl; 
						destruirLista(&aux_1); 
						escogioListaPosicionada();
					
					break; 
					
					case 3: 
						cout << "Se va a destruir la lista posicionada" << endl; 
						destruirLista(&aux_2); 
						escogioListaPosicionada();
					break; 
		    
		    
			}
	    
	    
	    
        break; 
	case 12: 
	
				switch(lista_id) {
				
				case 1: 
					cout << "Imprimiendo lista" << endl; 
					cout << "------------------------" << endl;
					cout << imprimirLista(&miListaPos) << endl; 
					cout << "------------------------" << endl;
					escogioListaPosicionada();
				break; 
				
				
				case 2: 
					cout << "Imprimiendo lista" << endl; 
					cout << "------------------------" << endl;
					cout << imprimirLista(&aux_1) << endl; 
					cout << "------------------------" << endl;
					escogioListaPosicionada();
				break; 
							
				
				case 3: 
					cout << "Imprimiendo lista" << endl; 
					cout << "------------------------" << endl;
					cout << imprimirLista(&aux_2) << endl; 
					cout << "------------------------" << endl;
					escogioListaPosicionada();
				break; 
		    	    
			}
			 
        break; 
	case 13: 
	
	
				switch(lista_id) {
				
				case 1: 
				
					cout << "Digite el elemento que desea ingresar al final de la lista" << endl; 
					cin >>value; 
					agregarPosicionAlFinal(value, &miListaPos);
					escogioListaPosicionada(); 		    
				break; 
				
				
				case 2: 
					cout << "Digite el elemento que desea ingresar al final de la lista" << endl; 
					cin >>value; 
					agregarPosicionAlFinal(value, &aux_1);
					escogioListaPosicionada(); 
				break; 
				
				case 3: 			
					cout << "Digite el elemento que desea ingresar al final de la lista" << endl; 
					cin >>value; 
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
			cout << "digite el valor que desea buscar en la lista : "; 
			cin >>value; 
			
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
				
			cout << endl; 

			if(esta != 0) {
				cout << "el valor ingresado se encuentra en la lista " << endl << endl; 
			}
			else {
				cout << "el valor ingresado no se encuentra en la lista" << endl << endl; 
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
		cout << endl << "la lista es simetrica " << endl << endl; 
	}
	else {
		cout << endl; 
		cout << "la lista no es simetrica " << endl << endl; 
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
			cout << "si esta contenida" << endl; 
		} 
		else {
			cout << "no esta contenida" << endl; 
		}
		
		escogioListaPosicionada(); 
		
	break; 
	
	
	case 32: 
		misAlgoritmosPos.burbujaBidireccional(miListaPos);
		escogioListaPosicionada();  
	
	
	break; 
	
	
	default: 
		cout << "La opcion seleccionada no es valida" << endl; 
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
		cout << "la posición que desea ingresar no es valida " << endl; 
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
