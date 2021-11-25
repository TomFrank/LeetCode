#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

vector<int> s1(const vector<int>& nums, int k) {
	if (nums.empty())
		return nums;
	auto ans = vector(nums);
	int n=nums.size();
	for (int j=1; j<k; ++j)
		for (int i=0; i<n-j; ++i)
		ans[i]=max(ans[i], ans[i+1]);
	ans.resize(n-k+1);
	return ans;
}

vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
	if (nums.empty())
		return nums;
	priority_queue<int> q(nums.begin(), nums.begin()+k-1);
	vector<int> ans;
	for (auto it=next(nums.begin(), k-1); it!=nums.end(); ++it) {
		q.push(*it);
		ans.push_back(q.top());
	}
	return ans;
}

int main(int argc, char *argv[]) {
	auto ans = maxSlidingWindow({1,-1,3}, 1);
	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, ","));
}