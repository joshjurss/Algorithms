#include <iostream>
#include "vector_helper.h"
#include <vector>

#include <string>

#include "InsertSort.h"
#include "MedianSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "BinarySearch.h"
#include "Node.h"
#include "Tree.h"

using namespace std;

int main()
{
	//sort1.initContainer(create_vector<string>("test")("test2"));
	//cout << sort1.ToString();
	//vector<int> arr1 = create_vector<int>(
	//QuickSort2<int> sort1;
	//sort1.initContainer(create_vector<int>(3)(2)(7)(3)(1));
	//sort1.initContainer(create_vector<int>(1)(2)(7)(3));
	//cout << sort1.ToString() << endl;
	//sort1.Sort();
	//cout << sort1.ToString() << endl;
	//BinarySearchRecursive<int> search1;
	//search1.initContainer(sort1.getContainer());
	//cout << search1.Search(3) << endl;
	Node<int> * root = new Node<int>(30);
	Node<int> * l = root->addLeft(20);
	Node<int> * r = root->addRight(40);
	l->addLeft(10)->addLeftRight(5,15);
	l->addRight(25)->addRight(28);
	r->addLeft(35);
	r->addRight(50)->addRight(41);
	Tree<int> tree(root);
	//vector<Node<int> *> nodes = tree.getBoundary(); 
	//for(size_t i = 0; i < nodes.size(); i++)
	//{
	//	cout << nodes[i]->object << " ";
	//}
	cout << tree.BFS(28)->object << endl;
	//cout << tree.BFS_R(25)->object << endl;
	//cout << endl;
	//tree.DeleteTree();
	//root->addRight(
	//root->left
	//Tree<int> t(root);
	


	//delete root;
}	