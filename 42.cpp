#include "./lttools.cpp"

class Solution {
public:
//	static
//	int trap(const vector<int>& height) {
//		if (height.empty()) return 0;
//		int n = height.size();
//		int res = 0;
//		vector<int> lm(n, height[0]), rm(n, height[n-1]);
//		for (int i=1,j=n-2; i<n; ++i,--j) {
//			lm[i] = max(lm[i-1], height[i]);
//			rm[j] = max(rm[j+1], height[j]);
//		}
//		for (int i=0; i<n; ++i) {
//			res += min(lm[i], rm[i]) - height[i];
//		}
//		return res;
//	}
	static
	int trap(const vector<int>& height) {
		if (height.empty()) return 0;
		int n = height.size();
		int res = 0;
		int lm = height[0], rm = height[n-1];
		for (int i=0, j=n-1; i<=j;) {
			lm = max(lm, height[i]);
			rm = max(rm, height[j]);
			if (lm > rm) {
				res += rm - height[j];
				--j;
			} else {
				res += lm - height[i];
				++i;
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(Solution::trap);
	t.test(LT::array_from("[0,1,0,2,1,0,1,3,2,1,2,1]"))
	 .equals(6);
	t.test(LT::array_from("[4,2,0,3,2,5]"))
	 .equals(9);
	t.test(LT::array_from("[]")).equals(0);
}