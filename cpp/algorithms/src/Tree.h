#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <vector>

template <class T>
class Tree
{
private:
	void _DeleteTree(Node<T> * node)
	{
		cout << "Killing node: " << node->object << endl;
		if (node->left != null)
			_DeleteTree(node->left);
		if (node->right != null)
			_DeleteTree(node->right);
		delete node;
		node = null;
	}
public:
	Node<T> * root;

	void DeleteTree()
	{
		this->_DeleteTree(root);
	}
	Tree(Node<T> * root)
	{
		this->root = root;
	}
	~Tree()
	{
		//DeleteTree(root);
	}

	Node<T> * DFS(T value)
	{
		return dfs(value, this->root);
	}

	Node<T> * dfs(T value, Node<T> * nodes)
	{
		if (nodes == null)
			return null;
		cout << "Examining: " << nodes->object << endl;
		if (nodes->object == value)
			return nodes;
		Node<T> * ret = null, * ret2 = null;
		if (nodes->left)
			ret = dfs(value, nodes->left);
		if (ret != null)
			return ret;
		if (nodes->right)
			ret = dfs(value, nodes->right);
		if (ret != null)
			return ret;
		return null;

	}

	Node<T> * BFS(T value)
	{
		std::vector<Node<T> *> stack;
		stack.push_back(this->root);
		Node<T> * curr;
		while (stack.size() != 0)
		{
			curr = stack.at(0);
			stack.erase(stack.begin());
			cout << "Examining: " << curr->object << endl;
			if (curr->object == value)
				return curr;
			if (curr->left != null)
				stack.push_back(curr->left);
			if (curr->right != null)
				stack.push_back(curr->right);
		}
		return null;
	}

	Node<T> * BFS_R(T value)
	{
		return bfs_r(value, this->root);
	}

	Node<T> * bfs_r(T value, Node<T> * nodes)
	{
		Node<T> * ret = null;
		if (nodes)
			cout << "Examined: " << nodes->object << endl;
		if (nodes->object == value)
			return nodes;
		if (nodes->left)
		{
			ret = bfs_r(value, nodes->left);
			if (ret && ret->object == value)
				return ret;
		}
		if (nodes->right)
		{
			ret = bfs_r(value, nodes->right);
			if (ret && ret->object == value)
				return ret;
		}

		return ret;
	}



	std::vector<Node<T> *> getBoundary()
	{
		std::vector<Node<T> *> edges;
		edges.push_back(root);
		std::vector<Node<T> *> tmp;
		tmp = getLeftEdges(root->left);
		edges.insert(edges.end(), tmp.begin(), tmp.end());
		tmp = getRightEdges(root->right);
		edges.insert(edges.end(), tmp.begin(), tmp.end());
		return edges;
	}

	std::vector<Node<T> *> getLeftEdges(Node<T> * nodes)
	{
		std::vector<Node<T> *> ret;
		if (nodes == null)
			return ret;
		if (nodes->parent->right == nodes) //if the node is a right child
		{
			//add current node
			if (nodes->right == null && nodes->left == null)
				ret.push_back(nodes);
		} 
		else if (nodes->parent->left == nodes) // if the node is a left child
		{
			ret.push_back(nodes);
		}
		std::vector<Node<T> *> tmp;
		tmp = getLeftEdges(nodes->left);
		ret.insert(ret.end(), tmp.begin(), tmp.end());
		tmp = getLeftEdges(nodes->right);
		ret.insert(ret.end(), tmp.begin(), tmp.end());
		return ret;
	}

	std::vector<Node<T> *> getRightEdges(Node<T> * nodes)
	{
		std::vector<Node<T> *> ret;
		if (nodes == null)
			return ret;
		
		std::vector<Node<T> *> tmp;
		tmp = getRightEdges(nodes->left);
		ret.insert(ret.end(), tmp.begin(), tmp.end());
		tmp = getRightEdges(nodes->right);
		ret.insert(ret.end(), tmp.begin(), tmp.end());
		if (nodes->parent->right == nodes) //if the node is a right child
		{
			//add current node
			ret.push_back(nodes);
		} 
		else if (nodes->parent->left == nodes) // if the node is a left child
		{
			if (nodes->right == null && nodes->left == null)
				ret.push_back(nodes);
		}
		return ret;
	}
};

#endif