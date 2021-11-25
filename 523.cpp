#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <numeric>
using namespace std;

bool checkSubarraySum(const vector<int>& nums, const int k) {
	vector<int> p;
	p.push_back(0);
	partial_sum(nums.cbegin(), nums.cend(), back_inserter(p), [&](int s, int a){
		return s + a;
	});
	
	unordered_map<int, int> m;
	for (int i=0; i<p.size(); ++i) {
		int x = k != 0 ? p[i] % k : p[i];
		if (m.count(x) > 0) {
			if (i - m[x] > 1) return true;
		} else {
			m[x] = i;
		}
	}
	
	return false;
}

int main(int argc, char *argv[]) {
	cout << checkSubarraySum({23, 2, 4, 6, 7}, 6) << endl;
	cout << checkSubarraySum({23, 2, 6, 4, 7}, 6) << endl;
	cout << !checkSubarraySum({23, 2, 6, 4, 7}, 0) << endl;
	cout << !checkSubarraySum({0}, 0) << endl;
	cout << checkSubarraySum({0,0}, 0) << endl;
	cout << checkSubarraySum({0,0,0}, 0) << endl;
	cout << !checkSubarraySum({0,1,0}, 0) << endl;
}