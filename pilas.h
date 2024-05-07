#ifndef_pilas
#define_pilas
#include <iostream>

struct Node{
    int valor;
    Node *prx;
};

bool validar(Node *p){
    if(p)
        return false;
    return true;
}

int desapilar(Node **p){
    Node *aux = *p;
    *p = (*p) -> prx;
    int valor = aux->valor;
    delete aux;
    return valor;
}

void apilar(Node **p, int valor){
    Node *aux = new Node;
    aux -> valor = valor;
    aux -> prx = *p;
    *p = aux;
    aux = NULL;
    delete aux;
}
#endif