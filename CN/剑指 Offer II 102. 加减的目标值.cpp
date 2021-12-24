#include "./lttools.cpp"

class Solution {
public:
	unordered_map<int, int> m;
	
	int dfs_1(const vector<int>& nums, const int target, int i, int s) {
		int k = i + s * 100;
		if (m.count(k) > 0)
			return m[k];
		
		if (i >= nums.size()) {
			m[k] = s == target;
			return m[k];
		}
		
		int res = dfs_1(nums, target, i+1, s+nums[i]) + dfs_1(nums, target, i+1, s-nums[i]);
		m[k] = res;
		return res;
	}
	
	int dfs_2(const vector<int>& nums, int i, int s) {
		int k = i + s * 100;
		if (m.count(k) > 0)
			return m[k];
		
		if (i < 0) {
			m[k] = s == 0;
			return m[k];
		}
		
		int res = dfs_2(nums, i-1, s+nums[i]) + dfs_2(nums, i-1, s-nums[i]);
		m[k] = res;
		return res;
	}
	
	int dp(const vector<int>& nums, const int target) {
		// sum of positive num = p, sum of negtive num = q
		// p - q = target
		// p + q = sum
		// => p = (target + sum)/2
		
		// f[i][j] = f[i-1][j+nums[i]] + f[i-1], 1<=i<=n-1
		// f[0][nums[0]] = 1, f[.][.] = 0
		// ans = f[n-1][(target + sum)/2]
		int s = accumulate(nums.begin(), nums.end(), 0);
		int t = (s + target);
		if (t < 0 || t % 2 != 0)
			return 0;
		t /= 2;
		vector<vector<int>> f(21, vector<int>(1001));
		f[0][0] = 1;
		for (int i=1; i<=nums.size(); ++i) {
			for (int j=0; j<=1000; ++j) {
				if (j >= nums[i-1])
					f[i][j] = f[i-1][j - nums[i-1]] + f[i-1][j];
				else
					f[i][j] = f[i-1][j];
			}
		}
		return f[nums.size()][t];
	}
	
	int findTargetSumWays(vector<int>& nums, int target) {
		// f[i][s] = f[i+1][s+nums[i]] + f[i+1][s-nums[i]]
		// f[n][s] = s==target
		// ans = f[0][0]
//		return dfs_1(nums, target, 0, 0);
		
		// f[i][s] = f[i-1][s+nums[i]] + f[i-1][s-nums[i]]
		// f[0][s] = s+nums[0]==0||s-nums[0]==0;
		// ans = f[n-1][target]
//		return dfs_2(nums, nums.size()-1, target);
		
		return dp(nums, target);
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::findTargetSumWays);
	t.test("[1,1,1,1,1]"_arr, 3).equals(5);
	t.test("[1]"_arr, 1).equals(1);
	t.test("[1]"_arr, 2).equals(0);
}