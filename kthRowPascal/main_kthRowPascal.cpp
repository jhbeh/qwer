/*
 * main_kthRowPascal.cpp
 *
 *  Created on: Apr 18, 2017
 *      Author: jounghoon
 */




vector<int> Solution::getRow(int A) {
	vector<int> past, curr;
	if (A == 0)
	{
		curr.push_back(1);
	}
	else
	{
		curr.push_back(1);
		curr.push_back(1);
	}

	for(int i = 2; i <= A; i++)
	{
		past = curr;
		curr.clear();
		curr.push_back(1);
		for(int j = 0; j < i-1; j++)
		{
			curr.push_back(past[j] + past[j+1]);
		}
		curr.push_back(1);
	}
	return curr;
}
