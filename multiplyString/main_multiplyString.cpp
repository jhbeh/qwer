/*
 * main_multiplyString.cpp
 *
 *  Created on: Apr 26, 2017
 *      Author: jounghoon
 */



#include<iostream>
#include<string>

using namespace std;
string multiply(string A, string B)
{
	string sol(A.size() + B.size(), '0');

	for(int i = A.size()-1; i >=0; i--)
	{
		for(int j = B.size()-1; j>=0; j--)
		{
			int ans = (A[i]-48) * (B[j]-48);
			if (ans >= 10)
			{

			}
			else
			{
				ans +=
			}

		}
	}
	return sol;
}
int main()
{
	string A="3333";
	string B="4444";
	string result = multiply(A,B);
	cout << result;
	cout << endl << ('8' - 48);

	return 0;
}
