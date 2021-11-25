#include "./lttools.cpp"

int concatenatedBinary(int n) {
	int res = 0;
	const int mod = 1e9 + 7;
	for (int i=1; i<=n; ++i) {
		int x = i;
		while (x > 0) {
			res = (res << 1) % mod;
			x >>= 1;
		}
		res += i;
	}
	return res;
}

int main(int argc, char *argv[]) {
	cout << concatenatedBinary(12);
}