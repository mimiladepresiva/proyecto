#pragma once
class Coordenada
{

public:
	float x, z;
	int num_coor;
	Coordenada *ant;

public:
	Coordenada(void);
	~Coordenada(void);
	void Coordenada::insertar(Coordenada *&bloque,int numCoor, float z, float x);


	/*float Getx(){return x;}
	void Setx(float x1){x = x1;}
	float Getz(){return z;}
	void Setz(float z1){z=z1;}
	int Getnum_coor(){return num_coor;}
	void Setnum_coor(int num){num_coor = num;};
	Coordenada* Getsig(){return sig;}
	void Setsig(Coordenada *sig1){sig = sig1;};*/

};

