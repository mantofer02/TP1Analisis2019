// #include "lista_index_LSE.h"
// #include "lista_index_array.h"
#include <iostream>

#define Ordenada 1
#define Posicionada 2
#define Indexada 3
#include <iostream>

#include "lista_index_LSE.h"
// #include "lista_index_array.h"

#include "lista_pos_Arreglo.h"

#include "lista_ord_array.h"
// #include "lista_ord_LSE.h"


using namespace std;

class Interfaz{
    private:
        //int esOrdenada;
        int tipoDeLista;
        int lengthParametro;
        int esIndexada;
        int esPosicionada;

        Lista_Index miListaIndexada;
        Lista_Ord miListaOrdena;

    public:
        Interfaz(){

            menu();
        }

        void menu(){
            cout << "Bienvenido " <<endl;
            cout << "Digite :" << endl;
            cout << "1: Si desea una lista Ordenada" << endl;
            cout << "2: Si desea una lista Posicionada" << endl;
            cout << "3: Si desea una lista Indexada" << endl;
            cin >> tipoDeLista;
        }

        void escogioListaOrdenada(){
            int operacion = 0;
            cout << "1) iniciar(int);" << endl;
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
            cin >> operacion;
            switch (operacion){
                case 1:
                    int parametro = 0;
                    cout << "Ingrese Parametro" << endl;
                    // NO SIRVE PARA LA ORDENADA ENLAZADA
                    miListaOrdena.iniciar(parametro);
                    break;
                case 2:
                    cout << "Se va a destruir la lista ordenada" << endl;
                    miListaOrdena.destruir();
                    break;
                case 3: 
                    cout << "Se va a vaciar la lista ordenada" << endl;
                    miListaOrdena.vaciar();
                    break;
                case 4:
                    if(miListaOrdena.vacia()){
                    cout << "Esta Vacia" << endl;
                    }else{
                        cout << "No esta vacia" << endl;
                    }
                    break;
                case 5:
                    cout << "Digite el elmento que desea agregar" << endl;
                    cin >> parametro;
                    miListaOrdena.agregar(parametro);
                    break;
                case 6:

                    
            }
        }

};