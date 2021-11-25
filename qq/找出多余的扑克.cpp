#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <random>
using namespace std;

int find(vector<int>& arr) {
	for (int i=0; i<arr.size(); ++i) {
		while (arr[i] != i) {
			if (arr[i] == arr[arr[i]]) {
				return arr[i];
			} else {
				int t = arr[i];
				int t2 = arr[t];
				arr[t] = t;
				arr[i] = t2;
//				swap(arr[i], arr[arr[i]]);
			}
		}
	}
	return -1;
}

int findv2(vector<int>& arr) {
	long sum = accumulate(arr.begin(), arr.end(), 0l);
	// long d = arr.size() * (arr.size() - 1) / 2;
	
	return sum - 499999500000;
}

int main(int argc, char *argv[]) {
	
	vector<int> arr(1000000);
	iota(arr.begin(), arr.end(), 0);
	arr.push_back(1);
	
	shuffle(arr.begin(), arr.end(), mt19937{std::random_device{}()});
	
	auto start2 = std::chrono::high_resolution_clock::now();
	int res2 = findv2(arr);
	auto end2 = std::chrono::high_resolution_clock::now();
	cout << "ans v2=" << res2 << endl;
	cout << (end2 - start2).count() << endl;
	
	auto start = std::chrono::high_resolution_clock::now();
	int res = find(arr);
	auto end = std::chrono::high_resolution_clock::now();
	cout << "ans v1=" << res << endl;
	cout << (end - start).count() << endl;
}