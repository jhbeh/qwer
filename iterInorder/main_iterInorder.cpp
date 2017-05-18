/*
 * main_iterInorder.cpp
 *
 *  Created on: May 3, 2017
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
#include<stack>
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

vector<int> inorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    TreeNode* root = A;
    vector<int> vector;
    if(!root) return vector;
    stack<TreeNode *> stack;
    stack.push(root);

    while(!stack.empty())
    {
    	TreeNode *pNode = stack.top();
    	if(pNode->left)
    	{
    		stack.push(pNode->left);
    		pNode->left = NULL;
    	}
    	else if(pNode->right)
    	{
    		stack.push(pNode->right);
    		pNode->right = NULL;
    	}
    	else
    	{
    		vector.push_back(pNode->val);
    		stack.pop();
    	}


    }

//    while(!stack.empty())
//        {
//        	TreeNode *pNode = stack.top();
//    		vector.push_back(pNode->val);
//    		stack.pop();
//        	if(pNode->right)
//        	{
//        		stack.push(pNode->right);
////        		pNode->right = NULL;
//        	}
//        	if(pNode->left)
//        	{
//        		stack.push(pNode->left);
////        		pNode->left = NULL;
//        	}
//
//
//        }

//    while(!stack.empty())
//    {
//        TreeNode *pNode = stack.top();
//        if(pNode->left)
//        {
//            stack.push(pNode->left);
//            pNode->left = NULL;
//        }
//        else
//        {
//            vector.push_back(pNode->val);
//            stack.pop();
//            if(pNode->right)
//                stack.push(pNode->right);
//        }
//    }
    return vector;


}

//    6
//  3   7
//2  5    9

void mypostOrder(TreeNode * A, vector<int> &conta)
{
	if(A)
	{
		mypostOrder(A->left, conta);
		mypostOrder(A->right, conta);
		conta.push_back(A->val);
	}
}
void myinOrder(TreeNode * A, vector<int> &conta)
{
	if(A)
	{
		myinOrder(A->left, conta);
		conta.push_back(A->val);
		myinOrder(A->right, conta);
	}
}
void mypreOrder(TreeNode * A, vector<int> &conta)
{
	if(A)
	{
		conta.push_back(A->val);
		mypreOrder(A->left, conta);
		mypreOrder(A->right, conta);
	}
//	if(!A) return;
//
//		conta.push_back(A->val);
//		mypostOrder(A->left, conta);
//		mypostOrder(A->right, conta);

}

int main()
{
//	vector<int> A = {1,2,3,4,5,-1,-1,-1,-1,-1,-1};
	vector<int> A = {6,3,7,2,5,-1,9,-1,-1,-1,-1,-1,-1};
//	vector<int> A = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, -1};
	TreeNode*root = dsbt(A);
	cout << "done." << endl;

	vector<int> result = inorderTraversal(root);
	cout << "done2." << endl;
	for(int i = 0; i < result.size(); i++)
		cout << result[i] << ", ";

//	cout << endl;
//	vector<int> result2;
////	mypostOrder(root, result2);
//	myinOrder(root, result2);
////	mypreOrder(root, result2);
//	for(int i = 0; i < result2.size(); i++)
//		cout << result2[i] << ", ";
	return 0;
}


