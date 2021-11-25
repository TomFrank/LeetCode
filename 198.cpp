#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <numeric>
using namespace std;

vector<int> a;
map<int,int> mem;
int n;

int dfs(int i) {
	if (i >= n)return 0;
	if (mem.count(i) > 0) return mem[i];
	int res = a[i] + max(dfs(i+2), dfs(i+3));
	mem[i] = res;
	return res;
}

int rob(const vector<int>& nums) {
	a = nums;
	n = nums.size();
	mem.clear();
	return max(dfs(0), dfs(1));
}

int main(int argc, char *argv[]) {
	cout << rob({1,2,3,1}) << endl;
	cout << rob({2,7,9,3,1}) << endl;
	cout << rob({226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,201,172,130,103,225,142,46,86,185,62,138,212,192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124}) << endl;
}