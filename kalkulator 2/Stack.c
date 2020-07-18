#include "Stack.h"
#include<conio.h>
#include<windows.h>
#include<stdio.h>

int StackIsEmpty(Stack *ParameterStack)
{
	if(!ParameterStack) {
		printf("\nStack tidak ada");
		return TRUE;
	}
	return ParameterStack->topNode == NULL;
}

StackNode* CreateStackNode()
{
	StackNode *tmp = (StackNode*)calloc(sizeof(StackNode), 1);
	if(!tmp){
		printf("\nmemory dalam kondisi penuh.");
		exit(1);
	}
	return tmp;
}

Stack* CreateStack()
{
	Stack *tmp = (Stack*)calloc(sizeof(Stack), 1);
	if(!tmp) {
		printf("\nkondisi memori penuh.");
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
gotoxy(int x,int y){
	
	HANDLE handle;
	COORD coord;
	coord.X =x;
	coord.Y =y;
	handle  = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle,coord);
}
void loading(int x,int y){
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
