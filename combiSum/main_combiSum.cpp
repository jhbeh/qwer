/*
 * main_combiSum.cpp
 *
 *  Created on: May 5, 2017
 *      Author: jounghoon
 */
#include<iostream>
#include<vector>
using namespace std;

void recurSum(vector<vector<int> > &result, vector<int> &part, int sum, vector<int> &A, int where, int &Target)
{
	if (where >= A.size()) return;

	if (sum == Target)
	{
		result.push_back(part);
		part.clear();
		return;
	}
	else if (sum < Target)
	{
		part.push_back(A[where]);
		sum += A[where];
		recurSum(result, part, sum, A, where+1, Target);
	}
	else
	{
		part.pop_back();
		sum -= A[where];
		recurSum(result, part, sum, A, where-1, Target);
	}
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	vector<vector<int> > result;
	vector<int> part;
	recurSum(result, part, 0, A, 0, B);
	return result;
}

int main()
{
	vector<int> A = {2,3,6,7};
	int B = 7;
	vector<vector<int> > result = ;


	return 0;
}



