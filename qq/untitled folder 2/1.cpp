#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		vector<int> a,b;
		int tmp;
		for (int ni=0; ni<n; ++ni) {
			scanf("%d ", &tmp);
			a.push_back(tmp);
		}
		for (int mi=0; mi<m; ++mi) {
			scanf("%d ", &tmp);
			b.push_back(tmp);
		}
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		int ans = 0;
		
		int i=0, j=0;
		while (i < n && j <m) {
			if (abs(a[i] - b[j]) <= k) {
				++ans;
				++i;
				++j;
			} else if (a[i] - b[j] > k) {
				++j;
			} else if (b[j] - a[i] > k) {
				++i;
			}
		}
		
		printf("%d\n", ans);
	}
}