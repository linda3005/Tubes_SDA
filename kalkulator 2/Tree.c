#include "Tree.h"

Root* CreateRootNode()
{
	Root* tmp = (Root*)calloc(sizeof(Root), 1);
	if(!tmp) {
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

NodeOfTree* CreateTreeNode()
{
	NodeOfTree* tmp = (NodeOfTree*)calloc(sizeof(NodeOfTree), 1);
	if(!tmp){
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

/** \brief
 *
 * \param Node : parent node
 * \param DataNumber : input data1
 * \param key : input data2
 * \return self node or new child node
 *
 */
NodeOfTree* make_child(NodeOfTree *Node, Data DataNumber, int key)
{
	if(!Node)
	{
		Node = CreateTreeNode();
		Node->info = DataNumber;
		Node->key = key;
		return Node;
	}
	if(Node->left && Node->right)
	{
		Node = Node->parent;
		if(!Node)	return NULL;
		return make_child(Node, DataNumber, key);
	}

	if(!key) // number, from right. return self node pointer.
	{
		if(Node->right)
		{
			CreateLeftChild(Node, DataNumber, key);
		}
		else
		{
			CreateRightChild(Node, DataNumber, key);
		}
		return Node;
	}
	else // operator, from left. return its child node pointer.
	{

		if(Node->right)
		{
			CreateLeftChild(Node, DataNumber, key);
			return Node->left;
		}
		else
		{
			CreateRightChild(Node, DataNumber, key);
			return Node->right;
		}
	}
}

void CreateLeftChild(NodeOfTree *Node, Data DataNumber, int key)
{
	NodeOfTree* tmp = CreateTreeNode();
	if(!tmp)	return;
	tmp->info = DataNumber;
	tmp->key = key;
	Node->left = tmp;
	tmp->parent = Node;
}

void CreateRightChild(NodeOfTree *Node, Data DataNumber, int key)
{
	NodeOfTree* tmp = CreateTreeNode();
	if(!tmp)	return;
	tmp->info = DataNumber;
	tmp->key = key;
	Node->right = tmp;
	tmp->parent = Node;
}

void PrintTraversal(Data DataNumber, int key)
{
	if(key) {
		printf("%c", DataNumber.Operation);
	}
	else {
		printf("%g", DataNumber.Number);
	}
}

void AllTraversal(Root *root, int mode)
{
	NodeOfTree *tmp = root->root;
	switch(mode)
	{
		case PREORDER:
			Preorder(tmp);
			break;
		case INORDER:
			Inorder(tmp);
			break;
		case POSTORDER:
			Postorder(tmp);
			break;
	}
}

void Preorder(NodeOfTree *TreeNode)
{
	if(!TreeNode)	return;
	PrintTraversal(TreeNode->info, TreeNode->key);
	Preorder(TreeNode->left);
	Preorder(TreeNode->right);
}

void Inorder(NodeOfTree *TreeNode)
{
	if(!TreeNode)	return;
	Inorder(TreeNode->left);
	PrintTraversal(TreeNode->info, TreeNode->key);
	Inorder(TreeNode->right);
}

void Postorder(NodeOfTree *TreeNode)
{
	if(!TreeNode)	return;
	Postorder(TreeNode->left);
	Postorder(TreeNode->right);
	PrintTraversal(TreeNode->info, TreeNode->key);
}

void DeleteNodeTree(NodeOfTree *TreeNode)
{
	if(!TreeNode)	return;
	DeleteNodeTree(TreeNode->left);
	DeleteNodeTree(TreeNode->right);
	free(TreeNode);
}

void DeleteAllNodeTree(Root* root)
{
	DeleteNodeTree(root->root);
}
