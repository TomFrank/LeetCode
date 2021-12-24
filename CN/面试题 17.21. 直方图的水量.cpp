#include "./lttools.cpp"

class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if (n <= 1)
			return 0;
		vector<int> l(n+1), r(n+1);
		l[0] = height[0];
		for (int i=1; i<n; ++i) {
			l[i] = max(l[i-1], height[i]);
		}
		r[n-1] = height[n-1];
		for (int i=n-2; i>=0; --i) {
			r[i] = max(r[i+1], height[i]);
		}
		int res = 0;
		for (int i=0; i<n; ++i) {
			res += min(l[i], r[i]) - height[i];
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::trap);
	t.test("[0,1,0,2,1,0,1,3,2,1,2,1]"_arr).equals(6);
}