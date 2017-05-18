/*
 * main_invertBT.cpp
 *
 *  Created on: May 4, 2017
 *      Author: jounghoon
 */
/*
 * main_myDeserializeBTree.cpp
 *
 *  Created on: May 2, 2017
 *      Author: jounghoon
 */

#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode * dsbt(vector<int> &A)
{
	TreeNode * result;
	if(A.empty()) return result;
	result = new TreeNode(A[0]);

	queue<TreeNode*> q;

	q.push(result);
	int cnt = 1;
	while(!q.empty())
	{
		if (cnt >= A.size()) break;
		TreeNode* tmp = q.front();
		q.pop();
		if (A[cnt] != -1)
		{
			tmp->left = new TreeNode(A[cnt]);
			q.push(tmp->left);
		}
		cnt++;
		if (A[cnt] != -1)
		{
			tmp->right = new TreeNode(A[cnt]);
			q.push(tmp->right);
		}
		cnt++;
	}
	return result;
}

TreeNode* invertTree(TreeNode* root)
{
	if(root)
	{
		invertTree(root->left);
		invertTree(root->right);
		swap(root->left, root->right);
	}
	return root;
}
int main()
{
	vector<int> A = {1,2,3,4,5,6,7,-1,-1,-1,-1,-1,-1,-1,-1};
	TreeNode*root = dsbt(A);
	cout << "done." << endl;
	TreeNode*iroot = invertTree(root);
	cout << "done.2" << endl;

	return 0;
}





