#include "../lttools.cpp"

class Solution {
public:
	struct Ratio {
		const int p;
		const int q;
		
		Ratio(int _p, int _q): p(_p / gcd(_p, _q)), q(_q / gcd(_p, _q)) {};
		
		bool operator==(const Ratio& other) const {
			return p == other.p && q == other.q;
		}
		
		operator string() const {
			return to_string(p) + "/" + to_string(q);
		}
	};
	
	struct RatioHasher {
		size_t operator()(const Ratio& r) const {
			return hash<int>{}(r.p) ^ hash<int>{}(r.q);
		}
	};
	
	vector<string> simplifiedFractions(int n) {
		unordered_set<Ratio, RatioHasher> s;
		for (int i=2; i<=n; ++i) {
			for (int j=1; j<i; ++j) {
				s.emplace(j, i);
			}
		}
		vector<string> res;
		for (auto& r: s) {
			res.push_back(r);
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::simplifiedFractions, true);
	t.test(2).equals({"1/2"});
	t.test(3).equals({"1/2","1/3","2/3"});
	t.test(4).equals({"1/2","1/3","1/4","2/3","3/4"});
	t.test(1).equals({});
}