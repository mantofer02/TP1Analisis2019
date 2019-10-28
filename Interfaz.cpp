#include "Interfaz.h"

#define Ordenada 1
#define Posicionada 2
#define Indexada 3


Interfaz :: Interfaz(){
  //  miListaPos = new Lista_Pos();
    miListaPos.iniciar();
    tipoDeLista = 0;
    cout << "Bienvenido " << endl;
    menu();
}

void Interfaz :: menu(){
    cout << "Digite :" << endl;
    cout << "1: Si desea el menu de lista Ordenada" << endl;
    cout << "2: Si desea el menu Posicionada" << endl;
    cout << "3: Si desea el menu Indexada" << endl;
    cout << "4: Exit" << endl;
    cin >> tipoDeLista;
    if(tipoDeLista == Ordenada)
        escogioListaOrdenada();
    if(tipoDeLista == Indexada)
        escogioListaIndexada();
    if(tipoDeLista == Posicionada)
        escogioListaPosicionada();
}

void Interfaz :: escogioListaOrdenada(){
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
            escogioListaOrdenada();
            break;
        case 2:
            cout << "Se va a destruir la lista ordenada" << endl;
            miListaOrdena.destruir();
            escogioListaOrdenada();
            break;
        case 3: 
            cout << "Se va a vaciar la lista ordenada" << endl;
            miListaOrdena.vaciar();
            escogioListaOrdenada();
            break;
        case 4:
            if(miListaOrdena.vacia()){
            cout << "Esta Vacia" << endl;
            }else{
                cout << "No esta vacia" << endl;
            }
            escogioListaOrdenada();
            break;
        case 5:
            cout << "Digite el elmento que desea agregar" << endl;
            cin >> parametro;
            miListaOrdena.agregar(parametro);
            escogioListaOrdenada();
            break;
        case 6:
            cout << "Digite el elemento que desea borrar de la lista " << endl;
            cin >> parametro;
            miListaOrdena.borrar(parametro);
            escogioListaOrdenada();
            break;
        case 7:
            cout << "Este es el primer elemento : " << miListaOrdena.primero() << endl;
            escogioListaOrdenada();
            break;
        case 8:
            cout << "Este es el ultimo elemento : " << miListaOrdena.ultimo() << endl;
            escogioListaOrdenada();
            break;
        case 9:
            cout << "Inserte un elemento " << endl;
            cin >> parametro;
            cout << "Este es el siguiente --->" << miListaOrdena.siguiente(parametro) << endl;
            escogioListaOrdenada();
            break;
        case 10:
            cout << "Inserte un elemento " << endl;
            cin >> parametro;
            cout << "Este es el anterior ---> " << miListaOrdena.anterior(parametro) << endl;
            escogioListaOrdenada();
            break;
        case 11:
            cout << "Hay " << miListaOrdena.numElem() << "elementos en la lista." << endl;
            escogioListaOrdenada();
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

void Interfaz :: escogioListaIndexada(){
    
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
            escogioListaIndexada();
            break;
        case 2:
            cout << "Se va a destruir la lista indexada" << endl;
            miListaIndex.destruir();
            escogioListaIndexada();
            break;
        case 3: 
            cout << "Se va a vaciar la lista indexada" << endl;
            miListaIndex.vaciar();
            escogioListaIndexada();
            break;
        case 4:
            if(miListaIndex.vacia() == true){
            cout << "Esta Vacia" << endl;
            }else{
                cout << "No esta vacia" << endl;
            }
            escogioListaIndexada();
            break;
        case 5:
            cout << "Digite el elemento que desea insertar" << endl;
            cin >> parametro1;
            miListaIndex.agregar(parametro1);
            escogioListaIndexada();
            break;
        case 6:
            cout << "Digite el indice del elemento que desea borrar de la lista " << endl;
            cin >> parametro1;
            miListaIndex.borrar(parametro1);
            escogioListaIndexada();
            break;
        case 7:
            cout << "¿Que indice desea ver ?" << endl;
            cin >> parametro1;
            if(miListaIndex.recuperar(parametro1) < 1){
                cout << "Este indice no posee elemento" << endl;
            }else{
                cout << "Indice : " << parametro1 << "Elemento :" << miListaIndex.recuperar(parametro1) << endl; 
            }
            escogioListaIndexada();
            break;
        case 8:
            cout << "Digite un indice para la lista indexada" << endl;
            cin >> parametro1;
            cout << "Digite el elemento que desea modificar" << endl;
            cin >> parametro2;
            miListaIndex.modificar(parametro1, parametro2);
            escogioListaIndexada();
            break;
        case 9:
            cout << "1er Indice : " << endl;
            cin >> parametro1;
            cout << "2ndo Indice : " << endl;
            cin >> parametro2;
            miListaIndex.intercambiar(parametro1, parametro2);
            escogioListaIndexada();
            break;
        case 10:
            cout << "Hay " << miListaIndex.numElem() << "elementos en la lista." << endl;
            escogioListaIndexada();
            break;
        case 11:
            cout << "------------------------" << endl;
            miListaIndex.imprimirLista();
            cout << "------------------------" << endl;
            escogioListaIndexada();
            break;
        case 12:
            menu();
            break;    
        default: 
            cout << "La opcion seleccionada no es valida" << endl; 
            escogioListaIndexada(); 	
            break; 
        }

}

void Interfaz :: escogioListaPosicionada(){
    int option = 0; 
    int position = 0; 
    int value = 0; 
    int lista_id = -1;
    bool id_valido = false;  
    cout << "Puede trabajar con 3 listas, para utilizar los algoritmos " << endl; 	//DE MOMENTO SOLO AGREGAR/IMPRIMIR Y AGREGARALFINAL
    while (!id_valido) {															//FUNCIONAN PARA LAS LISTAS AUXILIARES
		cout << "1) lista del programa \n 2) lista auxiliar 1 \n 3) lista auxiliar 2" << endl;  //SUFICIENTE PARA HACER PRUEBAS. 
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
    cout << "14) EXIT" << endl; 
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
				
				
				case 3: 
				insertarPosicion(position, value, &aux_2); 
				escogioListaPosicionada(); 
				break; 
		    
		    
			}
			
	    break; 
	case 2: 
	
	    cout << "Digite la posicion del elemento que desea borrar de la lista " << endl;
		cin >> position; 
		borrarPosicion(position, &miListaPos); 	
		escogioListaPosicionada();
        break; 	
	case 3: 
		cout << "Digite la posicion del elemento que desea modificar de la lista" << endl; 
		cin >>position; 
		cout << "Digite el nuevo valor de la posicion que desea modificar" << endl; 
		cin >>value; 
		modificarPosicion(position, value, &miListaPos); 
	    escogioListaPosicionada();
        break; 
	case 4: 
		cout << "Digite la posicion del elemento que desea recuperar" << endl; 
		cin >> position; 
		cout << "El elemento recuperado de dicha posicion corresponde al  : " <<  recuperarPosicion(position, &miListaPos) << endl; 
	    escogioListaPosicionada();
        break; 
	case 5: 
		cout << "Digite la posicion del elemento al que desea conocer su siguiente" << endl; 
		cin >>position; 
		cout << "El elemento siguiente a la posicion ingresada corresponde al : " << siguientePosicion(position, &miListaPos) << endl; 
	    escogioListaPosicionada();
        break; 
	case 6: 
		cout << "Digite la posicion del elemento al que desea conocer el anterior" << endl; 
		cin >>position; 
		cout << "El elemento anterior a la posicion ingresaada corresponde al : " << anteriorPosicion(position, &miListaPos) << endl; 
	    escogioListaPosicionada();
        break; 
	case 7: 
		cout << "El primer elemento de la lista corresponde al  : " <<  primeraPosicion(&miListaPos) << endl; 
	    escogioListaPosicionada();
        break; 
	case 8: 
		cout << "El ultimo elemento de la lista corresponde al : " <<  ultimaPosicion(&miListaPos) << endl; 
	    escogioListaPosicionada();
        break; 
	case 9: 
		cout << "Se inicio la lista posicionada" << endl; 
		iniciarLista(&miListaPos); 
	    escogioListaPosicionada();
        break; 
	case 10: 
		cout << "Se va a vaciar la lista posicionada" << endl; 
		vaciarLista(&miListaPos); 
	    escogioListaPosicionada();
        break; 
	case 11: 
		cout << "Se va a destruir la lista posicionada" << endl; 
		destruirLista(&miListaPos); 
	    escogioListaPosicionada();
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
		algoritmos.burbuja(miListaPos); 			//probado y funciona
		escogioListaPosicionada(); 
	
	break; 
	
	case 16: 
		 algoritmos.seleccion(miListaPos);					//probado y funciona. 
		escogioListaPosicionada();  
	break; 
	
	case 17: 
		 algoritmos.seleccionRecursivo(miListaPos, miListaPos.primera()); 	//probado y funciona
		escogioListaPosicionada(); 
	
	break; 
	
	case 18: 
		 algoritmos.insercion(miListaPos);		//probado y funciona. 
		escogioListaPosicionada();  
	
	break; 
	
	case 19: 
		algoritmos.quickSort(miListaPos);		//probado y funciona
		escogioListaPosicionada();  
	
	break; 
	
	case 20: 
		algoritmos.mergeSort_v2(miListaPos);		//probado y funciona
		escogioListaPosicionada();  
	
	break; 
	
	
	case 21: //le agrega a l1, los elementos de l2, sin que en l1 queden elementos repetidos. 
			//requiere l1 y l2 ordenadas sin elementos repetidos. 
		algoritmos.unionOrdenada(miListaPos, aux_1);	//probado y funciona.
		escogioListaPosicionada(); 
	break; 
	
	
	case 22: //requiere que l1 y l2 no tenga elementos repetidos. el orden no importa. 
		algoritmos.unionNoOrdenada(miListaPos, aux_1); //probado y funciona
		escogioListaPosicionada(); 
	
	break; 
	
	case 23: //deja en l3, la interseccion de l1 y l2, 
			//si l3 poseía valores anteriormente se borran. 
		algoritmos.interseccionOrdenada_v1(miListaPos, aux_1, aux_2); // probado y funciona. 
		escogioListaPosicionada(); 
	break; 
	
	
	
	case 24: 
		algoritmos.interseccionOrdenada_v2(miListaPos, aux_1, aux_2);	//aún no programado
		escogioListaPosicionada(); 
	break; 
	
	
	case 25: //deja en l3, la interseccion de l1, y l2, requiere que no posean elementos repetidos. 
		algoritmos.interseccion(miListaPos, aux_1, aux_2);	//probado y funciona. 
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
