#include "lista_index_array.h"
#define M 20


/*
Metodo Constructor de Lista_Index
*/
Lista_Index::Lista_Index(){
    this->m = 0;
}


/*

Efecto: inicializa la lista. 
Requiere: que la lista exista. 
Modiﬁca :   1) parámetro contador con la cantidad de elementos, lo deja en 0. 
            2) reserva memoria estática suﬁciente para la cantidad de índices igual a la longitud del parámetro inicial.

*/
void Lista_Index::iniciar(){
    this->m = M;
    listaIndexa = new int[m];
    for (int i = 0; i < m; i++){
        agregar(i, elementoNulo);
    }
    contador = 0;
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
Efecto : retorna un booleano de si la cantidad de elementos es igual a 0 o no. 
Requiere : que la lista exista y se encuentre inicializada. 
Modiﬁca : no modiﬁca nada, solo retorna información existente.
*/
bool Lista_Index::vacia(){
    bool estaVacio = false;
    if(contador == 0)
        estaVacio = true;
    return estaVacio;
}

/*
Efecto: ninguno, se podría restaurar el contador de índices ocupados en 0, pero simplemente se hace al iniciar nuevamente. 
Requiere : que la lista exista y se encuentre inicializada. 
Modiﬁca : no modiﬁca nada.
*/
void Lista_Index::destruir(){
    delete[] listaIndexa;
    contador = 0;
    
}

/*
Operador propio del modelo Lista_IndexIndexadaLSE. Nos permite liberar el espacio de memoria.
*/
Lista_Index :: ~Lista_Index(){
    delete[] listaIndexa;
}

/*
Efecto : agrega un elemento a un índice de la lista 
Requiere : 1) que el índice sea un valor válido de 0 a M-1, donde M es la longitud máxima de la lista. 
           2) que la lista exista y se encuentre inicializada. 
           3) que el índice se encuentre entre el rango de 0 y la cantidad de elementos de la lista. 
Modiﬁca :  1) aumenta el contador de elementos que se encuentran en la lista.  
           2) cambia el valor contenido en el índice del vector al que se agrega.
*/
void Lista_Index::agregar(int indice, int elemento){
    if(indice < m)
        listaIndexa[indice] = elemento;
        contador++;
}

/*
Efecto : reduce la cantidad de elementos de la lista en una unidad, el borrado puede ser simbólico y no necesariamente físico. 
Requiere : 1) Que la lista exista y se encuentre inicializada. 
           2) Que el índice sea un valor válido de 0 a M-1, donde M es la longitud máxima de la lista. 
           3)Que dicho índice contenga un elemento, o que el índice ingresado sea menor a la cantidad de elementos de la lista. 
Modiﬁca : el contador de elementos.
*/
void Lista_Index::borrar(int indice){
    if(indice < m)
        if(listaIndexa[indice]!= elementoNulo){
            listaIndexa[indice] = elementoNulo;
            contador--;
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
int Lista_Index::recuperar(int indice){
    int elementoAdevolver = elementoNulo;
    if(indice < m)
        elementoAdevolver = listaIndexa[indice];
    return elementoAdevolver;
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
    if(indice < m)
        listaIndexa[indice] = elemento;
}

/*
Efecto : Intercambia dos elementos existentes de una lista. 
Requiere : 1)Que ambos índices sean posiciones válidas, valores de 0 a M-1, donde M es la longitud máxima de la lista.
           2)Que la lista exista y se encuentre inicializada. 
           3)Que los índices sean menores a la cantidad de elementos actuales.(que dichos elementos existan en la lista) 
Modiﬁca : los elementos de los índices ingresados como parámetros.
*/
void Lista_Index::intercambiar(int indice1, int indice2){
    int elementoAux = 0;
    if(indice1, indice2 < m){
        elementoAux = listaIndexa[indice1];
        listaIndexa[indice1] = listaIndexa[indice2];
        listaIndexa[indice2] = elementoAux;
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

void Lista_Index::imprimirLista(){
    for(int i = 0; i < m; i++){
        if(listaIndexa[i] == elementoNulo){
            std::cout << "Indice : " << i << " Sin Elemento" << std:: endl;
        }else{    
            std::cout << "Indice : " << i << " Elemento : " << listaIndexa[i] << std:: endl;
        }
    }
}