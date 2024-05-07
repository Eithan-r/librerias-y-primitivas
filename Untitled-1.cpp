#include <iostream>
#include "pilas.h"

using namespace std;

void imprimir(Node *p){
    int x;
    if(p){
        cout << p->valor << endl;
        x = desapilar(&p);
        imprimir(p);
        apilar(&p,x);
    }
}

Node* suma(){}

int bajar(Node **p){
    if(!validar(*p)){
        int x = desapilar(p);
        bajar(p);
        apilar(p,x);
    }
}

void ayuda(Node **p1,Node **p2){
    if((!validar(*p1)) && (!validar(*p2))){
        int x = desapilar(p1), y = desapilar(p2);
        ayuda(p1,p2);
        apilar(p1,x);
        apilar(p2,y);
    }
    else{
        if(!validar(*p1)){
            
        }
        else{
            if(!validar(*p2)){
                int j = desapilar(p2);
                ayuda(p1,p2);
                apilar(p2,j);
            }
            else{

            }
        }
    }
}

int main(){
    Node *p1 = NULL, *p2 = NULL;
    apilar(&p1,3);
    apilar(&p1,9);
    apilar(&p1,5);
    apilar(&p1,1);
    apilar(&p2,1);
    apilar(&p2,5);
    apilar(&p2,4);
    imprimir(p1);
    imprimir(p2);
    ayuda(&p1,&p2);
    system("pause");


    return 0;
}

/*int main() {
	int resp;
    Node *p = NULL;
	do {
        system("cls");
		cout << "MENU\n\n";
		cout << "1) Insertar elemento en la pila\n";
		cout << "2) Imprimir pila\n";
		cout << "3) Eliminar elementos repetidos\n";
		cout << "0) Salir\n\n";
		cout << "\tMarque su opcion: ";
		cin >> resp;
        switch (resp) {
            case 0: {
                cout << "\nFinalizando programa\n\n";
                system("pause");
                system("cls");            
            } break;

            case 1: {
                int element;
                cout << "\tIngrese el elemento a insertar: ";
                cin >> element;
                apilar(&p, element);
            } break;

            case 2: {
                imprimir(p);
                cout << endl;
                system("pause");
            } break;

            case 3: {
                EliminarRepetidos(&p, 0);
                cout << "Repetidos Eliminados\n\n";
                system("pause");
                system("cls");
            } break;

            case 4: {
            } break;

            default:
                cout << "Opción no valida";
                break;
        }
		
    } while(resp);
    return 0;
}*/