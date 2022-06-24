
//LABERINTO
//ESCUELA POLITECNICA NACIONAL | PROGRAMACION I, CD | 22/02/2022
//HECHO POR: MARTINEZ KEVIN, FERNANDEZ ANDRES, ENRIQUEZ MELANY.
#include <stdio.h>
#include <constream>
#include <windows.h>
#include <string>
using namespace std;
using namespace conio;




#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80



void gotoxy (int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}


void Ocultar_el_Cursor (){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 10	;
	cci.bVisible = FALSE;
	
	SetConsoleCursorInfo(hCon, &cci);
}


int main(){
	
	Ocultar_el_Cursor();
	int x = 10, y = 10;
	gotoxy (x,y); 
	printf("%c", 5);
	
	
	bool game_over = false;
	while (!game_over){
		
		if (kbhit()){
			char tecla = getch();
			gotoxy (x,y); 
			cout << (" ");
			if(tecla == IZQUIERDA) x--;
			if(tecla == DERECHA) x++;
			if(tecla == ARRIBA) y--;
			if(tecla == ABAJO) y++;
			gotoxy (x,y); 
			printf("%c", 5);
		}
		
		Sleep (30);		
	}
	return 0;
}




