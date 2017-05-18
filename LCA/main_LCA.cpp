/*
 * main_LCA.cpp
 *
 *  Created on: May 16, 2017
 *      Author: jounghoon
 */
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * makeTree(vector<int> Avec)
{
	queue<TreeNode *> q;
	TreeNode * A = new TreeNode(Avec[0]);
	q.push(A);
	int cnt = 1;
	while(!q.empty())
	{
		TreeNode*tmp = q.front();
		q.pop();
		if(Avec[cnt] != -1)
		{
			tmp->left = new TreeNode(Avec[cnt]);
			q.push(tmp->left);
		}
		cnt++;
		if(Avec[cnt] != -1)
		{
			tmp->right = new TreeNode(Avec[cnt]);
			q.push(tmp->right);
		}
		cnt++;
	}
	return A;

}

vector<int> traceBack(vector<int> &trace, TreeNode* A, int n)
{
	queue<TreeNode *> q;

	q.push(A);

	while(!q.empty())
	{
		TreeNode * tmp = q.front();
		q.pop();

	}

	if (found) return;

	if (A == NULL) return;

	trace.push_back(A->val);

	if (A->val == n)
	{
		found = true;
	}
	else
	{
		found = false;
	}

	traceBack(trace, A->left;)
	if(A == NULL)
	{
		return;
	}

}

void serializeInorder(vector<int> & B, TreeNode* A)
{
	if(!A) return;

	serializeInorder(B, A->left);

	B.push_back(A->val);
	serializeInorder(B, A->right);

}
int main()
{
	vector<int> Avec = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, -1};
	TreeNode * A = makeTree(Avec);
	vector<int> B;
	serializeInorder(B, A);
	for(int i = 0; i < B.size(); i++)
		cout << B[i] << ", ";
	cout << endl;
	cout << "Done." << endl;

	vector<int> trace;
	vector<int> result;
	bool found = false;
	int nElem = B.size();
	result = traceBack(trace, A, 5, nElem);

	return 0;

}
