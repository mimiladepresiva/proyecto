#pragma once
#include "Coordenada.h"

class pieza
{
public:
	Coordenada *coordenaditas;
	
public:

	pieza(void);
	~pieza(void);

	void cubito();
	void inicializacion();

	friend class pieza;
};

