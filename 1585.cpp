#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
	
	auto cnt(string s) {
		array<int, 10> res{};
		for(char c:s) ++res[c-'0'];
		return res;
	}
	
	int rc(string s) {
		int res = 0;
		for (int i=0; i<s.size(); ++i)
			for (int j=i+1; j<s.size(); ++j)
				if (s[j] < s[i]) ++res;
		return res;
	}
	
	bool isTransformable(string s, string t) {
		if (s == t) return true;
		if (cnt(s) != cnt(t)) return false;
		return rc(s) > rc(t);
	}
};

int main(int argc, char *argv[]) {
	cout << Solution().isTransformable("84532", "34852") << endl;
	cout << Solution().isTransformable("34521", "23415") << endl;
	cout << !Solution().isTransformable("12345", "12435") << endl;
	cout << !Solution().isTransformable("1", "2") << endl;
	cout << !Solution().isTransformable("5894", "4985") << endl;
	cout << !Solution().isTransformable("891", "198") << endl;
}