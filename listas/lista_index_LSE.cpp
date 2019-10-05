#include "lista_index_LSE.h"
/*
Metodo Constructor de Lista_Index
*/
Lista_Index::Lista_Index(){
    this->inicio = 0;
    this->contador = 0;
    this->m = 0;
}

/*

Efecto: inicializa la lista. 
Requiere: que la lista exista. 
Modiﬁca :   1) parámetro contador con la cantidad de elementos, lo deja en 0. 
            2) reserva memoria estática suﬁciente para la cantidad de índices igual a la longitud del parámetro inicial.
*/
void Lista_Index::iniciar(int m){
    this->m = m;
    for(int i = 0; i < m; i++){
        crearCelda(i);
    }
}

/*
Efecto: Al ser una lista SE, se crea una nueva celda que va a poseer un elemento indice.
Requiere: Un parametro Indice.
Modifica: El espacio de memoria al pedir recursos a la pila.
*/
void Lista_Index::crearCelda(int indice){
    if(!inicio){
        Celda* nueva = new Celda(indice);
        inicio = nueva;
    }else{
        Celda* actual = inicio;
        while(actual->siguiente){
            actual = actual->siguiente;
        }
        Celda* nueva = new Celda(indice);
        actual->siguiente = nueva;
    }
}

/*
Metodo Propio el cual es el constructor de una Celda. 
Siempre necesita un parametro para inicializar cada celda.
*/
Lista_Index::Celda::Celda(int indice){
    this->indice = indice;
    this->elemento = elemntoNulo;
    this->siguiente = 0;
}

/*
Efecto : agrega un elemento a un índice de la lista 
Requiere : 1) que el índice sea un valor válido de 0 a M-1, donde M es la longitud máxima de la lista. 
           2) que la lista exista y se encuentre inicializada. 
           3) que el índice se encuentre entre el rango de 0 y la cantidad de elementos de la lista. 
Modiﬁca :  1) aumenta el contador de elementos que se encuentran en la lista.  
           2) cambia el valor contenido en el índice del vector al que se agrega.
*/
void Lista_Index::insertar(int indice, int elemento){
    //Se asume que ya se inicializo
    if(indice < m){
        Celda* actual = inicio;
            while(indice != actual->indice){
                actual = actual->siguiente;
            }
        actual->elemento = elemento;
        contador++;
    }
}

/*
Efecto : modiﬁca el elemento ubicado en la posición índice solicitado. 
Requiere : 1)Que la lista exista y se encuentre inicializada. 
           2)Que la lista no este vacia. 
           3)Que el índice sea un valor válido de 0 a M-1, donde M es la longitud máxima de la lista. 
           4)Que el índice solicitado sea menor a la cantidad de elementos de la lista. 
Modiﬁca : el elemento contenido en la posición indice de la lista.
*/
void Lista_Index::modificarElemento(int indice, int elemento){
    if(indice < m){
        Celda* actual = inicio;
        while(indice != actual->indice){
            actual = actual->siguiente;
        }
        actual->elemento = elemento;
    }
}

/*
Efecto : reduce la cantidad de elementos de la lista en una unidad, el borrado puede ser simbólico y no necesariamente físico. 
Requiere : 1) Que la lista exista y se encuentre inicializada. 
           2) Que el índice sea un valor válido de 0 a M-1, donde M es la longitud máxima de la lista. 
           3)Que dicho índice contenga un elemento, o que el índice ingresado sea menor a la cantidad de elementos de la lista. 
Modiﬁca : el contador de elementos.

*/
void Lista_Index::borrar(int indice){
    if(indice < m){
        Celda* actual = inicio;
        while(indice != actual->indice){
            actual = actual->siguiente;
        }
        if(actual->elemento != elemntoNulo){
            actual->elemento = elemntoNulo;
            contador--;
        }
    }
}

/*
Efecto : retorna la cantidad de elementos de la lista. 
Requiere : que la lista exista y se encuentre inicializada. 
Modiﬁca : no modiﬁca nada, solo retorna información ya existente.
*/
int Lista_Index::numElem(){
    return contador;
}

/*
Efecto : retorna una copia del elemento en el índice solicitado. 
Requiere : 1)Que la lista exista y se encuentre inicializada.
           2)Que la lista no este vacia. 
           3)Que el índice sea un valor válido de 0 a M-1, donde M es la longitud máxima de la lista.  
           4)Que el índice solicitado sea menor a la cantidad de elementos de la lista. 
Modiﬁca : no modiﬁca nada solo retorna información ya existente.
*/
int Lista_Index::recuperar(int indice){
    int elementoADevolver = 0;
    if(indice < m){
        Celda* actual = inicio;
        while(indice != actual->indice){
            actual = actual->siguiente;
        }
        elementoADevolver = actual->elemento;
    }
    return elementoADevolver;
}

/*
Efecto : Intercambia dos elementos existentes de una lista. 
Requiere : 1)Que ambos índices sean posiciones válidas, valores de 0 a M-1, donde M es la longitud máxima de la lista.
           2)Que la lista exista y se encuentre inicializada. 
           3)Que los índices sean menores a la cantidad de elementos actuales.(que dichos elementos existan en la lista) 
Modiﬁca : los elementos de los índices ingresados como parámetros.
*/
void Lista_Index::intercambiar(int indice1, int indice2){
    if(indice1, indice2  < m){
        int elemento3 = 0;
        Celda* actual1 = inicio;
        Celda* actual2 = inicio;
        while(indice1 != actual1->indice){
            actual1 = actual1->siguiente;
        }
        while(indice2 != actual2->indice){
            actual2 = actual2->siguiente;
        }
        elemento3 = actual2->elemento;
        actual2->elemento = actual1->elemento;
        actual1->elemento = elemento3;
    }
}

/*
Efecto : retorna un booleano de si la cantidad de elementos es igual a 0 o no. 
Requiere : que la lista exista y se encuentre inicializada. 
Modiﬁca : no modiﬁca nada, solo retorna información existente.
*/
bool Lista_Index::vacio(){
    bool estaVacio = true;
        if(inicio)
            estaVacio = false;
    return estaVacio;
}

/*
Efecto : vacía la lista de manera simbólica, ya que los datos continúan en la lista. 
Requiere : que la lista exista y se encuentre inicializada. 
Modiﬁca : Establece el contador de índices ocupados en 0.
*/
void Lista_Index::vaciar(){
    for(int i = 0; i < m; i++)
        borrar(i);
}

/*
Efecto: ninguno, se podría restaurar el contador de índices ocupados en 0, pero simplemente se hace al iniciar nuevamente. 
Requiere : que la lista exista y se encuentre inicializada. 
Modiﬁca : no modiﬁca nada.
*/
void Lista_Index::destruir(){
     if(inicio)
        delete inicio;
}

/*
Operador propio del modelo Lista_IndexIndexadaLSE. Nos permite liberar el espacio de memoria.
*/
Lista_Index :: ~Lista_Index(){
    if(inicio)
        delete inicio;
}

/*

*/
void Lista_Index :: imprimirLista_Index(){
    if(inicio){
        Celda* actual = inicio;
        while(actual){
            if(actual->indice == elemntoNulo){
                std::cout << "Indice : " << actual->indice << " Sin Elemento" << std:: endl;
            }else{
                std::cout << "Indice : " << actual->indice << " Elemento : " <<actual->elemento << std:: endl;
                }
            actual = actual->siguiente;
        }
    }
}

/*
Operador propio del modelo Lista_IndexIndexadaLSE. Nos permite liberar el espacio de memoria.
*/
Lista_Index :: Celda :: ~Celda(){
    if(this->siguiente)
        delete this->siguiente;
}