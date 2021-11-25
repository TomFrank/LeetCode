#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <map>
#include <set>
#include <array>
using namespace std;

map<vector<int>, int> mem;
vector<int> jobs;
int opt=INT_MAX;
int n;
int k;

void printTable(const vector<int>& table) {
	for(int r: table) {
		printf("%d ", r);
	}
	printf("\n");
}

bool pruncing(const vector<int>& timeTable, const int curJob) {
	int numOfZero = 0;
	for (int i=0; i<k; ++i) {
		if (timeTable[i] >= opt) {
			return true;
		}
		else if (timeTable[i] == 0) {
			++numOfZero;
		}
	}
//	if (numOfZero > 0 && curJob >= n) {
//		return true;
//	}
//	if (numOfZero > n - curJob) {
//		return true;
//	}
	return false;
}

int helper(vector<int>& timeTable, int curJob) {
	if (mem.count(timeTable) > 0)
		return mem[timeTable];
	
	if (pruncing(timeTable, curJob)) {
		return INT_MAX;
	}
	
	if (curJob >= n) {
//		printTable(timeTable);
		int maxWkr = *max_element(timeTable.begin(), timeTable.end());
		mem[timeTable] = maxWkr;
		opt = min(opt, maxWkr);
		return maxWkr;
	}
	
	int minOfMax = INT_MAX;
	for (int i=0; i<k; ++i) {
		timeTable[i] += jobs[curJob];
		minOfMax = min(minOfMax, helper(timeTable, curJob+1));
		timeTable[i] -= jobs[curJob];
	}
	return minOfMax;
}

int minimumTimeRequired(const vector<int>& j, int wn) {
	jobs=j;
	sort(jobs.rbegin(), jobs.rend());
	n=j.size();
	k=wn;
	mem.clear();
	opt=INT_MAX;
	vector<int> timeTable(k, 0);
	for (int i=0; i<k-1; ++i)
		timeTable[i] = jobs[i];
	int res = helper(timeTable, k-1);
//	int res = helper(timeTable, 0);
//	printTable(min_element(mem.begin(), mem.end())->first);
	return res;
}

int main(int argc, char *argv[]) {
	cout << minimumTimeRequired({3,2,3}, 3) << endl;
	cout << minimumTimeRequired({1,2,4,7,8}, 2) << endl;
	cout << minimumTimeRequired({1,2,4,7,8,2,5,7,2,6}, 3) << endl;
	cout << minimumTimeRequired({9899456,8291115,9477657,9288480,5146275,7697968,8573153,3582365,3758448,9881935,2420271,4542202}, 9) << endl;
	cout << minimumTimeRequired({17,20,4,6,2,5,13,5,8}, 8) << endl;
	cout << minimumTimeRequired({46,13,54,51,38,49,54,67,26,78,33}, 10) << endl;
	cout << minimumTimeRequired({46,13,54,51,38,49,54,67,26,78,33,11}, 12) << endl;
	cout << minimumTimeRequired({254,256,256,254,251,256,254,253,255,251,251,255}, 10)  << endl;
}