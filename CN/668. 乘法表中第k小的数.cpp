#include "./lttools.cpp"

class Solution {
public:
	// count the # of nums "less or equal than" x in the table
	int count(int x, int m, int n) {
		int res = 0;
		for (int i=1; i<=m; ++i) {
			res += min(x / i, n);
		}
		return res;
	}
	
	int findKthNumber(int m, int n, int k) {
		int l = 1;
		int r = m*n;
		while (l <= r) {
			int mid = (l + r) / 2;
			int c = count(mid, m, n);
			if (c < k) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return l;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::findKthNumber);
	t.test(3, 3, 5).equals(3);
	t.test(2, 3, 6).equals(6);
}