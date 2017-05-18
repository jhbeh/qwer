/*
 * main_genParenII.cpp
 *
 *  Created on: May 13, 2017
 *      Author: jounghoon
 */
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void genParUtil(vector<string> &result, string curr, int A, int end)
{
    if (A == 0 and end == 0)
    {
        result.push_back(curr);
        return;
    }

    if(A > 0)
    {
    	cout << 'A' << endl;
//    	curr += '(';
    	string temp = curr+'(';
//    	genParUtil(result,curr+'(',A-1,end+1);
    	genParUtil(result,temp,A-1,end+1);
//    	genParUtil(result,curr,A-1,end+1);
    }
    if(end > 0)
    {
    	cout << "end" << endl;
//    	curr += ')';
    	string temp = curr+')';
//    	genParUtil(result,curr+')',A, end-1);
    	genParUtil(result,temp,A, end-1);
//    	genParUtil(result,curr,A, end-1);
    }

}

vector<string> generateParenthesis(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> result;
    string curr;

    genParUtil(result, curr, A, 0);

    return result;
}

int main()
{
	int A = 3;
	vector<string> result;
	result = generateParenthesis(A);
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i];
		cout << endl;
	}
	return 0;
}



