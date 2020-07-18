#ifndef KALKULATOR_H_INCLUDED
#define KALKULATOR_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PREORDER	0
#define INORDER		1
#define POSTORDER	2

#define TRUE		1
#define FALSE	 	0

typedef union
{
	double Number;
	char Operation;
} Data;


double term();
double sum();
double factor();
double powerof();
void CheckAndGetChar(char tmp);
void GotError();
void Menu();
//===============================================UI==================================/
void gotoxy(int x,int y);
void loading(int x,int y);

#endif // BANTUAN_H_INCLUDED
