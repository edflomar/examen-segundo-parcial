#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *i;
	Nodo *d;
};

Nodo *nuevoNodo(int);
void insertarArbol(Nodo *&,int);
void imprimirDatos(Nodo *,int,int &,int &);

int main(){
	/*sol es igual a 1
	aguila es igual a 2*/
	int contador=0;
	int contador2=0;
	int contador3=0;
	Nodo *arbol=NULL;
	int num;
	int cantidad;
	srand(time(NULL));
	cout<<"\nIngresar el numero de veces que desea tirar la moneda: "; cin>>cantidad;
	for(int i=0; i<cantidad; i++){
		num=1+rand()%(3-1);
		insertarArbol(arbol,num);
	}
	imprimirDatos(arbol,contador3,contador,contador2);
	cout<<"\nSol cayo : "<<contador<<" veces"<<endl;
	cout<<"\nAguila cayo:  "<<contador2<<" veces"<<endl;
	
	getch();
	return 0;
}

Nodo *nuevoNodo(int dato){
	Nodo *nNodo = new Nodo();
	nNodo->dato=dato;
	nNodo->d=NULL;
	nNodo->i=NULL;
	
	return nNodo;
}

void insertarArbol(Nodo *&arbol,int dato){
	if(arbol==NULL){
		Nodo *nuevoNodo2 = nuevoNodo(dato);
		arbol = nuevoNodo2;
	}else if(dato < arbol->dato){
		insertarArbol(arbol->i,dato);
	}else{
		insertarArbol(arbol->d,dato);
	}
}

void imprimirDatos(Nodo *arbol,int contador3,int &contador,int &contador2){
	
	if(arbol == NULL){
		return;
	}else{
		imprimirDatos(arbol->d,contador3+1,contador,contador2);
		if(arbol->dato==1){
			contador +=1;
		}else{
			contador2 +=1;
		}
		for(int i=0; i<contador3; i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		imprimirDatos(arbol->i,contador3+1,contador,contador2);
	}
	
}
