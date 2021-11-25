#include "../lttools.cpp"

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	// word, num of doc
	map<string, int> strdoc;
	
	set<string> dict;
	
	vector<map<string, int>> docs(n);
	
	for (int i=0; i<n; ++i) {
		int m;
		cin >> m;
		for (int j=0; j<m; ++j) {
			string w;
			cin >> w;
			docs[i][w]++;
		}
	}
	
	for(int i=0; i<n; ++i) {
		for(auto it=docs[i].begin(); it!=docs[i].end(); ++it) {
			cout << it->first << ":" << it->second << ", ";
			dict.insert(it->first);
		}
		cout << endl;
	}
	
	
	for(int i=0; i<n; ++i) {
		for(auto it=dict.begin(); it!=dict.end(); ++it) {
			int dc = docs[i].count(*it);
			if (dc > 0) {
				strdoc[*it]++;
				break;
			}
		}
	}
	
	for(int i=0; i<n; ++i) {
		cout << strdoc[docs[i].begin()->first] << endl;
	}
}