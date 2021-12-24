#include "../lttools.cpp"

class Solution {
public:
	vector<string> getFolderNames(vector<string>& names) {
		unordered_map<string, int> m;
		vector<string> res;
		for (string a: names) {
			if (m.count(a) > 0) {
				int k = m[a]+1;
				while (m.count(a + "(" + to_string(k) + ")") > 0) {
					++k;
				}
				string s = a + "(" + to_string(k) + ")";
				res.push_back(s);
				m[a] = k;
				m[s] = 0;
			} else {
				m[a] = 0;
				res.push_back(a);
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::getFolderNames);
	t.test({"pes","fifa","gta","pes(2019)"}).equals({"pes","fifa","gta","pes(2019)"});
	t.test({"gta","gta(1)","gta","avalon"}).equals({"gta","gta(1)","gta(2)","avalon"});
	t.test({"onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"}).equals({"onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece(4)"});
	t.test({"wano","wano","wano","wano"}).equals({"wano","wano(1)","wano(2)","wano(3)"});
	t.test({"kaido","kaido(1)","kaido","kaido(1)"}).equals({"kaido","kaido(1)","kaido(2)","kaido(1)(1)"});
	t.test({"kaido","kaido(1)","kaido","kaido(1)","kaido(2)"}).equals({"kaido","kaido(1)","kaido(2)","kaido(1)(1)","kaido(2)(1)"});
}