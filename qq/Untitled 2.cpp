#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<char>> permutations(std::vector<char> arr) {
	std::sort(arr.begin(), arr.end());
	std::vector<std::vector<char>> res;
	do {
		res.push_back(arr);
	} while(std::next_permutation(arr.begin(), arr.end()));
	return res;
}

template<class T>
void printvv(const std::vector<std::vector<T>>& vv) {
	for (auto v: vv) {
		for (auto a: v) {
			std::cout << a << " ";
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	std::vector<std::vector<char>> ss = {
		{'1','1','1'},
		{'2','2','2'},
		{'3','3','3'}
	};
	
	std::vector<char> s;
	
	std::vector<std::vector<int>> rows;
	for (int x=0; x<(1<<ss.size()); ++x) {
		std::vector<int> row;
		int t = x;
		for (int i=0; i<ss.size(); ++i) {
			row.push_back(t & 1);
			t >>= 1;
		}
		rows.push_back(row);
	}
	
	printvv(rows);
	
	for (int i=0; i<rows.size(); ++i) {
		s = {};
		for (int j=0; j<rows[i].size(); ++j) {
			
			s.push_back(ss[rows[i][j]][j]);
			
		}
		
		auto p = permutations(s);
		printvv(p);
	}
	
	
//	s = {'1', '2', '3'};
//	auto res = permutations(s);
//	printvv(res);
//	
//	s = {};
//	res = permutations(s);
//	printvv(res);
//	
//	s = {'1'};
//	res = permutations(s);
//	printvv(res);
//	
//	s = {'1','1','2'};
//	res = permutations(s);
//	printvv(res);
}