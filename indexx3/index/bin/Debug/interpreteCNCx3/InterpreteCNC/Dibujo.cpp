#include "Dibujo.h"

bool codigoL, cuadriculaL, codigo1L, escalaL, frontalL,isometricoL, lateralL,superiorL,taristasL ,locultasL,solidoL,alturaL,radioL;
float xpiezaL, zpiezaL, unidadL, radiofigura, alturafigura;
int numBloqueL, zp=50, xp=50;
Nodo *bloque[9999];
maquina *miMaquina = new maquina();
pieza *figura = new pieza();
pieza *original = new pieza();
int n=0;

void display();
void cuadricu();
void comando(Nodo*);
void instruccion();
void G00();
void G01();
void dibujofrontal();
void dibujolateral();
void dibujosuperior();
void dibujoisometrico();
void iniciafigura();
void insertarcoor(float , float);
void hola();
void invertir(Coordenada *, Coordenada *&);

Dibujo::Dibujo()
{
	
	unidad = 50;
	codigo = false, 
	cuadricula = false, 
	codigo1 = false, 
	escala = false, 
	frontal = false,
	isometrico = false,
	lateral = false,
	superior = false,
	taristas = false,
	locultas = false,
	solido = false,
	altura = false,
	radio = false;
	xpieza = 0;
	zpieza = 0;
	igualacion();
	miMaquina->x = unidad;
	miMaquina->z =  unidad;
	miMaquina->x_A = unidad;
	miMaquina->z_A =  unidad;
}


Dibujo::~Dibujo(void)
{
}

void iniciafigura(){
	/*insertarcoor(-alturafigura, radiofigura);
	insertarcoor(-alturafigura, radiofigura);
	insertarcoor(-4, -15);
	insertarcoor(-4, -12);
	insertarcoor(-2, -12);
	insertarcoor(-2, -10);
	insertarcoor(0, -10);
	insertarcoor(0, 10);
insertarcoor(-2, 10);
		insertarcoor(-2, 12);
	insertarcoor(-4, 12);
	insertarcoor(-4, radiofigura);
	insertarcoor(-2, 15);
	insertarcoor(-alturafigura, radiofigura);
	insertarcoor(-alturafigura, radiofigura);*/
	//ppppppppppppppppppppppppppp

	insertarcoor(-alturafigura, radiofigura);
	insertarcoor(0, radiofigura);
	insertarcoor(0, -radiofigura);
	insertarcoor(-alturafigura, -radiofigura);
	insertarcoor(-alturafigura, radiofigura);
}

void insertarcoor(float z,float x){
	Coordenada *aux = new Coordenada();
	aux->ant = figura->coordenaditas;
	aux->x = x;
	aux->z = z;
	aux->num_coor = n;
	figura->coordenaditas = aux;
	n++;			
}


void Dibujo::igualacion(){
	unidadL  = unidad;
	codigoL = codigo, 
	cuadriculaL = cuadricula, 
	codigo1L = codigo1, 
	escalaL = escala, 
	frontalL = frontal,
	isometricoL = isometrico,
	lateralL = lateral,
	superiorL = superior,
	taristasL = taristas,
	locultasL = locultas,
	solidoL = solido,
	alturaL = altura,
	radioL = radio;
	xpiezaL = xpieza;
	radiofigura = xpieza;
	zpiezaL = zpieza;
	alturafigura= zpieza;
}

void Dibujo::inicializacionpantalla(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
	glutInitWindowPosition(-3,-3); 
	glutInitWindowSize(600,600); 
	glutCreateWindow("Ventana Figura");
	gluOrtho2D(-unidad,unidad,-unidad,unidad); //espacio en el que se divide la pantalla
	glClearColor(1.0,1.0,1.0,0.0); 
	igualacion();
	iniciafigura();
	original = figura;
	glutDisplayFunc(display); 
	glutMainLoop();
}

void display() {  

	glMatrixMode(GL_PROJECTION); //modo de proyeccion
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); 
	glColor3i(1,0.0,0.0);


	if(cuadriculaL)(cuadricu());

	for(int q=0; q<=numBloqueL; q++){
		//bloque[q]->invertir(bloque[q], bloque[q]);
		while(bloque[q] != NULL){
			cout<< bloque[q]->comm <<endl;
			comando(bloque[q]);
			instruccion();

			bloque[q]=bloque[q]->ant;
		}


		cout<<"Comando modal activo: " <<miMaquina->comgActivoM << endl;
		cout<<"Comando no modal activo: " <<miMaquina->comgActivoNM << endl;
		cout<< "X: " << miMaquina->x<< endl;
		cout<< "Z: " << miMaquina->z<< endl;
		miMaquina->comgActivoNM="";

	}

	//hola();

	if(isometricoL){
		dibujoisometrico();
	}else if(superiorL){
		dibujosuperior();
	}else if(lateralL){
		dibujolateral();
	}else if(frontalL){
		dibujofrontal();
	}
	//glEnd();




	/*glEnd();*/
	//	glBegin(GL_LINES);
	//glVertex2f(50, 50);glVertex2f(20,20);
	//glEnd();
	
	/*glEnd();*/
	 glFlush();
} 


void comando(Nodo * aux){
	char inicial = aux->comm[0];

	switch (inicial)
	{

		case 'G':
			if( aux->grupo == 01){
			miMaquina->comgActivoNM = aux->comm; 
			}else{
			miMaquina->comgActivoM = aux->comm; 
			}
			break;
		case 'F':
			miMaquina->f = aux->valor;
			break;
		case 'M':
			miMaquina->commActivo = aux->valor;
			break;
		case 'N':
			miMaquina->nbloque = aux->valor;
			break;

		case 'U':
			miMaquina->u = aux->valor;
			break;

		case 'T':
			miMaquina->herramienta = aux->valor;
			break;

		case 'S':
			if(miMaquina->comgActivoNM == "G50") miMaquina->velmax = aux->valor;
			miMaquina->vel = aux->valor;
			break;
		case 'W':
			miMaquina->w = aux->valor;
			break;

		case 'X':
			miMaquina->z_A = miMaquina->z;
			miMaquina->x_A = miMaquina->x;
			miMaquina->x = aux->valor;
			break;
		case 'Z':
			miMaquina->x_A = miMaquina->x;
			miMaquina->z_A = miMaquina->z;
			miMaquina->z = aux->valor;
			break;
		default:
			break;
	}
	
}

void cuadricu(){
 for(int fila = -unidadL; fila<=unidadL; fila++){
	 if(fila == 0) glColor3f(1.0,0.0,0.0);
	 else glColor3f(0.0,0.0,0.0);
	 glBegin(GL_LINES);
		glVertex2f(-unidadL, fila);glVertex2f(unidadL,fila);
	 }

	 for(int columna = -unidadL; columna<=unidadL; columna++){
		if(columna == 0) glColor3f(1.0,0.0,0.0);
		else glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINES);
		glVertex2f(columna, -unidadL);glVertex2f(columna, unidadL);
	 }
	glEnd();
}

void instruccion(){
	string comando;
	int opc;
	if(miMaquina->comgActivoM != ""){
		comando = miMaquina->comgActivoM;
		comando=comando.substr(1);
		opc = stoi(comando);
			switch(opc){
				case 00:
					G00();
					break;
				case 01:
					G01();
					break;
				case 02:
					miMaquina->sentidoGiro = 0;
					break;
				case 03:
					miMaquina->sentidoGiro = 1;
					break;
				case 20:
					miMaquina->sistemaProgramacion = 1;
					break;
				case 21:
					miMaquina->sistemaProgramacion = 0;
					break;
				case 98:
					miMaquina->avance = 1;
					break;
				case 99:
					miMaquina->avance = 0;
					miMaquina->comgActivoM ="";
					break;


			}
	} 
	if(miMaquina->comgActivoNM != ""){
		comando = miMaquina->comgActivoNM;
		comando=comando.substr(1);
		opc = stoi(comando);
			switch(opc){
			case 04:
				break;
			case 50:
				break;

			}
	}
}

void Dibujo:: configuracion(string line){
	string conf= "";
	char palabra[30];
	int conCarac=0;
	bool activacion=true;
	int ext=line.length();
	for(int caracter = 0; caracter<ext; caracter++){
		if(line[caracter] == '/'){
			activacion = false;
			break;
		}else if(line[caracter] != '<' && line[caracter] != '>'){
			palabra[conCarac]=line[caracter];
			conCarac++;
		}
	}
	palabra[conCarac]='\x0';
	conf = palabra;
	if(altura && activacion){ zpieza = stof(conf); altura = false;}
	if(radio && activacion) {xpieza = stof(conf); radio = false; }

	if(conf == "cuadricula" && activacion==true) cuadricula = true;
	if(conf == "codigo" && activacion==true){
		codigo =true;
	}else if(conf == "codigo" && activacion==false){
		codigo1 = false;
		codigo = false;
	}

	if(conf == "escala" && activacion == true)  escala=true;
	if(conf == "frontal" && activacion == true)  frontal=true;
	if(conf == "isometrico" && activacion == true) isometrico=true;
	if(conf == "lateral" && activacion == true)  lateral=true;
	if(conf == "superior" && activacion == true)  superior=true;
	if(conf == "taristas" && activacion == true)  taristas=true;
	if(conf == "locultas" && activacion == true)  locultas=true;
	if(conf == "solido" && activacion == true)  solido=true;
	if(conf == "altura" && activacion == true) altura = true;
	if(conf == "radio" && activacion == true) radio = true;
}

void Dibujo::SetNodo(Nodo * nodo, int x){
	bloque[x] = nodo;
	numBloque = x;
	numBloqueL = x;

}

/////////////////////////VISTAS
void dibujofrontal(){
	Coordenada *equis = new Coordenada;

		glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	invertir(figura->coordenaditas, equis);
	while(equis->ant!= NULL){
		glVertex2f(equis->z,equis->x);
		equis = equis->ant;
	}
	glEnd();
	glColor3f(1.0,1.0,0.0);
	cout<<"entro frontal"<<endl;
	//glBegin(GL_POLYGON);
	glPointSize(5);
	glBegin(GL_POINTS);
	
	equis = figura->coordenaditas;
	while(equis->ant!= NULL){
		cout<<equis->z<<" "<<equis->x<<endl;
		equis = equis->ant;
	}
	//equis = figura->coordenaditas;
	invertir(figura->coordenaditas, equis);
	while(equis->ant!= NULL){
		glVertex2f(equis->z,equis->x);
		equis = equis->ant;
	}
	glEnd();




}

void dibujosuperior(){
	cout<<"entro superior"<<endl;
	cout<<radioL<<endl;
	float px = 0, py = 0, calx, caly;
	glBegin(GL_POLYGON);
	//glBegin(GL_POINTS);
	for(double i=0; i<10; i+=0.001){
		calx = radiofigura*cos(i)+px;
		caly = radiofigura * sin(i)+px;

		glVertex2f(calx, caly);
	}
	//glEnd();
}

void dibujoisometrico(){
}

void dibujolateral(){
}
/////////////////////////CODIGOS


void G00(){
	Coordenada *aux = new Coordenada();
	aux = figura->coordenaditas;
	glColor3f(0.0,0.0,1.0);
	
	 glLineWidth(3.0f);
	glBegin(GL_LINES);
	 glVertex2f(miMaquina->z_A, miMaquina->x_A);
	 glVertex2f(miMaquina->z, miMaquina->x);
	glEnd();

	 while(aux != NULL){
		 if(aux->x == miMaquina->x){
			 cout<<"Cuidado"<<endl;
		 }else if(aux->z == miMaquina->z){
			cout<<"Cuidado"<<endl;
		 }
		 aux=aux->ant;
	 }
}

void G01(){
	Coordenada *aux = new Coordenada();
	Coordenada *aux2= new Coordenada();
	Coordenada *nuevo = new Coordenada();
	Coordenada *nuevo2 = new Coordenada();
	Coordenada *p = new Coordenada();
	float zz, xx, hza = 16 ,hz = -5, hx=12, hxa=14; //-2, 14
	nuevo=NULL;
	int numcoor = 0;
	bool punto = false;
	hx = miMaquina->x;
	hxa= miMaquina->x_A;
	if(miMaquina->x <0) miMaquina->x = miMaquina->x * -1;
	
	invertir(figura->coordenaditas, aux);
	aux2 = aux->ant;
	glColor3f(0.0,0.0,1.0);
	nuevo->insertar(nuevo,numcoor,aux->z, aux->x);
	numcoor++;
	while(aux != NULL){
		if(miMaquina->z >= aux->z && miMaquina->z <= aux2->z){
			cout<<"prr1"<<endl;
			nuevo2 = aux->ant;
			if(aux2->ant != NULL) p=aux2->ant;
			
			if (miMaquina->x <= nuevo2->x && miMaquina->x >= p->x){
				cout<<"prr2"<<endl;
				nuevo->insertar(nuevo,numcoor,miMaquina->z, aux2->x);
				nuevo->insertar(nuevo, numcoor+1, miMaquina->z, miMaquina->x );
				if(miMaquina->x_A>aux2->x) nuevo->insertar(nuevo, numcoor+2, aux2->z, aux2->x);
				else nuevo->insertar(nuevo, numcoor+2, aux2->z, miMaquina->x_A);
				aux = aux->ant;
				if(aux->ant != NULL)aux2=aux->ant;
				punto = true;
				}
			}
		if(!punto){
			nuevo->insertar(nuevo, numcoor, aux->z, aux->x);	
		}else{
			punto = false;
		}
		numcoor++;
		if(aux2->ant != NULL)aux2=aux2->ant;
		aux=aux->ant;	
	}
	///////////////////////////
	 miMaquina->x = miMaquina->x * -1;
	 figura->coordenaditas = nuevo;
	 nuevo=NULL;
	 numcoor = 0;
	 punto = false;
	 /////////////////////
	invertir(figura->coordenaditas, aux);
	aux= figura->coordenaditas;
	aux2 = aux->ant;
	nuevo->insertar(nuevo,numcoor,aux->z, aux->x);
	numcoor++;
	nuevo->insertar(nuevo,numcoor,aux->ant->z, aux->ant->x);
	numcoor++;

	while(aux!= NULL){
		if(miMaquina->x <= aux->x && miMaquina->x >= aux2->x){
			cout<<"prr1"<<endl;
			nuevo2 = aux->ant;
			if(aux2->ant != NULL) p=aux2->ant;
			
 			if (miMaquina->z >= nuevo2->z && miMaquina->z <= p->z){
				cout<<"prr2"<<endl;
				nuevo->insertar(nuevo,numcoor,miMaquina->z, aux2->x);
				nuevo->insertar(nuevo, numcoor+1, miMaquina->z, miMaquina->x );
				if((miMaquina->x_A*-1)<aux2->x){ nuevo->insertar(nuevo, numcoor+2, p->z, aux2->x);
				cout<<"1";
				}else {nuevo->insertar(nuevo, numcoor+2, p->z, miMaquina->x_A*-1);
				cout<<"2";
				}
				aux = aux->ant;
				aux = aux->ant;
				if(aux->ant != NULL)aux2=aux->ant;
				punto = true;
				}
			}
		if(!punto){
			nuevo->insertar(nuevo, numcoor, aux->z, aux->x);	
		}else{
			punto = false;
		}
		numcoor++;
		if(aux2->ant != NULL)aux2=aux2->ant;
		aux=aux->ant;	
	}



	 ////////////////////////
	 miMaquina->x =hx;
	 miMaquina->x_A=hxa;
	figura->coordenaditas = nuevo;
}


void hola(){
	cout<<endl<<endl<<endl<<endl<<endl<<"hola"<<endl;
	Coordenada *aux = new Coordenada();
	Coordenada *aux2= new Coordenada();
	Coordenada *nuevo = new Coordenada();
	Coordenada *nuevo2 = new Coordenada();
	Coordenada *p = new Coordenada();
	float zz, xx, hza = 16 ,hz = -5, hx=12, hxa=14; //-2, 14
	nuevo=NULL;
	int numcoor = 0;
	bool punto = false;
	

	//for(int x=0; x<3; x++){
	invertir(figura->coordenaditas, aux);
	p = aux;
	while(p != NULL){
		p->z;
		p->x;
		p=p->ant;
	}
	//aux=figura->coordenaditas;
	aux2 = aux->ant;
	glColor3f(0.0,0.0,1.0);
	nuevo->insertar(nuevo,numcoor,aux->z, aux->x);
	numcoor++;
	while(aux != NULL){
		cout << "***************************"<<endl;
		cout <<"z: " <<aux->z<< " zsig: "<<aux2->z<<endl;
		cout <<"x: " <<aux->x<<" xsig: " << aux2->x <<endl;
		//cout << "maquinaz: " << miMaquina->z<<" maquinax: "<< miMaquina->x <<endl;

	if(hz >= aux->z && hz <= aux2->z){
			cout<<"prr1"<<endl;
			nuevo2 = aux->ant;
			//while(nuevo2 != NULL){

			if(aux2->ant != NULL){
				p=aux2->ant;
			}

				cout <<"2x: " <<nuevo2->x<<"2xsig: " << p->x <<endl;
				if (hx <= nuevo2->x && hx >= p->x){
					cout<<"prr2"<<endl;
	//insertarcoor(-2, 15);
	//insertarcoor(-2, 14);////////////
	//insertarcoor(0, 14);
					//nuevo->insertar(nuevo, numcoor+2, -2, 15 );

					nuevo->insertar(nuevo,numcoor,hz, aux2->x);
					nuevo->insertar(nuevo, numcoor+1, hz, hx );
					nuevo->insertar(nuevo, numcoor+2, aux2->z, hxa);
					//nuevo->insertar(nuevo, numcoor+2, aux2->z, 12);
					aux = aux->ant;
					if(aux->ant != NULL){
						aux2=aux->ant;
					}
				
					
				
			/*		numcoor = numcoor+3;*/
					punto = true;
					//cout<<"chido"<<zz << " " << xx<<endl;

					//break;
				
				}
	
				//nuevo2 = nuevo2->ant;
			//}
		}

		if(!punto){
			nuevo->insertar(nuevo, numcoor, aux->z, aux->x);	
		}else{
			punto = false;
		}

		numcoor++;
		if(aux2->ant != NULL){
			aux2=aux2->ant;
		}
		aux=aux->ant;	
		}
	//	}
	//invertir(nuevo, figura->coordenaditas);
	//figura->coordenaditas = nuevo;
	while(nuevo!=NULL){
		cout <<"z: " <<nuevo->z;
		cout <<" x: " <<nuevo->x<<endl;
		nuevo = nuevo->ant;
	}
}

void invertir(Coordenada *bloque, Coordenada *&aux ){
	Coordenada *nuevo = NULL;
	aux = NULL;
	while(bloque != NULL){
		aux->insertar(aux, bloque->num_coor, bloque->z, bloque->x);
		bloque=bloque->ant;	
	}
}