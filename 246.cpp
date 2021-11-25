#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

int help2(int n) {
	vector<int> dp = {1,1,2,3};
	dp.resize(n+1);
	
	for(int i=4;i<=n;++i) {
		dp[i] = min({dp[i-1]*2, dp[i-2]*3, dp[i-3]*5});
	}
	for(int i:dp)cout<<i<<" ";
	return dp[n];
}

int nthUglyNumber(int n) {
	return help2(n);
}

int main(int argc, char *argv[]) {
	cout << nthUglyNumber(10) << endl;
}