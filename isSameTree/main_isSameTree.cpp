/*
 * main_isSameTree.cpp
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
int isSameTree(TreeNode* A, TreeNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    stack<TreeNode*> sA, sB;
    sA.push(A);
    sB.push(B);
    while(!sA.empty() && !sB.empty())
    {
        TreeNode* tmpA = sA.top();
        TreeNode* tmpB = sB.top();
        if (tmpA->val != tmpB->val) return 0;
        sA.pop();
        sB.pop();
        if (tmpA->right && tmpB->right)
        {
            sA.push(tmpA->right);
            sB.push(tmpB->right);
        }
        else if (!(tmpA->right) && tmpB->right)
            return 0;
        else if ((tmpA->right) && !(tmpB->right))
            return 0;


        if (tmpA->left && tmpB->left)
        {
            sA.push(tmpA->left);
            sB.push(tmpB->left);
        }
        else if (!(tmpA->left) && tmpB->left)
            return 0;
        else if ((tmpA->left) && !(tmpB->left))
            return 0;

    }
    return 1;
}

int main()
{
	vector<int> A = {0,-1,-1};
	vector<int> B = {0,-1,-1};
	TreeNode*rootA = dsbt(A);
	TreeNode*rootB = dsbt(B);
	cout << isSameTree(rootA,rootB) << endl;
	cout << "done." << endl;
	return 0;
}


