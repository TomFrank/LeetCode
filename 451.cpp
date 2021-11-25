#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

string frequencySort(string s) {
	map<char, int> m;
	
	for(auto c: s) {
		m[c]++;
	}

	//sort(m.begin(), m.end());
	
	string ans;
	
	for(auto [c,n]:m) {
		ans.append(string(n, c));
	}
	
	return ans;
}

int main(int argc, char *argv[]) {
	
	cout<< frequencySort("Aabb");
}