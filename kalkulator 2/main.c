#include "Tree.h"
#include "Stack.h"
#include "Bantuan.h"



char token; // variable for reading a character
Root *root;
Stack *st;


/** main function
 *
 */
int main()
{

	char Pengulangan;
	double value;
	StackNode tmp;
	NodeOfTree *tn = NULL;
	root = CreateRootNode();
	st = CreateStack();
	
	do{
	system("cls");
	printf("Masukan Angka dan operasi bilangan contoh : ((1+2)*(3-4)) :\n");

    token = getchar();
    value = sum();
	
	while(!StackIsEmpty(st))
	{
		// Mengeluarkan dari stack dan memasukan ke tree
		tmp = PopStackNode(st);
		while(tmp.key)
		{
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
    
    printf("Ulangi Program? y/n \n");
    scanf("%c",&Pengulangan);
    if(Pengulangan=='y'){
	}
	else{
		exit(1);
	}
    fflush(stdin);
}while(1);
    return 0;

}

