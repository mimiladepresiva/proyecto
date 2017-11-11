#include "maquina.h"


maquina::maquina(void)
{
	z = 100;
	x = 100;
	f = 0;
	avance = 0;
	sistemaProgramacion = 0;
	nbloque=0;
	herramienta = 0;


	comgActivoM= "";
	comgActivoNM = "";
}


maquina::~maquina(void)
{
}

//void maquina::coordenadas(Nodo * bloque){
//	Nodo *nodito = new Nodo();
//	bloque->invertir(bloque, nodito);
//	string comando;
//	int opc;
//	comando = nodito->comm;
//	comando=comando.substr(1);
//	opc = stoi(comando);
//	switch (opc)
//	{
//	case 00:
//		cout<< "marcha rapida" << endl;
//		G00(nodito->ant);
//		break;
//	case 20:
//		cout<< "programacion en pulgadas" << endl;
//		sistemaProgramacion = 1;
//		break;
//	case 21:
//		cout<< "programacion en milimetros" << endl;
//		sistemaProgramacion = 0;
//		break;
//	case 98:
//		cout<< "avance en minutos" << endl;
//		avance = 1;
//		break;
//	case 99:
//		cout<< "avance en revoluciones" << endl;
//		avance = 0;
//		break;
//	default:
//		break;
//	}
//}

//void maquina::G00(Nodo *bloque){
//	char* cadena;
//	while(bloque != NULL){
//		cadena = (char*)bloque->comm.c_str();
//		switch (cadena[0])
//		{
//		case 'X':
//			dibujo('x', bloque->valor);
//			x_contrapunto = bloque->valor;
//			break;
//
//		case 'Z':
//			dibujo('z', bloque->valor);
//			z_contrapunto = bloque->valor;
//			break;
//		default:
//			break;
//		}
//		
//	}
//}

