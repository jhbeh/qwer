/*
 * main_verticalTraversal.cpp
 *
 *  Created on: Apr 30, 2017
 *      Author: jounghoon
 */


#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void makeTree(TreeNode* root, vector<int> A)
{
	if (A[0] != -1)
		root->left = new TreeNode(A[0]);
	if (A[1] != -1)
		root->right = new TreeNode(A[1]);
}


TreeNode * makeLevelOrderTree(vector<int> A)
{
	vector<vector<int> > Astack;
	Astack.push_back({A[0]});
	vector<int> Apart = Astack[0];
	int cnt = 1;
	int amount = cnt * 2;
	int cur = 1;

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
//	cout << "done 2." << endl;
	return root;

}

vector<vector<int> > verticalOrderTraversal(TreeNode *A)
{
	vector<vector<int> > result;

	if(A == NULL) return result;

	map<int, vector<int> > m;

	queue<pair<TreeNode*, int> > q;
//	q.push(make_pair(A,0));
	q.push({A,0});

	while(!q.empty())
	{
		pair<TreeNode*, int> front = q.front();
		q.pop();
		int currentHorizontalDistance = front.second;
		TreeNode* currentTreeNode = front.first;

		// insert current node to hash map
		m[currentHorizontalDistance].push_back(currentTreeNode->val);

		if (currentTreeNode->left != NULL)
			q.push(make_pair(currentTreeNode->left, currentHorizontalDistance-1));

		if (currentTreeNode->right != NULL)
			q.push(make_pair(currentTreeNode->right, currentHorizontalDistance+1));

	}

	for (auto it = m.begin(); it != m.end(); it++)
		result.push_back(it->second);
}

int main()
{
	vector<int> A = {6,3,7,2,5,-1,9,-1,-1,-1,-1,-1,-1};
	TreeNode *root = makeLevelOrderTree(A);
	vector<vector<int> > result;
	result = verticalOrderTraversal(root);
	for(int i = 0; i < result.size(); i++)
	{
		cout << "[";
		for(int j = 0; j < result[i].size();j++)
			cout << result[i][j] << ", ";
		cout << "], " << endl;
	}





	cout<< "done3."<< endl;


}

