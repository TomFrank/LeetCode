#include "../lttools.cpp"

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		int n = nums.size();
		vector<unordered_map<long,int>> f(n);
		int res = 0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<i; ++j) {
				long d = (long)nums[i] - nums[j];
				if (f[j].count(d) > 0) {
					f[i][d] += f[j][d] + 1;
					res += f[j][d];
				} else {
					f[i][d] += 1;
				}
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::numberOfArithmeticSlices);
//	t.test("[2,4,6,8,10]"_arr).equals(7);
//	t.test("[7,7,7,7,7]"_arr).equals(16);
	t.test("[0,2000000000,-294967296]"_arr).equals(0);
}