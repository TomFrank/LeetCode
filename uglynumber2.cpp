#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool isugly(int n) {
	while (n>0&&n%2==0) n/=2;
	while (n>0&&n%3==0) n/=3;
	while (n>0&&n%5==0) n/=5;
	return n==1;
}

int nthUglyNumber(int n) {
	int start = 1;
	while (n>0) {
		if (isugly(start))n--;
		start++;
	}
	return start-1;
}

int main(int argc, char *argv[]) {
	cout<< nthUglyNumber(1352);
}
