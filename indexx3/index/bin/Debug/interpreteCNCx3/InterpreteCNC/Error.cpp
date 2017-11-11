#include "Error.h"


Error::Error(void)
{
	sig=NULL;
}


Error::~Error(void)
{
}

void Error::SuperError(Error *& errores, string pal, string desc, int lin){
	Error *nuevo = new Error();
	nuevo->Descripcion = desc;
	nuevo->palabra = pal;
	nuevo->linea = lin;
	nuevo->sig = errores;
	errores= nuevo;
}
