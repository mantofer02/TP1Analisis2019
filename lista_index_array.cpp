#include "lista_index_array.h"

#define TAMANYO 100

/*
Metodo Constructor de Lista_Index
*/

Lista_Index :: Lista_Index(){
    contador = 0;
    tamanyo = 0;
    size = TAMANYO;
    primerIndex = 0;
    ultimoIndex = 0;
}

Lista_Index :: Lista_Index(int algo){
    contador = 0;
    tamanyo = 0;
    size = algo;
    primerIndex = 0;
    ultimoIndex = 0;
}


int Lista_Index::siguiente(int indice) {			//VERIFICAR SI ESTO Y EL DE ANTERIOR ESTA CORRECTO. 
    int answer = indice; 
    answer++;
    if(answer > ultimoIndex){
        answer = ultimoIndex;
    } 
    return answer; 	
}

int Lista_Index::anterior(int indice) {
    int answer = indice; 
    --answer;
    if(answer < primerIndex){
        answer = primerIndex;
    } 				//esto podría llegar a darme un -1 ?. el indice 0 cuenta ?, o comienza en 1. 
    return answer; 	

}

/*
Efecto: inicializa la lista. 
Requiere: que la lista exista. 
Modiﬁca :   1) parámetro contador con la cantidad de elementos, lo deja en 0. 
            2) reserva memoria estática suﬁciente para la cantidad de índices igual a la longitud del parámetro inicial.
*/

void Lista_Index :: iniciar(){
    listaIndexada = new int[size + 1];
    tamanyo = size + 1;
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

void Lista_Index :: iniciar (int tamanyo){
    this->tamanyo = tamanyo + 1;
    listaIndexada = new int[tamanyo + 1];
    primerIndex = 0;
    ultimoIndex = 0;
    contador = 0;
}

/*
Efecto : agrega un elemento a un índice de la lista 
Requiere : 1) que el índice sea un valor válido de 0 a M-1, donde M es la longitud máxima de la lista. 
           2) que la lista exista y se encuentre inicializada. 
           3) que el índice se encuentre entre el rango de 0 y la cantidad de elementos de la lista. 
Modiﬁca :  1) aumenta el contador de elementos que se encuentran en la lista.  
           2) cambia el valor contenido en el índice del vector al que se agrega.
*/

void Lista_Index :: agregar(int indice, int elemento){
    if(this->vacia()){
        agregarAlFinal(elemento);
    }else{
        if(indice == primerIndex){
            agregarAlInicio(elemento);
        }else{
            if(indice == ultimoIndex){
                agregarAlFinal(elemento);
            }else{
                if(indice < ultimoIndex && indice > primerIndex){
                    if(ultimoIndex < tamanyo - 1){
                        ultimoIndex++;
                        contador++;
                    }
                    for(int i = ultimoIndex; i > indice; i--){
                        listaIndexada[i] = listaIndexada[i - 1];
                    }
                    listaIndexada[indice] = elemento;
                }
            }
        }
    }
}

void Lista_Index:: agregarAlInicio(int elemento){
    if(primerIndex == 0 && ultimoIndex == 0){
        primerIndex++;
    }
    if(ultimoIndex < tamanyo - 1){
        ultimoIndex++;
        contador++;
    }
    for(int i = ultimoIndex; i >= primerIndex; i--){
        listaIndexada[i] = listaIndexada[i - 1];
    }
    listaIndexada[primerIndex] = elemento;
}



void Lista_Index :: agregarAlFinal(int elemento){
    if(primerIndex == 0 && ultimoIndex == 0){
        primerIndex++;
    }
    if(ultimoIndex < tamanyo - 1){
        ultimoIndex++;
        contador++;
    }
    listaIndexada[ultimoIndex] = elemento;
}

/*
Efecto : vacía la lista de manera simbólica, ya que los datos continúan en la lista. 
Requiere : que la lista exista y se encuentre inicializada. 
Modiﬁca : Establece el contador de índices ocupados en 0.
*/

void Lista_Index :: vaciar(){
    primerIndex = 0;
    ultimoIndex = 0;
    contador = 0;
}

/*
Efecto : retorna un booleano de si la cantidad de elementos es igual a 0 o no. 
Requiere : que la lista exista y se encuentre inicializada. 
Modiﬁca : no modiﬁca nada, solo retorna información existente.
*/

int Lista_Index :: vacia(){
    int estaVacia = 0;
    if(primerIndex == 0 && ultimoIndex == 0 && contador == 0){
        estaVacia = 1;
    }
    return estaVacia;
}

/*
Efecto: ninguno, se podría restaurar el contador de índices ocupados en 0, pero simplemente se hace al iniciar nuevamente. 
Requiere : que la lista exista y se encuentre inicializada. 
Modiﬁca : no modiﬁca nada.
*/


void Lista_Index :: destruir(){
    delete listaIndexada;
}

/*
Operador propio del modelo Lista_IndexIndexadaLSE. Nos permite liberar el espacio de memoria.
*/

Lista_Index :: ~Lista_Index(){
     if (listaIndexada){
        delete[] listaIndexada;
    }
   
}

/*
Efecto : reduce la cantidad de elementos de la lista en una unidad, el borrado puede ser simbólico y no necesariamente físico. 
Requiere : 1) Que la lista exista y se encuentre inicializada. 
           2) Que el índice sea un valor válido de 0 a M-1, donde M es la longitud máxima de la lista. 
           3)Que dicho índice contenga un elemento, o que el índice ingresado sea menor a la cantidad de elementos de la lista. 
Modiﬁca : el contador de elementos.
*/

void Lista_Index :: borrar(int indice){
    int indiceActual = primerIndex;
    if(indice == ultimoIndex){
        ultimoIndex--;
        contador--;
    }else{
        if(indice < ultimoIndex && indice >= primerIndex){
            indiceActual = indice;
            while(indiceActual < ultimoIndex){
                listaIndexada[indiceActual] = listaIndexada[indiceActual + 1];
                indiceActual++;
            }
        ultimoIndex--;
        contador--;
        if(ultimoIndex == 0){
            primerIndex = 0;
        }
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

int Lista_Index :: recuperar(int indice){
    int elemento = 0;
    if(indice >= primerIndex && indice <= ultimoIndex)
        elemento = listaIndexada[indice];
    
    return elemento;
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
    if(indice >= primerIndex && indice <= ultimoIndex)
        listaIndexada[indice] = elemento;
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
        int elementoAux = listaIndexada[indice1];
        listaIndexada[indice1] = listaIndexada[indice2];
        listaIndexada[indice2] = elementoAux;
    }
}

int Lista_Index :: primerIndice(){
    return primerIndex;
}

int Lista_Index :: ultimoIndice(){
    return ultimoIndex;
}

void Lista_Index :: imprimirLista(){
    if(listaIndexada){
        if(!(this->vacia())){
            for(int i = primerIndex; i <= ultimoIndex; i++)
                std :: cout << "Indice : " << i << " Elemento : " << listaIndexada[i] << std :: endl;
        }
    }
}
