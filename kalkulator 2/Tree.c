#include "Tree.h"

Root* CreateRootNode(){
	Root* tmp = (Root*)calloc(sizeof(Root), 1);
	if(!tmp){
		puts("Memori dalam kondisi penuh\n.");
		exit(1);
	}
	return tmp;
}

NodeOfTree* CreateTreeNode(){
	NodeOfTree* tmp = (NodeOfTree*)calloc(sizeof(NodeOfTree), 1);
	if(!tmp){
		puts("Memori dalam kondisi penuh\n.");
		exit(1);
	}
	return tmp;
}

/* Node : parent node
 * DataNumber : input data1
 * key : input data2
 * return ke nodenya sendiri atau node child
 */
NodeOfTree* make_child(NodeOfTree *Node, Data DataNumber, int key){
	if(!Node){
		Node = CreateTreeNode();
		Node->info = DataNumber;
		Node->key = key;
		return Node;
	}
	if(Node->left && Node->right){
		Node = Node->parent;
		if(!Node)	return NULL;
		return make_child(Node, DataNumber, key);
	}

	if(!key){// number,  dari kanan. return ke pointer node.
		if(Node->right){
			CreateLeftChild(Node, DataNumber, key);
		}
		else{
			CreateRightChild(Node, DataNumber, key);
		}
		return Node;
	}
	else{ // operator, dari kiri. return ke pointer node child (?).
		if(Node->right){
			CreateLeftChild(Node, DataNumber, key);
			return Node->left;
		}
		else{
			CreateRightChild(Node, DataNumber, key);
			return Node->right;
		}
	}
}

void CreateLeftChild(NodeOfTree *Node, Data DataNumber, int key){
	NodeOfTree* tmp = CreateTreeNode();
	if(!tmp)	return;
	tmp->info = DataNumber;
	tmp->key = key;
	Node->left = tmp;
	tmp->parent = Node;
}

void CreateRightChild(NodeOfTree *Node, Data DataNumber, int key){
	NodeOfTree* tmp = CreateTreeNode();
	if(!tmp)	return;
	tmp->info = DataNumber;
	tmp->key = key;
	Node->right = tmp;
	tmp->parent = Node;
}

void PrintTraversal(Data DataNumber, int key){
	if(key) {
		printf("%c", DataNumber.Operation);
	}
	else {
		printf("%g", DataNumber.Number);
	}
}

void AllTraversal(Root *root, int mode){
	NodeOfTree *tmp = root->root;
	switch(mode){
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

void Preorder(NodeOfTree *TreeNode){
	if(!TreeNode)	return;
	PrintTraversal(TreeNode->info, TreeNode->key);
	Preorder(TreeNode->left);
	Preorder(TreeNode->right);
}

void Inorder(NodeOfTree *TreeNode){
	if(!TreeNode)	return;
	Inorder(TreeNode->left);
	PrintTraversal(TreeNode->info, TreeNode->key);
	Inorder(TreeNode->right);
}

void Postorder(NodeOfTree *TreeNode){
	if(!TreeNode)	return;
	Postorder(TreeNode->left);
	Postorder(TreeNode->right);
	PrintTraversal(TreeNode->info, TreeNode->key);
}

void DeleteNodeTree(NodeOfTree *TreeNode){
	if(!TreeNode)	return;
	DeleteNodeTree(TreeNode->left);
	DeleteNodeTree(TreeNode->right);
	free(TreeNode);
}

void DeleteAllNodeTree(Root* root){
	DeleteNodeTree(root->root);
}
