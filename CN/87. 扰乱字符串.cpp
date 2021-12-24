#include "./lttools.cpp"

class Solution {
public:
	
	bool chk(const string& s1, const string& s2) {
		if (s1.size() != s2.size())
			return false;
		auto freq = [](const string& s){
			array<int, 26> f{};
			for (char c: s) {
				++f[c-'a'];
			}
			return f;
		};
		auto f1 = freq(s1);
		auto f2 = freq(s2);
		return f1 == f2;
	}
	
	unordered_map<string, bool> mem;
	
	bool dfs(const string s1, const string s2) {
		auto key = s1 + "#" + s2;
		if (mem.count(key) > 0)
			return mem[key];
		
		if (s1 == s2) {
			mem[key] = true;
			return true;
		}
		
		if (!chk(s1, s2)) {
			mem[key] = false;
			return false;
		}
			
		int n = s1.size();
		for (int i=1; i<n; ++i) {
			bool noexg = dfs(s1.substr(0, i), s2.substr(0, i)) && dfs(s1.substr(i), s2.substr(i));
			if (noexg) {
				mem[key] = true;
				return true;
			}
				
			bool exg = dfs(s1.substr(0, i), s2.substr(n-i)) && dfs(s1.substr(i), s2.substr(0, n-i));
			if (exg) {
				mem[key] = true;
				return true;
			}
		}
		
		mem[key] = false;
		return false;
	}
	
	bool isScramble(string s1, string s2) {
		return dfs(s1, s2);
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::isScramble);
	t.test("great", "rgeat").equals(true);
	t.test("a", "a").equals(true);
	t.test("abcde", "caebd").equals(false);
}