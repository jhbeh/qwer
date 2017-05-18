/*
 * main_allocateBooks.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: jounghoon
 */


#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
	bool isPossible(vector<int> &V, int npages, int M)
	{
		long long cnt = 1, sum = 0;
		for(auto it = V.begin(); it != V.end(); )
		{
			if (sum + (*it) > npages)
			{
				sum = 0;
				cnt++;
			}
			else
			{
				sum += (*it);
				it++;
			}
		}
		if (cnt <= M) return true;

		return false;
	}
	int books(vector<int> &V, int M)
	{
		long long low, high, mid, sum = 0;
		for(auto it = V.begin(); it !=V.end(); it++) sum += (*it);
		low = 0;
		high = sum;

//		long long res = (long long)INT_MAX * INT_MAX;
		long long res = 0;
		while(low <= high)
		{
			mid = (low+high) / 2;
			if (isPossible(V, mid, M))
			{
				res = mid; // keep the result because mid change
				high = mid - 1;
			}
			else
				low = mid + 1;
		}

		return res;
	}

};

int main()
{
	vector<int> V= {12,34,67,90};
	int M = 2;

	Solution mysol;
	int res = mysol.books(V,M);
	cout<<res;
	return 0;
}
