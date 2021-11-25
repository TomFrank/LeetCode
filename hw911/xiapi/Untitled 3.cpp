#include <string>
using namespace std;

class Solution {
public:
	/**
	* Note: 类名、方法名、参数名已经指定，请勿修改
	*
	* 
	* 
	* @param src string字符串 输入字符串
	* @param match string字符串 查找字符串
	* @param replace string字符串 替换字符串
	* @return string字符串
	*/
	string FindAndReplace(string src, string match, string replace) {
		// write code here
		if (src.empty() || match.empty()) return src;
		
		string ret = src;
		int j = 0;
		while ((j = src.find(match)) != string::npos) {
			ret.replace(j, match.size(), replace);
			j += replace.size();
		}
		return ret;
	}
};


int main(int argc, char *argv[]) {
	
}