#pragma once
#include "Nodo.h"
#include "pieza.h"
#include "maquina.h"
#include <string>
#include <gl\glut.h>
using namespace std;

class Dibujo
{
	maquina *mMaquina ;
	bool codigo, cuadricula, codigo1, escala, frontal,isometrico, lateral,superior,taristas,locultas,solido,altura,radio;
	float xpieza, zpieza, unidad;
	//Nodo* bloque[9999];
	int numBloque;


public:
	Dibujo();
	~Dibujo(void);
	void inicializacionpantalla();
	void configuracion(string );
	bool Getcodigo(){return codigo;}
	bool Getcodigo1(){return codigo1;}
	void Setcodigo1(bool codigo1N){codigo1 = codigo1N;}
	void Dibujo::igualacion();
	void SetNodo(Nodo *, int);

	
};

