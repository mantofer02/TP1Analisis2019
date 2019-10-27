#include "lista_index_LSE.h"

/*
Metodo Constructor de Lista_Index
*/
Lista_Index :: Lista_Index(){
    primera = 0;
    ultima = 0;
    primerIndex = 0;
    ultimoIndex = 0;
    contador = 0;
}
/*
Efecto: inicializa la lista. 
Requiere: que la lista exista. 
Modiﬁca :   1) parámetro contador con la cantidad de elementos, lo deja en 0. 
            2) reserva memoria estática suﬁciente para la cantidad de índices igual a la longitud del parámetro inicial.
*/
void Lista_Index :: iniciar(){
    primera = 0;
    ultima = 0;
    primerIndex = 0;
    ultimoIndex = 0;
    contador = 0;
}

/*
Efecto: ninguno, se podría restaurar el contador de índices ocupados en 0, pero simplemente se hace al iniciar nuevamente. 
Requiere : que la lista exista y se encuentre inicializada. 
Modiﬁca : no modiﬁca nada.
*/
void Lista_Index :: destruir(){
    if(primera){
        Celda * actual = primera;
        while(primera->siguiente){
            actual = primera;
            while(actual->siguiente->siguiente){
                actual = actual->siguiente;
            }
            delete actual->siguiente;
        }
        delete primera;
        ultima = 0;
    }
}

/*
Efecto : Intercambia dos elementos existentes de una lista. 
Requiere : 1)Que ambos índices sean posiciones válidas, valores de 0 a M-1, donde M es la longitud máxima de la lista.
           2)Que la lista exista y se encuentre inicializada. 
           3)Que los índices sean menores a la cantidad de elementos actuales.(que dichos elementos existan en la lista) 
Modiﬁca : los elementos de los índices ingresados como parámetros.
*/

void Lista_Index :: intercambiar(int indice1, int indice2){
    if(indice1 >= primerIndex && indice1 <= ultimoIndex && indice2 >= primerIndex && indice2 <= ultimoIndex){
        Celda * actual1 = primera;
        Celda * actual2 = primera;
        
        for(int i = 1; i < indice1; i++){
            actual1 = actual1->siguiente;
        }

        for (int j = 0; j < indice2; j++){
            actual2 = actual2->siguiente;
        }
        
        int elementoAux = actual1->elemento;
        actual1->elemento = actual2->elemento;
        actual2->elemento = elementoAux;
    }
}

/*
Efecto : retorna una copia del elemento en el índice solicitado. 
Requiere : 1)Que la lista exista y se encuentre inicializada.
           2)Que la lista no este vacia. 
           3)Que el índice sea un valor válido de 0 a M-1, donde M es la longitud máxima de la lista.  
           4)Que el índice solicitado sea menor a la cantidad de elementos de la lista. 
Modiﬁca : no modiﬁca nada solo retorna información ya existente.
*/

int Lista_Index :: recuperar(int indice){
    int aDevolver = 0;
    
    if(indice >= primerIndex && indice <= ultimoIndex){
        Celda * actual = primera;
        for(int i = 1; i < indice; i++){
            actual = actual->siguiente;
        }
    
        aDevolver = actual->elemento;
    }

    return aDevolver;

}


/*
Efecto : modiﬁca el elemento ubicado en la posición índice solicitado. 
Requiere : 1)Que la lista exista y se encuentre inicializada. 
           2)Que la lista no este vacia. 
           3)Que el índice sea un valor válido de 0 a M-1, donde M es la longitud máxima de la lista. 
           4)Que el índice solicitado sea menor a la cantidad de elementos de la lista. 
Modiﬁca : el elemento contenido en la posición indice de la lista.
*/

void Lista_Index :: modificar(int indice, int elemento){
    if(indice >= primerIndex && indice <= ultimoIndex){
        Celda * actual = primera;
        for(int i = 1; i < indice; i++){
            actual = actual->siguiente;
        }

        actual->elemento = elemento;
    }
}


/*
Efecto : agrega un elemento a un índice de la lista 
Requiere : 1) que el índice sea un valor válido de 0 a M-1, donde M es la longitud máxima de la lista. 
           2) que la lista exista y se encuentre inicializada. 
           3) que el índice se encuentre entre el rango de 0 y la cantidad de elementos de la lista. 
Modiﬁca :  1) aumenta el contador de elementos que se encuentran en la lista.  
           2) cambia el valor contenido en el índice del vector al que se agrega.
*/

void Lista_Index :: agregar(int elemento){
    if(!primera){
        Celda * nueva = new Celda(elemento);
        primera = nueva;
        ultima = nueva;
        primerIndex++;
        ultimoIndex++;
        contador++;
    }else{
        Celda * nueva = new Celda(elemento);
        ultima->siguiente = nueva;
        ultima = nueva;
        ultimoIndex++;
        contador++;
    }
}

/*
Efecto : retorna la cantidad de elementos de la lista. 
Requiere : que la lista exista y se encuentre inicializada. 
Modiﬁca : no modiﬁca nada, solo retorna información ya existente.
*/


int Lista_Index :: numElem(){
    return contador;
}

int Lista_Index :: primerIndice(){
    return primerIndex;
}

int Lista_Index :: ultimoIndice(){
    return ultimoIndex;
}


/*
Efecto : vacía la lista de manera simbólica, ya que los datos continúan en la lista. 
Requiere : que la lista exista y se encuentre inicializada. 
Modiﬁca : Establece el contador de índices ocupados en 0.
*/

void Lista_Index :: vaciar(){
    destruir();
    contador = 0;
    primerIndex = 0;
    ultimoIndex = 0;
}

/*
Operador propio del modelo Lista_IndexIndexadaLSE. Nos permite liberar el espacio de memoria.
*/

Lista_Index :: ~Lista_Index(){
    //destruir();
    //Arreglar
}

/*
Efecto : retorna un booleano de si la cantidad de elementos es igual a 0 o no. 
Requiere : que la lista exista y se encuentre inicializada. 
Modiﬁca : no modiﬁca nada, solo retorna información existente.
*/

int Lista_Index :: vacia(){
    int estaVacia = 0;
    if(!primera)
        estaVacia = 1;
    return estaVacia;
}


/*
Efecto : reduce la cantidad de elementos de la lista en una unidad, el borrado puede ser simbólico y no necesariamente físico. 
Requiere : 1) Que la lista exista y se encuentre inicializada. 
           2) Que el índice sea un valor válido de 0 a M-1, donde M es la longitud máxima de la lista. 
           3)Que dicho índice contenga un elemento, o que el índice ingresado sea menor a la cantidad de elementos de la lista. 
Modiﬁca : el contador de elementos.

*/
void Lista_Index :: borrar(int indice){
    if(indice >= primerIndex && indice <= ultimoIndex){
        Celda * actual = primera;
        if(indice == 1){
            primera = actual->siguiente;
            delete actual;
        }else{
            for(int i = 0; i < indice; i++){
                actual = actual->siguiente;
            }
            if(actual->siguiente == ultima)
                ultima = actual;
            Celda * aBorrar = actual->siguiente;

            if(aBorrar->siguiente){
                actual->siguiente = aBorrar->siguiente;
            }
            delete aBorrar;
        }
    }
}

void Lista_Index :: imprimirLista(){
    if(primera){
        Celda * actual = primera;
        int i = 1;
        while(actual){
            std :: cout << "Indice : " << i << " Elemento : " << actual->elemento << std :: endl;
            i++;
            actual = actual->siguiente;
        }
    }
}

Lista_Index :: Celda :: Celda(int elemento){
    this->elemento = elemento;
    siguiente = 0;
}