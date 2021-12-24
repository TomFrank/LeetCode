#include <stdio.h>

int padovanSequence(int n) {
	// write code here
	int a[n];
	a = {0, 1, 1, 1, 2, 2};
	for (int i=5; i<=n; ++i) {
		a[i] = a[i-1] + a[i-2];
	}
	return a[n];
}

int main(int argc, char *argv[]) {
	
}