#pragma once
#include <string>
#include "Error.h"
#include "Nodo.h"
class Sintactico
{
public:
	Error *errorsitos2;
	string codigo;
	Nodo *instruccion[9999], *nSintac[9999];
	Nodo *muerte;
	Nodo *nuevo;
	int conBloq, con_aux, conG;
	bool f; //
	
public:
	Sintactico(void);
	~Sintactico(void);
	void iniciaNodo(Nodo *&bloque); 
	void analizador(Nodo *bloque, int &contInst, int conbloqueMain, int y);
	void sintaxis(); 
	Nodo* GetInstruccion(int contInst); 
	void mostrar(int conInstr); 
	int commG00(Nodo*); //revisa sintaxis codigo G00
	int commG01(Nodo*); //revisa sintaxis codigo G01
	int commG02_3(Nodo*); //revisa sintaxis codigo G02 y G03
	int commG04(Nodo*); //revisa sintaxis codigo G04
	int commG28(Nodo*); //revisa sintaxis codigo G28
	int commG50(Nodo*);//revisa sintaxis codigo G50
	int commG70(Nodo*);//revisa sintaxis codigo G70
	int commG71(Nodo*, int );//revisa sintaxis codigo G71
	int commG72(Nodo*, int);//revisa sintaxis codigo G72
	int commG74(Nodo*, int);//revisa sintaxis codigo G74
	int commG75(Nodo*, int);//revisa sintaxis codigo G75
	int commG76(Nodo*, int);//revisa sintaxis codigo G76
	int commG96(Nodo*);//revisa sintaxis codigo G96
	int commG99(Nodo*);//revisa sintaxis codigo G99
	Error* GetErrores(){return errorsitos2;} //retorna los errores encontrados por funcion "sintaxis"
	void mostrar2();
	
};

