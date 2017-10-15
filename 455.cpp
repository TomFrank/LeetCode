#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
	public:
		int findContentChildren(vector<int>& g, vector<int>& s) {
			sort(g.begin(), g.end());
			sort(s.begin(), s.end());
			int i = g.size()-1;
			int j = s.size()-1;
			int ret = 0;
			while (i>=0 && j>=0) {
				if (s[j] >= g[i]) {
					++ret;
					--j;
					--i;
				} else {
					--i;
				}
			}
			return ret;
		}
	};
vector<int> readList() {
	vector<int> ret;
	getchar();
	int t;
	char c;
	while (cin >> t >> c) {
		ret.push_back(t);
		if (c == ']')break;
	}
	getchar();
	return ret;
}
void writeList(const vector<int>& v) {
	cout << "[";
	for (int i=0; i<v.size(); ++i) {
		cout << v[i];
		if (i!=v.size()-1)cout << ",";
	}
	cout << "]";
}
int main() {
    auto g = readList();
	auto s = readList();
	cout << Solution().findContentChildren(g, s);
}



