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

int main()
{
	vector<int> A = {6,3,7,2,5,-1,9,-1,-1,-1,-1,-1,-1};
	TreeNode*root = dsbt(A);
	cout << "done." << endl;
	return 0;
}


