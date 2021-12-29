#include "../lttools.cpp"

class Solution {
public:
	int countQuadruplets(vector<int>& nums) {
		const int n = nums.size();
		int res = 0;
		for (int i=0; i<n; ++i) {
			for (int j=i+1; j<n; ++j) {
				for (int k=j+1; k<n; ++k) {
					for (int l=k+1; l<n; ++l) {
						if (nums[i] + nums[j] + nums[k] == nums[l]) {
							++res;
						}
					}
				}
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::countQuadruplets);
	t.test("[1,2,3,6]"_arr).equals(1);
	t.test("[3,3,6,4,5]"_arr).equals(0);
	t.test("[1,1,1,3,5]"_arr).equals(4);
}