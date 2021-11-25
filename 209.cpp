#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

int minSubArrayLen(int target, const vector<int>& nums) {
	vector<int> presum(nums.size(), 0);
	presum[0] = nums[0];
	for (int i=1; i<nums.size(); ++i)
		presum[i] = presum[i-1] + nums[i];
	//copy(presum.begin(), presum.end(), ostream_iterator<int>(cout,","));
	int i=0,j=0,res=INT_MAX;
	while (i<=j && j<nums.size()) {
		if (presum[j]-presum[i]+nums[i] < target)
			++j;
		else {
			res = min(res, j-i+1);
			++i;
		}
	}
	return res == INT_MAX ? 0 : res;
}

int main(int argc, char *argv[]) {
	cout << minSubArrayLen(7, {2,3,1,2,4,3}) << endl;
	cout << minSubArrayLen(4, {1,4,4}) << endl;
	cout << minSubArrayLen(11, {1,1,1,1,1,1,1,1,1}) << endl;
}