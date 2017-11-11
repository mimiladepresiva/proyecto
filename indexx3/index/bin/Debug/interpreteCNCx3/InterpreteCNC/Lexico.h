#pragma once
#include "Error.h"
#include "Nodo.h"
#include "Tab.h"

class Lexico{
private:

	Tab comparacion;
	Error *errorsitos;
	Nodo *bloque;
	string tokens[100];//almacena los elementos de un bloque
	int conToken, porciento; // contador de nuemero de elementos

public:
	Lexico(void);
	~Lexico(void);
	void separacion(string line); //separa cadenas por espacios
	Nodo* comprobacion(int Nlinea); // verifica que sean validos
	Error* GetError(){return errorsitos;}
	string ifdig(char*);
	float conver(string);
};

