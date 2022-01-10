#include "../lttools.cpp"

class Solution {
public:
	vector<string_view> split(string_view s, char delimiter) {
		vector<string_view> res;
		size_t i = 0, p;
		while ((p = s.find(delimiter, i)) != string_view::npos) {
			res.push_back(s.substr(i, p-i));
			i = p+1;
		}
		if (i < s.size()) res.push_back(s.substr(i));
		return res;
	}
	
	string simplifyPath(string_view path) {
		auto ps = split(path, '/');
		deque<string_view> s;
		for (auto n: ps) {
			//cout << n << ";";
			if (n == "." || n.empty()) continue;
			else if (n == "..") {if (!s.empty()) s.pop_back();}
			else s.push_back(n);
		}
		string res;
		for (auto& n: s) {
			res += "/";
			res += n;
		}
		if (res.empty()) res = '/';
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::simplifyPath);
	t.test("/home/").equals("/home");
	t.test("/../").equals("/");
	t.test("/home//foo/").equals("/home/foo");
	t.test("/a/./b/../../c/").equals("/c");
	t.test("/a//b////c/d//././/..").equals("/a/b/c");
}