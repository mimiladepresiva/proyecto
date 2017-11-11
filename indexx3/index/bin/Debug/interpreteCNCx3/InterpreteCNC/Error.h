#pragma once
#include <string>
using namespace std;

class Error
{
public:
	int linea; //linea de ubicacion de error
	string Descripcion, palabra; //descripcion de error, comando erroneo
	Error *sig;
public:
	Error(void);
	~Error(void);
	void SuperError(Error *&, string, string, int); //inserccion de nodo
};

