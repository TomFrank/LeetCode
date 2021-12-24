#include "./lttools.cpp"

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		unordered_map<char,int> ps;
		for (char c: p) {
			++ps[c];
		}
		unordered_map<char,int> ms;
		vector<int> res;
		int i=0, j=0;
		for (; j<s.size(); ) {
			if (ms == ps) {
				res.push_back(i);
				--ms[s[i]];
				++i;
				//continue;
			}
			if (ps.count(s[j]) == 0) {
				i = j + 1;
				j = i;
				ms.clear();
			} else if (ms[s[j]] == ps[s[j]]) {
				for (; i <= j; ++i) {
					--ms[s[i]];
					if (s[i] == s[j]) {
						++i;
						break;
					}
				}
				++ms[s[j]];
				++j;
			} else {
				++ms[s[j]];
				++j;
			}
		}
		if (ms == ps)
			res.push_back(i);
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::findAnagrams);
	t.test("cbaebabacd", "abc").equals("[0,6]"_arr);
	t.test("abab", "ab").equals("[0,1,2]"_arr);
}