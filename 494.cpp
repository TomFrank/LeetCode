#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

vector<int> num;
int target;
int n;
vector<int> sufsum;
int mem[21][2001];

bool prunce(int i, int s) {
	if ((s < target && s + sufsum[i] < target) 
		|| (s > target && s - sufsum[i] > target)) {
		return true;
	}
	return false;
}

int dfs(int i, int s) {
	if (i >= n) {
		if (s == target)
			return 1;
		else return 0;
	}
	
	if (s > 1000) {
		cout<<"error "<<s<<endl;
	}
	
	if (mem[i][s+1000] > 0)
		return mem[i][s+1000];
	
	if (prunce(i, s))
		return 0;
	
	int l = dfs(i+1, s+num[i]);
	int r = dfs(i+1, s-num[i]);
	mem[i][s+1000] = l + r;
	return l + r;
}

int findTargetSumWays(const vector<int>& nums, int S) {
	num = nums;
	target = S;
	n = nums.size();
	fill(mem[0], mem[0]+21*2001, 0);
	sufsum = vector<int>(n+1, 0);
	for(int i=n-1;i>=0;--i)
		sufsum[i] = sufsum[i+1] + nums[i];
	return dfs(0, 0);;
}

int main(int argc, char *argv[]) {
	cout << findTargetSumWays({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 3) << endl;
	cout << findTargetSumWays({1,2,1}, 0) << endl;
	cout << findTargetSumWays({1,3,1,2,1,3,1,3,1,4,3,1,3,1,2,3,4}, 3) << endl;
}