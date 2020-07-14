#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Bantuan.h"

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
void PrintStackNode(StackNode*);
void PushStackNode(Stack *ParameterStack, Data DataNumber, int key);
StackNode PopStackNode(Stack *ParameterStack);
void DeleteStack(Stack *ParameterStack);

#endif // STACK_H_INCLUDED
