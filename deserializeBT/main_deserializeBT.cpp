/*
 * main_deserializeBT.cpp
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
	TreeNode() : val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void deserializeBt(TreeNode *&root, vector<int> &A, int &idx)
{
	if (idx >= A.size() || A[idx] == -1) return;


	root->val = A[idx];
	root->left = new TreeNode;
	deserializeBt(root->left, A, ++idx);
	root->right = new TreeNode;
	deserializeBt(root->right, A, ++idx);

}
int main()
{
//	vector<int> A = {1,2,3,-1,-1,4,-1,-1,5,1,-1};
	vector<int> A = { 20, 8, 4, -1, -1, 12, 10, -1, -1, 14, -1, -1, -1};
	TreeNode *root = new TreeNode;
//	root->val = 3;
//	root->left = new TreeNode;
//	root->left->val = 5;

//	TreeNode *root = new TreeNode(5);
//	root->left = new TreeNode(3);
//	root->right = new TreeNode(6);
//	TreeNode *new
//	TreeNode root(1);
//	root.left = TreeNode(2);
	int idx = 0;
	deserializeBt(root, A, idx);
	cout << "done." << endl;

	return 0;
}


