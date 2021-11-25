#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

int carFleet(int target, const vector<int>& position, const vector<int>& speed) {
	vector<pair<int, int>> ps;
	transform(position.begin(), position.end(), speed.begin(), back_inserter(ps), [=](int p, int s){
		return make_pair(target-p, s);
	});
	sort(ps.begin(), ps.end(), [](const pair<int, int>& a, const pair<int, int>& b){
		return a.first < b.first;
	});
	vector<double> t;
	transform(ps.begin(), ps.end(), back_inserter(t), [](const pair<int, int>& a){
		return double(a.first) / a.second;
	});
	int res = position.empty() ? 0 : 1;
	for (int i=1; i<position.size(); ++i) {
		if (t[i] > t[i-1])
			res ++;
		else if (t[i] < t[i-1])
			t[i] = t[i-1];
	}
	return res;
}

int main(int argc, char *argv[]) {
	cout << carFleet(12, {10,8,0,5,3}, {2,4,1,1,3}) << endl;
}