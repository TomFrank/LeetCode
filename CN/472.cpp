#include "../lttools.cpp"

class Solution {
public:
	using key_t = unsigned long;
	unordered_set<key_t> st;
	const key_t p = 100031;
	
	bool check(string s) {
		int n = s.size();
		if (n == 0) return false;
		vector<int> f(n+1, -1);
		f[0] = 0;
		for (int i=0; i<n; ++i) if (f[i] >= 0) {
			key_t h = 0;
			for (int j=i+1; j<=n; ++j) {
				h = h * p + s[j-1];
				if (st.count(h) > 0) {
					f[j] = max(f[j], f[i] + 1);
				}
			}
			if (f[n] > 1) return true;
		}
		return false;
	}
	
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		for (const auto& w: words) {
			key_t h = 0;
			for (const char& c: w) {
				h = h * p + c;
			}
			st.insert(h);
		}
		vector<string> res;
		for (const auto& w: words) {
			if (check(w)) {
				res.push_back(w);
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::findAllConcatenatedWordsInADict);
	t.test({"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"}).equals({"catsdogcats","dogcatsdog","ratcatdogcat"});
	t.test({"cat","dog","catdog"}).equals({"catdog"});
	t.test({"a","b","ab","abc"}).equals({"ab"});
	t.test({""}).equals({});
	t.test({}).equals({});
}