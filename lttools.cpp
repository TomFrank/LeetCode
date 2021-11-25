#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <numeric>
#include <regex>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <experimental/iterator>
#include <random>
#include <type_traits>
#include <memory>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	printf("[");
	copy(v.cbegin(), v.cend(), experimental::make_ostream_joiner(cout, ","));
	printf("]");
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& vv) {
	printf("[");
	for_each(vv.begin(), vv.end(), [](auto v){
		cout << v;
	});
	printf("]");
	return os;
}

static
ostream& operator<<(ostream& os, ListNode* head) {
	printf("[");
	while (head != nullptr) {
		printf("%d%s", head->val, head->next != nullptr ? "," : "");
		head=head->next;
	}
	printf("]");
	return os;
}

namespace LT {
	
static vector<string> split(const string& str, const string& regex_str) {
	std::regex regexz(regex_str);
	std::vector<std::string> list(std::sregex_token_iterator(str.begin(), str.end(), regexz, -1),
		std::sregex_token_iterator());
	return list;
}


static vector<int> array_from(const string& s) {
	assert(s.size() >= 2 && s.front()== '[' && s.back() == ']');
	const regex rg(R"([^,]+)");
	vector<std::string> list(sregex_token_iterator(s.begin()+1, s.begin()+s.size()-1, rg), sregex_token_iterator());
	vector<int> arr;
	transform(list.cbegin(), list.cend(), back_inserter(arr), [](string ns){
		return stoi(ns);
	});
	return arr;
}
	
static vector<vector<int>> array2d_from(const string& s) {
	assert(s.size() >= 2 && s.front() == '[' && s.back() == ']');
	const regex rg(R"(\[[^\]]*\])");
	std::vector<std::string> list(sregex_token_iterator(s.begin()+1, s.end(), rg), sregex_token_iterator());
	vector<vector<int>> arr;
	transform(list.begin(), list.end(), back_inserter(arr), [](auto s){
		return array_from(s);
	});
	return arr;
}

static ListNode* list_from(const vector<int>& v) {
	auto head = ListNode();
	auto cur = &head;
	for (auto a:v) {
		cur->next = new ListNode(a);
		cur = cur->next;
	}
	return head.next;
}
	
static ListNode* list_from(const string& s) {
	return list_from(array_from(s));
}

static bool is_equal(ListNode* a, ListNode* b) {
	while (a != nullptr && b != nullptr) {
		if (a->val != b->val) return false;
		a = a->next;
		b = b->next;
	}
	return a == nullptr && b == nullptr;
}
	
static bool is_equal(TreeNode* a, TreeNode* b) {
	perror("no implementation");
	abort();
}

static void print_inorder(TreeNode* root) {
	if (root == nullptr) return;
	print_inorder(root->left);
	printf("%d,", root->val);
	print_inorder(root->right);
}
	
template<typename... T, typename P, typename R>
static void batch_test(initializer_list<tuple<tuple<T...>, P>> data, R f) {
	for (const auto& d: data) {
		auto [in, out] = d;
		auto y = apply(f, in);
		if (y == out) {
			cout << y << "==" << out << " ✅" << endl;
		} else {
			cout << y << "!=" << out << " ❌" << endl;
		}
	}
}

template<typename OUT, class C=void, typename ...IN>
class Tester {
private:
	using F = OUT(IN...);
	using MemF = OUT (C::*)(IN...);
	
	function<F> f;
	MemF mf;
	
	OUT res;
public:
	Tester(F f):f(f) {}
	Tester(MemF f):mf(f) {}
	
	Tester& test(const IN&... in) {
		if constexpr (is_void_v<C>) {
			res = f(forward<IN>(in)...);
		} else {
			auto callee = mem_fn(mf);
			res = callee(new C, in...);
		}
		return *this;
	}
	
	void equals(const OUT& out) {
		if (equals(out, res)) {
			cout << "✅ " << res << " == " << out << endl;
		} else {
			cout << "❌ " << res << " != " << out << endl;
		}
	}
	
	OUT& lastResult() {
		return res;
	}
	
private:
	bool equals(const OUT& a, const OUT& b) {
		if constexpr (is_same_v<OUT, ListNode*> || is_same_v<OUT, TreeNode*>) {
			return is_equal(a, b);
		} else {
			return a == b;
		}
	}
};
}

static
auto operator"" _arr(const char* s, const size_t len) {
	return LT::array_from(s);
}

static
auto operator"" _arr2d(const char* s, const size_t len) {
	return LT::array2d_from(s);
}

static
auto operator"" _list(const char* s, const size_t len) {
	return LT::list_from(s);
}

// https://stackoverflow.com/a/21439212/9685108
#include <tuple>
// function has to live in the std namespace 
// so that it is picked up by argument-dependent name lookup (ADL).
namespace std{
	namespace
	{
		
		// Code from boost
		// Reciprocal of the golden ratio helps spread entropy
		//     and handles duplicates.
		// See Mike Seymour in magic-numbers-in-boosthash-combine:
		//     https://stackoverflow.com/questions/4948780
		
		template <class T>
		inline void hash_combine(std::size_t& seed, T const& v)
		{
			seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
		}
		
		// Recursive template code derived from Matthieu M.
		template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
		struct HashValueImpl
		{
			static void apply(size_t& seed, Tuple const& tuple)
			{
				HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
				hash_combine(seed, get<Index>(tuple));
			}
		};
		
		template <class Tuple>
		struct HashValueImpl<Tuple,0>
		{
			static void apply(size_t& seed, Tuple const& tuple)
			{
				hash_combine(seed, get<0>(tuple));
			}
		};
	}
	
	template <typename ... TT>
	struct hash<std::tuple<TT...>> 
	{
		size_t
		operator()(std::tuple<TT...> const& tt) const
		{                                              
			size_t seed = 0;                             
			HashValueImpl<std::tuple<TT...> >::apply(seed, tt);    
			return seed;                                 
		}                                              
		
	};
}