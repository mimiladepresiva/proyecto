#pragma once
#include <string>
#include "Error.h"
#include "Nodo.h"
#include "Sintactico.h"
class Semanticox2
{
public:
	Error *errorsitos3;
	string codigo;
	Nodo *instruccion[9999], *nSintac[9999];
	Nodo *muerte;
	Nodo *nuevo;
	int conBloq, nose, conG;
	bool f; //
	Semanticox2(void);
	void start(Sintactico,int);
	~Semanticox2(void);
	Error* GetErrores(){return errorsitos3;} //retorna los errores encontrados por funcion "sintaxis"
	void analizadorG();
};


