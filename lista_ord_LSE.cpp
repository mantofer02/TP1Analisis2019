#include "lista_ord_LSE.h"

Lista_Ord::Elemento::Elemento(int elemento){
    this->elemento = elemento;
    siguiente = 0;
}

Lista_Ord::Elemento::~Elemento(){
    if(siguiente){
        delete siguiente;
    }
}

Lista_Ord::Lista_Ord(){

}
Lista_Ord::~Lista_Ord(){
    delete primeraPosicion;
    numeroElementos = 0;
    tamanoMaximo = 0;
}

//Iniciar(L)
//Efecto: Este operador asigna e inicializa la Lista_Ord Ordenada que se va a usar.
//Requiere: Que la lista no haya sido inicializada anteriormente.
//Modifica: Los espacios de memoria que la Lista_Ord va utilizar (Si es estática, no se necesitan más espacios de memoria para el manejo de la lista).
void Lista_Ord::iniciar(){
    //cout << "La lista ha sido inicializada con exito.\n"<< endl;                    
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
    delete  primeraPosicion;
    this->primeraPosicion = 0;
    this->ultimaPosicion = 0;
    numeroElementos = 0;
}


//Vacía(L) → Bool
//Efecto : Retorna un booleano indicando si la lista está vacía o no.
//Requiere: Una lista inicializada.
//Modifica: Este operador no modifica nada.
int Lista_Ord::vacia(){
    return primeraPosicion == 0;
}

//Agregar(L, e)
//Efecto: Agrega el elemento e a la lista L. Como es una Lista_Ord Ordenada, la lista esta ordenada ascendentemente. Se busca la primera celda vacía que encuentra y 
//esa es la posición en la cual el elemento va a ser insertado. Se podría implementar una lista en la cual la misma estructura tiene implementada el sistema de
//ordenamiento, entonces no sería un agregado secuencial, sin embargo ya seria una lista ordenada de uso específico. Pero, por defecto y convenio se espera que 
//cuando se agreguen los elementos vayan en orden ascendente y el usuario es quien tiene la responsabilidad de eso.
//Requiere: Este operador requiere una lista L ya inicializada un un elemento e, el cual no es vacío.
//Modifica: Este operador modifica la lista, incrementando su cantidad de elementos + 1.
void Lista_Ord::agregar(int elemento){
    Elemento * nuevo = new Elemento(elemento);
    if(!vacia()){
        Elemento * temp = primeraPosicion;
        int agregue = 0;  
        if(temp && temp->elemento > nuevo->elemento){
            nuevo->siguiente = temp;
            primeraPosicion = nuevo;
            agregue=1;    
            //cout << "Se agrega el elemento "<< elemento << " con exito.\n";          
        }
        while(temp!=nullptr && !agregue){
            if(temp->elemento == elemento){
                //cout << "El elemento "<< elemento <<" ya esta en la lista.\n"<< endl;
                agregue = 1;
                temp=nullptr;
                numeroElementos--;
            }
            else{
                if(temp->siguiente){
                    if(temp->siguiente->elemento > nuevo->elemento){
                        nuevo->siguiente = temp->siguiente;
                        temp->siguiente = nuevo;
                        agregue = 1;
                        //cout << "Se agrega el elemento "<< elemento << " con exito.\n";
                    }
                    else{
                        temp = temp->siguiente;
                    }
                }
                else{
                    temp = temp->siguiente;
                }
            }
        }
        if(!agregue){
            ultimaPosicion->siguiente = nuevo;
            ultimaPosicion = nuevo;
           // cout << "Se agrega el elemento "<< elemento << " con exito.\n";
        }
    }
    else{
        primeraPosicion = nuevo;
        ultimaPosicion = nuevo;
       // cout << "Se agrega el elemento "<< elemento << " con exito.\n";
    }
    numeroElementos++;
}


//Borrar(e)
//Efecto: Este operador recorre toda la lista en busca del elemento e. Si este elemento existe lo borra de la lista. Si hay elementos a la derecha del elemento
//que se quiso borrar, todos son desplazados una posición para hacer la lista continua, además de respetar el criterio de ordenamiento.
//Requiere: Este operador requiere que e no sea un valor vacío. No es un requisito pero es preferible que e fuera un elemento que se sabe que está en la lista.
//Modifica: Este operador modifica al elemento e, borrandolo de la lista. Además modifica la lista reduciendo su cantidad de elementos por 1.
void Lista_Ord::borrar(int elemento){
    if(!vacia()){
        Elemento * temp = primeraPosicion;
        int borre = 0;
        if(temp->elemento == elemento){//caso en el que se borrara el primer elemento
            primeraPosicion = temp->siguiente;
            temp->siguiente = 0;
            delete temp;
            borre = 1;        
        }
        while(temp != nullptr && !borre){
            if(temp->siguiente->elemento == elemento){
                Elemento * victima = temp->siguiente;
                temp->siguiente = victima->siguiente;
                victima->siguiente = 0;
                temp = victima;
                delete victima;
                borre=1; 
            }
            else{
                temp = temp->siguiente;
            }
        }
        numeroElementos--;
        if(!borre){
           // cout << "No se pudo borrar el elemento deseado, ya que el elemento no esta en la lista.\n";    
        }
    }
    else{
       //cout << "No se pudo borrar el elemento deseado, ya que la lista esta vacia.\n";
    }
}

//Primero(L) → e
//Efecto: Este operador devuelve , si existe, el primer elemento de la Lista_Ord Ordenada. Como la lista está ordenada ascendentemente el elemento que devuelva va a
//ser el del valor más bajo.
//Requiere: Una lista L inicializada.
//Modifica: Este operador no modifica nada dentro de la lista.
int Lista_Ord::primero(){
    int resultado = -1;
    if (primeraPosicion){
        resultado = primeraPosicion->elemento;
    }
    else{
       // cout << "La lista esta vacia, por lo que no se puede devolver un primer elemento.\n";
    }
    return resultado;
}

//Último(L) → e
//Efecto: Este operador devuelve , si existe, el último elemento de la Lista_Ord Ordenada. Como la lista está ordenada ascendentemente el elemento que devuelva va a
//ser el del valor más alto.
//Requiere: Una lista L inicializada.
//Modifica: Este operador no modifica nada dentro de la lista.
int Lista_Ord::ultimo(){
    int resultado = -1;
    if (ultimaPosicion){
        resultado = ultimaPosicion->elemento;
    }
    else{
        //cout << "La lista esta vacia, por lo que no se puede devolver un ultimo elemento.\n";
    }
    return resultado;
}

//Siguiente(e) → eSiguiente
//Efecto : Este operador devuelve , si existe, el elemento que está siguiente a e. Como la lista está ordenada ascendentemente el elemento que devuelva va a tener
//un valor mayor a e.
//Requiere: Una lista L inicializada.
//Modifica : Este operador no modifica nada dentro de la lista.
int Lista_Ord::siguiente(int elemento){
    Elemento * temp = primeraPosicion;
    int resultado = 0;
    if(temp){
        if(ultimaPosicion->elemento == elemento){
            resultado = -1;
           // cout << "El elemento deseado es el ultimo de la lista.\n";
        }
        else{
            int encontre = 0;
            while(temp!=nullptr && !encontre){
                if(temp->elemento == elemento){
                    resultado = temp->siguiente->elemento;
                    encontre = 1;
                }
                else{
                    temp = temp->siguiente;
                }
            }
            if(!encontre){
                //cout << "El elemento deseado no esta en la lista\n";
            }
        }
    }
    else{
        resultado = -1;
        //cout <<"La lista esta vacia.\n"<< endl;
    }
    return resultado;
}

//Anterior(e) → eAnterior
//Efecto: Este operador devuelve , si existe, el elemento que está anterior a e. Como la lista está ordenada ascendentemente el elemento que devuelva va a tener
//un valor menor a e.
//Requiere: Una lista L inicializada Además, es preferible que e no sea el primer elemento de la lista.
//Modifica: Este operador no modifica nada dentro de la lista.
int Lista_Ord::anterior(int elemento){
    Elemento * temp = primeraPosicion;
    int resultado = 0;
    if(temp){
        if(temp->elemento == elemento){
            resultado = -1;
            //cout << "El elemento deseado es el primero de la lista.\n";
        }
        else{
            int encontre = 0;
            while(temp!=nullptr && !encontre){
                if(temp->siguiente->elemento == elemento){
                    resultado = temp->elemento;
                    encontre = 1;
                }
                else{
                    temp = temp->siguiente;
                }
            }
            if(!encontre){
                //cout << "El elemento deseado no esta en la lista\n";
            }
        }
    }
    else{
        resultado = -1;
       // cout <<"La lista esta vacia.\n"<< endl;
    }    
    return resultado;
}

//NumElem(L) → número
//Efecto: Este operador cuenta la cantidad de elementos de la lista y devuelve un número que indica la cantidad de elementos que se encuentran en la lista.
//Requiere: Este operador requiere una lista L inicializada.
//Modifica: Este operador modifica al número que va a devolver. Si se quisiera como opción de diseño, se podría implementar un contador de elementos que
//incremente cada vez que se agrega algo. Si así fuera el caso no se modificaría nada.
int Lista_Ord::numElem(){
    return numeroElementos;
}

void Lista_Ord::imprimir(){
    cout << "{";
    if(primeraPosicion){
        primeraPosicion->imprimir();
    }
    cout << "}\n";
}

void Lista_Ord::Elemento::imprimir(){
    cout << elemento;
    if(siguiente){
        cout << " ";
        siguiente->imprimir();
    }
}

/* //void Lista_Ord::imprimirMenu(Lista_Ord * lista){
//   cout << "Bienvenido al programa de prueba de la lista ordenada implementada a través de una lista simplemente enlazada. Digite los dígitos correspondientes a los operadores básicos que desea usar:\n" << endl;
//  cout << "1. Iniciar.\n2. Destruir.\n3. Vaciar.\n4. Vacia.\n5. Agregar.\n6. Borrar.\n7. Primero.\n8. Ultimo.\n9. Siguiente.\n10. Anterior.\n11. NumElem\n12. Imprimir.\n13. Salir." << endl;
//int decision = 0;
//  if(!(cin >> decision)){
//    cin.clear();
//  cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
        imprimirMenu(lista);
    }
    else{
        if(0 < decision || 14 < decision){
            if(decision == 1){
                lista->iniciar();
                imprimirMenu(lista);
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
                lista->imprimirMenu(lista);
            }
            if(decision == 11){
                decision = lista->numElem(); 
                cout << "El numero de elementos de la lista es " <<decision<<".\n"<< endl ;
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
} */