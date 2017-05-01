/*
 * main_deserializeLevelOrderBT.cpp
 *
 *  Created on: 2017. 4. 30.
 *      Author: jobim
 */
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//void deserializeBt(TreeNode *&root, vector<int> &A, int idx)
//{
//	if (root == NULL) return;
//
//	if ()
//}

void makeTree(TreeNode*& root, vector<int> A)
{
	if (A[0] != -1)
		root->left = new TreeNode(A[0]);
	if (A[1] != -1)
		root->right = new TreeNode(A[1]);
}

int main()
{
//	vector<int> A = {1,2,3,-1,-1,4,-1,-1,5,-1,-1};
	vector<int> A = {6,3,7,2,5,-1, 9,-1,-1,-1,-1,-1,-1};

	vector<vector<int> > Astack;
	Astack.push_back({A[0]});
	vector<int> Apart = Astack[0];
	int cnt = 1;
	int amount = cnt * 2;
	int cur = 1;
	cout <<"done." << endl;
	while (cur < A.size())
	{

		Apart.clear();
		for(int i = cur; i < cur+amount; i++)
			Apart.push_back(A[i]);
		int cnt = 0;
		for(int i = 0; i < Apart.size(); i++)
			if (Apart[i] != -1)
				cnt++;
		amount = cnt * 2;
		cur += Apart.size();
		Astack.push_back(Apart);
	}
	cout << "Done 1." << endl;

	TreeNode *root = new TreeNode(A[0]);
	vector<TreeNode*> validNode, newNode, oldNode;
	validNode.push_back(root);

	for(int i = 0; i < Astack.size()-1; i++)
	{

		vector<int> nextA = Astack[i+1];
		for(int j = 0; j < validNode.size(); j++)
		{
			if (nextA[j*2] != -1 || nextA[j*2+1] != -1)
			{
				vector<int>tmpA;
				tmpA.push_back(nextA[j*2]);
				tmpA.push_back(nextA[j*2+1]);
				makeTree(validNode[j], tmpA);
			}
		}
		oldNode = validNode;
		validNode.clear();
		for(int j = 0; j < oldNode.size(); j++)
		{
			if(oldNode[j]->left != NULL)
				validNode.push_back(oldNode[j]->left);
			if(oldNode[j]->right != NULL)
				validNode.push_back(oldNode[j]->right);
		}
	}
	cout << "done 2." << endl;
	return 0;
}



