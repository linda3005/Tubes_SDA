#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Kalkulator.h"

//Compiler : Dev-C++ 5.1
//Author : Muhammad Hargi Muttaqin
//Berfungsi sebagai inputan dari user setelah itu akan di pop menuju ADT Kalkulator dan ADT Stack
//Dan sebagai alokasi memori bagi stack sendiri.

typedef struct StackNode
{
	int key;
	Data info;
	struct StackNode *pNode;
} StackNode;

typedef struct Stack
{
	StackNode *topNode;
} Stack;

int StackIsEmpty(Stack *ParameterStack);
StackNode* CreateStackNode();
Stack* CreateStack();
//void PrintStackNode(StackNode*);
void PushStackNode(Stack *ParameterStack, Data DataNumber, int key);
StackNode PopStackNode(Stack *ParameterStack);
//void DeleteStack(Stack *ParameterStack);

#endif // STACK_H_INCLUDED
