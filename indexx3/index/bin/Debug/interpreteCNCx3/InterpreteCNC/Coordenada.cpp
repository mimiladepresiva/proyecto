#include "Coordenada.h"


Coordenada::Coordenada(void)
{
	z = 0;
	x = 0;
	num_coor = 0;
	ant = nullptr;
}


Coordenada::~Coordenada(void)
{
}

void Coordenada::insertar(Coordenada *&bloque,int numCoor, float z, float x){
	Coordenada *nuevo = new Coordenada();
	nuevo->num_coor = numCoor;
	nuevo->x = x;
	nuevo->z = z;
	nuevo->ant = bloque;
	bloque = nuevo;
}


