#include "./lttools.cpp"

class Solution {
public:
	static
	bool closeStrings(string word1, string word2) {
		int n = word1.size();
		
		if (n != word2.size()) return false;
		
		vector<int> a1(26, 0), a2(26, 0);
		for (int i=0; i<n; ++i) {
			++a1[word1[i]-'a'];
			++a2[word2[i]-'a'];
		}
		
		for (int i=0; i<a1.size(); ++i)
			if ((a1[i] == 0 && a2[i] > 0) || (a2[i] == 0 && a1[i] > 0))
				return false;
		
		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end());
		if (a1 != a2) return false;
		return true;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(Solution::closeStrings);
	t.test("abc", "bca").equals(true);
	t.test("a", "aa").equals(false);
	t.test("cabbba", "abbccc").equals(true);
	t.test("cabbba", "aabbss").equals(false);
	t.test("xxxxxxxxxxxxxxxxxxx", "zzzzzzzzzzzzzzzzzzz").equals(false);
}