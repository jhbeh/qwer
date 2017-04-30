/*
 * main_levelOrderBT.cpp
 *
 *  Created on: 2017. 4. 30.
 *      Author: jobim
 */
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode *root)
{
	if (root == NULL)
		return 0;
	else
	{
		int lhd = height(root->left);
		int rhd = height(root->right);

		if (lhd > rhd)
			return (lhd + 1);
		else
			return (rhd + 1);
	}
}

void printGivenLevel(TreeNode *root, int i)
{
	if (root == NULL) return;

	if (i == 1)
		cout << root->val << endl;
	else if (i > 1)
	{
		printGivenLevel(root->left,i-1);
		printGivenLevel(root->right,i-1);
	}
}
int main()
{

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->left->right->right = new TreeNode(6);
	int hd = height(root);
	cout << hd << endl;
	for(int i = 1; i <= hd; i++)
		printGivenLevel(root, i);
	return 0;

}



