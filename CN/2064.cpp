#include "../lttools.cpp"

class Solution {
public:
	bool check(int n, const vector<int>& quantities, int x) {
		int c = 0;
		for (int q: quantities) {
			c += (q + x - 1) / x;
		}
		return c <= n;
	}
	
	int minimizedMaximum(int n, vector<int>& quantities) {
		int l = 1;
		int r = 1e5;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (check(n, quantities, m)) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return l;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::minimizedMaximum);
	t.test(6, "[11,6]"_arr).equals(3);
	t.test(7, "[15,10,10]"_arr).equals(5);
	t.test(1, "[100000]"_arr).equals(100000);
	t.test(1, "[1]"_arr).equals(1);
}