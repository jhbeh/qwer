/*
 * main_nqueens.cpp
 *
 *  Created on: May 14, 2017
 *      Author: jounghoon
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isValid(vector<string> &curr, int row,  int col, int A)
{

	for (int i = 0; i < row; i++)
	{
		if(curr[i][col] == 'Q') return false;
	}
	for (int i = row-1, j = col-1; i >=0 && j >= 0; i--, j--)
	{
		if(curr[i][j] == 'Q') return false;
	}
	for (int i = row-1, j = col+1; i >=0 && j < A; i--, j++)
	{
		if(curr[i][j] == 'Q') return false;
	}

	return true;
}

void nqUtil(vector<vector<string> > &result, vector<string> &curr, int row, int &A)
{
	if (row == A)
	{
		result.push_back(curr);
		return;
	}

	for(int col = 0; col < A; col++)
	{
		if (isValid(curr, row, col, A))
		{
			curr[row][col] = 'Q';
			nqUtil(result, curr, row+1, A);
			curr[row][col] = 'P';
		}
	}

}
vector<vector<string> > solveNQueens(int A)
{
	vector<vector<string> > result;
	vector<string> curr(A, string(A,'_'));
	nqUtil(result, curr, 0, A);
	return result;
}

int main()
{
	int A = 2;
	vector<vector<string> > result;
	result = solveNQueens(A);
	for(int i = 0; i < result.size(); i++)
	{
		for(int j = 0; j < result[i].size();j++)
		{
			cout << result[i][j] << endl;
		}
		cout << "--------------------"<<endl;
	}

	return 0;
}



