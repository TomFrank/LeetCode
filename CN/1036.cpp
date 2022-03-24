#include "../lttools.cpp"

using Point = pair<int,int>;

namespace std {
	template<> struct hash<Point> {
		std::size_t operator()(const Point &p) const {
			return (p.first * size_t(1e5)) ^ p.second;
		}
	};
}

class Solution {
public:
	static constexpr int dir[][2] {{-1,0},{0,-1},{0,1},{1,0}};
	static constexpr int maxx = 1e6 - 1;
	static constexpr int maxl = 200 * 200;
	
	bool check(const unordered_set<Point>& bl, const vector<int>& source, const vector<int>& target) {
		unordered_set<Point> visited;
		queue<Point> q;
		q.emplace(source[0], source[1]);
		visited.emplace(source[0], source[1]);
		while (!q.empty() && visited.size() <= maxl) {
			auto t = q.front();
			q.pop();
			auto [x,y] = t;
			if (x == target[0] && y == target[1])
				return true;
			for (int i=0; i<4; ++i) {
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				auto np = make_pair(nx, ny);
				if (nx >= 0 && nx <= maxx && ny >= 0 && ny <= maxx && bl.count(np) == 0 && visited.count(np) == 0) {
					q.emplace(nx, ny);
					visited.insert(np);
				}
			}
		}
		return visited.size() > maxl;
	}
	
	bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
		unordered_set<Point> bl;
		for (auto& b: blocked) {
			bl.emplace(b[0], b[1]);
		}
		return check(bl, source, target) && check(bl, target, source);
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::isEscapePossible);
	t.test("[[0,1],[1,0]]"_arr2d, "[0,0]"_arr, "[0,2]"_arr).equals(false);
	t.test("[]"_arr2d, "[0,0]"_arr, "[999999,999999]"_arr).equals(true);
	t.test("[[100059,100063],[100060,100064],[100061,100065],[100062,100066],[100063,100067],[100064,100068],[100065,100069],[100066,100070],[100067,100071],[100068,100072],[100069,100073],[100070,100074],[100071,100075],[100072,100076],[100073,100077],[100074,100078],[100075,100079],[100076,100080],[100077,100081],[100078,100082],[100079,100083],[100080,100082],[100081,100081],[100082,100080],[100083,100079],[100084,100078],[100085,100077],[100086,100076],[100087,100075],[100088,100074],[100089,100073],[100090,100072],[100091,100071],[100092,100070],[100093,100069],[100094,100068],[100095,100067],[100096,100066],[100097,100065],[100098,100064],[100099,100063],[100098,100062],[100097,100061],[100096,100060],[100095,100059],[100094,100058],[100093,100057],[100092,100056],[100091,100055],[100090,100054],[100089,100053],[100088,100052],[100087,100051],[100086,100050],[100085,100049],[100084,100048],[100083,100047],[100082,100046],[100081,100045],[100080,100044],[100079,100043],[100078,100044],[100077,100045],[100076,100046],[100075,100047],[100074,100048],[100073,100049],[100072,100050],[100071,100051],[100070,100052],[100069,100053],[100068,100054],[100067,100055],[100066,100056],[100065,100057],[100064,100058],[100063,100059],[100062,100060],[100061,100061],[100060,100062]]"_arr2d, "[100079,100063]"_arr, "[999948,999967]"_arr).equals(false);

	t.test("[[911403,385527],[239959,111299],[616794,581419],[389409,15658],[130782,942945],[776414,292428],[192474,535030],[437516,709103],[620485,873275],[402557,436044],[663467,858356],[853911,115092],[127916,16601],[489938,706537],[832380,545560],[20734,182880],[348641,238353],[66362,828038],[460729,741337],[545598,153112],[137201,291704],[695378,276425],[301902,689387],[147989,699840],[475048,689442],[549239,98327],[957802,316547],[179262,286365],[122004,691173],[44677,888277],[711929,484566],[834937,804469],[693569,520854],[967578,60328],[607848,629914],[97024,25612],[633853,167945],[20,405493],[980580,204610],[377234,129064],[451349,851733],[880718,313633],[639707,842181],[228203,220493],[113621,408333],[346405,49105],[673336,79383],[26185,729729],[561163,451782],[523320,208617],[774697,966766],[541224,421512],[704131,580566],[131042,175312],[458396,869181],[81157,357928],[659723,740626],[474434,786986],[449916,252667],[436318,261093],[503279,313295],[843187,619164],[936952,66524],[312878,316484]]"_arr2d, "[765971,548106]"_arr, "[802301,185762]"_arr).equals(true);
}