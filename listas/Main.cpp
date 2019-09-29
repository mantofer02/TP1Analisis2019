#include "lista_ord_LSE.h"

int main(){

    Lista * lista = new Lista();
    lista->iniciar(10);
    
    for(int i=1;i<11;i++){
        lista->agregar(i);
    }
        
    lista->imprimir();
    
    for(int k=4;k<7;k++){
        lista->borrar(k);
    }
    
    lista->imprimir();

    int resultado = lista->vacia();
    cout << resultado << "\n";
    resultado = lista->numElem();
    cout << resultado << "\n";
    resultado = lista->primero();
    cout << resultado << "\n";
    resultado = lista->ultimo();
    cout << resultado << "\n";
    resultado = lista->siguiente(3);
    cout << resultado << "\n";
    resultado = lista->anterior(10);
    cout << resultado << "\n";
    lista->vaciar();
    lista->imprimir();
    cout << lista->primero() << "\n";
    cout << lista->ultimo() << "\n";
    lista->destruir();
    return 0;
}