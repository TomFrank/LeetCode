#include <iostream>
#include <string>
#include <numeric>
#include <cmath>
using namespace std;
class Solution {
	public:
		char findTheDifference(string s, string t) {
//			int bits = 0, bitt = 0;			
//			for (auto& c:s)bits^=1<<(c-'a');
//			for (auto& c:t)bitt^=1<<(c-'a');			
			auto acc = [](string& ss){
				return accumulate(ss.begin(), ss.end(), 0, [](int bt, char c){
					return bt^(1<<(c-'a'));
				});
			};
			return char(log2(acc(s)^acc(t)) + 'a');
		}
	};
int main(int argc, char *argv[]) {
	string s,t;
	cin >> s >> t;
	cout << Solution().findTheDifference(s.substr(1, s.size()-2), t.substr(1, t.size()-2));
}