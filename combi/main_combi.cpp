/*
 * main_combi.cpp
 *
 *  Created on: May 5, 2017
 *      Author: jounghoon
 */


#include<iostream>
#include<vector>

using namespace std;

void mycombi(vector<vector<int> > &result, vector<int> &part, int start, int where, int n, int k)
{
	if (where == k)
	{
		result.push_back(part);
		return;
	}

	for(int i = start; i < n; i++)
	{
		part.push_back(i+1);
		mycombi(result,part,i+1,where+1,n,k);
		part.pop_back();
	}
}
vector<vector<int> > combine(int n, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	vector<vector<int> > result;
	if (n<k) return result;
	vector<int> part;
	mycombi(result,part,0,0, n,k);
	return result;

}

int main()
{
	int n = 6, k = 3;
	vector<vector<int> > result = combine(n,k);
	for(int i = 0; i < result.size();i++)
	{
		cout << "[";
		for(int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << ", ";
		}
		cout << "]" << endl;
	}

}

