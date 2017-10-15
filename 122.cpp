#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
void writeList(const vector<int>& v);
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		adjacent_difference(prices.begin(), prices.end(), prices.begin());
		return accumulate(prices.begin()!=prices.end()?prices.begin()+1:prices.begin(), prices.end(), 0, [](int n, int a){return a>0?a+n:n;});
//		int ret = 0;
//		for (int i=1; i<prices.size(); ++i)
//			if (prices[i] > prices[i-1])
//				ret += prices[i] - prices[i-1];
//		return ret;
//		for (int i=1; i<int(prices.size())-1; ) {
//			if ( (prices[i-1] <= prices[i] && prices[i] <= prices[i+1]) || (prices[i-1] >= prices[i] && prices[i] >= prices[i+1]))
//				prices.erase(prices.begin() + i);
//			else ++i;
//		}
//		int ret = 0;
//		if (prices.size() > 1)
//		for (int i=prices[1]>prices[0]?1:2; i<prices.size(); i+=2)
//			ret += prices[i] - prices[i-1];
//		return ret;
	}
};
vector<int> readList() {
	vector<int> ret;
	getchar();
	int t;
	char c;
	while (cin >> t >> c) {
		ret.push_back(t);
		if (c == ']')break;
	}
	getchar();
	return ret;
}
void writeList(const vector<int>& v) {
	cout << "[";
	for (int i=0; i<v.size(); ++i) {
		cout << v[i];
		if (i!=v.size()-1)cout << ",";
	}
	cout << "]";
}
int main(int argc, char *argv[]) {
	auto p = readList();
	cout << Solution().maxProfit(p);
}