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
	
	double value;
	StackNode tmp;
	NodeOfTree *tn = NULL;
	/// make info structures for each cases
	root = CreateRootNode();
	st = make_stack();
	
	printf("Masukan Angka dan operasi bilangan contoh : ((1+2)*(3-4)) :\n");

	/// process
    token = getchar();
    value = sum();
	// now, stack is already built

	/// construct tree
	while(!isEmpty_stack(st))
	{
		// As the stack is being removed, constructs tree
		tmp = pop(st);
		while(tmp.key)
		{
			// operator
			tn = make_child(tn, tmp.info, tmp.key);
			if(root->root == NULL)	root->root = tn;
			tmp = pop(st);
		}
		// number
		tn = make_child(tn, tmp.info, tmp.key);
		if(root->root == NULL)	root->root = tn;
	}
    /// printing
    printf("prefix : ");
    AllTraversal(root, PREORDER);//prefix using preorder
    printf("\n");
    printf("infix : ");
    AllTraversal(root, INORDER);//infix using inorder
    printf("\n");
    printf("postfix : ");
    AllTraversal(root, POSTORDER);//postfix using postorder
    printf("\n");
    printf("Evaluation result : %g\n", value);
    printf("");

    /// delete
    DeleteAllNodeTree(root);
    return 0;
}


