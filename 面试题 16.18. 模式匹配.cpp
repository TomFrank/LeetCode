#include "./lttools.cpp"

class Solution {
public:
	string p, v;
	int n,m;
//	unordered_map<char,string> mp;
	
	bool dfs(int pi, int vi, string a, string b) {
//		cout << "a=" << a << ", b=" << b << ", pi=" << pi << ", vi="<< vi << "\n";
		
		if ((pi >= m && vi < n) || (vi >= n && pi < m)) 
			return false;
		if (pi >= m && vi >= n) 
			return true;
		
		char cp = p[pi];
		
		int i=vi, j=0;
		string cpv = cp == 'a' ? a : b;
		for (; i<n&&j<cpv.size(); ++i,++j) {
			if (cpv[j] != v[i]) return false;
		}
		if (!cpv.empty() && j == cpv.size()) return dfs(pi+1, i, a, b);
			
		for (int i=vi; i<n; ++i) {
			if (cp == 'a') {
				a += v[i];
			} else {
				b += v[i];
			}
			bool res = dfs(pi+1, i+1, a, b);
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
		bool res = dfs(0, 0, "", "");
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::patternMatching);
	t.test("abba", "dogcatcatdog").equals(true);
	t.test("aaaa", "dogcatcatdog").equals(false);
	t.test("abba", "dogcatcatfish").equals(false);
	t.test("abba", "dogdogdogdog").equals(true);
}