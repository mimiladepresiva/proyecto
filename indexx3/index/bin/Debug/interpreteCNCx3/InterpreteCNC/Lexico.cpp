#include "Lexico.h"
#include <iostream>
using namespace std;
#define MAX 650


Lexico::Lexico(void)
{
	porciento=0;
	conToken=0;
}


Lexico::~Lexico(void)
{
}


/**
    * Función requerida para la verificación del valor definido en el comando, se revisa que el valor dado sea un digito numerico
    * @param cadena: Recibe arreglo de caracteres que se verificará.
    * @return valor: retorna la cadena auxiliar
*/
string Lexico::ifdig(char* cadena){
			int z = 1,n=1, puntos=0; //z: indica la posicion en el arreglo "cadena". //n= utilizado para revisar si el valor es negativo.  //puntos: lleva la cuenta de los puntos '.' encontrados.
			string cadena_aux=""; //cadena_aux: variable a retornar, almacenara el valor en dado caso de que se realice un cambio en la variable "cadena"
			bool negativo = false; //negativo: informa si el valor es negativo
			while(cadena[z] != '\x0'){//ciclo que recorre cada caracter
				if(cadena[n]=='-'){ // si valor negativo
					negativo = true; //activa variable negativo
					z++; //incrementa contador
					n++; //incrementa para evitar que se cumpla nuevamente la condicion.
				}else{ 
					if(isdigit(cadena[z]) || cadena[z]=='.'){ 
						if(cadena[z]=='.'){//al encontrar punto el valor se registra en milimetros, de no ser asi en milesimas
							puntos++; // contador de puntos incrementa
							if(puntos>1){ return ("error");} //De registrar mas de dos puntos encontrados, retorna "error"
						}
						cadena_aux = cadena_aux + cadena[z]; // si el caracter de cadena es un digito se almacena en valor
						z++; 
					}else{return("error");} //caracter de cadena no es un digito, retorna "error"
				}
			}
			if(negativo){ // Termino analisis caracter por caracter, se establece si el número es negativo
				cadena_aux="-" + cadena_aux;
			}

			return cadena_aux;		
}

/**
    * Función que realiza una conversión de string a float 
    * @param value: Recibe el valor (en string) listo para ser convertido en variable tipo float 
    * @return valNum: retorna valor en variable tipo float
*/
float Lexico::conver(string value){
	float valNum; //ValNum: variable que almacenará el valor numerico de parametro "value".
	string cadena_aux; //cadena_aux: cadena auxiliar utilizada para examinar la ubicación de algun punto en el digito
	int exten=value.length();  //entensión de la variable "value"
	bool conv=true; //conve: variable que informará si el valor debe encontrarse en milesimas o milimetros. 
	if(value[0]=='-'){ //si es valor negativo
		cadena_aux=""; //inicializacion de cadena_aux
		for(int m=1;m<exten;m++){ 
			if(m==(exten-1) && value[m] == '.'){ conv = false; break;} //si punto se encuentra al final de valor, este no es entero ni se convierte en milesimas, finaliza el analisis en caso de ser negativo
			cadena_aux= cadena_aux + value[m];//almacena caracter por caracter
		}
		valNum = (stof(cadena_aux))*-1; // valor pasa a una variable float ademas de ser establecida como negativa.
	}else{
		if(value[exten-1] == '.'){ //si punto se encuentra al final el valor no se convierte en milesimas
			value.erase(exten-1);
			conv = false;
		}
		valNum=stof(value);  //valor pasa a una variable float
	}
	if(conv) valNum=valNum/100;// se convierte a milesimas
	

	return valNum; 
}


/**
    * Función que realiza la tarea de separa por tokens, elimina comentarios y tabulaciónes que se encuentren en la linea de codigo.
    * @param code: recibe la linea de codigo a separar
*/
void Lexico::separacion(string code){ 
	conToken=0; //contador de tokens registrados
	bool espacio=false;  // variable utilizada para evitar registrar un espacio ' ' como token.
	int conPal=0, ext=code.length(); //conPal: contador de caracteres. // ext: extensión de caracteres en la linea recibida.
	char pal[MAX]; //almacena los caracteres analizados para formar lo que sera el token.
	for(int x=0; x<=ext;x++){ 
			if((code[x] == ' ' && espacio == false) || code[x]== ';'){ //se almacenara un nuevo token al encontrarse un punto y coma (;) o espacio 
				pal[conPal]= '\x0'; //Establece fin de la palabra formada.
				tokens[conToken] = pal; //Se almacena token en arreglo
				conToken++;//aumenta contador de tokens.
				conPal=0; //contador de caracteres se reinicia en 0.
				if(code[x]==' '){espacio=true;} //condición que evitará que se almacene espacios como token.
				if(code[x]== ';'){break;} //se termina separacion por tokens, despues de punto y coma seran comentarios 
			}else{
				if(code[x]==' '){espacio=true;}
				else{
					if(code[x]!=9){ //no se almacenarán tabulaciones.
						pal[conPal] = code[x]; //almacena caracter.
						conPal++;
						espacio = false;
					}
				}
			} 
	}

	if(conPal!=0 ){ //almacena ultimo token de linea pues no es registrado en el ciclo for
		tokens[conToken] = pal;
		conToken++;
	}
}


/**
    * Función requerida para:
	-Revisar que los comandos G y M sean validos.
	-Analizar si las literales escritas son validas.
	-Examinar que cada literal cuente con un valor numerico.
	-Almacena cada token para asi pasar al siguiente analisis (sintactico).
    * @param Nlinea: variable que informa sobre el numero de linea que se esta analizando.
    * @return bloque: Nodo finalizado con todos los tokens encontrados en dicha linea.
*/
Nodo* Lexico::comprobacion(int Nlinea){
	bloque = NULL; // bloque: almacenara todos los tokens ubicados en la linea.
	Tab comparacion; //comparacion: Variable que permite la conexión con la tabla de simbolos. 
	string value=""; //
	float valNum; 
	char* token_aux; //token_aux: Variable que almacena token para comprobar su existencia y validez.

	for(int lexCon=0; lexCon<conToken; lexCon++){
		bool exist=false; //exist: Variable que registra la existencia de algun comando G. se inicializa en 0.
		token_aux = (char*)tokens[lexCon].c_str(); //token auxiliar es declarado con por el token actual a analizar.
		if(token_aux[1]=='\x0' && token_aux[0] != '%'){ //condición que verifica si se encuentra declaración de comando antes de signo de inicio de programa.
			errorsitos->SuperError(errorsitos, tokens[lexCon], "Falta valor", Nlinea); // De ser asi se marca como error.
			break; 
		}else if(token_aux[1]=='.' && token_aux[2]=='\x0'){ // condición utilizada para verificar que no se haya agregado ningun valor.
			errorsitos->SuperError(errorsitos, tokens[lexCon], "Falta valor", Nlinea); // se marcará como error.
			break;
		}
		switch(token_aux[0]){ //Se toma el primer caracter para hacer el analisis pues en el se declara la literal.
			
		case '%':
				if(porciento>1){errorsitos->SuperError(errorsitos, tokens[lexCon], "Error:signo encontrado nuevamente", Nlinea); return NULL;} //No puede haber mas de dos signos %
				if(lexCon==0){ //el signo debe ser el primero ya que establece el inicio del programa
						porciento++;
						return NULL; //se retorna valor nulo pues no se tomara en cuenta en los demas analisis
				}else{ 
					errorsitos->SuperError(errorsitos, tokens[lexCon], "Error:debe encontrarse al principio", Nlinea); 
					porciento++;
					return NULL;
				}
			break;

		case 'G': //Se busca en todos los grupo de comandos G.
				for(int com0C=0; com0C<14; com0C++){ //Grupo 0
					if(tokens[lexCon]==comparacion.GetComm00(com0C)){
						bloque->insertar(bloque, 0,NULL, comparacion.GetComm00(com0C), Nlinea ); //codigo G encontrado, se añade al nodo con la información correspondiente.
						exist=true; 
						break;
					}
				}

			if(exist)break; // se encontro su existencia, termina proceso

				for(int com1C=0; com1C<10; com1C++){//Grupo 1
					if(tokens[lexCon]==comparacion.GetComm01(com1C)){
						bloque->insertar( bloque, 1,NULL, comparacion.GetComm01(com1C), Nlinea ); //codigo G encontrado, se añade al nodo con la información correspondiente.
						exist=true;
						break;
					}
				}

			if(exist)break;// se encontro su existencia, termina proceso
		
				for(int com2C=0; com2C<5; com2C++){//Grupo 2
					if(tokens[lexCon]==comparacion.GetComm02(com2C)){
						bloque->insertar( bloque, 2,NULL, comparacion.GetComm02(com2C) , Nlinea);//codigo G encontrado, se añade al nodo con la información correspondiente.
						exist=true;
						break;
					}
				}
		
			if(exist)break;// se encontro su existencia, termina proceso
		
				for(int com4C=0; com4C<2; com4C++){//Grupo 4
					if(tokens[lexCon]==comparacion.GetComm04(com4C)){
						bloque->insertar( bloque, 4,NULL, comparacion.GetComm04(com4C), Nlinea );//codigo G encontrado, se añade al nodo con la información correspondiente.
						exist=true;
						break;
					}
				}
		
			if(exist)break;// se encontro su existencia, termina proceso
		
				for(int com5C=0; com5C<5; com5C++){//Grupo 5
					if(tokens[lexCon]==comparacion.GetComm05(com5C)){
						bloque->insertar( bloque, 5,NULL, comparacion.GetComm05(com5C), Nlinea );//codigo G encontrado, se añade al nodo con la información correspondiente.
						exist=true;
						break;
					}
				}
		
			if(exist)break;// se encontro su existencia, termina proceso
		
				for(int com7C=0; com7C<3; com7C++){//Grupo 7
					if(tokens[lexCon]==comparacion.GetComm07(com7C)){
						bloque->insertar( bloque, 7,NULL, comparacion.GetComm07(com7C), Nlinea );//codigo G encontrado, se añade al nodo con la información correspondiente.
						exist=true;
						break;
					}
				}
		
			if(exist)break;// se encontro su existencia, termina proceso
		
				for(int com8C=0; com8C<2; com8C++){//Grupo 8
					if(tokens[lexCon]==comparacion.GetComm08(com8C)){
						bloque->insertar( bloque, 8,NULL, comparacion.GetComm08(com8C), Nlinea );//codigo G encontrado, se añade al nodo con la información correspondiente.
						exist=true;
			break;
					}
				}
		
			if(exist)break;// se encontro su existencia, termina proceso
		
				for(int com9C=0; com9C<7; com9C++){//Grupo 9
					if(tokens[lexCon]==comparacion.GetComm09(com9C)){
						bloque->insertar( bloque, 9,NULL, comparacion.GetComm09(com9C), Nlinea );//codigo G encontrado, se añade al nodo con la información correspondiente.
						exist=true;
			break;
					}
				}
		
			if(exist)break;// se encontro su existencia, termina proceso
		
				for(int com12C=0; com12C<2; com12C++){//Grupo 12
					if(tokens[lexCon]==comparacion.GetComm12(com12C)){
					bloque->insertar( bloque, 12,NULL, comparacion.GetComm12(com12C) , Nlinea);//codigo G encontrado, se añade al nodo con la información correspondiente.
					exist=true;
			break;
					}
				}
				if(!exist)errorsitos->SuperError(errorsitos, tokens[lexCon], "No se reconoce comando :c", Nlinea);/* Si no se encuentra en ningun grupo se marcara como error*/
			break;
			

			case 'M': 
				value=ifdig(token_aux); //se revisa su valor, si este valor no es numerico, no se reconoce como comando y se retorna un string "error"
				if(value=="error"){
					errorsitos->SuperError(errorsitos, tokens[lexCon], "No se reconoce comando :c", Nlinea); // se almacena error
					break;
				}else{
					valNum=conver(value); //se convierte valor retornado por funcion "ifdig()" en variable float
				}
				//verificacion de que se encuentre en el rango
				if((valNum>=00 && valNum<25) || (valNum>26 && valNum<33) || (valNum<43 && valNum>39) || valNum==51 ){ //si el valor no se encuentra en el rango se toma como error
					bloque->insertar( bloque, NULL,valNum, "M",  Nlinea ); // de encontrarse en el rango se añade a nodo
				}else{
					errorsitos->SuperError(errorsitos, tokens[lexCon], "No se reconoce comando :c", Nlinea);
				}
			break;

			default:
				if(token_aux[0] == 'F' || (token_aux[0]>77 && token_aux[0]< 86) || token_aux[0] == 'W' || token_aux[0] == 'X' || token_aux[0] == 'Z'){ //si el comando se encuentra entre las literales validas
					string com; // com: almacena la literal
					com=token_aux[0];
					value=ifdig(token_aux);//valor de literal 
					if(value=="error"){ //el valor no es numerico, marca error
						errorsitos->SuperError(errorsitos, tokens[lexCon], "No se reconoce comando :c", Nlinea);
						break;
					}else{//el valor si es numerico, se convierte en float 
						valNum=conver(value);
						if( token_aux[0] =='N' || token_aux[0]=='T'){//literales N y T no pueden tener valores en milesimas
							valNum=valNum*100; //se regresa a su estado original
						}
					}
						bloque->insertar( bloque, NULL,valNum, com,  Nlinea ); //se añade a nodo
						break;
				}else{
					if(conToken<1){ //si hay menos de un token en la linea se envia valor nulo
						return NULL;
					}else{
						if(tokens[lexCon]=="")break; //si no se encuentra ningun valor en el token, no se toma en cuenta
						//si el token no se encuentra en la tabla de simbolos o literales validas tampoco se tomara en cuenta y sera error.
						errorsitos->SuperError(errorsitos, tokens[lexCon], "No se reconoce comando :c", Nlinea); 
						break;
					}
	
				}

		}//cierre switch
	} //cierre for
return bloque;
}

