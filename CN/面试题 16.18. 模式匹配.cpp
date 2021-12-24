#include "./lttools.cpp"

class Solution {
public:
	string p, v;
	int n,m;
//	unordered_map<char,string> mp;
	
	bool dfs(int pi, int vi, string a, string b, bool aa, bool bb) {
		// cout << "a=" << a << ", b=" << b << ", pi=" << pi << ", vi="<< vi << "\n";
		
		if ((pi >= m && vi < n) || (vi >= n && pi < m)) 
			return false;
		if (pi >= m && vi >= n) 
			return true;
		
		const char cp = p[pi];
		
		int i=vi, j=0;
		const string cpv = cp == 'a' ? a : b;
		if (cpv.empty()) {
			bool res = dfs(pi+1, i, a, b, cpv == a, cpv == b);
			if (res) return true;
		} 
		for (; i<n&&j<cpv.size(); ++i,++j) {
			if (cpv[j] != v[i]) return false;
		}
		if (!cpv.empty() && j == cpv.size()) return dfs(pi+1, i, a, b, cpv == a, cpv == b);
			
		for (int i=vi; i<n; ++i) {
			if (cp == 'a') {
				a += v[i];
			} else {
				b += v[i];
			}
			bool res = dfs(pi+1, i+1, a, b, aa, bb);
			if (res) {
				return true;
			}
		}
		return false;
	}
	
	bool patternMatching(string pattern, string value) {
		p = pattern;
		v = value;
		n = value.size();
		m = pattern.size();
		if (n == 0 && m == 1) return true;
		bool res = dfs(0, 0, "", "", false, false);
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::patternMatching);
//	t.test("a", "").equals(true);
//	t.test("", "").equals(true);
//	t.test("", "a").equals(false);
//	t.test("aaaaab",
//		"xahnxdxyaahnxdxyaahnxdxyaahnxdxyaauxuhuo").equals(true);
//	t.test("abba", "dogcatcatdog").equals(true);
	t.test("aaaa", "dogcatcatdog").equals(false);
//	t.test("abba", "dogcatcatfish").equals(false);
//	t.test("abba", "dogdogdogdog").equals(true);
}