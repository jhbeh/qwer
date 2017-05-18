/*
 * main_longestCommonPrefix.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: jounghoon
 */




#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
bool mycmp(string &A, string &B)
{
	return (A.size() < B.size());
}

string LCP(vector<string> &A)
{
	string minstr = *min_element(A.begin(), A.end(), mycmp);
	vector<string>::iterator it = A.begin();
	string lcp = minstr;
	while(it != A.end() and !lcp.empty())
	{
//		int tmp = lcp.compare(0,lcp.size(), *it );
		if (it->compare(0,lcp.size(), lcp ) == 0)
		{
			it++;
		}
		else
		{
			lcp.pop_back();
		}
	}
	return lcp;
}

int main()
{
	vector<string> A = {"abcdefgh", "aefghijk", "abcefgh"};
//	vector<string> A = {"abc", "aefghijk", "abcefgh"};
	string lcp = LCP(A);
	if (lcp.empty()) cout << "NULL" << endl;
	else cout << lcp << endl;;
//	cout << A[2].compare(0, 3, A[0]);
//	vector<string> A = {"a", "ae", "abc", "asdf"};

//	cout << *min_element(A.begin(), A.end(), mycmp);
//	vector<string>::iterator it = A.begin();
//	cout << *it << endl;
//	it++;
//	cout << *it << endl;
//	cout << (*(++it)) << endl;
	return 0;
}
