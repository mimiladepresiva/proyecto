#include "Nodo.h"


Nodo::Nodo(void){
	ant=NULL;
}

Nodo::~Nodo(void)
{
}

//inserccion de nuevo nodo
void Nodo::insertar(Nodo *&bloque,int gpo, float vlor, string com, int Nlinea){
	Nodo *nuevo = new Nodo();
	nuevo->valor = vlor;
	nuevo->grupo = gpo;
	nuevo->comm = com;
	nuevo->linea = Nlinea;
	nuevo->ant = bloque;
	bloque = nuevo;
}

//mueve el primer nodo a la ultima posicion .
void Nodo::invertir(Nodo *bloque, Nodo *&aux){
	Nodo *nuevo = NULL;
	aux = NULL;
	while(bloque != NULL){
		aux->insertar(aux, bloque->grupo, bloque->valor, bloque->comm, bloque->linea);
		bloque=bloque->ant;	
	}

	//visualiza el nodo: eliminar comentarios
	//nuevo=aux;
	//while(nuevo != NULL){
	//			cout<<nuevo->comm;
	//			nuevo=nuevo->ant;		
	//}
	
	
}
