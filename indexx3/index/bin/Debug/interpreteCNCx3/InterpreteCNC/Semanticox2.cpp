#include "Semanticox2.h"

Semanticox2::Semanticox2()
{
}
Semanticox2::~Semanticox2(void)
{
}

void Semanticox2::start(Sintactico analizador,int conBloque)
{
	codigo=analizador.codigo;
	for (int x=0;x<conBloque;x++)
	{
		instruccion[x]=analizador.instruccion[x];
	}
	muerte=analizador.muerte;
	nuevo=analizador.nuevo;
	conBloq=conBloque;
	nose=analizador.con_aux;
	conG=analizador.conG;
	f=analizador.f;
}

void Semanticox2::analizadorG()
{
	
	Nodo *puntero;
	int Ggroup=-1;
	bool Gstatus=false,Mstatus=false;
	for (int x=0;x<conBloq;x++)
	{
		puntero=instruccion[x];
		while(puntero!=NULL)
		{
			if(puntero->comm[0]=='G')
			{
				if(!Gstatus)
					Gstatus=true;
				else
					errorsitos3->SuperError(errorsitos3,puntero->comm,"Ya tienes otra G en el mismo bloque",puntero->linea);
				if(Ggroup!=puntero->grupo)
					Ggroup=puntero->grupo;
				else
					errorsitos3->SuperError(errorsitos3,puntero->comm,"Ya tienes otra G del mismo grupo",puntero->linea);
			}
			if(puntero->comm[0]=='M')
			{
				if(!Mstatus)
					Mstatus=true;
				else
					errorsitos3->SuperError(errorsitos3,puntero->comm,"Ya tienes otra M en el mismo bloque",puntero->linea);
			}
			puntero=puntero->ant;
		}

		Ggroup=-1;
		Gstatus=false;
		Mstatus=false;
	}
	
}