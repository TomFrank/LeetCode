#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int trailingZeroes(int n) {
	if(n <= 0) {
		return 0;
	}
	int k = log(n) / log(5);
	int ans = 0;
	
	for(int i=1,f=n/5; i<=k; ++i,f/=5) {
		ans += f;
	}
	return ans;
}

int main(int argc, char *argv[]) {
	cout << trailingZeroes(INT_MAX);
}