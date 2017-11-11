#pragma once
#include <string>
#include <iostream>
using namespace std;

class Nodo{
public:
	int grupo, linea;
	float valor;
	string comm;
	Nodo *ant;

public:
	Nodo(void);
	~Nodo(void);
	void insertar(Nodo *&, int, float, string, int);
	void invertir(Nodo *, Nodo *&);
	

};

