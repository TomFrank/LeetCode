#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <numeric>
#include <regex>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <experimental/iterator>
#include <random>
#include <type_traits>
#include <memory>
#include <cassert>
#include <bitset>
#include <iterator>
//#if __cplusplus > 201703L
//#include <format>
//#else
#define FMT_HEADER_ONLY
#include <fmt/format.h>
//#endif
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
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
	printf("[");
	copy(v.cbegin(), v.cend(), std::experimental::make_ostream_joiner(std::cout, ","));
	printf("]");
	return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& vv) {
	printf("[");
	for_each(vv.begin(), vv.end(), [](auto v){
		std::cout << v;
	});
	printf("]");
	return os;
}

static
std::ostream& operator<<(std::ostream& os, ListNode* head) {
	printf("[");
	while (head != nullptr) {
		printf("%d%s", head->val, head->next != nullptr ? "," : "");
		head=head->next;
	}
	printf("]");
	return os;
}

template<class... Types>
static std::ostream& operator<<(std::ostream& os, const std::tuple<Types...>& t) {
	os << fmt::format("({}, {})", std::get<0>(t), std::get<1>(t));
	return os;
}

template<class T, class C, class CMP>
static std::ostream& operator<<(std::ostream& os, std::priority_queue<T, C, CMP> q) {
	while (!q.empty()) {
		os << q.top() << ", ";
		q.pop();
	}
	return os;
}

namespace LT {
	
//static std::vector<std::string> split(const std::string& str, const std::string& regex_str) {
//	std::regex regexz(regex_str);
//	std::vector<std::string> list(std::sregex_token_iterator(str.begin(), str.end(), regexz, -1),
//		std::sregex_token_iterator());
//	return list;
//}

static std::vector<int> array_from(const std::string& s) {
	assert(s.size() >= 2 && s.front()== '[' && s.back() == ']');
	std::regex rg(R"([^,]+)");
	std::vector<std::string> list(std::sregex_token_iterator(s.begin()+1, s.begin()+s.size()-1, rg), std::sregex_token_iterator());
	std::vector<int> arr;
	transform(list.cbegin(), list.cend(), back_inserter(arr), [](std::string ns){
		return stoi(ns);
	});
	return arr;
}
	
static std::vector<std::vector<int>> array2d_from(const std::string& s) {
	assert(s.size() >= 2 && s.front() == '[' && s.back() == ']');
	const std::regex rg(R"(\[[^\]]*\])");
	std::vector<std::string> list(std::sregex_token_iterator(s.begin()+1, s.end(), rg), std::sregex_token_iterator());
	std::vector<std::vector<int>> arr;
	std::transform(list.begin(), list.end(), std::back_inserter(arr), [](auto s){
		return array_from(s);
	});
	return arr;
}

static ListNode* list_from(const std::vector<int>& v) {
	auto head = ListNode();
	auto cur = &head;
	for (auto a:v) {
		cur->next = new ListNode(a);
		cur = cur->next;
	}
	return head.next;
}
	
static ListNode* list_from(const std::string& s) {
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

static void print_inorder(TreeNode* root) {
	if (root == nullptr) return;
	print_inorder(root->left);
	printf("%d,", root->val);
	print_inorder(root->right);
}
	
template<typename... T, typename P, typename R>
static void batch_test(std::initializer_list<std::tuple<std::tuple<T...>, P>> data, R f) {
	for (const auto& d: data) {
		auto [in, out] = d;
		auto y = apply(f, in);
		if (y == out) {
			std::cout << y << "==" << out << " ✅" << std::endl;
		} else {
			std::cout << y << "!=" << out << " ❌" << std::endl;
		}
	}
}
	
template<class T>
concept is_sortable = requires(T t) {
	std::sort(t.begin(), t.end());
};

template<typename OUT, class C=void, typename ...IN>
class Tester {
private:
	using F = OUT(IN...);
	using MemF = OUT (C::*)(IN...);
	
	std::function<F> f;
	MemF mf;
	
	OUT res;
	
	const bool unordered_result;
	
public:
	bool show_error_only;
	
	Tester(F f, bool unordered_result=false, bool show_error_only=false):f(f), unordered_result(unordered_result), show_error_only(show_error_only) {}
	Tester(MemF f, bool unordered_result=false, bool show_error_only=false):mf(f), unordered_result(unordered_result), show_error_only(show_error_only) {}
	
	Tester& test(std::remove_reference_t<IN>&&... in) {
		if constexpr (std::is_void_v<C>) {
			res = f(std::forward<IN>(in)...);
		} else { 
			auto callee = std::mem_fn(mf);
			std::unique_ptr<C> p(new C);
			res = callee(p, std::forward<IN>(in)...);
		}
		return *this;
	}
	
	Tester& test(const std::remove_reference_t<IN>&... in) {
		if constexpr (std::is_void_v<C>) {
			res = f(in...);
		} else {
			auto callee = std::mem_fn(mf);
			std::unique_ptr<C> p(new C);
			res = callee(p, in...);
		}
		return *this;
	}
	
	void equals(OUT&& out) {
		if (equals(out, res)) {
			if (!show_error_only)
				std::cout << "✅ " << res << " == " << out << std::endl;
		} else {
			std::cout << "❌ " << res << " != " << out << std::endl;
		}
	}
	
	OUT& lastResult() {
		return res;
	}
	
private:
	bool areEqualRel(float a, float b, float epsilon=1e-5) {
		return (fabs(a - b) <= epsilon * std::max(fabs(a), fabs(b)));
	}
	
	bool equals(is_sortable auto& a, is_sortable auto& b) {
		if (unordered_result) {
			std::sort(a.begin(), a.end());
			std::sort(b.begin(), b.end());
		}
		return a == b;
	}
	
	bool equals(OUT& a, OUT& b) {
		if constexpr (std::is_same_v<OUT, ListNode*> || std::is_same_v<OUT, TreeNode*>) {
			return is_equal(a, b);
		} else if constexpr (std::is_floating_point_v<OUT>) {
			return areEqualRel(a, b);
		} else {
			return a == b;
		}
	}

	
};
	
class Codec {
public:
	int nullnum = -131313;
	int stopnum = -242424;
	// Encodes a tree to a single string.
	std::string serialize(TreeNode* root) {
		if (root == nullptr)
			return "[]";
		std::vector<int> v;
		std::queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			if (t != nullptr) {
				v.push_back(t->val);
				q.push(t->left);
				q.push(t->right);
			} else {
				v.push_back(nullnum);
			}  
		}
		while (v.back() == nullnum) {
			v.pop_back();
		}
		std::string res = "[";
		for (int a: v) {
			if (a != nullnum) {
				res += std::to_string(a);
			} else {
				res += "null";
			}
			res += ",";
		}
		res.back() = ']';
		// cout << res << " ";
		return res;
	}
	
	// Decodes your encoded data to tree.
	TreeNode* deserialize(const std::string data) {
		assert(data.size() >= 2 && data.front() == '[' && data.back() == ']');
		// cout << fmt::format("data={}", data) << endl;
		if (data[1] == ']')
			return nullptr;
		
		auto nextnum = [&,i=1ul]() mutable {
			while (i < data.size()) {
				try {
					size_t j;
					int v = stoi(data.substr(i), &j);
					// cout << fmt::format("v={}; ", v);
					i += j+1;
					return v;
				} catch (std::invalid_argument const& e) {
					i += 5;
					return nullnum;
				}
			}
			return stopnum;
		};
		
		TreeNode* root = new TreeNode(nextnum());
		std::queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			int lv = nextnum();
			int rv = nextnum();
			if (lv == stopnum)
				break;
			if (lv != nullnum) {
				t->left = new TreeNode(lv);
				q.push(t->left);
			}
			if (rv == stopnum)
				break;
			if (rv != nullnum) {
				t->right = new TreeNode(rv);
				q.push(t->right);
			}
		}
		
		return root;
	}
};
	
static
std::ostream& operator<<(std::ostream& os, TreeNode* root) {
	os << Codec().serialize(root) << std::endl;
	return os;
}
	
static TreeNode* tree_from(const std::string& s) {
	return Codec().deserialize(s);
}

static bool is_equal(TreeNode* a, TreeNode* b) {
	return Codec().serialize(a) == Codec().serialize(b);
}

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

static
auto operator"" _tree(const char* s, const size_t len) {
	return LT::tree_from(s);
}

using namespace std;

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