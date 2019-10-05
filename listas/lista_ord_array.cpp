#include "lista_ord_array.h"

Lista_Ord::Lista_Ord(){

}

Lista_Ord::~Lista_Ord(){
    delete array;
    numeroElementos = 0;
    tamanoMaximo = 0;
}

//Iniciar(L)
//Efecto: Este operador asigna e inicializa la Lista_Ord Ordenada que se va a usar
//Requiere: Que la lista no haya sido inicializada anteriormente
//Modifica: Los espacios de memoria que la Lista_Ord va utilizar (Si es estática, no se necesitan más espacios de memoria para el manejo de la lista)
void Lista_Ord::iniciar(int tamanoMaximo){
    this->tamanoMaximo = tamanoMaximo;
    array = new int[tamanoMaximo];
    numeroElementos=0;
}

//Destruir(L)
//Efecto: Este operador libera los espacios y usos de memoria utilizados por la lista, además de sus elementos..
//Requiere: Para este operador se requiere que la Lista_Ord L haya sido inicializada
//Modifica: Modifica la misma lista haciéndola inutilizable. Además se modifica la memoria, liberando sus espacios en donde se tenía un uso asignado para la lista.
void Lista_Ord::destruir(){
    delete this;
}

//Vaciar(L)
//Efecto: Vacía la lista sacando todos los elementos de la lista. Como es una lista Ordenada solo quedan las celdas vacías.
//Requiere: Que una lista L haya sido inicializada anteriormente y este activa.
//Modifica: La lista en sí, sacando los elementos de la lista. Puede ser que no elimine los elementos, queda a discreción de la implementación.
void Lista_Ord::vaciar(){
    delete array;
    array = new int[tamanoMaximo];
    numeroElementos = 0;
    cout <<"La lista ha sido vaciada con exito.\n"<< endl;
}

//Vacía(L) → Bool
//Efecto : Retorna un booleano indicando si la lista está vacía o no.
//Requiere: Una lista inicializada.
//Modifica: Este operador no modifica nada.
int Lista_Ord::vacia(){
    return numeroElementos == 0;
}

//Agregar(L, e)
//Efecto: Agrega el elemento e a la lista L. Como es una Lista_Ord Ordenada, la lista esta ordenada ascendentemente. Se busca la primera celda vacía que encuentra y 
//esa es la posición en la cual el elemento va a ser insertado. Se podría implementar una lista en la cual la misma estructura tiene implementada el sistema de
//ordenamiento, entonces no sería un agregado secuencial, sin embargo ya seria una lista ordenada de uso específico. Pero, por defecto y convenio se espera que 
//cuando se agreguen los elementos vayan en orden ascendente y el usuario es quien tiene la responsabilidad de eso.
//Requiere: Este operador requiere una lista L ya inicializada un un elemento e, el cual no es vacío.
//Modifica: Este operador modifica la lista, incrementando su cantidad de elementos + 1.
void Lista_Ord::agregar(int elemento){
    if(!(this->tamanoMaximo==numeroElementos)){
        int agregue = 0;
        for(int i=0;i<=numeroElementos && !agregue;i++){
            if(array[i] == elemento){
                i = numeroElementos;
                agregue=1;
                numeroElementos--;
                cout << "El elemento "<< elemento << " ya esta en la lista.\n"<< endl;                
            }
            if(elemento<array[i]){
                for(int k = numeroElementos;k>i;k--){
                    array[k] = array[k-1];
                }
                array[i] = elemento;
                cout << "Se agrega el elemento "<< elemento << " con exito.\n"<< endl;
                agregue=1;
            }
        }
        if(!agregue){
            array[numeroElementos] = elemento;
            cout << "Se agrega el elemento "<< elemento << " con exito.\n"<< endl;
        }
        numeroElementos++;
    }
    else{
        cout << "La lista esta llena; no se pudo agregar el elemento deseado.\n"<< endl;
    }
}

//Borrar(e)
//Efecto: Este operador recorre toda la lista en busca del elemento e. Si este elemento existe lo borra de la lista. Si hay elementos a la derecha del elemento
//que se quiso borrar, todos son desplazados una posición para hacer la lista continua, además de respetar el criterio de ordenamiento.
//Requiere: Este operador requiere que e no sea un valor vacío. No es un requisito pero es preferible que e fuera un elemento que se sabe que está en la lista.
//Modifica: Este operador modifica al elemento e, borrandolo de la lista. Además modifica la lista reduciendo su cantidad de elementos por 1.
void Lista_Ord::borrar(int elemento){
    if(!vacia()){
        int encontre = 0;
        for(int i=0;i<=numeroElementos && !encontre;i++){
            if(elemento == array[i]){
                encontre = 1;
                cout << "Se borra el elemento "<<elemento<<" con exito.\n"<< endl;
                array[i] = 0;
                for(i;i<numeroElementos;i++){
                    array[i] = array[i+1];
                }
            }
        }
        if(encontre){
            array[numeroElementos-1]=0;
            numeroElementos--;
        }
        else{
            cout << "No se pudo borrar el elemento deseado, ya que no estaba en la lista.\n"<< endl;     
        }
    }
    else{
        cout << "No se pudo borrar el elemento deseado, ya que la lista esta vacia.\n"<< endl;
    }
}

//Primero(L) → e
//Efecto: Este operador devuelve , si existe, el primer elemento de la Lista_Ord Ordenada. Como la lista está ordenada ascendentemente el elemento que devuelva va a
//ser el del valor más bajo.
//Requiere: Una lista L inicializada.
//Modifica: Este operador no modifica nada dentro de la lista.
int Lista_Ord::primero(){
    int primero = 0;
    if(vacia()){
        cout << "La lista esta vacia.\n"<< endl;
        primero = -1;               
    }
    else{
        primero = array[0];
    }
    return primero;
}

//Último(L) → e
//Efecto: Este operador devuelve , si existe, el último elemento de la Lista_Ord Ordenada. Como la lista está ordenada ascendentemente el elemento que devuelva va a
//ser el del valor más alto.
//Requiere: Una lista L inicializada.
//Modifica: Este operador no modifica nada dentro de la lista.
int Lista_Ord::ultimo(){
    int ultimo = 0;
    if(vacia()){
        cout << "La lista esta vacia.\n"<< endl;
        ultimo = -1;
    }
    else{
        ultimo = array[0];
    }
    return ultimo;
}

//Siguiente(e) → eSiguiente
//Efecto : Este operador devuelve , si existe, el elemento que está siguiente a e. Como la lista está ordenada ascendentemente el elemento que devuelva va a tener
//un valor mayor a e.
//Requiere: Una lista L inicializada.
//Modifica : Este operador no modifica nada dentro de la lista.
int Lista_Ord::siguiente(int elemento){
    int resultado = 0;
    int encontro = 0; 
    for(int i=0; i<numeroElementos; i++){
        if(array[i] == elemento){
            if((i+1) != numeroElementos){
                resultado = array[i+1];
            } 
            else{
                cout << "El elemento deseado es el último en la lista.\n"<< endl; 
                resultado = -1;
            }
            encontro=1;             
        }
    }
    if(!encontro){
        cout << "El elemento deseado no esta en la lista.\n"<< endl;
        resultado=-1;
    }
    return resultado;
}

//Anterior(e) → eAnterior
//Efecto: Este operador devuelve , si existe, el elemento que está anterior a e. Como la lista está ordenada ascendentemente el elemento que devuelva va a tener
//un valor menor a e.
//Requiere: Una lista L inicializada Además, es preferible que e no sea el primer elemento de la lista.
//Modifica: Este operador no modifica nada dentro de la lista.
int Lista_Ord::anterior(int elemento){
    int resultado = 0;
    int encontro=0;
    for(int i=0; i<numeroElementos; i++){
        if(array[i] == elemento){
            if(i!=0){
                resultado = array[i-1];
            }
            else{
                cout << "El elemento deseado es el primero en la lista.\n"<< endl;
                resultado = -1;
            }
            encontro=1;             
        }
    }
    if(!encontro){
        cout << "El elemento deseado no esta en la lista.\n"<< endl;
        resultado=-1;
    }
    return resultado;
}

//NumElem(L) → número
//Efecto: Este operador cuenta la cantidad de elementos de la lista y devuelve un número que indica la cantidad de elementos que se encuentran en la lista.
//Requiere: Este operador requiere una lista L inicializada.
//Modifica: Este operador modifica al número que va a devolver. Si se quisiera como opción de diseño, se podría implementar un contador de elementos que
//incremente cada vez que se agrega algo. Si así fuera el caso no se modificaria nada.
int Lista_Ord::numElem(){
    return numeroElementos;
}

void Lista_Ord::imprimir(){
    cout << "{"; 
    for(int i=0;i<numeroElementos;i++){
        if(array[i]!=0){
            cout << array[i] << " ";   
        }   
    }
    cout << "}"<< endl;
}

void Lista_Ord::imprimirMenu(Lista_Ord * lista){
    cout << "Bienvenido al programa de prueba de la lista ordenada implementada a través de un array. Digite los dígitos correspondientes a los operadores básicos que desea usar:\n" << endl;
    cout << "1. Iniciar.\n2. Destruir.\n3. Vaciar.\n4. Vacia.\n5. Agregar.\n6. Borrar.\n7. Primero.\n8. Ultimo.\n9. Siguiente.\n10. Anterior.\n11. NumElem\n12. Imprimir.\n13. Salir." << endl;
    int decision = 0;
    if(!(cin >> decision)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
        imprimirMenu(lista);
    }
    else{
        if(0 < decision || 14 > decision){
            if(decision == 1){
                decision = 0;
                cout << "Ingrese un valor valido para M (tamano maximo de la lista)" << endl;
                if(!(cin >> decision)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
                if(decision>0){
                    lista->iniciar(decision);
                    decision=0;
                    imprimirMenu(lista);
                }  
                else{
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
            }
            if(decision == 2){
                cout << "CUIDADO! Si destruye la lista, debera reiniciar el programa. Esta seguro?\n1. Si.\n2. No.\n" << endl; 
                if(!(cin >> decision)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
                if(decision == 2){
                    imprimirMenu(lista);
                }
            }
            if(decision == 3){
                lista->vaciar();
                imprimirMenu(lista);           
            }
            if(decision == 4){
                int vacia = lista->vacia();
                if(vacia){
                    cout << "La lista esta vacia.\n" << endl;
                }
                else{
                    cout << "La lista no esta vacia.\n" << endl;
                }
                imprimirMenu(lista);
            }
            if(decision == 5){
                decision = 0;
                cout << "Digite el numero que desea agregar:\n" << endl;
                if(!(cin >> decision)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
                lista->agregar(decision);
                decision=0;
                imprimirMenu(lista); 
            }
            if(decision == 6){
                decision = 0;
                cout << "Digite el numero que desea borrar:\n" << endl;
                if(!(cin >> decision)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
                lista->borrar(decision);
                decision=0;
                imprimirMenu(lista);
            }
            if(decision == 7){
                int primero = lista->primero();
                if(primero>-1){
                    cout << "El primer elemento de la lista es "<< primero << ".\n" << endl;
                }
                lista->imprimirMenu(lista);
            }
            if(decision == 8){
                int ultimo = lista->ultimo();
                if(ultimo>-1){
                    cout << "El ultimo elemento de la lista es "<< ultimo << ".\n" << endl;
                }
                lista->imprimirMenu(lista);
            }
            if(decision == 9){
                decision = 0;
                cout << "Digite el numero del cual desea averiguar:\n" << endl;
                if(!(cin >> decision)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
                int resultado = lista->siguiente(decision);
                if(resultado != -1){
                    cout << "El elemento siguiente a "<< decision <<" es " << resultado << ".\n"<< endl;
                }
                decision=0;
                lista->imprimirMenu(lista);
            }
            if(decision == 10){
                decision = 0;
                cout << "Digite el numero del cual desea averiguar:\n" << endl;
                if(!(cin >> decision)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    imprimirMenu(lista);
                }
                int resultado = lista->anterior(decision);
                if(resultado != -1){
                    cout << "El elemento anterior a "<< decision <<" es " << resultado << ".\n"<< endl;
                }
                decision=0;
                lista->imprimirMenu(lista);
            }
            if(decision == 11){
                decision = lista->numElem(); 
                cout << "El numero de elementos de la lista es " <<decision<<".\n"<< endl ;
                decision=0;
                lista->imprimirMenu(lista);
            }
            if(decision == 12){
                cout << "L:";
                lista->imprimir();
                imprimirMenu(lista);
            }
        }
        else{
            cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
            imprimirMenu(lista);
        }
    }
}
