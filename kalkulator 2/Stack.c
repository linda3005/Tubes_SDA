#include "Stack.h"

int StackIsEmpty(Stack *ParameterStack)
{
	if(!ParameterStack) {
		puts("the stack doesn't exist.");
		return TRUE;
	}
	return ParameterStack->topNode == NULL;
}

StackNode* CreateStackNode()
{
	StackNode *tmp = (StackNode*)calloc(sizeof(StackNode), 1);
	if(!tmp){
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

Stack* CreateStack()
{
	Stack *tmp = (Stack*)calloc(sizeof(Stack), 1);
	if(!tmp) {
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

void PrintStackNode(StackNode *TreeNode)
{
	if(!TreeNode)	return;
	if(TreeNode->key){
		printf("%c", TreeNode->info.Operation);
	}
	else{
		printf("%g", TreeNode->info.Number);
	}
}

void PushStackNode(Stack *ParameterStack, Data DataNumber, int key)
{
	StackNode *tmp = CreateStackNode();
	tmp->info = DataNumber;
	tmp->key = key;
	tmp->pNode = ParameterStack->topNode;
	ParameterStack->topNode = tmp;
}

StackNode PopStackNode(Stack *ParameterStack)
{
	StackNode res;
	res.key = FALSE;
	if(!ParameterStack || StackIsEmpty(ParameterStack))	return res;
	res = *(ParameterStack->topNode);
	StackNode *tmp = ParameterStack->topNode;
	ParameterStack->topNode = tmp->pNode;
	free(tmp);
	return res;
}

void DeleteStack(Stack *ParameterStack)
{
	StackNode sn;
	while(!StackIsEmpty(ParameterStack)) {
		sn = PopStackNode(ParameterStack);
		PrintStackNode(&sn);
	}
}
