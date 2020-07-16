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

	int x;
	double value;
	StackNode tmp;
	NodeOfTree *tn = NULL;
	root = CreateRootNode();
	st = CreateStack();
	
	printf("Masukan Angka dan operasi bilangan contoh : ((1+2)*(3-4)) :\n");

    token = getchar();
    value = sum();
	
	while(!StackIsEmpty(st))
	{
		tmp = PopStackNode(st);
		while(tmp.key)
		{
			tn = make_child(tn, tmp.info, tmp.key);
			if(root->root == NULL)	root->root = tn;
			tmp = PopStackNode(st);
		}
		tn = make_child(tn, tmp.info, tmp.key);
		if(root->root == NULL)	root->root = tn;
	}
	
    printf("prefix : ");
    AllTraversal(root, PREORDER);
    printf("\n");
    printf("infix : ");
    AllTraversal(root, INORDER);
    printf("\n");
    printf("postfix : ");
    AllTraversal(root, POSTORDER);
    printf("\n");
    printf("Evaluation result : %g\n", value);
    printf("");

    DeleteAllNodeTree(root);
    return 0;

}

