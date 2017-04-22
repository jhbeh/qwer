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

//class Solution {
//    public:
//        static bool myCmp(Interval a, Interval b) {
//            return a.start < b.start;
//        }
//
//        vector<Interval> merge(vector<Interval> &intervals) {
//            if(intervals.size() < 2) {
//                return intervals;
//            }
//            sort(intervals.begin(), intervals.end(), myCmp);
//            int first = 0;
//            for(int second = 1; second < intervals.size(); second++) {
//                // There is overlap in intervals at first and second position.
//                if(intervals[second].start <= intervals[first].end) {
//                    // We merge the second interval into the first one and modify the first interval to reflect it.
//                    intervals[first].end = max(intervals[second].end, intervals[first].end);
//                }
//                else {
//                    // No overlap between first and second. Move forward.
//                    ++first;
//                    intervals[first].start = intervals[second].start;
//                    intervals[first].end = intervals[second].end;
//                }
//            }
//            intervals.erase(intervals.begin() + first + 1, intervals.end());
//            return intervals;
//        }
//};

bool compare(Interval x, Interval y)
{
	return x.start < y.start;
}
class Solution
{
public:
	Solution(){};
	~Solution(){};
	vector<Interval>merge(vector<Interval> &);
//	static bool compare(Interval x, Interval y)
//	{
//		return x.start < y.start;
//	}
};
//static bool Solution::compare(Interval x, Interval y)
//{
//	return x.start < y.start;
//}

vector<Interval> Solution:: merge(vector<Interval> &A)
{
	vector<Interval> res = A;
	if (A.size() <= 1)
	{
		return res;
	}
	// sorting first
	sort(res.begin(), res.end(), compare);
	int i = 0;
	for(int j = 1; j < res.size(); j++)
	{
		if (res[j].start <= res[i].end)
			res[i].end = max(res[i].end, res[j].end);
		else
		{
			i++;
			res[i].start = res[j].start;
			res[i].end = res[j].end;
		}
	}
	res.erase(res.begin()+i+1, res.end());
	return res;

//	bool mergeStart = false;
//	bool mergeEnd = false;
//	vector<Interval>::iterator it = res.begin();
//	while((it+1) != res.end())
//	{
//		if ( ((it+1)->start >= it->start) and ((it+1)->start <= it->end) )
//			mergeStart = true;
//		else
//			mergeStart = false;
//		if ( ((it+1)->end >= it->start) and ((it+1)->end <= it->end) )
//			mergeEnd = true;
//		else
//			mergeEnd = false;
//
//		if (mergeStart and mergeEnd)
//		{
//			res.erase((it+1));
//		}
//		else if (mergeStart and !mergeEnd)
//		{
//			it->end = (it+1)->end;
//			res.erase(it+1);
//		}
//		else if (!mergeStart and !mergeEnd)
//		{
//			it++;
//			mergeStart = false;
//			mergeEnd = false;
//		}
//		else
//		{
//			// not likely happen
//		}
//
//	}

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
