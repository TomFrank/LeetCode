#include <iostream>
#include <numeric>
#include <vector>
#include <string>
using namespace std;
class Solution {
	public:
		vector<string> findWords(vector<string>& words) {
			auto toBits = [](const string& ss){
				return accumulate(ss.begin(), ss.end(), 0, [](int n, char c){
					return n |= (1 << (tolower(c) - 'a'));
				});
			};
			const vector<int> rows {toBits("qwertyuiop"), toBits("asdfghjkl"), toBits("zxcvbnm")};
			vector<string> ret;
			copy_if(words.begin(), words.end(), back_inserter(ret), [&](const string& ss){
				return any_of(rows.cbegin(), rows.cend(), [&](int r){
					return r == (toBits(ss) | r);
				});
			});
			return ret;
		}
};
int main(int argc, char *argv[]) {
	vector<string> words;
	getchar();
	string t;
	while (cin >> t)
		words.push_back(t.substr(1, t.size()-3));
	auto ans = Solution().findWords(words);
//	copy(words.begin(), words.end(), ostream_iterator<string>(cout, ", "));
	cout << "[";
	for (int i=0; i<ans.size(); ++i) {
		cout << "\"" << ans[i] << "\"";
		if (i!=ans.size()-1)cout << ",";
	}
	cout << "]";
}