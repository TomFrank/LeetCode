#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

int intersectionSizeTwo(const vector<vector<int>>& intervals) {
	vector<vector<int>> a = intervals;
	sort(a.begin(), a.end(), [](vector<int> s, vector<int> e){
		if (s[0] != e[0]) return s[0] < e[0];
		else return s[1] > e[1];
	});
	
	int res = 2;
	for(int i=0; i<a.size()-1; ++i) {
		if (a[i+1][0] > a[i][1]) {
			res += 2;
		} else {
			if (a[i+1][1] > a[i][1]) {
				res += 1;
			} else {
				
			}
		}
	}
	return res;
}

int main(int argc, char *argv[]) {
	cout << intersectionSizeTwo({{1,3},{1,4},{2,5},{3,5}}) << endl;
	cout << intersectionSizeTwo({{1,2},{2,3},{2,4},{4,5}}) << endl;
}