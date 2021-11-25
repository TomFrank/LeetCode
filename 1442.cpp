#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

int countTriplets(const vector<int>& a) {
	vector<int> c(a.size()+1, 0);
	for (int i=1; i<=a.size(); ++i)
		c[i] = c[i-1] ^ a[i-1];
		
	int res = 0;
	for (int i=0; i<a.size(); ++i)
		for (int k=i+1; k<a.size(); ++k)
			if ((c[i] ^ c[k+1]) == 0)
				res += k-i;

	return res;
}

int main(int argc, char *argv[]) {
	cout << countTriplets({2,3,1,6,7}) << endl;
	cout << countTriplets({1,1,1,1,1}) << endl;
	cout << countTriplets({2,3}) << endl;
	cout << countTriplets({1,3,5,7,9}) << endl;
	cout << countTriplets({7,11,12,9,5,2,7,17,22}) << endl;
}