#include "Sintactico.h"
#include <iostream>
using namespace std;
//falta M
Sintactico::Sintactico(void)
{
		f=false;
		nuevo=NULL;
		con_aux=0;
		conG=-2;
		conBloq=0;

}

Sintactico::~Sintactico(void)
{
}


//void Sintactico::analizador(Nodo *bloque, int &contInst){
//	muerte=bloque;
//	char odio;
//	while(muerte != NULL){
//		cout<<"comando: "<<muerte->comm<<endl;
//		odio = muerte->comm[0];
//		if(odio=='G' || odio=='T'){
//				muerte->insertar(nuevo, muerte->grupo,muerte->valor,muerte->comm, muerte->linea);
//				instruccion[nose]=nuevo;
//				nose++;
//				contInst++;
//				iniciaNodo(nuevo);
//				cout<<"g"<<endl;
//		}else{
//			muerte->insertar(nuevo, muerte->grupo,muerte->valor,muerte->comm, muerte->linea);
//		}
//		muerte= muerte->ant;
//	}
//
//	
//	
//
//}

//separa en comandos G
void Sintactico::analizador(Nodo *bloque, int &contInst, int conbloqueMain, int y){
	instruccion[contInst]=bloque;
	contInst++;
	/*muerte=bloque; 
	char odio; //variable que tomara el primer caracter del comando a evaluar
	while(muerte != NULL){
		//cout<<"comando: "<<muerte->comm<<endl;
		odio = muerte->comm[0];
		if(odio=='G'){//si comado es un codigo G define un nuevo nodo y almacena el que se ha ido creando
			conG++;//contador de codigos G encontrados
			if(conG==nose){	
				instruccion[nose]=nuevo; //almacena en arreglo
				nose++; //contador de arreglo
				contInst++; 
				iniciaNodo(nuevo); //nodo inicia en Nulo
				muerte->insertar(nuevo, muerte->grupo,muerte->valor,muerte->comm, muerte->linea);
			}else{
			muerte->insertar(nuevo, muerte->grupo,muerte->valor,muerte->comm, muerte->linea);
		}
		}else{
			muerte->insertar(nuevo, muerte->grupo,muerte->valor,muerte->comm, muerte->linea);//se inserta en nodo
		}
		muerte= muerte->ant;
	}

	if(y == conbloqueMain-1){ //almacena ultimo nodo 
		instruccion[nose]=nuevo;
				nose++;
				contInst++;
	}*/
	
	

}


/**
    * Se inicializa nodo con un valor nulo
    * @param Bloque: Se recibe el nodo a inicializar
*/
void Sintactico::iniciaNodo(Nodo *&Bloque){
	Bloque=NULL;
}


/**
    * Función que cumple la tarea de revisa sintaxis de cada bloque de instrucciones.
*/
void Sintactico::sintaxis(){
	Nodo *aux; //aux: nodo auxiliar que almacenara el nodo a analizar.
	int opc, G71=0, G72=0, G74=0,G75=0 ,G76=0; //opc:variable utilizada para estrctura switch// G71:contador de bloques g71 // G72:contador de bloqus g72// G74:contador de bloques g74 // G75:contador de bloques g75// G76:contador de bloques g76
	string comando; //comando: guarda el comando G del bloque a examinar.
	int res=1;
	for(int z=0; z<con_aux; z++){
		aux->invertir(instruccion[z], aux); // se declara aux.
		while(aux !=NULL){ //se verifica que el inicio de bloque se haya declarado un comando G 
			if(aux->comm[0]=='G'){res=0;break;}
			if(aux->comm != "T" || aux->comm != "N" ||  aux->comm != "M"){ 
				res=1;
			}else{res=2;}
			aux=aux->ant;
		}
		if(res==1){errorsitos2->SuperError(errorsitos2, instruccion[z]->comm, "codigo G ¿?", instruccion[z]->linea);break;} // de no declararse un comando G al inicio se marcara como error
		if(res==2){	// de no ser asi se almacena en nodo sintactico.
			nSintac[conBloq]=instruccion[z];
			conBloq++; 
			break;}
		comando = aux->comm; //se declara el comando G
		comando=comando.substr(1); // se elimina el primer caracter (correspondiente a la literal) de comando
		opc = stoi(comando); // se convierte a variable float para ser utilizado en la estructura switch
			switch(opc){ 
		case 00: //comando G00
			res=commG00(instruccion[z]);
			if(res){  // error en los parametros proporcionados a comando G00
				errorsitos2->SuperError(errorsitos2, "G00", "error en parametros >:c", instruccion[z]->linea);
			}else{
				nSintac[conBloq]=instruccion[z]; // Se almacena en nodo sintactico
				conBloq++;
			}
			break;

		case 01: //comando G01
			res=commG01(instruccion[z]);
			if(res){// error en los parametros proporcionados a comando G01
				errorsitos2->SuperError(errorsitos2, "G01", "error en parametros >:c", instruccion[z]->linea);
			}else{
				nSintac[conBloq]=instruccion[z];  // Se almacena en nodo sintactico
				conBloq++;
			}
			break;

		case 02://comado G02
			res = commG02_3(instruccion[z]); 
			if(res){
				errorsitos2->SuperError(errorsitos2, "G02", "error en parametros >:c", instruccion[z]->linea);
			}else{
				nSintac[conBloq]=instruccion[z]; // Se almacena en nodo sintactico
				conBloq++;
			}
			break;
		case 03: //comado G03
			res = commG02_3(instruccion[z]);
					if(res){
						errorsitos2->SuperError(errorsitos2, "G03", "error en parametros >:c", instruccion[z]->linea);
					}else{
				nSintac[conBloq]=instruccion[z];// Se almacena en nodo sintactico
				conBloq++;
			}
			break;
		case 04: //comado G04
			res = commG04(instruccion[z]);
			if(res){
				errorsitos2->SuperError(errorsitos2, "G04", "error en parametros >:c", instruccion[z]->linea);
			}else{
				nSintac[conBloq]=instruccion[z];// Se almacena en nodo sintactico
				conBloq++;
			}
			break;

			case 28: //comado G28
			res = commG28(instruccion[z]);
			if(res){
				errorsitos2->SuperError(errorsitos2, "G28", "error en parametros >:c", instruccion[z]->linea);
			}else{
				nSintac[conBloq]=instruccion[z];// Se almacena en nodo sintactico
				conBloq++;
			}
			break;

		case 50: //comado G50
			res = commG50(instruccion[z]);
			if(res){
				errorsitos2->SuperError(errorsitos2, "G50", "error en parametros >:c", instruccion[z]->linea);
			}else{
				nSintac[conBloq]=instruccion[z];// Se almacena en nodo sintactico
				conBloq++;
			}
			break;

		case 70: //comado G70
			res = commG70(instruccion[z]);
			if(res){
				errorsitos2->SuperError(errorsitos2, "G70", "error en parametros >:c", instruccion[z]->linea);
			}else{
				nSintac[conBloq]=instruccion[z];// Se almacena en nodo sintactico
				conBloq++;
			}
			break;
		case 71: //comado G71
			aux->invertir(instruccion[z+1],aux);  // se invierte el orden del nodo para recibir primero los parametros
			if(aux->comm == "G71" && z+1<con_aux ){ //Se verifica que el siguiente bloque sea correspondido a este comando, es decir, la extension de bloques de este comando son 2.
				res = commG71(instruccion[z], G71);
				if(res){
					errorsitos2->SuperError(errorsitos2, "G71", "error en parametros >:c", instruccion[z]->linea);
					z++;
				}else{
					nSintac[conBloq]=instruccion[z]; // Se almacena en nodo sintactico
					conBloq++;
					G71++;//aumenta contador del comando correspondiente
					z++;
					aux->invertir(instruccion[z],aux); //regresa a su orden inicial
					instruccion[z]=aux;
					res = commG71(instruccion[z], G71); // llama nuevamente a la funcion para revisar el siguiente bloque y que este cumpla con la sintaxis
					G71=0; // reinicia contador
					if(res){
						errorsitos2->SuperError(errorsitos2, "G71", "error en parametros >:c", instruccion[z]->linea); //error en el 2do bloque 
					}else{
					nSintac[conBloq]=instruccion[z];
					conBloq++;
					}
				}
			}else{
				errorsitos2->SuperError(errorsitos2, "G71", "error en parametros >:c", instruccion[z]->linea);//error en el 1er bloque 
			}
			break;

		case 72: //comado G02
			aux->invertir(instruccion[z+1],aux);  // se invierte el orden del nodo para recibir primero los parametros
			if(aux->comm == "G72" && z+1<con_aux ){ //Se verifica que el siguiente bloque sea correspondido a este comando, es decir, la extension de bloques de este comando son 2.
				res = commG72(instruccion[z], G72);
				if(res){ //si el siguiente bloque no corresponde al comando se marca como error
					errorsitos2->SuperError(errorsitos2, "G72", "error en parametros >:c", instruccion[z]->linea);
					z++;
				}else{
					nSintac[conBloq]=instruccion[z]; // Se almacena en nodo sintactico
					conBloq++; 
					G72++;//aumenta contador del comando correspondiente
					z++;
					aux->invertir(instruccion[z],aux);//regresa a su orden inicial
					instruccion[z]=aux;
					res = commG72(instruccion[z], G72);// llama nuevamente a la funcion para revisar el siguiente bloque y que este cumpla con la sintaxis
					G72=0;
					if(res){
						errorsitos2->SuperError(errorsitos2, "G72", "error en parametros >:c", instruccion[z]->linea); //error en el 2do bloque 
						cout<<"error"<<endl;
					}else{
				nSintac[conBloq]=instruccion[z];
				conBloq++;
			}
				}
			}else{
				errorsitos2->SuperError(errorsitos2, "G72", "error en parametros >:c", instruccion[z]->linea);
			}
			break;
		case 73://comado G02
			break;
		case 74://comado G02
			aux->invertir(instruccion[z],aux);  // se invierte el orden del nodo para recibir primero los parametros
			if(aux->comm == "G74" && z+1<con_aux ){//Se verifica que el siguiente bloque sea correspondido a este comando, es decir, la extension de bloques de este comando son 2.
				res = commG74(instruccion[z], G74);
				if(res){
					errorsitos2->SuperError(errorsitos2, "G74", "error en parametros >:c", instruccion[z]->linea);
					z++;
				}else{
					nSintac[conBloq]=instruccion[z]; // Se almacena en nodo sintactico
					conBloq++; 
					G74++;//aumenta contador del comando correspondiente
					z++;
					aux->invertir(instruccion[z],aux);//regresa a su orden inicial
					instruccion[z]=aux;
					res = commG74(instruccion[z], G74);// llama nuevamente a la funcion para revisar el siguiente bloque y que este cumpla con la sintaxis
					G74=0;
					if(res){
						errorsitos2->SuperError(errorsitos2, "G74" ,"error en parametros >:c", instruccion[z]->linea); //error en el 2do bloque 
						//cout<<"error"<<endl;
					}else{
				nSintac[conBloq]=instruccion[z];
				conBloq++;
			}
				}
			}else{
				errorsitos2->SuperError(errorsitos2, "G74", "error en parametros >:c", instruccion[z]->linea);
			}
			break;
		case 75: //comado G02
			aux->invertir(instruccion[z+1],aux); // se invierte el orden del nodo para recibir primero los parametros
			if(aux->comm == "G75" && z+1<con_aux ){//Se verifica que el siguiente bloque sea correspondido a este comando, es decir, la extension de bloques de este comando son 2.
				res = commG75(instruccion[z], G75);
				if(res){
					errorsitos2->SuperError(errorsitos2, "G75", "error en parametros >:c", instruccion[z]->linea);
					z++;
				}else{
					nSintac[conBloq]=instruccion[z]; // Se almacena en nodo sintactico
					conBloq++;
					G75++;//aumenta contador del comando correspondiente
					z++;
					aux->invertir(instruccion[z],aux);//regresa a su orden inicial
					instruccion[z]=aux;
					res = commG75(instruccion[z], G75);// llama nuevamente a la funcion para revisar el siguiente bloque y que este cumpla con la sintaxis
					G75=0;
					if(res){
						errorsitos2->SuperError(errorsitos2, "G75", "error en parametros >:c", instruccion[z]->linea); //error en el 2do bloque 
					}else{
				nSintac[conBloq]=instruccion[z];
				conBloq++;
			}
				}
			}else{
				errorsitos2->SuperError(errorsitos2, "G75", "error en parametros >:c", instruccion[z]->linea);
			}
			break;

		case 76: //comado G76
			aux->invertir(instruccion[z+1],aux);
			if(aux->comm == "G76" && z+1<con_aux ){//Se verifica que el siguiente bloque sea correspondido a este comando, es decir, la extension de bloques de este comando son 2.
			res = commG76(instruccion[z], G76);
			if(res){
				errorsitos2->SuperError(errorsitos2, "G76", "error en parametros >:c", instruccion[z]->linea);
				z++;
			}else{
				nSintac[conBloq]=instruccion[z]; // Se almacena en nodo sintactico
				conBloq++;
				G76++;//aumenta contador del comando correspondiente
				z++;
				aux->invertir(instruccion[z],aux);//regresa a su orden inicial
				instruccion[z]=aux;
				res = commG76(instruccion[z], G76);// llama nuevamente a la funcion para revisar el siguiente bloque y que este cumpla con la sintaxis
				G76=0;
				if(res){
					errorsitos2->SuperError(errorsitos2,"G76", "error en parametros >:c", instruccion[z]->linea);  //error en el 2do bloque 
				}else{
				nSintac[conBloq]=instruccion[z];
				conBloq++;
			}
			}
		}else{
			errorsitos2->SuperError(errorsitos2, "G76", "error en parametros >:c", instruccion[z]->linea);
		}
		break;
		case 96: //comado G96
			res = commG96(instruccion[z]);
				if(res){
					errorsitos2->SuperError(errorsitos2, "G96", "error en parametros >:c", instruccion[z]->linea);
				}else{
				nSintac[conBloq]=instruccion[z]; // Se almacena en nodo sintactico
				conBloq++;
			}
				break;

		case 97: //comado G97
			res = commG96(instruccion[z]); //utiliza los mismos parametros que comando G96
				if(res){
					errorsitos2->SuperError(errorsitos2, "G97", "error en parametros >:c", instruccion[z]->linea);
				}else{
				nSintac[conBloq]=instruccion[z];// Se almacena en nodo sintactico
				conBloq++;
			}
				break;

		case 99: //comado G99
			//No necesita parametros sin embargo se revisa que no cuente con literales innecesarias.
			res= commG99(instruccion[z]);
			if(res){
					errorsitos2->SuperError(errorsitos2, "G99", "error en parametros >:c", instruccion[z]->linea);
				}else{
				nSintac[conBloq]=instruccion[z]; // Se almacena en nodo sintactico
				conBloq++;
			}
			
			break;



		}
		
	}
}


/**
    * Función para revision de sintaxis comando G00
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/

int Sintactico::commG00(Nodo* bloque){
	bool n=false,x=false, z=false, t=false; // variables que indican la existencia de literal N, X, Z, T
	while(bloque != NULL){
		switch (bloque->comm[0]){
		case 'G': // No se toma en cuenta
			break;
		case 'N':
			n=true; // N si se encuentra en el bloque
			break;
		case 'X': 
			x=true;// X si se encuentra en el bloque
			break;
		case 'Z':
			z= true; // Z si se encuentra en el bloque
			break;
		case 'T':
			t= true; // T si se encuentra en el bloque
			break;
		default:
			return 1; // Se encuentra literal no aceptada
				break;
		}
		bloque = bloque->ant;
	}
	if(x==false && z==false){ //si se ha declarado el comando sin ningun parametro se considera error.
		return 1; 
	}

	return 0; //sintaxis correcta
	
	
}

/**
    * Función para revision de sintaxis comando G01
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/
int Sintactico::commG01(Nodo* bloque){
	bool n=false,x=false, z=false; // variables para verificar si se encuentran literales N, X y Z declarados en el bloque
	while(bloque != NULL){
		switch (bloque->comm[0]){
		case 'G':
			break;
		case 'N':
			n=true; //Expresion N se encuentra en el bloque
			break;
		case 'X':
			x=true; //Expresion Z se encuentra en el bloque
			break;
		case 'Z':
			z= true; //Expresion Z se encuentra en el bloque
			break;
		case 'F':
			f = true; //Expresion F se encuentra en el bloque
			break;
		default:
			return 1;
				break;
		}
		bloque=bloque->ant;
	}
	if((!z && !f) ||  (!x && !f) || !f){ // marcará error si no se ha declarado ningun valor de velocidad (f)
		return 1;
	}
	
	return 0;
}

/**
    * Función para revision de sintaxis comando G02 y G03 
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/
int Sintactico::commG02_3(Nodo* bloque){
	bool n=false,x=false, z=false, r= false;// variables para guardan registro de si se encuentran literales N, X, Z y R declarados en el bloque
	while(bloque != NULL){
		switch (bloque->comm[0]){
		case 'G':
			break;
		case 'N': 
			n=true; //Expresión N se encuentra en el bloque
			break;
		case 'X':
			x=true; //Expresión X se encuentra en el bloque
			break;
		case 'Z':
			z= true; //Expresión Z se encuentra en el bloque
			break;
		case 'R':
			r = true; //Expresión R se encuentra en el bloque
			break;
		default:
			return 1; //De encontrarse alguna expresión o literal no aceptada se retorna un error
				break;
		}
		bloque=bloque->ant;
	}
	if((!z && !r) || (!x && !r)){  // en cualquiera de estas combinaciones debe de encontrarse la literal R
		return 1;
	}
	
	return 0;
}

/**
    * Función para revision de sintaxis comando G04
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/
int Sintactico::commG04(Nodo* bloque){
	bool n=false,p=false; // variables para guardan registro de si se encuentran literal N y P.
	while(bloque != NULL){
		switch (bloque->comm[0]){
		case 'G':
			break; 
		case 'N': //Expresión N se encuentra en el bloque
			n=true;
			break;
		case 'P': //Expresión P se encuentra en el bloque
			p=true;
			break;
		default: //De encontrarse alguna expresión o literal no aceptada se retorna un error
			return 1;
				break;
		}
		bloque=bloque->ant;
	}
	if(!p){// Retorna error en caso de no declararse expresión P
		return 1;
	}
	
	return 0;
}

/**
    * Función para revision de sintaxis comando G28
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/
int Sintactico::commG28(Nodo* bloque){
	bool t=false,n=false,x=false, z=false, r= false, u=false, w=false, m=false; // variables para guardan registro de si se encuentran literal T, N, X, Z, R, U, W, M.
	while(bloque != NULL){
		switch (bloque->comm[0]){
		case 'G':
			break;
		case 'N': 
			n=true; //Expresión N se encuentra en el bloque
			break;
		case 'X':
			x=true; //Expresión X se encuentra en el bloque
			break;
		case 'Z':
			z= true; //Expresión Z se encuentra en el bloque
			break;
		case 'R':
			r = true; //Expresión R se encuentra en el bloque
			break;
		case 'U':
			u= true; //Expresión U se encuentra en el bloque
			break;
		case 'W':
			w = true; //Expresión W se encuentra en el bloque
			break;
		case 'M':
			m = true; //Expresión M se encuentra en el bloque
			break;
		case 'T':
			t = true; //Expresión T se encuentra en el bloque
			break;
		default://De encontrarse alguna expresión o literal no aceptada se retorna un error
			return 1;
				break;
		}
		bloque=bloque->ant;
	}
	if(!w && !u ){ // Retorna error en caso de no declararse expresión W y U
		return 1;
	}
	
	return 0;
}


/**
    * Función para revision de sintaxis comando G50
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/
int Sintactico::commG50(Nodo* bloque){
	bool n=false,s=false; // variables para guardan registro de si se encuentran literal N y S en el bloque.
	while(bloque != NULL){
		switch (bloque->comm[0]){
		case 'G':
			break;
		case 'N':
			n=true; //Literal N se encuentra en el bloque
			break;
		case 'S':
			s=true; //Literal S se encuentra en el bloque
			break;
		default: //Literal no aceptada, retorna un error.
			return 1; 
				break;
		}
		bloque=bloque->ant;
	}
	if(!s){  // Retorna error en caso de no declararse expresión S.
		return 1;
	}
	
	return 0;
}


/**
    * Función para revision de sintaxis comando G70
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/
int Sintactico::commG70(Nodo* bloque){
	bool n=false, p=false,q=false,f=false,s=false,t=false;  // variables para guardan registro de si se encuentran literal N, S, P. Q, F y T en el bloque recibido.
	while(bloque != NULL){
		switch (bloque->comm[0]){
		case 'G':
			break;
		case 'N':
			n=true;  //Literal N se encuentra en el bloque
			break;
		case 'P':
			p=true;  //Literal P se encuentra en el bloque
			break;
		case 'Q':
			q=true; //Literal Q se encuentra en el bloque
			break;
		case 'F':
			f=true; //Literal F se encuentra en el bloque
			break;
		case 'S':
			s=true; //Literal S se encuentra en el bloque
			break;
		case 'T':
			t=true; //Literal T se encuentra en el bloque
			break;
		
		default:  //Literal no definida, retorna un error.
			return 1;
				break;
		}
		bloque = bloque->ant;
	}
	if(!p && !q && !f && !s && !t){ //De no existir ninguna de estas expresiones se retorna error
		return 1;
	}
	
	return 0;
}

/**
    * Función para revision de sintaxis comando G71
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
	*@param x: Recibe el numero de bloque referente a G71
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/
int Sintactico::commG71(Nodo* bloque, int x){ // 
bool n=false,w=false,r=false,p=false,q=false, u=false, f=false, s=false, t=false; // variables para guardan registro de si se encuentran las literales necesarias en el bloque
	if(!x){ //Dependiendo del numero de bloque, es la sintaxis que se va a revisar. Si x = 0 se revisa sintaxis referente a bloque 1, de ser 1 se verifica la sintaxis del bloque 2
		while(bloque != NULL){
			switch (bloque->comm[0]){
			case 'G':
			break;	
			case 'N':
				n=true;//Literal N se encuentra en el bloque
				break;
			case 'U':
				u=true; //Literal U se encuentra en el bloque
				break;
			case 'R':
				r=true; //Literal R se encuentra en el bloque
				break;
			default: //literal no definida, retorna error
				return 1;
				break;
				}
			bloque = bloque->ant;

		}
			if(u==false && r==false) return 1; //De no existir ninguna de estas expresiones se retorna error
			return 0;
	}
	if(x){
		while(bloque != NULL){
			switch (bloque->comm[0]){
			case 'G':
			break;
			case 'N':
					n=true;
					break;
				case 'P':
					p=true; //Literal P se encuentra en el bloque
					break;
				case 'Q':
					q=true; //Literal Q se encuentra en el bloque
					break;
				case 'U':
					u=true; //Literal U se encuentra en el bloque
					break;
				case 'W':
					w=true; //Literal W se encuentra en el bloque
					break;
				case 'F':
					f=true; //Literal F se encuentra en el bloque
					break;
				case 'S':
					s=true; //Literal S se encuentra en el bloque
					break;
				case 'T':
					t=true; //Literal T se encuentra en el bloque
					break;
		
				default:  //error, literal no aceptada
				return 1;
				break;
			}
			
		bloque=bloque->ant;
			
		}
		if(p==false && q==false && w==false && u==false){ //De no existir ninguna de estas expresiones se retorna error
		return 1;
		}
	}
	
	return 0;
}


/**
    * Función para revision de sintaxis comando G72
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/
int Sintactico::commG72(Nodo* bloque, int x){
	bool n=false, w=false,r=false,p=false,q=false, u=false, f=false, s=false, t=false; // variables para guardan registro de si se encuentran las literales necesarias en el bloque
	if(!x){//Dependiendo del numero de bloque, es la sintaxis que se va a revisar. Si x = 0 se revisa sintaxis referente a bloque 1, de ser 1 se verifica la sintaxis del bloque 2
		while(bloque != NULL){
			switch (bloque->comm[0]){
			case 'G':
			break;
			case 'N':
					n=true; //Literal N se encuentra en el bloque
					break;
				case 'W':
					w=true; //Literal W se encuentra en el bloque
					break;
				case 'R':
					r=true; //Literal R se encuentra en el bloque
					break;
				default:
					return 1;//Literal no aceptada, retorna error
					break;
				}
			bloque = bloque->ant;

		}
			if(w==false && r==false) return 1; //De no existir ninguna de estas expresiones se retorna error
			return 0;
	}
	if(x){ // bloque 2
		while(bloque != NULL){
			switch (bloque->comm[0]){
			case 'G':
			break;
			case 'N':
					n=true; //Literal N se encuentra en el bloque
					break;
				case 'P':
					p=true; //Literal P se encuentra en el bloque
					break;
				case 'Q':
					q=true; //Literal Q se encuentra en el bloque
					break;
				case 'U':
					u=true;//Literal U se encuentra en el bloque
					break;
				case 'W':
					w=true; //Literal W se encuentra en el bloque
					break;
				case 'F':
					f=true; //Literal F se encuentra en el bloque
					break;
				case 'S':
					s=true; //Literal S se encuentra en el bloque
					break;
				case 'T':
					t=true; //Literal T se encuentra en el bloque
					break;
		
				default: ////Literal no aceptada, error
				return 1;
				break;
			}
			
		bloque=bloque->ant;
			
		}
		if(p==false && q==false && w==false && u==false && f==false){ //De no existir ninguna de estas expresiones se retorna error
		return 1;
		}
	}
	
	return 0;
}


/**
    * Función para revision de sintaxis comando G74
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
	*@param x: Establece el numero de bloque a analizar
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/
int Sintactico::commG74(Nodo* bloque, int x){
	bool n=false,w=false,r=false,z=false,q=false, u=false, f=false, s=false, t=false;  // variables para guardan registro de si se encuentran las literales necesarias en el bloque
	if(!x){
		while(bloque != NULL){
			switch (bloque->comm[0]){
			case 'G':
			break;
			case 'N':
					n=true; //Literal N se encuentra en el bloque
					break;
				case 'R':
					r=true; //Literal R se encuentra en el bloque
					break;
				default:
					return 1; //Literal no aceptada de acuerdo a la sintaxis, se marca como error
					break;
				}
			bloque = bloque->ant;

		}
			if(r==false) return 1;
			return 0;
	}
	if(x){ //bloque 2
		while(bloque != NULL){
			switch (bloque->comm[0]){
			case 'G':
			break;
			case 'N':
					n=true; //Literal N se encuentra en el bloque
					break;
				case 'Z':
					z=true; //Literal Z se encuentra en el bloque
					break;
				case 'Q':
					q=true; //Literal Q se encuentra en el bloque
					break;
				case 'F':
					f=true; //Literal F se encuentra en el bloque
					break;
		
				default:
					return 1;
				break;
			}
			
		bloque=bloque->ant;
			
		}
		if(z==false && q==false && f==false){ //De no encontrarse ninguna de estas literales en el bloque se marca como error.
			return 1;
		}
	}
	
	return 0;
}

/**
    * Función para revision de sintaxis comando G75
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
	*@param num: variable que establece el numero de bloque a analizar
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/
int Sintactico::commG75(Nodo* bloque, int num){
	bool x=false,r=false,p=false,f=false, n=false; // variables para guardan registro de si se encuentran las literales necesarias en el bloque
	if(!num){
		while(bloque != NULL){
			switch (bloque->comm[0]){
			case 'G':
			break;
			case 'R':
				r=true; //Expresión R encontrada en el bloque
				break;
			default:
				return 1;
				break;
				}
			bloque = bloque->ant;

		}
			if(r==false) return 1;  //De no encontrarse esta literal en el bloque se marca como error.
			return 0;
	}
	if(num){
		while(bloque != NULL){
			switch (bloque->comm[0]){
			case 'G':
			break;
			case 'N':
					n=true; //Expresión N encontrada en el bloque
					break;
				case 'X': 
					x=true; //Expresión X encontrada en el bloque
					break;
				case 'P':
					p=true; //Expresión P encontrada en el bloque
					break;
				case 'F':
					f=true; //Expresión F encontrada en el bloque
					break;
		
				default:
				return 1;
				break;
			}
			
		bloque=bloque->ant;
			
		}
		if(x==false && p==false && f==false){ //Literales necesarias en el bloque 
		return 1;
		}


	}
	
	return 0;
}


/**
    * Función para revision de sintaxis comando G76
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
	*@param num: Variable que establece el numero de bloque.
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/
int Sintactico::commG76(Nodo* bloque, int num){
	bool x=false,r=false,p=false,f=false, q=false, u=false, z=false, w=false;  // variables para guardan registro de si se encuentran las literales necesarias en el bloque
	if(!num){
		while(bloque != NULL){
			switch (bloque->comm[0]){
			case 'G':
			break;
			case 'R':
					r=true;//Expresión R encontrada en el bloque
					break;
				case 'Q':
					q=true; //Expresión Q encontrada en el bloque
					break;
				case 'P':
					p=true; //Expresión P encontrada en el bloque
					break;
				default:
					return 1;
					break;
				}
			bloque = bloque->ant;

		}
			if(r==false && q==false && p==false) return 1;  //De no encontrarse ninguna de estas literales en el bloque se marca como error.
			return 0;
	}
	if(num){
		while(bloque != NULL){
			switch (bloque->comm[0]){
			case 'G':
			break;
			case 'X':
					x=true; //Expresión X encontrada en el bloque
					break;
				case 'U':
					u=true;  //Expresión U encontrada en el bloque
					break;
				case 'Z':
					z=true; //Expresión Z encontrada en el bloque
					break;
				case 'W':
					w=true; //Expresión W encontrada en el bloque
					break;
				case 'R':
					r=true; //Expresión R encontrada en el bloque
					break;
				case 'Q':
					q=true; //Expresión Q encontrada en el bloque
					break;
				case 'P':
					p=true; //Expresión P encontrada en el bloque
					break;
				case 'F':
					f=true; //Expresión F encontrada en el bloque
					break;
		
				default: // 
					return 1;
				break;
			}
			
		bloque=bloque->ant;
		}
		if((x==false || u==false) && (z==false || w==false) && p==false && r==false && f==false){ // Combinacion de expresiones en el bloque necesarias en la sintaxis
		return 1;
		}
	}
	
	return 0;
}


/**
    * Función para revision de sintaxis comando G96
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/
int Sintactico::commG96(Nodo* bloque){
	bool s=false,m=false, t=false; //Literales aceptadas en el bloque
	while(bloque != NULL){
		switch (bloque->comm[0]){
		case 'G':
			break;
		case 'T':
			t=true; // Expresión M encontrada
			break;
		case 'S':
			s=true; // Expresión M encontrada
			break;
		case 'M': 
			m=true; // Expresión M encontrada
			break;
		
		default: // se encuentra una literal no valida
			return 1;
				break;
		}
		bloque=bloque->ant;
	}
	if(!s){ //de no encontrarse literal S, se marca como error
		return 1;
	}
	return 0;
}

/**
    * Función para revision de sintaxis comando G99
	*@param bloque: Recibe Nodo con donde se tiene registrado las literales del bloque
    * @return 1: si se encuentra literal no aceptada, 0: si todas las literales incluidas son validas.
*/
int Sintactico::commG99(Nodo* bloque){ 
	if(bloque->ant == NULL){ //dicho bloque no debe contener ningun otra literal pues no necesita.
		return 0;
	}else{
		return 1;
	}
}