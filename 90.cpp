#include "./lttools.cpp"

class Solution {
public:
	vector<vector<int>> subsetsWithDup(const vector<int>& nums) {
		int n=nums.size();
		vector<vector<int>> res;
		for (int i=0; i<(1<<n); ++i) {
			vector<int> t;
			for (int j=0; j<n; ++j) if ((i>>j)&1)
				t.push_back(nums[j]);
			sort(t.begin(), t.end());
			res.push_back(t);
		}
		sort(res.begin(), res.end());
		auto lst = unique(res.begin(), res.end());
		res.erase(lst, res.end());
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto res = Solution().subsetsWithDup({4,4,4,1,4});
	LT().print(res);
}