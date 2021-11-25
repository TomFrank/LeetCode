#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int n,k;
map<pair<int,int>,int> mem;

int helper(int i, int j) {
	if (i>=n-1)return 0;
	if (j==k)return n-i;
	if (mem.count({i,j}) > 0)return mem[{i,j}];
	int c=n-i;
	for(int p=i+1;p<n-1;++p)
		c += helper(p, j+1);
	mem[{i,j}]=c;
	return c;
}

int numberOfSets(int nn, int kk) {
	n=nn;
	k=kk;
	return helper(0,0);
}

int main(int argc, char *argv[]) {
	cout << numberOfSets(4, 2) << endl;
	cout << numberOfSets(3, 1) << endl;
	cout << numberOfSets(30, 17) << endl;
	
}