/*
 * main_rotateMtx.cpp
 *
 *  Created on: Apr 19, 2017
 *      Author: jounghoon
 */

#include<iostream>
#include<vector>

using namespace std;

void partialRotate(vector<vector<int> > &A, int row)
{
    // n fix, m move
    // (m,N-1-n) <-- (n,m)
    // (N-1-n,N-1-m) <-- (m,N-1-n)
    // (N-1-m,n) <-- (N-1-n,N-1-m)
    // (n,m) <-- (N-1-m,n)

    int n = row;
    int N = A.size() - 2*n;
    int tmp;
    for(int m = 0; m< N-1; m++)
    {
    	tmp = A[n+m][n+N-1];
    	A[n+m][n+N-1] = A[n][n+m];
    	A[n][n+m] = A[n+N-1-m][n];
    	A[n+N-1-m][n] = A[n+N-1][n+N-1-m];
    	A[n+N-1][n+N-1-m] = tmp;
    	// (n,n) .... (n,n+N-1)
    	//                 .
    	// (n+N-1,n) ..(n+N-1,n+N-1)
    	// example with [1,2]     A[1][1]  A[1][2]
    	//              [3,4]     A[2][1]  A[2][2]
    	// n = 1, N = 2
    	// N-1+n = 2
    	// m = n = 1
    	// N-1-m+n = 2
    	//
    	// tmp = A[1][2]
    	// A[0][1] = A[0][0]
    	// A[0][0] = A[1][0]
    	// A[1][0] = A[1][1]
    	// A[1][1] = tmp

    	// example with [1,2]     A[0][0]  A[0][1]
    	//              [3,4]     A[1][0]  A[1][1]
    	// n = 0, N = 2
    	// N-1-n = 1
    	// m = n = 0
    	// N-1-m = 1
    	//
    	// tmp = A[0][1]
    	// A[0][1] = A[0][0]
    	// A[0][0] = A[1][0]
    	// A[1][0] = A[1][1]
    	// A[1][1] = tmp
    }
//    for(int m = n; m< n+N-1; m++)
//    {
//        tmp = A[m][N-1+n];
//        A[m][N-1+n] = A[n][m];
//        A[n][m] = A[N-1-m][n];
//        A[N-1-m][n] = A[N-1-n][N-1-m];
//        A[N-1-n][N-1-m] = tmp;
//        // example with [1,2]     A[1][1]  A[1][2]
//        //              [3,4]     A[2][1]  A[2][2]
//        // n = 1, N = 2
//        // N-1+n = 2
//        // m = n = 1
//        // N-1-m+n = 2
//        //
//        // tmp = A[1][2]
//        // A[0][1] = A[0][0]
//        // A[0][0] = A[1][0]
//        // A[1][0] = A[1][1]
//        // A[1][1] = tmp
//
//        // example with [1,2]     A[0][0]  A[0][1]
//        //              [3,4]     A[1][0]  A[1][1]
//        // n = 0, N = 2
//        // N-1-n = 1
//        // m = n = 0
//        // N-1-m = 1
//        //
//        // tmp = A[0][1]
//        // A[0][1] = A[0][0]
//        // A[0][0] = A[1][0]
//        // A[1][0] = A[1][1]
//        // A[1][1] = tmp
//    }
}

int main()
{
//	vector<vector<int> > A = {{1,2},{3,4}};
	vector<vector<int> > A = {{31, 32, 228, 333}
							 ,{79, 197, 241, 246}
							 ,{77, 84, 126, 337}
							 ,{110, 291, 356, 371}};

	for(size_t i = 0; i < A.size(); i++)
	{
		partialRotate(A,i);
	}
	for(size_t i = 0; i < A.size(); i++)
	{
		for(size_t j = 0; j < A.size(); j++)
			cout << A[i][j] << ", ";
		cout << endl;
	}
	return 0;

}


