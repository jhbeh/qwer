/*
 * main_permute.cpp
 *
 *  Created on: May 16, 2017
 *      Author: jounghoon
 */
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void permuteUtil(vector<vector<int> > &result, vector<int> &A, int n)
{
	if (n == A.size())
	{
		result.push_back(A);
		return;
	}

	for(int i = n; i < A.size(); i++)
	{
		swap(A[n], A[i]);
		permuteUtil(result, A, n+1);
		swap(A[n], A[i]);
	}
}

vector<vector<int> > permute(vector<int> &A) {
	vector<vector<int> > result;
	vector<int> curr;

	int T = A.size();
	permuteUtil(result, A, 0);
	return result;
}

int main()
{
	vector<int> A = {1,2,3,4};
	vector<vector<int> > result = permute(A);
	for(int i = 0; i < result.size(); i++)
	{
		cout << "[";
		for(int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << ", ";
		}
		cout << "]" << endl;
	}


	return 0;
}



