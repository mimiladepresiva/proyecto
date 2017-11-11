#pragma once
#include <string>
using namespace std;

class Tab
{
	private: //se almacena comandos G por grupos
	string comm_00[14];
	string comm_01[10];
	string comm_02[5];
	string comm_04[2];
	string comm_05[4];
	string comm_07[4];
	string comm_08[2];
	string comm_09[7];
	string comm_12[3];
public:
	Tab(void);
	~Tab(void);
		//acceso a los arreglo de comandos dependiendo de su grupo
	string  GetComm00(int x){return comm_00[x];}
	string  GetComm01(int x){return comm_01[x];}
	string  GetComm02(int x){return comm_02[x];}
	string  GetComm04(int x){return comm_04[x];}
	string  GetComm05(int x){return comm_05[x];}
	string  GetComm07(int x){return comm_07[x];}
	string  GetComm08(int x){return comm_08[x];}
	string  GetComm09(int x){return comm_09[x];}
	string  GetComm12(int x){return comm_12[x];}
};

