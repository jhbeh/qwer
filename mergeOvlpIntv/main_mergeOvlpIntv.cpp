/*
 * main_mergeOvlpIntv.cpp
 *
 *  Created on: Apr 19, 2017
 *      Author: jounghoon
 */



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval():start(0),end(0) {};
//	~Interval();
	Interval(int s, int e):start(s), end(e) {};
};
//Interval::Interval() {}
//Interval::~Interval() {}



//class Interval
//{
//	int start;
//	int end;
//	Interval();
//	Interval(int, int);
//	~Interval();
//
//	vector<Interval> merge(vector<Interval> &A);
//};
//Interval::Interval(): start(0), end(0) {}
//Interval::Interval(int s, int e) : start(s), end(e) {}
//Interval::~Interval(){}
//
//vector<Interval> Interval::merge(vector<Interval> &A)
//{
//
//}
//

class Solution
{
public:
	Solution(){};
	~Solution(){};
	vector<Interval>merge(vector<Interval> &);
};
vector<Interval> Solution:: merge(vector<Interval> &A)
{
	vector<Interval> res = A;
	if (A.size() <= 1)
	{
		return res;
	}
	// sorting first
	vector<pair<int,int> > temp4sort;
	for(auto resi:res)
		temp4sort.push_back(make_pair(resi.start, resi.end));

	sort(temp4sort.begin(),temp4sort.end());
	int idx = 0;
	for(auto it = temp4sort.begin(); it != temp4sort.end(); it++)
	{
		res[idx++].start = it->first;
		res[idx++].end = it->second;
	}
//	for(size_t i = 0; i < temp4sort.size(); i++)
//	{
//		res[i].start = temp4sort[i].first;
//		res[i].end = temp4sort[i].second;
//	}

	bool mergeStart = false;
	bool mergeEnd = false;
	vector<Interval>::iterator it = res.begin();
	while((it+1) != res.end())
	{
		if ( ((it+1)->start >= it->start) and ((it+1)->start <= it->end) )
			mergeStart = true;
		else
			mergeStart = false;
		if ( ((it+1)->end >= it->start) and ((it+1)->end <= it->end) )
			mergeEnd = true;
		else
			mergeEnd = false;

		if (mergeStart and mergeEnd)
		{
			res.erase((it+1));
		}
		else if (mergeStart and !mergeEnd)
		{
			it->end = (it+1)->end;
			res.erase(it+1);
		}
		else if (!mergeStart and !mergeEnd)
		{
			it++;
			mergeStart = false;
			mergeEnd = false;
		}
		else
		{
			// not likely happen
		}

	}

	return res;
}
int main()
{
	Solution mysol;
	vector<Interval> input;
	vector<Interval> output;
//	(1, 10) (3, 8) (4, 7) (5, 6) (6, 6)
//	input.push_back(Interval(1,3));
//	input.push_back(Interval(2,6));
//	input.push_back(Interval(8,10));
//	input.push_back(Interval(15,18));
	input.push_back(Interval(5,6));
	input.push_back(Interval(1,10));
	input.push_back(Interval(3,8));
	input.push_back(Interval(4,7));
	input.push_back(Interval(6,6));

	output = mysol.merge(input);
//	vector<pair<int,int> > input2;
//	input2.push_back(make_pair(15,18));
//	input2.push_back(make_pair(1,3));
//	input2.push_back(make_pair(2,6));
//	input2.push_back(make_pair(8,10));
//	sort(input2.begin(),input2.end());
	return 0;
}
