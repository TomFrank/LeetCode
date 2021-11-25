#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	
//	sort(nums.begin(), nums.end());
//	vector<vector<int>> ret;
//	for (int i=0; i<nums.size(); ++i)
//		for (int j=i+1; j<nums.size(); ++j) {
//			if (binary_search(nums.begin() + j + 1, nums.end(), -(nums[i]+nums[j]))) {
//				ret.push_back({nums[i], nums[j], -(nums[i]+nums[j])});
//			}
//		}
//	sort(ret.begin(), ret.end());
//	auto end = unique(ret.begin(), ret.end());
//	ret.erase(end, ret.end());
//	return ret;
}

int main(int argc, char *argv[]) {
	auto nums = vector<int> {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	auto ans = threeSum(nums);
	
	for (auto& v : ans) {
		for (auto x : v)
			cout << x << " ";
		cout << "\n";
	}
}