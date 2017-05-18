/*
 * main_powerFunc.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: jounghoon
 */




#include<iostream>
#include<vector>

using namespace std;

int powd(int x, int n, int d)
{
	if (n == 0) return 1%d;

	long long ans = 1, base = x%d;

	while(n>0)
	{
		if (n%2 == 1)
		{
			ans = (ans * base) %d;
			n--;
		}
		else
		{
			base = (base * base) %d;
			n /= 2;
		}
		if (ans < 0) ans = (ans + d) % d;
	}

	return ans;

}

int main()
{
	int res = powd(-1,1,20);
	cout << res;
	return 0;
}


//int pow(int x, int n, int d)
//{
//	if (n == 0)
//	{
//		if (x == 0)
//			return 1%d;
//		else
//			return x%d;
//	}
//
//	while( x< 0 )  x+=d;
//
//	long long cntall = 1;
//
//	while( cntall < n)
//	{
//		long long cnt = 1;
//		bool keepgoing = true;
//		while( keepgoing)
//		{
//			if (cnt < n / cnt)
//			{
//				cnt *= cnt;
//				keepgoing = true;
//			}
//			else if (cnt == n / cnt)
//			{
//				cnt *= cnt;
//				keepgoing = false;
//			}
//			else
//			{
//				keepgoing = false;
//			}
//
//
//		}
//		cntall *= cnt;
//	}
//
//}
