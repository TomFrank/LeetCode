#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <map>
using namespace std;

vector<vector<int>> bs;
map<pair<int,int>,int> mem;
int n;
int sw;

int helper(int i, int h, int cw) {
	if(cw > sw)return INT_MAX;
	if(i >= n)return h;
	if(mem.count({i,cw})==1)return mem[{i,cw}];
	int bw = bs[i][0];
	int bh = bs[i][1];
	
	int cur = helper(i+1, max(h, bh), cw+bw);
	int nxt = h+helper(i+1, bh, bw);
	mem[{i,cw}]=min(cur, nxt);
	return mem[{i,cw}];
}

int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
	sw = shelf_width;
	bs = books;
	n = bs.size();
	return helper(0, 0, 0);
}

int main(int argc, char *argv[]) {
	vector<vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
	int shelf_width = 4;
	cout << minHeightShelves(books, shelf_width) << endl;
}