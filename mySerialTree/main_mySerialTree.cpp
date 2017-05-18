/*
 * main_mySerialTree.cpp
 *
 *  Created on: Apr 29, 2017
 *      Author: jounghoon
 */



#include<iostream>
#include<vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(NULL), right(NULL) {}
	~TreeNode() {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void deSerialize(TreeNode *&root)
{
	if (root->val == -1) return;

	deSerialize(root->left);
	deSerialize(root->right);
}
int main()
{
	TreeNode a;
	a.val = 3;
	return 0;
}
