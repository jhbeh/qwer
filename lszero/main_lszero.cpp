/*
 * main_lszero.cpp
 *
 *  Created on: May 18, 2017
 *      Author: jounghoon
 */
#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> lszero(vector<int> &A) {
    map<int,int>tb;
    tb[0] = -1;
    int sum = 0;
    int start = 0, end = 0;
    int maxLen = -1;
    for(int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (tb.find(sum) == tb.end())
        {
        	tb[sum] = i;
        }
        else
        {
        	if (maxLen < i - tb[sum])
        	{
        		maxLen = i-tb[sum];

        		start = tb[sum];
        		end = i;
        	}
        }
    }

    vector<int> result;
    for(int i = start+1; i <= end; i++)
    	result.push_back(A[i]);
    return result;
}

int main()
{
//	vector<int> A = {1,2,-2,4,-4};
//	vector<int> A = {1,2,-3,3};
	vector<int> A = {-19, 8, 2, -8, 19, 5, -2, -23};
	vector<int> result = lszero(A);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ", ";
	cout << endl << "Done.";
	return 0;
}



