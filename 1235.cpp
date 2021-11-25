#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

struct job {
	int s;
	int e;
	int p;
};

int jobScheduling(const vector<int>& startTime, const vector<int>& endTime, const vector<int>& profit) {
	int n = startTime.size();
	
	vector<job> jobs(n+1, {0,0,0});
	for(int i=1;i<=n;++i)
		jobs[i] = {startTime[i-1], endTime[i-1], profit[i-1]};
	
	sort(jobs.begin()+1, jobs.end(), [](job a,job b){return a.e<b.e;});
	
//	for(const auto& j:jobs) {
//		cout << j.s << " " << j.e << " " << j.p << endl;
//	}
	
	vector<int> dp(n+1, 0);
	
	auto find_pre = [&](int i) -> int {
		for(int j=i-1;j>=1;--j) {
			if(jobs[j].e <= jobs[i].s) {
				return j;
			}
		}
		return -1;
	};
	
	//dp[0] = jobs[0].p;
	for(int i=1;i<=n;++i) {
		int j = find_pre(i);
		int f = (j < 0 ? 0 : dp[j]);
		dp[i] = max(dp[i-1], f+jobs[i].p);
//		cout << "j=" << j << ", i=" << i << ", f=" << f
//		     << ", dp[" << i+1 << "]=" << dp[i+1] << endl;
	}
	
	return dp[n];
}

int main(int argc, char *argv[]) {
	//cout << jobScheduling({1,2,3,3}, {3,4,5,6}, {50,10,40,70}) << endl;
	cout << jobScheduling({1,2,3,4,6}, {3,5,10,6,9}, {20,20,100,70,60}) << endl;
}