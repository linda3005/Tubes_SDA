#include "Kalkulator.h"
#include "Stack.h"
#include "Tree.h"

#include<conio.h>
#include<windows.h>
#include<stdio.h>


char token; // variable for reading a charactor
Root *root;
Stack *st;

void GotError(){
	puts("Error.\nperiksa kembali masukan anda.");
	exit(1);
}

void CheckAndGetChar(char tmp){
	if(tmp != token){
		GotError();
	}
	token = getchar();
}

/* Push data stack dengan metode postfix 
 * Menghitung operasi penjumlahan dan pengurangan
 */
double sum(){
	double temp = term();
	Data DataNumber;
	while(token == '+' || token == '-'){
		if(token == '+'){
			DataNumber.Operation = '+';
			CheckAndGetChar('+');
			temp += term();
			PushStackNode(st, DataNumber, TRUE);
		}
		else if(token == '-'){
			DataNumber.Operation = '-';
			CheckAndGetChar('-');
			temp -= term();
			PushStackNode(st, DataNumber, TRUE);
		}
	}
	return temp;
}

//Menghitung operasi perkalian dan pembagian
double term(){
	double temp = powerof();
	Data DataNumber;
	while(token == '*' || token == '/'){
		if(token == '*'){
			DataNumber.Operation = '*';
			CheckAndGetChar('*');
			temp *= factor();
			PushStackNode(st, DataNumber, TRUE);
		}
		else if(token == '/'){
			DataNumber.Operation = '/';
			CheckAndGetChar('/');
			temp /= factor();
			PushStackNode(st, DataNumber, TRUE);
		}
	}
	return temp;
}

//menganggap faktor sebagai angka
double factor(){
	double temp = 0.0;
	Data DataNumber;
	if(token == '('){
		// dimuali dengan sum lagi
		CheckAndGetChar('(');
		temp = sum();
		CheckAndGetChar(')');
	}
	else if(token == '-'){
		// negasi
		CheckAndGetChar('-');
		DataNumber.Operation = '-';
		temp = -factor();
		PushStackNode(st, DataNumber, TRUE);
		return temp;
	}
	else if(token == '+'){
		CheckAndGetChar('+');
		return factor();
	}
	else if(isdigit(token)){
		ungetc(token, stdin);//untuk mereplace input (token)
		scanf("%lf", &temp);
		DataNumber.Number = temp;
		PushStackNode(st, DataNumber, FALSE);
		token = getchar();
	}
	else GotError();
	return temp;
}


double powerof(){
	double temp=factor();
	Data DataNumber;
	
	if(token == 'v'){
		CheckAndGetChar('v');
		DataNumber.Operation = 'v';
		temp=sqrt(factor());
		PushStackNode(st, DataNumber, TRUE);
	}
	while(token == '^'){//cek untuk operasi pangkat
		if(token == '^'){
			DataNumber.Operation= '^';
			CheckAndGetChar('^');
			temp=pow(temp,factor());
			PushStackNode(st,DataNumber,TRUE);
		}
	}
	return temp;
}
//==================================UI=======================================//
gotoxy(int x,int y){
	
	HANDLE handle;
	COORD coord;
	coord.X =x;
	coord.Y =y;
	handle  = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle,coord);
}
void loading(int x,int y){
	system("COLOR 70");
	system("cls");
	int i;
	gotoxy(x,y-1);printf("Loading...");
	
	
	for(i=x;i<=x+19;i++){
	    gotoxy(i,y);printf("%c",196);
		gotoxy(i,y+1);printf("%c",196);	
	}
	for(i=y;i<=y+1;i++){
	    gotoxy(x,i);printf("%c",179);
		gotoxy(x+19,i);printf("%c",179);	
	}
	gotoxy(x,y);printf("%c",218);
	gotoxy(x+19,y);printf("%c",191);
	gotoxy(x,y+1);printf("%c",192);
	gotoxy(x+19,y+1);printf("%c",217);
	for ( i = x; i<=x+19;i++){
		gotoxy(i,y);printf("%c",220);
		gotoxy(i,y+1);printf("%c",223);
		Sleep(20);
	}
	system("cls");
}
