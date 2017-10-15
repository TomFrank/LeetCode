#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
	public:
		vector<int> constructRectangle(int area) {
			int w, l;
			for (int i=sqrt(area); i<=area; ++i)
				if (area % i == 0) {
					l = i;
					break;
				}
			w = area / l;
			if (l<w)swap(l, w);
			return {l,w};
		}
	};

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	auto ans = Solution().constructRectangle(n);
	cout << ans[0] << " " << ans[1] <<endl;
}