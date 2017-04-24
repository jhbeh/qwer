/*
 * main_medianArray.cpp
 *
 *  Created on: Apr 21, 2017
 *      Author: jounghoon
 */




#include<iostream>
#include<vector>

using namespace std;

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
	if (A.size() > B.size())
		return findMedianSortedArrays(B, A);
	int imin = 0, imax = A.size(), i, j;
	// A.size() < B.size(), and A B coincided
	while( imin <= imax)
	{
		i = (imin+imax)/2;
		j = (A.size()+B.size()+1)/2 - i;
		if (j > 0 && i < A.size() && B[j-1] > A[i])
			imin = i + 1;
		else if (i > 0 && j < B.size() && A[i-1] > B[j])
			imax = i - 1;
		else
		{
			int median1 = 0, median2 = 0;
			if (i == 0) // when A is null
				median1 = B[j-1];
			else if (j == 0) // when B is null
				median1 = A[i-i];
			else
				median1 = max(A[i-1], B[j-1]);

			if ((A.size() + B.size()) % 2 == 1)
				return 1.0 * median1;

			if (i == A.size())
				median2 = B[j];
			else if (j == B.size())
				median2 = A[i];
			else
				median2 = min(A[i],B[j]);
			return 1.0 * (median1 + median2) / 2.0;
		}
	}
	return -1.0;


//	double res;
//	if (B[B.size()-1] <= A[0])
//	{
//		int medIdx = ( (B.size() + A.size()) /2 ) - B.size();
//		if ((B.size() + A.size()) % 2 != 0)
//		{
//			res = A[medIdx];
//		}
//		else
//		{
//			res = 0.5*(A[medIdx] + A[medIdx-1]);
//		}
//		return res;
//	}
//	else if (A[A.size()-1] <= B[0])
//	{
//		int medIdx = ( (B.size() + A.size()) /2 ) - A.size();
//		if ((B.size() + A.size()) % 2 != 0)
//		{
//			res = B[medIdx];
//		}
//		else
//		{
//			res = 0.5*(B[medIdx] + B[medIdx-1]);
//		}
//		return res;
//	}
//
//	return res;
}
int main()
{
//	vector<int> A = {1,4,5}, B = {2,3};
	vector<int> A = {1,2}, B = {3,4,5};
	double res = findMedianSortedArrays(A,B);
	cout << res;
	return 0;
}
