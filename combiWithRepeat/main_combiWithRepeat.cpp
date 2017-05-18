/*
 * main_combiWithRepeat.cpp
 *
 *  Created on: May 7, 2017
 *      Author: jounghoon
 */
#include<iostream>
#include<vector>
using namespace std;
void combiUtil(vector<vector<int> > &result, vector<int> &curr, int start, int where, int n, int k)
{
	if (where == k)
	{
		result.push_back(curr);
		return;
	}

	for(int i = start; i < n;i++)
	{
		curr.push_back(i);
		combiUtil(result,curr, i+1, where+1, n,k);
		curr.pop_back();
	}
}
vector<vector<int> > combiWithRepeat(int n, int k)
{
	vector<vector<int> > result;
	vector<int> curr;
	int start = 0;
	int where = 0;

	combiUtil(result, curr, start, where, n, k);
	return result;

}
int main()
{
	int n = 4, k = 2;
	vector<vector<int> > result;
	result = combiWithRepeat(n,k);
	cout << "done" << endl;
	for(int i = 0; i < result.size();i++)
	{
		cout << "[" ;
		for(int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << ", ";
		}
		cout << "]" << endl;
	}
	return 0;
}



