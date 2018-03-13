#ifndef NODE_H
#define NODE_H

#define null 0

#include <string>
#include <iostream>

template <class T>
class Node
{
private:
	Node * createNode(T obj)
	{
		Node<T> * newnode = new Node<T>(obj);
		newnode->parent = this;
		return newnode;
	}

	void initVars()
	{
		this->parent = 0;
		this->left = 0;
		this->right = 0;
	}
public:
	Node(T obj) { this->object = obj; initVars(); }
	T object;
	Node * parent;
	Node * left;
	Node * right;

	Node<T> * addLeft(T obj)
	{
		if (this->left != null)
			throw std::string("Left is not null!");
		this->left = createNode(obj);
		return this->left;
	}

	Node<T> * addRight(T obj)
	{
		if (this->right != null)
			throw std::string("Right is not null!");
		this->right = createNode(obj);
		return this->right;
	}

	void addLeftRight(T left, T right)
	{
		this->addLeft(left);
		this->addRight(right);
	}
};

#endif