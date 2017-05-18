/*
 * main_painterProblem.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: jounghoon
 */
#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;



bool isPossible(int K, long long _Max, vector<int> &L)
{
    // _Max: time
    int _max_ele = *max_element(L.begin(), L.end());
    if(_max_ele > _Max) return false; // case if the suggested time does not hold even one panel (the longest panel)

    long long Sum = 0;
    int cnt = 1;

    for(size_t i = 0; i < L.size();)
    {
        if (Sum + ((long long)L[i]) > _Max)
        {
            Sum = 0;
            cnt++;
        }
        else
        {
            Sum += ((long long )L[i]);
            i++;
        }
    }

    if (cnt <= K)
        return true;

    return false;
}

int paint(int K, int T, vector<int> &L) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    long long start, end;
    start = end = 0;

    for (size_t i = 0; i < L.size(); i++)         end += L[i];

    long long res = (long long) INT_MAX * INT_MAX;
    long long mid;
    while(start <= end)
    {
        mid = (start+end)/2;
        if (isPossible(K, mid, L)) // mid:
        {
            res = min(res, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return (res * (long long)T) % 10000003; // res: possible maximum number of consecutive panels
//    return (mid * (long long)T) % 10000003;


}

int main()
{
//	int K = 3;
//	int T = 10;
//	vector<int> L = {640, 435, 647, 352, 8, 90, 960, 329, 859};
	int K = 2;
	int T = 5;
	vector<int> L = {1,10};

	int total = paint(K, T, L);
	cout << total <<endl;

	return 0;
}
