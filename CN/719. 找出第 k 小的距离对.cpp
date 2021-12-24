#include "./lttools.cpp"

class Solution {
public:
	/*
	  1 2 3 4 5 6
	1 0 1 2 3 4 5
	2 1 0 1 2 3 4
	3 2 1 0 1 2 3 
	4 3 2 1 0 1 2
	5 4 3 2 1 0 1
	6 5 4 3 2 1 0
	*/
	/*
	  1 1 6
	1 - 0 5
	1 - - 5
	6 - - -
	
	  1 1 3
	1 - 0 2
	1 - - 2
	3 - - -
	
	    4 62 100
	4   - 58 96
	62  - -  38
	100 - -  -
	
	    4  62 100
	4   -  -  -
	62  58 -  -
	100 96 38 -
	*/
	// count # of pair distance less or equal than x in nums
	int check(int x, vector<int>& nums) {
		int ret = 0;
		int n = nums.size();
		for (int i=0, j=1; i<n; ++i) {
			while (j < n && nums[j] - nums[i] <= x) {
				ret += j-i;
				++j;
			}
		}
		return ret;
	}
	
	int smallestDistancePair(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int r = nums.back() - nums.front();
		int l = 0;
		while (l < r) {
			int m = (l + r) / 2;
			int c = check(m, nums);
			if (c < k) {
				l = m+1;
			} else {
				r = m;
			}
		}
		return l;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::smallestDistancePair);
	t.test("[1,6,1]"_arr, 3).equals(5);
	t.test("[1,1,1]"_arr, 2).equals(0);
	t.test("[1,3,1]"_arr, 1).equals(0);
	t.test("[62,100,4]"_arr, 2).equals(58);
}