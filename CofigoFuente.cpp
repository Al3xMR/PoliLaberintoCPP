
//LABERINTO
//ESCUELA POLITECNICA NACIONAL | PROGRAMACION I, CD | 22/02/2022
//HECHO POR: MARTINEZ KEVIN, FERNANDEZ ANDRES, ENRIQUEZ MELANY.
#include <stdio.h>
#include <constream>
#include <windows.h>
#include <string>
#include <iostream>
using namespace std;
using namespace conio;

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

void ejecutarjuego();
void nombredejugador();
void ir_a (int x, int y);
void Ocultar_el_Cursor();
void imprcar(int x, int y, int ascii);
void pintarborde();
void letreroLaberinto(int i, int j);
void menuprincipal();
void ControlesYEncabezado();
void imprimirmapa1();
void letreroFin(int i, int j);
void nivelcompletado();
bool verificar_limite(int x,int y);
int player=0;
void pantallacreditos();
void pantallapuntajes();
void pantallaFinal();

struct jugador{
	int puntuacion;
	string nombre;
}; jugador usuario[10];


int main(){
	for(int i=0; i<10; i++){
		usuario[i].nombre="----";
		usuario[i].puntuacion=0;
	}
	Ocultar_el_Cursor();
	menuprincipal();
	
	return 0;
}


void ir_a (int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}

void Ocultar_el_Cursor(){
	system("mode con: cols=100 lines=40"); //tamanio inicial del cmd
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 10	;
	cci.bVisible = FALSE;
	
	SetConsoleCursorInfo(hCon, &cci);
}

void imprcar(int x, int y, int ascii){
	ir_a(x, y); printf("%c", ascii);
}

void pintarborde(){
	//borde superior
	for(int i=0; i<92; i++){
	ir_a(3+i, 3); printf("%c", 177);	
	}
	//borde inferior
	for(int i=0; i<93; i++){
	ir_a(3+i, 38); printf("%c", 177);	
	}
	//borde izquierdo
	for(int i=0; i<35; i++){
	ir_a(3, 3+i); printf("%c", 177);	
	}
	//borde derecho
	for(int i=0; i<35; i++){
	ir_a(95, 3+i); printf("%c", 177);	
	}
	//borde medio
	for(int i=0; i<93; i++){
		imprcar(3+i, 29, 177);	
	}
}

void letreroLaberinto(int i, int j){

	imprcar(17+i, 15+j, 219);
	imprcar(17+i, 16+j, 219);
	imprcar(17+i, 17+j, 219);
	imprcar(17+i, 18+j, 219);	//L
	imprcar(17+i, 19+j, 219);
	imprcar(18+i, 19+j, 219);
	imprcar(19+i, 19+j, 219);
	
	imprcar(21+i, 19+j, 219);
	imprcar(21+i, 18+j, 219);
	imprcar(21+i, 17+j, 219);
	imprcar(21+i, 16+j, 219);	//A
	imprcar(22+i, 15+j, 219);
	imprcar(22+i, 17+j, 219);
	imprcar(23+i, 19+j, 219);
	imprcar(23+i, 18+j, 219);
	imprcar(23+i, 17+j, 219);
	imprcar(23+i, 16+j, 219);
	
	imprcar(25+i, 15+j, 219);
	imprcar(25+i, 16+j, 219);
	imprcar(25+i, 17+j, 219);
	imprcar(25+i, 18+j, 219);	//B
	imprcar(25+i, 19+j, 219);
	imprcar(26+i, 15+j, 219);
	imprcar(26+i, 19+j, 219);
	imprcar(26+i, 17+j, 219);
	imprcar(27+i, 18+j, 219);
	imprcar(27+i, 16+j, 219);
	
	imprcar(29+i, 15+j, 219);
	imprcar(29+i, 16+j, 219);
	imprcar(29+i, 17+j, 219);
	imprcar(29+i, 18+j, 219);	//E
	imprcar(29+i, 19+j, 219);
	imprcar(30+i, 15+j, 219);
	imprcar(31+i, 15+j, 219);
	imprcar(30+i, 19+j, 219);
	imprcar(31+i, 19+j, 219);
	imprcar(30+i, 17+j, 219);

	imprcar(33+i, 15+j, 219);
	imprcar(33+i, 16+j, 219);
	imprcar(33+i, 17+j, 219);
	imprcar(33+i, 18+j, 219);	//R
	imprcar(33+i, 19+j, 219);
	imprcar(34+i, 15+j, 219);
	imprcar(35+i, 15+j, 219);
	imprcar(35+i, 16+j, 219);
	imprcar(34+i, 17+j, 219);
	imprcar(35+i, 18+j, 219);
	imprcar(35+i, 19+j, 219);
	
	imprcar(37+i, 15+j, 219);
	imprcar(37+i, 16+j, 219);
	imprcar(37+i, 17+j, 219);
	imprcar(37+i, 18+j, 219);	//I
	imprcar(37+i, 19+j, 219);
	
	imprcar(39+i, 15+j, 219);
	imprcar(39+i, 16+j, 219);
	imprcar(39+i, 17+j, 219);
	imprcar(39+i, 18+j, 219);	//N
	imprcar(39+i, 19+j, 219);
	imprcar(40+i, 16+j, 219);
	imprcar(40+i, 17+j, 219);
	imprcar(41+i, 17+j, 219);
	imprcar(41+i, 18+j, 219);
	imprcar(42+i, 15+j, 219);
	imprcar(42+i, 16+j, 219);
	imprcar(42+i, 17+j, 219);
	imprcar(42+i, 18+j, 219);
	imprcar(42+i, 19+j, 219);
	
	imprcar(45+i, 15+j, 219);
	imprcar(45+i, 16+j, 219);
	imprcar(45+i, 17+j, 219);
	imprcar(45+i, 18+j, 219);	//T
	imprcar(45+i, 19+j, 219);
	imprcar(44+i, 15+j, 219);
	imprcar(46+i, 15+j, 219);
	
	imprcar(48+i, 15+j, 219);
	imprcar(48+i, 16+j, 219);
	imprcar(48+i, 17+j, 219);
	imprcar(48+i, 18+j, 219);	//O
	imprcar(48+i, 19+j, 219);
	imprcar(49+i, 15+j, 219);
	imprcar(49+i, 19+j, 219);
	imprcar(50+i, 15+j, 219);
	imprcar(50+i, 16+j, 219);
	imprcar(50+i, 17+j, 219);
	imprcar(50+i, 18+j, 219);
	imprcar(50+i, 19+j, 219);

	imprcar(28+i, 9+j, 219);
	imprcar(28+i, 10+j, 219);
	imprcar(28+i, 11+j, 219);
	imprcar(28+i, 12+j, 219);	//P
	imprcar(28+i, 13+j, 219);
	imprcar(29+i, 9+j, 219);
	imprcar(29+i, 11+j, 219);
	imprcar(30+i, 10+j, 219);
	
	imprcar(32+i, 9+j, 219);
	imprcar(32+i, 10+j, 219);
	imprcar(32+i, 11+j, 219);
	imprcar(32+i, 12+j, 219);	//O
	imprcar(32+i, 13+j, 219);
	imprcar(33+i, 9+j, 219);
	imprcar(33+i, 13+j, 219);
	imprcar(34+i, 9+j, 219);
	imprcar(34+i, 10+j, 219);
	imprcar(34+i, 11+j, 219);
	imprcar(34+i, 12+j, 219);
	imprcar(34+i, 13+j, 219);
	
	imprcar(36+i, 9+j, 219);
	imprcar(36+i, 10+j, 219);
	imprcar(36+i, 11+j, 219);
	imprcar(36+i, 12+j, 219);	//L
	imprcar(36+i, 13+j, 219);
	imprcar(37+i, 13+j, 219);
	imprcar(38+i, 13+j, 219);
	
	imprcar(40+i, 9+j, 219);
	imprcar(40+i, 10+j, 219);
	imprcar(40+i, 11+j, 219);
	imprcar(40+i, 12+j, 219);	//I
	imprcar(40+i, 13+j, 219);
}

void letreroFin(int i, int j){
	imprcar(0+i, 0+j, 219);
	imprcar(1+i, 0+j, 219);
	imprcar(2+i, 0+j, 219);
	imprcar(5+i, 0+j, 219);
	imprcar(8+i, 0+j, 219);
	imprcar(12+i, 0+j, 219);
	imprcar(14+i, 0+j, 219);
	imprcar(15+i, 0+j, 219);
	imprcar(16+i, 0+j, 219);
	imprcar(0+i, 1+j, 219);
	imprcar(4+i, 1+j, 219);
	imprcar(6+i, 1+j, 219);
	imprcar(8+i, 1+j, 219);
	imprcar(9+i, 1+j, 219);
	imprcar(11+i, 1+j, 219);
	imprcar(12+i, 1+j, 219);
	imprcar(14+i, 1+j, 219);//
	imprcar(0+i, 2+j, 219);
	imprcar(2+i, 2+j, 219);
	imprcar(4+i, 2+j, 219);
	imprcar(6+i, 2+j, 219);
	imprcar(8+i, 2+j, 219);
	imprcar(10+i, 2+j, 219);
	imprcar(12+i, 2+j, 219);
	imprcar(14+i, 2+j, 219);
	imprcar(15+i, 2+j, 219);
	imprcar(0+i, 3+j, 219);
	imprcar(2+i, 3+j, 219);
	imprcar(4+i, 3+j, 219);
	imprcar(5+i, 3+j, 219);
	imprcar(6+i, 3+j, 219);
	imprcar(8+i, 3+j, 219);
	imprcar(12+i, 3+j, 219);//
	imprcar(14+i, 3+j, 219);
	imprcar(0+i, 4+j, 219);
	imprcar(1+i, 4+j, 219);
	imprcar(2+i, 4+j, 219);
	imprcar(4+i, 4+j, 219);
	imprcar(6+i, 4+j, 219);
	imprcar(8+i, 4+j, 219);
	imprcar(12+i, 4+j, 219);
	imprcar(14+i, 4+j, 219);
	imprcar(15+i, 4+j, 219);
	imprcar(16+i, 4+j, 219);
	imprcar(2+i, 6+j, 219);
	imprcar(3+i, 6+j, 219);
	imprcar(4+i, 6+j, 219);
	imprcar(6+i, 6+j, 219);
	imprcar(10+i, 6+j, 219);
	imprcar(12+i, 6+j, 219);//
	imprcar(13+i, 6+j, 219);
	imprcar(14+i, 6+j, 219);
	imprcar(16+i, 6+j, 219);
	imprcar(17+i, 6+j, 219);
	imprcar(2+i, 7+j, 219);
	imprcar(4+i, 7+j, 219);
	imprcar(6+i, 7+j, 219);
	imprcar(10+i, 7+j, 219);
	imprcar(12+i, 7+j, 219);
	imprcar(16+i, 7+j, 219);
	imprcar(18+i, 7+j, 219);
	imprcar(2+i, 8+j, 219);
	imprcar(4+i, 8+j, 219);
	imprcar(7+i, 8+j, 219);
	imprcar(9+i, 8+j, 219);
	imprcar(12+i, 8+j, 219);
	imprcar(13+i, 8+j, 219);//
	imprcar(16+i, 8+j, 219);
	imprcar(17+i, 8+j, 219);
	imprcar(2+i, 9+j, 219);
	imprcar(4+i, 9+j, 219);
	imprcar(7+i, 9+j, 219);
	imprcar(9+i, 9+j, 219);
	imprcar(12+i, 9+j, 219);
	imprcar(16+i, 9+j, 219);
	imprcar(18+i, 9+j, 219);
	imprcar(2+i, 10+j, 219);
	imprcar(3+i, 10+j, 219);
	imprcar(4+i, 10+j, 219);
	imprcar(8+i, 10+j, 219);
	imprcar(12+i, 10+j, 219);
	imprcar(13+i, 10+j, 219);
	imprcar(14+i, 10+j, 219);
	imprcar(16+i, 10+j, 219);
	imprcar(18+i, 10+j, 219);
}

void menuprincipal(){
	char opc;
	bool respuesta=false;
	do{
		textbackground(WHITE);
		clrscr();
		textcolor(BLUE); letreroLaberinto(15, 0);
		textcolor(BLACK); ir_a(45, 23); printf("%i. JUGAR", 1);
		ir_a(45, 24); printf("%i. PUNTAJES", 2);
		ir_a(45, 25); printf("%i. CR%cDITOS", 3, 144);
		ir_a(45, 26); printf("%i. SALIR", 4);
		opc = getch();
		if((opc=='1'||opc=='2')||(opc=='3'||opc=='4')){
			respuesta=true;
		}
	}while(respuesta==false);
	clrscr();
	switch(opc){
		case '1':{
			ejecutarjuego();
			break;
		}
		case '2':{
			pantallapuntajes();
			break;
		}
		case '3':{
			pantallacreditos();
			break;
		}
		case '4':{
			pantallaFinal();
			break;
		}
	}
}

void imprimirmapa1(){
	pintarborde();
	for(int i=0; i<24; i++){
		imprcar(4+i, 5, 177);
	}
	for(int i=0; i<63; i++){
		imprcar(33+i, 5, 177);
	}
	imprcar(8, 6, 177);
	imprcar(27, 6, 177);
	imprcar(33, 6, 177);
	imprcar(41, 6, 177);
	imprcar(8, 7, 177);
	imprcar(16, 7, 177);
	imprcar(27, 7, 177);
	imprcar(41, 7, 177);
	imprcar(33, 7, 177);
	imprcar(8, 8, 177);
	imprcar(16, 8, 177);
	imprcar(33, 8, 177);
	for(int i=0; i<44; i++){
		imprcar(46+i, 8, 177);
	}
	imprcar(8, 9, 177);
	for(int i=0; i<26; i++){
		imprcar(16+i, 9, 177);
	}
	imprcar(41, 9, 177);
	imprcar(46, 9, 177);
	imprcar(50, 9, 177);
	imprcar(89, 9, 177);
	imprcar(8, 10, 177);
	imprcar(16, 10, 177);
	imprcar(27, 10, 177);
	imprcar(41, 10, 177);
	imprcar(46, 10, 177);
	imprcar(50, 10, 177);
	imprcar(89, 10, 177);
	for(int i=0; i<32; i++){
		imprcar(54+i, 10, 177);
	}
	imprcar(16, 11, 177);
	imprcar(27, 11, 177);
	imprcar(46, 11, 177);
	imprcar(41, 11, 177);
	imprcar(54, 11, 177);
	for(int i=0; i<9; i++){
		imprcar(4+i, 12, 177);
	}
	imprcar(16, 12, 177);
	imprcar(27, 12, 177);
	imprcar(33, 12, 177);
	imprcar(41, 12, 177);
	for(int i=0; i<5; i++){
		imprcar(46+i, 12, 177);
	}
	for(int i=0; i<41; i++){
		imprcar(54+i, 12, 177);
	}
	imprcar(16, 13, 177);
	imprcar(27, 13, 177);
	imprcar(33, 13, 177);
	imprcar(41, 13, 177);
	imprcar(46, 13, 177);
	for(int i=0; i<9; i++){
		imprcar(8+i, 14, 177);
	}
	imprcar(27, 14, 177);
	imprcar(33, 14, 177);
	imprcar(41, 14, 177);
	imprcar(46, 14, 177);
	for(int i=0; i<40; i++){
		imprcar(50+i, 14, 177);	
	}
	imprcar(8, 15, 177);
	imprcar(27, 15, 177);
	imprcar(33, 15, 177);
	imprcar(46, 15, 177);
	imprcar(50, 15, 177);
	imprcar(89, 15, 177);
	imprcar(54, 15, 177);
	imprcar(8, 16, 177);
	imprcar(27, 16, 177);
	imprcar(33, 16, 177);
	imprcar(46, 16, 177);
	imprcar(50, 16, 177);
	imprcar(89, 16, 177);
	imprcar(54, 16, 177);
	for(int i=0; i<9; i++){
		imprcar(8+i, 17, 177);
	}
	imprcar(27, 17, 177);
	for(int i=0; i<13; i++){
		imprcar(33+i, 17, 177);
	}
	imprcar(46, 17, 177);
	imprcar(50, 17, 177);
	imprcar(89, 17, 177);
	imprcar(54, 17, 177);
	imprcar(60, 17, 177);
	imprcar(64, 17, 177);
	imprcar(27, 18, 177);
	imprcar(50, 18, 177);
	imprcar(54, 18, 177);
	imprcar(60, 18, 177);
	imprcar(64, 18, 177);
	imprcar(46, 18, 177);
	for(int i=0; i<14; i++){
		imprcar(3+i, 19, 177);
	}
	for(int i=0; i<15; i++){
		imprcar(27+i, 19, 177);
	}
	imprcar(46, 19, 177);
	imprcar(50, 19, 177);
	imprcar(54, 19, 177);
	for(int i=0; i<35; i++){
		imprcar(60+i, 19, 177);
	}
	imprcar(46, 20, 177);
	imprcar(54, 20, 177);
	imprcar(27, 20, 177);
	imprcar(16, 20, 177);
	imprcar(41, 20, 177);
	imprcar(60, 20, 177);
	imprcar(8, 21, 177);
	imprcar(16, 21, 177);
	for(int i=0; i<9; i++){
		imprcar(27+i, 21, 177);
	}
	imprcar(41, 21, 177);
	for(int i=0; i<9; i++){
		imprcar(46+i, 21, 177);
	}
	imprcar(60, 21, 177);
	imprcar(75, 21, 177);
	imprcar(80, 21, 177);
	imprcar(16, 22, 177);
	imprcar(8, 22, 177);
	imprcar(35, 22, 177);
	imprcar(41, 22, 177);
	imprcar(46, 22, 177);
	imprcar(60, 22, 177);
	imprcar(75, 22, 177);
	imprcar(80, 22, 177);
	for(int i=0; i<15; i++){
		imprcar(16+i, 23, 177);
	}
	imprcar(8, 23, 177);
	imprcar(35, 23, 177);
	imprcar(41, 23, 177);
	imprcar(46, 23, 177);
	for(int i=0; i<5; i++){
		imprcar(50+i, 23, 177);
	}
	imprcar(60, 23, 177);
	for(int i=0; i<6; i++){
		imprcar(75+i, 23, 177);
	}
	imprcar(8, 24, 177);
	imprcar(35, 24, 177);
	imprcar(46, 24, 177);
	imprcar(50, 24, 177);
	imprcar(60, 24, 177);
	imprcar(75, 24, 177);
	imprcar(8, 25, 177);
	for(int i=0; i<20; i++){
		imprcar(16+i, 25, 177);
	}
	for(int i=0; i<6; i++){
		imprcar(41+i, 25, 177);
	}
	for(int i=0; i<11; i++){
		imprcar(50+i, 25, 177);
	}
	imprcar(75, 25, 177);
	for(int i=0; i<15; i++){
		imprcar(80+i, 25, 177);
	}
	imprcar(8, 26, 177);
	imprcar(16, 26, 177);
	imprcar(41, 26, 177);
	imprcar(46, 26, 177);
	imprcar(75, 26, 177);
	imprcar(8, 27, 177);
	imprcar(16, 27, 177);
	for(int i=0; i<22; i++){
		imprcar(20+i, 27, 177);
	}
	for(int i=0; i<15; i++){
		imprcar(46+i, 27, 177);
	}
	for(int i=0; i<11; i++){
		imprcar(65+i, 27, 177);
	}
	for(int i=0; i<15; i++){
		imprcar(80+i, 27, 177);
	}
	imprcar(8, 28, 177);
	imprcar(20, 28, 177);
	imprcar(65, 28, 177);
	for(int i=0; i<5; i++){
		imprcar(12, 10-i, 177);
	}
	for(int i=0; i<12; i++){
		imprcar(22, 10+i, 177);
	}
	for(int i=0; i<20; i++){
		imprcar(88-i, 17, 177);
	}
	for(int i=0; i<8; i++){
		imprcar(12, 20+i, 177);
	}
	for(int i=0; i<10; i++){
		imprcar(60+i, 25, 177);
	}
	for(int i=0; i<5; i++){
		imprcar(69, 25-i, 177);
	}
	for(int i=0; i<11; i++){
		imprcar(95-i, 22, 177);
	}
	textcolor(RED); ir_a(94, 28); printf("%c", 219);
	textcolor(BLUE); ir_a(4, 4); printf("%c", 219);
}

void ControlesYEncabezado(){
	ir_a(5, 1); printf("%c%c POLI LABERINTO %c%c", 158, 158, 158, 158);
	ir_a(75, 1); printf("%c PUNTAJE%c", 175, 58);
	ir_a(5, 31); printf("CONTROLES%c", 58);
	ir_a(8, 32); printf("Tecla %c%c Ir a la derecha", 16, 58);
	ir_a(8, 33); printf("Tecla %c%c Ir a la izquierda", 17, 58);
	ir_a(8, 34); printf("Tecla %c%c Ir a la arriba", 30, 58);
	ir_a(8, 35); printf("Tecla %c%c Ir a la abajo", 31, 58);
	ir_a(8, 36); printf("Tecla Q%c Salir al menu principal", 58);
	ir_a(60, 31); printf("OBJETIVO%c", 58);
	ir_a(63, 32); printf("Lleva a");
	textcolor(BLACK); ir_a(71, 32); printf("%c", 207); ir_a(73, 32); printf("desde");
	textcolor(RED); ir_a(79, 32); printf("%c", 219);
	textcolor(BLACK); ir_a(81, 32); printf("hasta");
	textcolor(BLUE); ir_a(87, 32); printf("%c", 219);
	textcolor(BLACK);ir_a(63, 33); printf("sin equivocarte de camino para");ir_a(63, 34); printf("obtener el mejor puntaje.");
}

bool verificar_limite(int x,int y){
	bool eslimite=false;
	switch(y){
		case 3:{
			for(int i=0; i<=92; i++){
				if(x==3+i){				//3 al 95
					eslimite=true;
				}
			}
			break;
		}
		case 4:{
			if(x==3||x==4||x==95){
				eslimite=true;			//x=3, x=4 o x=95
			}
			break;
		}
		case 5:{
			for(int i=0; i<=24; i++){
				if(x==3+i){				//3 al 27
					eslimite=true;
				}
			}
			for(int i=0; i<=62; i++){
				if(x==33+i){			//33 al 95
					eslimite=true;
				}
			}
			break;
		}
		case 6:{
			if(x==3||x==8||x==12||x==27||x==33||x==41||x==95){
				eslimite=true;			//x=3, x=8, x=12, x==27, x=33, x=41 o x=95
			}
			break;
		}
		case 7:{
			if(x==3||x==8||x==12||x==16||x==27||x==33||x==41||x==95){
				eslimite=true;			
			}
			break;
		}
		case 8:{
			if(x==3||x==8||x==12||x==16||x==33||x==95){
				eslimite=true;			
			}
			for(int i=0; i<=43; i++){
				if(x==46+i){			
					eslimite=true;
				}
			}
			break;
		}
		case 9:{
			if(x==3||x==8||x==12||x==46||x==50||x==89||x==95){
				eslimite=true;			
			}
			for(int i=0; i<=25; i++){
				if(x==16+i){			
					eslimite=true;
				}
			}
			break;
		}
		case 10:{
			if(x==3||x==8||x==12||x==16||x==22||x==27||x==41||x==46||x==50||x==89||x==95){
				eslimite=true;			
			}
			for(int i=0; i<=31; i++){
				if(x==54+i){			
					eslimite=true;
				}
			}
			break;
		}
		case 11:{
			if(x==3||x==16||x==22||x==27||x==41||x==46||x==54||x==95){
				eslimite=true;			
			}
			break;
		}
		case 12:{
			if(x==16||x==22||x==27||x==33||x==41){
				eslimite=true;			
			}
			for(int i=0; i<=9; i++){
				if(x==3+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=4; i++){
				if(x==46+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=41; i++){
				if(x==54+i){			
					eslimite=true;
				}
			}
			break;
		}
		case 13:{
			if(x==3||x==16||x==22||x==27||x==33||x==41||x==46||x==95){
				eslimite=true;			
			}
			break;
		}
		case 14:{
			if(x==3||x==22||x==27||x==33||x==41||x==46||x==95){
				eslimite=true;			
			}
			for(int i=0; i<=8; i++){
				if(x==8+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=39; i++){
				if(x==50+i){			
					eslimite=true;
				}
			}
			break;
		}
		case 15:{
			if(x==3||x==8||x==22||x==27||x==33||x==46||x==50||x==54||x==89||x==95){
				eslimite=true;			
			}
			break;
		}
		case 16:{
			if(x==3||x==8||x==22||x==27||x==33||x==46||x==50||x==54||x==89||x==95){
				eslimite=true;			
			}
			break;
		}
		case 17:{
			if(x==3||x==22||x==27||x==50||x==54||x==60||x==64||x==95){
				eslimite=true;			
			}
			for(int i=0; i<=8; i++){
				if(x==8+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=13; i++){
				if(x==33+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=20; i++){
				if(x==69+i){			
					eslimite=true;
				}
			}
			break;
		}
		case 18:{
			if(x==3||x==22||x==27||x==46||x==50||x==54||x==60||x==64||x==95){
				eslimite=true;			
			}
			break;
		}
		case 19:{
			if(x==22||x==46||x==50||x==54){
				eslimite=true;			
			}
			for(int i=0; i<=13; i++){
				if(x==3+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=14; i++){
				if(x==27+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=35; i++){
				if(x==60+i){			
					eslimite=true;
				}
			}
			break;
		}
		case 20:{
			if(x==3||x==12||x==16||x==22||x==27||x==41||x==46||x==54||x==60||x==95){
				eslimite=true;			
			}
			break;
		}
		case 21:{
			if(x==3||x==8||x==12||x==16||x==22||x==41||x==60||x==69||x==75||x==80||x==95){
				eslimite=true;			
			}
			for(int i=0; i<=7; i++){
				if(x==27+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=8; i++){
				if(x==46+i){			
					eslimite=true;
				}
			}
			break;
		}
		case 22:{
			if(x==3||x==8||x==12||x==16||x==34||x==41||x==46||x==60||x==69||x==75||x==80){
				eslimite=true;			
			}
			for(int i=0; i<=10; i++){
				if(x==85+i){			
					eslimite=true;
				}
			}
			break;
		}
		case 23:{
			if(x==3||x==8||x==12||x==35||x==41||x==46||x==60||x==69||x==95){
				eslimite=true;			
			}
			for(int i=0; i<=14; i++){
				if(x==16+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=4; i++){
				if(x==50+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=5; i++){
				if(x==75+i){			
					eslimite=true;
				}
			}
			break;
		}
		case 24:{
			if(x==3||x==8||x==12||x==34||x==46||x==50||x==60||x==69||x==75||x==95){
				eslimite=true;			
			}
			break;
		}
		case 25:{
			if(x==3||x==8||x==12||x==75){
				eslimite=true;			
			}
			for(int i=0; i<=19; i++){
				if(x==16+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=5; i++){
				if(x==41+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=19; i++){
				if(x==50+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=15; i++){
				if(x==80+i){			
					eslimite=true;
				}
			}
			break;
		}
		case 26:{
			if(x==3||x==8||x==12||x==16||x==41||x==46||x==75||x==95){
				eslimite=true;			
			}
			break;
		}
		case 27:{
			if(x==3||x==8||x==12||x==16){
				eslimite=true;			
			}
			for(int i=0; i<=21; i++){
				if(x==20+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=14; i++){
				if(x==46+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=10; i++){
				if(x==65+i){			
					eslimite=true;
				}
			}
			for(int i=0; i<=15; i++){
				if(x==80+i){			
					eslimite=true;
				}
			}
			break;
		}
		case 28:{
			if(x==3||x==8||x==20||x==65||x==94||x==95){
				eslimite=true;			
			}
			break;
		}
		case 29:{
			for(int i=0; i<=92; i++){
				if(x==3+i){			
					eslimite=true;
				}
			}
			break;
		}
	}
	return eslimite;
}

int puntuar(int x, int y){
	int puntaje=0;
	if(x==80&&y==20) puntaje=10;
	if(x==65&&y==26) puntaje=10;
	if(x==81&&y==18) puntaje=10;
	if(x==58&&y==13) puntaje=10;
	if(x==85&&y==9) puntaje=10;
	if(x==37&&y==18) puntaje=10;
	if(x==25&&y==24) puntaje=10;
	if(x==9&&y==18) puntaje=10;
	if(x==16&&y==6) puntaje=10;
	if(x==24&&y==4) puntaje=10;
	if(x==41&&y==8) puntaje=-5;
	if(x==35&&y==20) puntaje=-5;
	if(x==9&&y==27) puntaje=-5;
	if(x==10&&y==27) puntaje=-5;
	if(x==11&&y==27) puntaje=-5;
	if(x==8&&y==20) puntaje=-5;
	if(x==23&&y==21) puntaje=-5;
	if(x==24&&y==21) puntaje=-5;
	if(x==25&&y==21) puntaje=-5;
	if(x==26&&y==21) puntaje=-5;
	if(x==60&&y==28) puntaje=-5;
	if(x==80&&y==26) puntaje=-5;
	if(x==69&&y==20) puntaje=-5;
	if(x==41&&y==28) puntaje=-5;
	if(x==69&&y==15) puntaje=-5;
	if(x==69&&y==16) puntaje=-5;
	if(x==50&&y==20) puntaje=-5;
	if(x==50&&y==13) puntaje=-5;
	if(x==50&&y==11) puntaje=-5;
	if(x==85&&y==11) puntaje=-5;
	if(x==12&&y==11) puntaje=-5;
	if(x==8&&y==11) puntaje=-5;
	if(x==50&&y==4) puntaje=-5;
	if(x==70&&y==4) puntaje=-5;
	if(x==86&&y==4) puntaje=-5;
	return puntaje;
}

void nombredejugador(){
	clrscr();
	ir_a(35, 14); printf("Introduce tu nombre:");
	ir_a(35, 16); cin>>usuario[player].nombre;
}

void nivelcompletado(){
	textbackground(WHITE); 
	clrscr();
	letreroFin(40, 12);
	ir_a(35, 27); cout<<"Jugador: "<<usuario[player].nombre;
	ir_a(35, 28); cout<<"Puntuacion: "<<usuario[player].puntuacion;
	Sleep (3000);
}

void ejecutarjuego(){
	nombredejugador();
	textbackground(YELLOW); clrscr();
	textcolor(MAGENTA); imprimirmapa1();
	textcolor(BLACK); ControlesYEncabezado();
	textcolor(BLACK);
	int x=93, y=28;
	ir_a(x, y); printf("%c", 207);
	int puntaje=100;
	bool yapaso=false;
	bool game_over = false;
	while (!game_over){
		if (kbhit()){
			ir_a(86, 1); cout<<"     ";
			ir_a(86, 1); cout<<puntaje;
			char tecla = getch();
			ir_a (x,y); 
			cout << (" ");
			if(tecla == IZQUIERDA){
				if(verificar_limite(x-1, y)==false){
					x--;
					puntaje=puntaje+puntuar(x, y);
				}
			}
			if(tecla == DERECHA){
				if(verificar_limite(x+1, y)==false){
					x++;
					puntaje=puntaje+puntuar(x, y);
				}
			}
			if(tecla == ABAJO){
				if(verificar_limite(x, y+1)==false){
					y++;
					puntaje=puntaje+puntuar(x, y);
				}
			}
			if(tecla == ARRIBA){
				if(verificar_limite(x, y-1)==false){
					y--;
					puntaje=puntaje+puntuar(x, y);
				}
			}
			if(tecla == 'q'||tecla == 'Q') game_over = true;
			if(x==5&&y==4) game_over = true;
			ir_a (x,y); 
			printf("%c", 207);
		}
		Sleep (30);		
	}
	usuario[player].puntuacion=puntaje;
	nivelcompletado();
	if(player==9){
		player==0;
	}else{
		player++;
	}
	clrscr();
	menuprincipal();
}

void pantallapuntajes(){
	textbackground(DARKGRAY);
	textcolor(WHITE);
	clrscr();
	ir_a(45, 3); cout<<"PUNTAJES";
	ir_a(45, 4); cout<<"========";
	ir_a(25, 7); cout<<usuario[0].nombre;
	ir_a(25, 10); cout<<usuario[1].nombre;
	ir_a(25, 13); cout<<usuario[2].nombre;
	ir_a(25, 16); cout<<usuario[3].nombre;
	ir_a(25, 19); cout<<usuario[4].nombre;
	ir_a(25, 22); cout<<usuario[5].nombre;
	ir_a(25, 25); cout<<usuario[6].nombre;
	ir_a(25, 28); cout<<usuario[7].nombre;
	ir_a(25, 31); cout<<usuario[8].nombre;
	ir_a(25, 34); cout<<usuario[9].nombre;
	
	ir_a(70, 7); cout<<usuario[0].puntuacion;
	ir_a(70, 10); cout<<usuario[1].puntuacion;
	ir_a(70, 13); cout<<usuario[2].puntuacion;
	ir_a(70, 16); cout<<usuario[3].puntuacion;
	ir_a(70, 19); cout<<usuario[4].puntuacion;
	ir_a(70, 22); cout<<usuario[5].puntuacion;
	ir_a(70, 25); cout<<usuario[6].puntuacion;
	ir_a(70, 28); cout<<usuario[7].puntuacion;
	ir_a(70, 31); cout<<usuario[8].puntuacion;
	ir_a(70, 34); cout<<usuario[9].puntuacion;
	getch();
	menuprincipal();
}

void pantallacreditos(){
	
	textbackground(BLACK);
	clrscr();
	textcolor(DARKGRAY);
	letreroLaberinto(15, -6);
	
	ir_a(35,15); printf("ESCUELA POLITECNICA NACIONAL");
	ir_a(40,16); printf("PROGRAMACION I, CD");
	ir_a(43,17); printf("PERIODO 2021-B");
	
	textcolor(WHITE); ir_a(15,20); printf("%c     KEVIN ALEXIS MARTINEZ RUEDA", 175);
	textcolor(CYAN); ir_a(22,21); printf("%cNo importa los obstaculos, el quiere construir su futuro con la carrera%c", 34, 34);
	textcolor(WHITE); ir_a(15,24); printf("%c     ANDRES PATRICIO FERNANDEZ OBACO", 175);
	textcolor(CYAN); ir_a(22,25); printf("%cSu mayor anhelo es vivir programando%c", 34, 34);
	textcolor(WHITE); ir_a(15,28); printf("%c     MELANY MIREYA ENRIQUEZ ONOFA", 175);
	textcolor(CYAN); ir_a(22,29); printf("%cAspira a crear un algoritmo que le permita recorrer el mundo%c", 34, 34);
	
	textcolor(DARKGRAY); ir_a(43,34); printf("ECUADOR - 2022");
	getch();
	menuprincipal();
}

void pantallaFinal(){
	textbackground(WHITE); 
	clrscr();
	letreroFin(40, 12);
	ir_a(40, 27); printf("%cGRACIAS POR JUGAR%c", 173, 33);
	textcolor(CYAN); ir_a(28,35); printf("%cSi puedes imaginarlo, puedes programarlo%c", 34, 34);
	textcolor(WHITE);
}