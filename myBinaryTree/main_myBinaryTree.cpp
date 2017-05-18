/*
 * main_myBinaryTree.cpp
 *
 *  Created on: Apr 28, 2017
 *      Author: jounghoon
 */
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int key_value;
	Node *left;
	Node *right;
};

class Btree
{
public:
	Btree();
	~Btree();

	void insert(int key);
	Node *search(int key);
	void destroy_tree();

	//////////////////////////////////////////
	void verticalOrder(Node *myroot);
	void findMinMax(Node *node, int *min, int *max, int hd);
	void printVerticalLine(Node *node, int line_no, int hd);
	//////////////////////////////////////////
	Node *root;
private:
	void destroy_tree(Node *leaf);
	void insert(int key, Node *leaf);
	Node *search(int key, Node *leaf);


};

Btree::Btree()
{
	root = NULL;
}

Btree::~Btree()
{
	destroy_tree();
}

void Btree::destroy_tree(Node *leaf)
{
	if (leaf !=NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void Btree::insert(int key, Node *leaf)
{
	if(key< leaf->key_value)
	{
		if(leaf->left != NULL)
			insert(key, leaf->left);
		else
		{
			leaf->left= new Node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->key_value)
	{
		if(leaf->right != NULL)
			insert(key, leaf->right);
		else
		{
			leaf->right= new Node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

Node *Btree::search(int key, Node *leaf)
{
	if(leaf!=NULL)
	{
		if(key==leaf->key_value) return leaf;
		if(key<leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else
		return NULL;
}

Node *Btree::search(int key)
{
	return search(key, root);
}

void Btree::insert(int key)
{
	if (root != NULL)
		insert(key, root);
	else
	{
		root = new Node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

void Btree::destroy_tree()
{
	destroy_tree(root);
}

//////////////////////////////////////////////////////
void Btree::findMinMax(Node *node, int *min, int *max, int hd)
{
	if (node == NULL) return;

	if(hd < *min) *min = hd;
	else if (hd > *max) *max = hd;

	findMinMax(node->left, min, max, hd-1);
	findMinMax(node->right, min, max, hd+1);
}
void Btree::printVerticalLine(Node *node, int line_no, int hd)
{
	if (node == NULL) return;

	if (hd == line_no)
		cout << node->key_value << " ";

	printVerticalLine(node->left, line_no, hd-1);
	printVerticalLine(node->right, line_no, hd+1);

}
void Btree::verticalOrder(Node *myroot)
{
	int min = 0, max = 0;
	findMinMax(myroot, &min, &max, 0);

	for (int line_no = min; line_no <= max; line_no++)
	{
		printVerticalLine(myroot, line_no, 0);
		cout << endl;
	}

}

//////////////////////////////////////////////////////
int main()
{
	vector<int> A = {6,3,7,2,5,9};
	Btree myBtree;
	for(auto it = A.begin(); it != A.end(); it++)
		myBtree.insert(*it);

	myBtree.verticalOrder(myBtree.root);

	for(auto i = 0; i < 10; i++)
	{
		vector<int> A;
		A.push_back(i);
		for(auto j = 0; j < A.size(); j++)
			cout << A[j];;
	}
	return 0;
}



