#include "Tree.h"
#include "Stack.h"
#include "Bantuan.h"



char token; // variable for reading a charactor
Root *root;
Stack *st;

/** main function
 *
 */
int main()
{
	double value;
	StackNode tmp;
	TreeNode *tn = NULL;
	/// make data structures for each cases
	root = make_root_node();
	st = make_stack();
	
	printf("Masukan Angka dan operasi bilangan contoh ((1+2)*(3-4)) :\n");

	/// process
    token = getchar();
    value = sum();
	// now, stack is already built

	/// construct tree
	while(!isEmpty_stack(st))
	{
		// As the stack is being removed, constructs tree
		tmp = pop(st);
		while(tmp.isChar)
		{
			// operator
			tn = make_child(tn, tmp.data, tmp.isChar);
			if(root->root == NULL)	root->root = tn;
			tmp = pop(st);
		}
		// number
		tn = make_child(tn, tmp.data, tmp.isChar);
		if(root->root == NULL)	root->root = tn;
	}
    /// printing
    printf("prefix : ");
    traversal(root, PREORDER);
    printf("\n");
    printf("infix : ");
    traversal(root, INORDER);
    printf("\n");
    printf("postfix : ");
    traversal(root, POSTORDER);
    printf("\n");
    printf("Evaluation result : %g\n", value);
    printf("");

    /// delete
    remove_all_tree_nodes(root);
    return 0;
}


