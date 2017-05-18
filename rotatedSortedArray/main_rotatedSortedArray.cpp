/*
 * main_rotatedSortedArray.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: jounghoon
 */


#include<iostream>
#include<vector>
using namespace std;

int findIndex(int B, const vector<int> &A, int start, int end)
{
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (A[mid] == B)
			return mid;
		else if (A[mid] < B)
			start = mid + 1;
		else
			end = mid-1;
	}
	return -1;
}
int search(const vector<int> &A, int B)
{
	if (A.empty()) return -1;
	if (A.size() == 1)
		if (A[0] == B)
			return 0;
		else
			return -1;
	if (A.size() == 2)
	{
		for(size_t i = 0; i < A.size(); i++)
			if (A[i] == B) return i;
		return -1;
	}

	if (A[0] == B) return 0;
	if (A[A.size()-1] == B) return A.size()-1;

	//find min value
	// should have like last element > x < next element
	int start = 0, end = A.size()-1;
	int mid;
	while(start <= end)
	{
		mid = (start + end) / 2;
		if (A[mid] < A[mid-1] && A[mid] < A[mid+1])
			break;
		else if (A[mid] < A[0])
			end = mid - 1;
		else if (A[mid] > A[0])
			start = mid + 1;
	}

	if (B < A[0]) //
		return findIndex(B, A, mid, A.size()-1);
	else
		return findIndex(B, A, 0, mid-1);

//	return mid;
}

int main()
{
	vector<int> A = {4,5,6,7,0,1,2};
	int out;
	for (size_t i = 4; i < A.size(); i++)
	{
		out = search(A,A[i]);
		cout << out << ", ";

	}
	return 0;
}

