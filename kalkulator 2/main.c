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
	
	do{
	NodeOfTree *tn = NULL;
	root = CreateRootNode();
	st = CreateStack();
	printf("|==============================================================|\n");
    printf("|Program Kalkulator By Linda Damayanti, Muhammad Hargi Muttaqin|\n");
    printf("|==============================================================|\n\n");
	printf("Masukan Angka dan operasi bilangan contoh : \n((1+2)*(3-4))\nJangan gunakan perpangkatan\n");
	printf("Masukkan Angka : \n");
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
    printf("prefix : ");
    AllTraversal(root, PREORDER);
    printf("\n");
    printf("infix : ");
    AllTraversal(root, INORDER);
    printf("\n");
    printf("postfix : ");
    AllTraversal(root, POSTORDER);
    printf("\n");
    printf("Hasil kalkulasi : %g\n", value);
    printf("");

    //Menghapus Tree
     DeleteAllNodeTree(root);
    
    //Perulangan Aplikasi (?)
    printf("Ulangi Program? y/n \n");
    scanf("%c",&Pengulangan);
   
    if(Pengulangan=='y'||Pengulangan=='Y'){
    	system("cls");    	
	}
	else{
		exit(1);
	}

    fflush(stdin);
}
	
 	while (1);
    return 0;

}
