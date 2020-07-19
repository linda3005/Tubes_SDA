#include "Tree.h"
#include "Stack.h"
#include "Kalkulator.h"
#include <math.h>




char token; // variabel untuk membaca karakter 
Root *root;
Stack *st;


int main(){
	char Pengulangan;
	double value;
	StackNode tmp;
	loading(30,12);
	system("color 57");
	do{
	NodeOfTree *tn = NULL;
	root = CreateRootNode();
	st = CreateStack();
	system("cls");
	printf("\t\t\t|==============================================================|\n");
    printf("\t\t\t|Program Kalkulator By Linda Damayanti, Muhammad Hargi Muttaqin|\n");
    printf("\t\t\t|==============================================================|\n\n");
	printf("\t\t\tMasukan Angka dan operasi bilangan contoh : \n\t\t\t((1+2)*(3-4))\n\t\t\tJangan gunakan perpangkatan\n");
	printf("\t\t\tMasukkan Angka : \n");
    token = getchar();
    value = sum();
	
	while(!StackIsEmpty(st)){
		// Mengeluarkan dari stack dan memasukan ke tree
		tmp = PopStackNode(st);
		while(tmp.key){
			// operator
			tn = make_child(tn, tmp.info, tmp.key);
			if(root->root == NULL)	root->root = tn;
			tmp = PopStackNode(st);
		}
		// number
		tn = make_child(tn, tmp.info, tmp.key);
		if(root->root == NULL)	root->root = tn;
	}
	
    /// Print
    printf("\t\t\tprefix : ");
    AllTraversal(root, PREORDER);
    printf("\n");
    printf("\t\t\tinfix : ");
    AllTraversal(root, INORDER);
    printf("\n");
    printf("\t\t\tpostfix : ");
    AllTraversal(root, POSTORDER);
    printf("\n");
    printf("\t\t\tHasil kalkulasi : %g\n", value);
    printf("");

    //Menghapus Tree
     DeleteAllNodeTree(root);
    
    //Pengulangan aplikasi jika diperlukan
    printf("\t\t\tUlangi Program? y/n \n");
    scanf("%c",&Pengulangan);
   
    if(Pengulangan=='y'||Pengulangan=='Y'){
    	system("cls");    	
	}
	else{
		exit(1);
	}

    fflush(stdin);
    system("COLOR 9C");
}	
 	while (1);
    return 0;

}

