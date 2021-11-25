#include "../lttools.cpp"

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int T;
	int l,r,k;
	scanf("%d\n", &T);
	for (int i=0; i<T; ++i) {
		scanf("%d %d %d\n", &l, &r, &k);
		
		double res = 0;
		for (int i=l; i<=r; ++i) {
			//res += pow(i + pow(10, -k), 1.0/3) - pow(i, 1.0/3);
			res += cbrt(i * pow(10, k) + 1) - cbrt(i * pow(10, k));
		}
		res /= pow(10.0, k/3.0);
//		printf("%e\n", res);
		int exp = floor(log10(fabs(res)));
		double base = (res * pow(10, -exp));
		printf("%.5lfE%+04d\n", base, exp);
	}
}