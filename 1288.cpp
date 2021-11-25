#include "./lttools.cpp"

class Solution {
public:
	static
	int removeCoveredIntervals(const vector<vector<int>>& intervals) {
		int n = intervals.size();
		auto a = intervals;
		sort(a.begin(), a.end(), [](auto x, auto y){
			if (x[0] != y[0]) return x[0] < y[0];
			else return x[1] > y[1];
		});
		int r=a[0][1];
		int res = n;
		for(int i=1; i<n; ++i) {
			if (a[i][1] <= r) {
				--res;
			} else {
				r = a[i][1];
			}
		}
		return res;
	}
	
//	int removeCoveredIntervals(vector<vector<int>>& A) {
//		int res = 0, left = -1, right = -1;
//		sort(A.begin(), A.end());
//		for (auto& v: A) {
//			if (v[0] > left && v[1] > right) {
//				left = v[0];
//				++res;
//			}
//			right = max(right, v[1]);
//		}
//		return res;
//	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(Solution::removeCoveredIntervals);
	t.test("[[1,4],[3,6],[2,8]]"_arr2d).equals(2);
	t.test("[[1,4],[2,3]]"_arr2d).equals(1);
	t.test("[[0,10],[5,12]]"_arr2d).equals(2);
	t.test("[[3,10],[4,10],[5,11]]"_arr2d).equals(2);
	t.test("[[1,2],[1,4],[3,4]]"_arr2d).equals(1);
}