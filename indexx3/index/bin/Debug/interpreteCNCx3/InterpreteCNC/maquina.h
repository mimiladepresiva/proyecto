#pragma once
#include <string>
#include <gl\glut.h>
using namespace std;

class maquina
{
public:

	bool husillo, avance, sistemaProgramacion, sentidoGiro;// gira = 1, nogira:0// 1 = min, 0 = rev // 1 = pulgadas, 0 milimetros // 0 = horario, 1 = antihorario;
	float f, x, z,  x_A, z_A, u, w;
	

	string comgActivoM, comgActivoNM;
	int commActivo, nbloque, herramienta, velmax, vel;


	maquina(void);
	~maquina(void);
	
};

