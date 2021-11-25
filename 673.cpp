#include "./lttools.cpp"

class Solution {
public:
	static
	int findNumberOfLIS(const vector<int>& nums) {
		int m1=-1, m2=-1;
		int n=nums.size();
		int res = 1;
		for (int i=0; i<n; ++i) {
			if (nums[i] > m1) {
				m1 = nums[i];
			} else if (nums[i] <= m1 && nums[i] > m2) {
				m2 = nums[i];
				res += 1;
			} else if (nums[i] <= m2) {
				
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(Solution::findNumberOfLIS);
	t.test("[1,3,5,4,7]"_arr).equals(2);
	t.test("[2,2,2,2,2]"_arr).equals(5);
}