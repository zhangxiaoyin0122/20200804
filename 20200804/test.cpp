#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const int& x, const int& y) {
	return x > y;
}

int findMax(const vector<int>& machines) {
	int ret = machines[0];
	for (const auto& cur : machines) {
		if (ret < cur) {
			ret = cur;
		}
	}
	return ret;
}

int greedStrategy(const vector<int>& works, vector<int>& machines) {
	sort(works.begin(), works.end(), cmp);
	int workNum = works.size();
	int machineNum = machines.size();
	//��ҵ��ĿС�ڵ��ڻ�����Ŀ
	if (workNum <= machineNum) {
		int minimalTime = works[0];
		return minimalTime;
	}
	else {
		for (int i = 0; i < workNum; i++) {
			int flag = 0;
			int tmp = machines[flag];
			for (int j = 1; j < machines.size(); j++) {
				if (tmp > machines[j]) {
					flag = j;
					tmp = machines[j];
				}
			}
			machines[flag] += works[i];
		}
		int minimalTime = findMax(machines);
		return minimalTime;
	}
}


bool cmp(const pair<int, int>& a, const pair<int, int>& b) { 
	return a.second < b.second; 
}

int greedyActivitySelector(const vector<pair<int, int>>& act) {
	//̰�����ԣ�ÿ��ѡ����������Ļ
	int num = 1, i = 0;
	for (int j = 1; j < act.size(); j++)  {
		if (act[j].first >= act[i].second) { 
			i = j;    
			num++;
		}
	}  
	return num;
}


bool cmp(const vector<int>& a, const vector<int>& b)
{     
	//������������     
	return a[0] < b[0];
}
 class Solution {
 public:     
	 int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		 if (intervals.size() == 0) {
			 return 0;         
		 }         
		 //������������
		 sort(intervals.begin(), intervals.end(), cmp);
		 int end = intervals[0][0], prev = 0, count = 0; 
		 for (int i = 1; i < intervals.size(); i++) { 
			 if (intervals[prev][1] > intervals[i][0]) {
				 if (intervals[prev][1] > intervals[i][1]) { 
					 //���2                     
					 prev = i;                
				 }                
				 //���3                
				 count++;             
			 } else {                 
				 //���1                 
				 prev = i;             
			 }         
		 }         
		 return count; 
};


