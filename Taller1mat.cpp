#include <iostream>
using namespace std;

struct Pila{
    int dato;
   Pila *prox;
};

struct Nodo {
    int dato;
     Nodo *previo;
     Nodo *prox;
};

bool listaVacia(Nodo *inicio) {
    return inicio == NULL;
}

void insertarUltimo(Nodo **inicio, int valor){
    Nodo *nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->previo = NULL;
    nuevo->prox = NULL;    
    if (listaVacia(*inicio))
       *inicio = nuevo;
    else {
       Nodo *actual = *inicio;
        while (actual->prox != NULL) {
            actual = actual->prox;
        }
        actual->prox = nuevo;
        actual->prox->previo = actual;
    }
}

void mostrarLista(Nodo *inicio) {
    if (!listaVacia(inicio)) {
        Nodo *actual = inicio;
        while (actual != NULL) {
            cout << actual->dato << "->"; 
            actual = actual->prox;
        }
    cout<<"NULL"<<endl;
    } else {
        cout << "La lista esta vacia" << endl;
    }
}

void eliminarDuplist(Nodo** inicio){
    if(!listaVacia(*inicio)){
        Nodo* mover = NULL;
        Nodo* borrar =NULL; 
        Nodo* subcomienzo = *inicio;
        while(subcomienzo->prox != NULL){
            mover = subcomienzo->prox;
            while(mover != NULL){
                if(mover->dato == subcomienzo->dato){ 
                    mover->previo->prox = mover->prox;
                    if(mover->prox != NULL)
                        mover->prox->previo = mover->previo,
                    borrar = mover;
                    mover = mover->prox;
                    delete borrar;
                } else{
                    mover = mover->prox;
                }
            }
            subcomienzo = subcomienzo->prox;
        } 
    }
    else{
        cout<<"La lista esta vacia"<<endl;
    }
}

Pila* crearPila(int valor){
    Pila *nuevo = new Pila;
    nuevo->dato = valor;
    nuevo->prox = NULL;
    return nuevo;
}

bool PilaVacia(Pila *pila){
    return pila==NULL;
}

Pila*  Tope(Pila *pila){
    if (!PilaVacia(pila))
    return pila; 
    else   
    return nullptr;    
}

void Apilar(Pila **pila, int valor){
   Pila *nuevo = crearPila(valor);
    nuevo->prox=*pila;
   *pila=nuevo;
}

void Desapilar(Pila **pila){
    if (!PilaVacia(*pila))
         *pila = (*pila)->prox; 
    else
        cout<<"Pila vacia imposible desapilar "<<endl;
}

void mostrarPila(Pila *pila){
    while (!PilaVacia(pila)) {
    cout <<Tope(pila)->dato<< "  ";
    Desapilar(&pila);
    }
}

//FUNCIONES ESPECIALES
bool buscarEnPila(Pila* pila, int valor){
    while(!PilaVacia(pila)){
        if(Tope(pila)->dato == valor)
            return true;
        else 
            Desapilar(&pila);
    }
    return false;
}

void eliminarDup(Pila **pila){
    Pila *pilaAux = NULL;
    if(PilaVacia(*pila))
        return;
    while(!PilaVacia(*pila)){
        int valor = Tope(*pila)->dato;
        Desapilar(pila);
        if(!buscarEnPila(pilaAux, valor))
            Apilar(&pilaAux,valor);    
    }
    while(!PilaVacia(pilaAux)){
        Apilar(pila, Tope(pilaAux)->dato);
        Desapilar(&pilaAux);
    }
}

Pila* mezclar(Pila* pila1, Pila* pila2){
    Pila* pila3 = NULL;
    while(!PilaVacia(pila1) && !PilaVacia(pila2)){
        Apilar(&pila3, Tope(pila1)->dato);
        Apilar(&pila3, Tope(pila2)->dato);
        Desapilar(&pila1);
        Desapilar(&pila2);
    }
    if(PilaVacia(pila1)){
        while(!PilaVacia(pila2)){
            Apilar(&pila3, Tope(pila2)->dato);
            Desapilar(&pila2);
        }  
    } else{
        while(!PilaVacia(pila1)){
            Apilar(&pila3, Tope(pila1)->dato);
            Desapilar(&pila1);
        }  
    }
    return pila3;
}

void llenarPila(Pila **pila, string mensaje){
    int cantidad,i,valor; 
    cout<<"Indica cantidad de elementos a ser colocados en la : "<<mensaje<<endl;
    cin>>cantidad; i=0;
    while (i != cantidad) {
        cout << "Indica valor a colocar: ";
        cin>>valor;
        Apilar(pila,valor);
        i++;
    }
}

void intercambiarPilas(Pila **pila1, Pila **pila2){
    Pila *PilaAux = NULL;
    while(!PilaVacia(*pila1)){
        Apilar(&PilaAux,Tope(*pila1)->dato);
        Desapilar(pila1);
    }
    while(!PilaVacia(*pila2)){
        Apilar(pila1,Tope(*pila2)->dato);
        Desapilar(pila2);
    }
    while(!PilaVacia(PilaAux)){
        Apilar(pila2,Tope(PilaAux)->dato);
        Desapilar(&PilaAux);
    }  
}
main(){

    cout<<"PRIMER EJERCICIO: "<<endl;
    Nodo* primero = NULL;
    int n = 0;
    int i = 0;
    int valor = 0;

    cout<<"Indica cantidad de elementos a ser agregados: "<<endl;
    cin>>n;
    while (i != n){
        cout<<"Indica valor: ";
        cin>>valor;
        insertarUltimo(&primero,valor);
        i++;
    }

    cout<<"La lista dada es: "<<endl;
    mostrarLista(primero);

    eliminarDuplist(&primero);

    cout<<"La lista sin elementos duplicados es: "<<endl;
    mostrarLista(primero);


    cout<<"SEGUNDO EJERCICIO: "<<endl;
    int cantidad = 0;
    int i = 0;
    int valor = 0; 
    Pila *pila = NULL;
    cout<<"Indica cantidad de elementos a ser colocados en la pila: ";
    cin>>cantidad; i=0;
  while (i != cantidad) {
      cout << "Indica valor a colocar: ";
      cin>>valor;
      Apilar(&pila,valor);
      i++;
   }

cout<<"Contenido de la Pila: "<<endl;
mostrarPila(pila);

} 