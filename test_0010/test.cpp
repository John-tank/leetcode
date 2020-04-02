//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regular-expression-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;
class Solution
{
public:
  bool isMatch(string s, string p) 
  {
    return doMatch(s, 0, p, 0);
  }

  bool doMatch(const string& s, int sIndex, const string& p, int pIndex)
  {
    int pSize = p.size();
    int sSize = s.size();
    if (pIndex >= pSize) return sIndex >= sSize;

		bool currentMatch = sIndex < sSize && (s[sIndex] == p[pIndex] || p[pIndex] == '.');

    if(pIndex + 1 < pSize && p[pIndex + 1] == '*')
    {
			// *匹配0个字符(无论当前字符匹不匹配这都有可能s = abbc, p = ab*bbc) || 当前字符匹配并尝试s中的下一个字符
			return doMatch(s, sIndex, p, pIndex + 2) || (currentMatch && doMatch(s, sIndex + 1, p, pIndex));
    }
    else // 没有*
    {
			// 正常匹配，包括了.
      // 匹配上就考察下一个，否则 return false
			return currentMatch && doMatch(s, sIndex + 1, p, pIndex + 1);
    }
  }
};

int main()
{
  Solution solution;
  
  int ret = solution.isMatch("abbcccedf", "ab.*cedf");
  
  std::cout<<"ret value["<<ret<<"]"<<std::endl;

  return 0;
}