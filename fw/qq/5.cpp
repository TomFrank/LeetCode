#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <random>

using namespace std;

long expp = 1000000;

std::random_device rd;
std::mt19937 gen(rd());

// m, 
map<int, uniform_int_distribution<>> mp;

int pk(int m, int n) {
	if (mp.count(m) > 0) {
		return mp[m](gen);
	} else {
		auto dist = std::uniform_int_distribution<>(1, m+n);
		mp[m] = dist;
		return dist(gen);
	}
}

bool issr(int m, int n, int i) {
	return i > n;
}

int main(int argc, char *argv[]) {
	double n, m;
	cin >> n >> m;
	
	double ans = 0;
	
	for (int i=m; i>=1; --i) {
		ans += m/(m+n)*2 + n/(m+n);
	}
	
	
	printf("%.2lf", ans);
//	int bk = m;
//	
//	vector<int> total, cp;
//	
//	for (long i=0; i<expp; ++i) {
//		int cnt = 0;
//		while (m > 0) {
//			int p = pk(m, n);
//			if (issr(m,n,p)) {
//				--m;
//				cnt += 2;
//			} else {
//				cnt += 1;
//			}
//		}
//		total.push_back(cnt);
//		if (m == 0) {
//			m = bk;
//		}
//	}
//	
//	sort(total.begin(), total.end());
//	
//	int ns = 0;
//	copy(total.begin()+ns, total.end()-ns, back_inserter(cp));
//	
//	double avg = accumulate(cp.begin(), cp.end(), 0l) / double(cp.size());
//	printf("%.2lf", avg);
}