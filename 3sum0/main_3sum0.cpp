/*
 * main_3sum0.cpp
 *
 *  Created on: May 5, 2017
 *      Author: jounghoon
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//void findNum(vector<int> A, int d, vector<vector<int> > &result)
//{
//    if (A.size() == 1) return;
//
//    for(int i = 0, j = A.size()-1; i < j;)
//    {
//        vector<int> partResult;
//        int sum = d + A[i] + A[j];
//        if (sum > 0)
//            j--;
//        else if (sum < 0)
//            i++;
//        else
//        {
//            partResult.push_back(d);
//            partResult.push_back(A[i]);
//            partResult.push_back(A[j]);
//            result.push_back(partResult);
//            partResult.clear();
//            i++;
//        }
//    }
//}
//
//vector<vector<int> > threeSum(vector<int> &A) {
//    // Do not write main() function.
//    // Do not read input, instead use the arguments to the function.
//    // Do not print the output, instead return values as specified
//    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
//    vector<vector<int> > result;
//    sort(A.begin(), A.end());
////    int tmp = A[A.size()-1];
////    for(int i = A.size()-2; i >= 0; i--)
////    {
////    	if (A[i] == A[i+1])
////    		A.erase(A.begin()+i+1);
////    }
//
//    for(int i = 0; i < A.size(); i++)
//    {
//        vector<int> Atmp = A;
//        Atmp.erase(Atmp.begin()+i);
//        findNum(Atmp, A[i], result);
//    }
//    return result;
//}

vector<vector<int> > threeSum(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int> > result;
    sort(A.begin(), A.end());

    int j,k;
    for(int i = 0; i< (int)A.size()-2;i++)
    {
//    	if(A[i] == A[i+1])
    	if(i>0 && A[i] == A[i-1])
    		continue;
    	j = i + 1;
    	k = (int)A.size()-1;
    	while(j<k)
    	{
        	int sum = A[i] + A[j] + A[k];
        	if (sum == 0)
        	{
        		vector<int> partResult;
        		partResult.push_back(A[i]);
        		partResult.push_back(A[j]);
        		partResult.push_back(A[k]);
        		result.push_back(partResult);
        		j++;
        		//while(j<k && A[j] == A[j+1])
        		while(j<k && A[j] == A[j-1])
        			j++;
        	}
        	else if (sum < 0)
        		j++;
        	else
        		k--;
    	}
    }
    return result;
}

int main()
{
	vector<int> A = { 1, -4, 0, 0, 5, -5, 1, 0, -2, 4, -4, 1, -1, -4, 3, 4, -1, -1, -3 };
	vector<vector<int> > result;
	result = threeSum(A);
	cout <<"done." << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << "[";
		for(int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << ", ";
		}
		cout << "]" << endl;;
	}
	cout << "done.2" << endl;
	return 0;
}
