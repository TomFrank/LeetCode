#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

int minTaps(int n, const vector<int>& ranges) {
	vector<pair<int,int>> rg;
	transform(ranges.begin(), ranges.end(), back_inserter(rg), [&,i=-1](int r) mutable {return i++,make_pair(max(0,i-r),min(n,i+r));});
		
	sort(rg.begin(), rg.end(), [](auto a,auto b){
		if (get<1>(a) != get<1>(b)) {
			return get<1>(a) < get<1>(b);
		} else {
			return get<0>(a) > get<0>(b);
		}
	});
	
		for(auto [s,e]:rg)
			cout << s << " " << e << "; ";cout<<endl;
	
	int ans = 0;
	int p = n;
	for(int i=n;i>=0; ) {
		if (get<1>(rg[i]) >= p) {
			p = get<0>(rg[i]);
			ans++;
			i = get<0>(rg[i]);
		} else {
			return -1;
		}
	}
	
	return ans;
}

int main(int argc, char *argv[]) {
	cout << minTaps(5, {3,4,1,1,0,0}) << endl;
	cout << minTaps(3, {0,0,0,0}) << endl;
	cout << minTaps(7, {1,2,1,0,2,1,0,1}) << endl;
	cout << minTaps(8, {4,0,0,0,0,0,0,0,4}) << endl;
	cout << minTaps(8, {4,0,0,0,4,0,0,0,4}) << endl;
	cout << minTaps(9, {0,5,0,3,3,3,1,4,0,4})  << endl;
}