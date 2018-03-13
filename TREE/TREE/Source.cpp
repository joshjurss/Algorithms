#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Tree
{
	char data;
	Tree *parent;
	Tree *left;
	Tree *right;
};

struct Tree *newTreeNode(int data)
{
	Tree *node = new Tree;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	return node;
}

struct Tree *insertTreeNode(struct Tree *node, int data)
{
	static Tree *p;
	Tree *returnNode;

	if (node == NULL)
	{
		returnNode = newTreeNode(data);
		returnNode->parent = p;
		return returnNode;
	}

	if (data <= node->data)
	{
		p = node;
		node->left = insertTreeNode(node->left, data);
	}
	else
	{
		p = node;
		node->right = insertTreeNode(node->right, data);
	}

	return node;
}

void printTreeInOrder(struct Tree *node)
{
	if (node == NULL) return;

	printTreeInOrder(node->left);
	cout << node->data << " ";
	printTreeInOrder(node->right);
}


int main()
{
	Tree *root = newTreeNode('E');
	insertTreeNode(root, 'P');	
	insertTreeNode(root, 'I');
	insertTreeNode(root, 'C');

	printTreeInOrder(root);

	cin.ignore();
	cin.get();

	return 0;
}