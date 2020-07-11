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

int isEmpty_stack(Stack *stack);
StackNode* make_stack_node();
Stack* make_stack();
void print_stack_node(StackNode*);
void push(Stack *stack, Data DataNumber, int key);
StackNode pop(Stack *stack);
void remove_stack(Stack *stack);

#endif // STACK_H_INCLUDED
