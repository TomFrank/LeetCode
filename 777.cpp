#include "./lttools.cpp"

class Solution {
public:
	static
	bool canTransform(string start, string end) {
		int n=start.size();
		if (n != end.size()) return false;
		int xc=0;
		vector<pair<char,int>> a,b;
		for(int i=0; i<n; ++i) {
			if (start[i] == 'X') ++xc;
			else a.emplace_back(start[i], i);
			if (end[i] == 'X') --xc;
			else b.emplace_back(end[i], i);
		}
		if (xc != 0) return false;
		int nn = a.size();
		if (nn != b.size()) return false;
		for (int i=0; i<nn; ++i) {
			if (a[i].first != b[i].first) return false;
			if (a[i].first == 'L') {
				if (a[i].second < b[i].second) return false;
			} else { //'R'
				if (a[i].second > b[i].second) return false;
			}
		}
		return true;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(Solution::canTransform);
	t.test("RXXLRXRXL", "XRLXXRRLX").equals(true);
	t.test("X", "L").equals(false);
	t.test("LLR", "RRL").equals(false);
	t.test("XL", "LX").equals(true);
	t.test("XLLR", "LXLX").equals(false);
	t.test("LXXLXRLXXL", "XLLXRXLXLX").equals(false);
}