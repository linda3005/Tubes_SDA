#ifndef BANTUAN_H_INCLUDED
#define BANTUAN_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>

#define PREORDER	0
#define INORDER		1
#define POSTORDER	2

#define TRUE		1
#define FALSE	 	0

typedef union
{
	double num;
	char opr;
} Data;



double term();
double sum();
double factor();

void CheckAndGetChar(char tmp);
void GotError();
void Menu();

#endif // BANTUAN_H_INCLUDED
