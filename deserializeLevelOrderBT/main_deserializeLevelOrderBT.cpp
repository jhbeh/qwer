/*
 * main_deserializeLevelOrderBT.cpp
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

//void deserializeBt(TreeNode *&root, vector<int> &A, int idx)
//{
//	if (root == NULL) return;
//
//	if ()
//}

int main()
{
	vector<int> A = {1,2,3,-1,-1,4,-1,-1,5,1,-1};
//	deserializeBt(root, A, 1);
	TreeNode *root = new TreeNode(A[0]);
	int cnt = 1;
	while (cnt <= A.size())
	{
		
	}

	return 0;
}



