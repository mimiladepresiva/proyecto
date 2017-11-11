#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#include "Nodo.h"
#include "Error.h"
#include "Lexico.h"
#include "Sintactico.h"
#include "Semanticox2.h"
//librerias opengl
#include <gl\glut.h>
#include "maquina.h"
#include "Dibujo.h"

//bool codigo = false, 
//	cuadricula = false, 
//	codigo1 = false, 
//	escala = false, 
//	frontal = false,
//	isometrico = false,
//	lateral = false,
//	superior = false,
//	taristas = false,
//	locultas = false,
//	solido = false,
//	altura = false,
//	radio = false;
float xpieza, zpieza, xcontrapunto=100, zcontrapunto=100, unidad=50;



//void inicio(){
//	glMatrixMode(GL_PROJECTION); //modo de proyeccion
//	glLoadIdentity();
//	gluOrtho2D(-unidad,unidad,-unidad,unidad); //espacio en el que se divide la pantalla
//	glClearColor(1.0,1.0,1.0,0.0); //color de pantalla
//}

//void cuadricu(){
// for(int fila = -unidad; fila<=unidad; fila++){
//	 if(fila == 0) glColor3f(1.0,0.0,0.0);
//	 else glColor3f(0.0,0.0,0.0);
//	 glBegin(GL_LINES);
//		glVertex2f(-unidad, fila);glVertex2f(unidad,fila);
//	 }
//
//	 for(int columna = -unidad; columna<=unidad; columna++){
//		if(columna == 0) glColor3f(1.0,0.0,0.0);
//		else glColor3f(0.0,0.0,0.0);
//		glBegin(GL_LINES);
//		glVertex2f(columna, -unidad);glVertex2f(columna, unidad);
//	 }
//	glEnd();
//	
//}
//void display() {  
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
//
//	 glMatrixMode(GL_MODELVIEW); 
//
//	 //int x1, y1, x2, y2;
//	 glColor3i(1,0.0,0.0);
//	 //for(int c=0; c<3; c++){
//	 //int x1 = -7, y1 =4, x2 =-5;
//	 //y2=y1-1;
//
//	 //while(){
//		glBegin(GL_QUADS);
//		for(float con1 = xpieza/2; con1>=-xpieza/2; con1-- ){
//			for(float con=-zpieza; con<=0; con++){
//				glVertex2f(con,con1);
//				glVertex2f(con,con1-1);
//				glVertex2f(con-1,con1-1);
//				glVertex2f(con-1,con1);
//			}
//		}
//
//	glVertex2f(100,100);
//	glVertex2f(100,100-1);
//	glVertex2f(100-1,100-1);
//	glVertex2f(100-1,100);
//	 //glBegin(GL_LINES);
//	 //glVertex2f(0.0,0.0);
//	 //glVertex2f(-1.0,1.0);
//
//
//		glEnd();
//	 //}
//	 
//	 //}
//
//	 if(cuadricula)cuadricu();
//	 glFlush();
//} 

//void configuracion(string line, bool &codigo, bool &cuadricula){
//	string conf= "";
//	char palabra[30];
//	int conCarac=0;
//	bool activacion=true;
//	for(int caracter = 0; caracter<line.length(); caracter++){
//		if(line[caracter] == '/'){
//			activacion = false;
//			break;
//		}else if(line[caracter] != '<' && line[caracter] != '>'){
//			palabra[conCarac]=line[caracter];
//			conCarac++;
//			
//		}
//	}
//	palabra[conCarac]='\x0';
//	conf = palabra;
//	if(altura && activacion){ zpieza = stof(conf); altura = false;}
//	if(radio && activacion) {xpieza = stof(conf); radio = false; }
//
//	if(conf == "cuadricula" && activacion==true) cuadricula = true;
//	if(conf == "codigo" && activacion==true){
//		codigo =true;
//	}else if(conf == "codigo" && activacion==false){
//		codigo1 = false;
//		codigo = false;
//	}
//
//	if(conf == "escala" && activacion == true)  escala=true;
//	if(conf == "frontal" && activacion == true)  frontal=true;
//	if(conf == "isometrico" && activacion == true) isometrico=true;
//	if(conf == "lateral" && activacion == true)  lateral=true;
//	if(conf == "superior" && activacion == true)  superior=true;
//	if(conf == "taristas" && activacion == true)  taristas=true;
//	if(conf == "locultas" && activacion == true)  locultas=true;
//	if(conf == "solido" && activacion == true)  solido=true;
//	if(conf == "altura" && activacion == true) altura = true;
//	if(conf == "radio" && activacion == true) radio = true;
//
//
//}

int main(){
	//****************************** configuracion pantalla
	Dibujo *pantalla = new Dibujo();

	//****************************** Interprete
	int contInst = 0;
	Lexico analizador;
	Semanticox2 analizador3;
	Sintactico analizador2;
	Error *iErrores = NULL; //Almacena los errores encontrados por analisis lexico
	Nodo *bloque[9999]; //bloques de cada linea
	string line="";  //adquiere valor de linea analizada
	int conBloque = 0, conLinea=1, conInst=0, conErrores=0; // contador para bloques de analizador lexico, contador de lineas, contador de instrucciones de analizador sintactico  
	
	ifstream file("temp.yii"); //archivo temporal
	if(file){  //si el archivo se puede abrir correctamente 
		while(getline(file, line)){ //mientras haya linea que analizar
			pantalla->configuracion(line);
			if(pantalla->Getcodigo1()){
				if(line != ""){
					analizador.separacion(line); //separacion por tokens
					bloque[conBloque]= analizador.comprobacion(conLinea);// se comprueba que tokens de linea sean validos 
					if(bloque[conBloque]!=NULL){//condicion que establece si el bloque regresa vacio, de ser asi no se toma en cuenta
						conBloque++;
					}
				}
				conLinea++;
			}
			if(pantalla->Getcodigo()){
				pantalla->Setcodigo1(true);
			}
		}

		file.close(); //cierre de archivo

		iErrores = analizador.GetError(); //se toman errores lexicos
		//muestra errores
		while(iErrores != NULL){
			cout << "!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << iErrores->palabra << endl << iErrores->Descripcion << endl << iErrores->linea<<endl;
			iErrores = iErrores->sig;
			conErrores++;
		}
		//
		if(conBloque>0){ //si se encontraron bloques de instrucciones, se continua al siguiente analisis
			Nodo *aux= new Nodo;
			aux = NULL;

			//comienza analisis sintactico
			Error *errores2=NULL; //registra errores sintacticos
			for(int y=0;y<conBloque;y++){
				//cout<<"***********************"<<endl;
				//aux=bloque[y];
				aux->invertir(bloque[y], aux); 
				analizador2.analizador(aux, contInst, conBloque, y); //separa en bloques por instrucciones (codigo G)
			}
			

			//analizador2.mostrar(contInst); //muestra resultados de separar por g
			analizador2.sintaxis(); //se revisa la sintaxis de cada bloque de instrucciones
			errores2 = analizador2.GetErrores(); //toma errores sintacticos
			
			//muestra errores
			while(errores2 != NULL){
				cout << "!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << errores2->palabra << endl << errores2->Descripcion << endl << errores2->linea<<endl;
				errores2 = errores2->sig;
				conErrores++;
			}


		}

		//inicio de analizador semantico
		analizador3.start(analizador2,conBloque);
		analizador3.analizadorG();
		Error *errores3=NULL;
		errores3 = analizador3.GetErrores(); //toma errores sintacticos
			
			//muestra errores
			while(errores3 != NULL){
				cout << "!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << errores3->palabra << endl << errores3->Descripcion << endl << errores3->linea<<endl;
				errores3 = errores3->sig;
				conErrores++;
			}

		/*Nodo *aux= new Nodo;
		for(int hola = 0; hola<analizador3.conBloq; hola++){
		aux = analizador3.instruccion[hola];
		cout<<"**************++"<<endl;
		while (aux != NULL)
		{
			cout<< aux->comm <<endl;
			cout<<"11111111111111111111111111"<<endl;
			aux = aux->ant;
		}
		cout<<"**************++"<<endl;
		}*/
		//fin de analizador semantico

	//		//****************************** pieza
		if(conErrores == 0){
			//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
			//glutInitWindowPosition(-3,-3); 
			//glutInitWindowSize(600,600); 
			//glutCreateWindow("hola");
			//inicio();
			//glutDisplayFunc(display); 
	
			////maquina *superpopo= new maquina();

		//for(int cont=0; cont<analizador2.conBloq; cont++){
		//	superpopo->coordenadas(analizador2.nSintac[cont]);
		//}

			//glutMainLoop();
			for(int cont = 0; cont < analizador3.conBloq; cont++){
				Nodo *aux = new Nodo();
				/*analizador2.instruccion[cont]->invertir(analizador2.instruccion[cont], aux);
				analizador2.instruccion[cont]=aux;*/
				pantalla->SetNodo(analizador3.instruccion[cont], cont);
			}
			pantalla->inicializacionpantalla();

		}




	}else{ //no se pudo abrir archivo  o no se encontro
		cout <<"Error archivo"<<endl;
	}


	
	system("pause");
	return 0;
}