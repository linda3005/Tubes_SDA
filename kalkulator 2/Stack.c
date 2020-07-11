#include "Stack.h"

int isEmpty_stack(Stack *stack)
{
	if(!stack) {
		puts("the stack doesn't exist.");
		return TRUE;
	}
	return stack->topNode == NULL;
}

StackNode* make_stack_node()
{
	StackNode *tmp = (StackNode*)calloc(sizeof(StackNode), 1);
	if(!tmp){
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

Stack* make_stack()
{
	Stack *tmp = (Stack*)calloc(sizeof(Stack), 1);
	if(!tmp) {
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

void print_stack_node(StackNode *TreeNode)
{
	if(!TreeNode)	return;
	if(TreeNode->key){
		printf("%c", TreeNode->info.Operation);
	}
	else{
		printf("%g", TreeNode->info.Number);
	}
}

void push(Stack *stack, Data DataNumber, int key)
{
	StackNode *tmp = make_stack_node();
	tmp->info = DataNumber;
	tmp->key = key;
	tmp->pNode = stack->topNode;
	stack->topNode = tmp;
}

StackNode pop(Stack *stack)
{
	StackNode res;
	res.key = FALSE;
	if(!stack || isEmpty_stack(stack))	return res;
	res = *(stack->topNode);
	StackNode *tmp = stack->topNode;
	stack->topNode = tmp->pNode;
	free(tmp);
	return res;
}

void remove_stack(Stack *stack)
{
	StackNode sn;
	while(!isEmpty_stack(stack)) {
		sn = pop(stack);
		print_stack_node(&sn);
	}
}
