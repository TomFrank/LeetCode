#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void gen(string s, int j, vector<string>& ans, const int n) {
	ans.push_back(s);
	for (int i=j; i<n/2; ++i) {
		string t = s;
		swap(t[i], t[n-i-1]);
		gen(t, i+1, ans, n);
	}
}

vector<string> gen(string s) {
	vector<string> ret;
	gen(s, 0, ret, s.size());
	return ret;
}

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	vector<string> ss;
	for (int i=0; i<N; ++i) {
		string tmp;
		cin >> tmp;
		ss.push_back(tmp);
	}
	
	map<string, vector<string>> mp;
	for (auto& s: ss) {
		mp[s] = gen(s);
	}
	
	sort(ss.begin(), ss.end(), [&](string a, string b){
		auto as = mp[a];
		auto bs = mp[b];
		
		for (const auto& ai: as) {
			if (all_of(bs.begin(), bs.end(), [&](string bi){
				return bi > ai;
			})) {
				return true;
			}
		}
		
		for(const auto& bi: bs) {
			if (all_of(as.begin(), as.end(), [&](string ai){
				return ai > bi;
			})) {
				return false;
			}
		}
		
		return true;
	});
	
	for (auto s: ss) {
		cout << s << "\n";
	}
}