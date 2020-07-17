#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include "Kalkulator.h"

typedef struct NodeOfTree{
	int key;
	Data info;
	struct NodeOfTree *parent;
	struct NodeOfTree *left;
	struct NodeOfTree *right;
} NodeOfTree;

typedef struct Root{
	NodeOfTree *root;
} Root;

Root* CreateRootNode();
NodeOfTree* CreateTreeNode();
NodeOfTree* make_child(NodeOfTree *Node, Data DataNumber, int key);
void CreateLeftChild(NodeOfTree *Node, Data DataNumber, int key);
void CreateRightChild(NodeOfTree *Node, Data DataNumber, int key);
void PrintTraversal(Data DataNumber, int key);
void AllTraversal(Root *root, int mode);
void Preorder(NodeOfTree *TreeNode);
void Inorder(NodeOfTree *TreeNode);
void Postorder(NodeOfTree *TreeNode);
void DeleteAllNodeTree(Root* root);
void DeleteNodeTree(NodeOfTree *TreeNode);
#endif

