//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
class Solution
{
 public:
  int lengthOfLongestSubstring(string s)
  {
    int ans = 0, i = 0, j = 0;
    int len = s.length();
    std::unordered_map<char, int> char_map;

    for (; j < len; j++)
    {
      if (char_map.find(s[j]) == char_map.end())
      {
        char_map[s[j]] = j;
      }
      else 
      {
        int tmp = char_map.find(s[j])->second + 1 ;
        for (; i < tmp;++i)
        {
          char_map.erase(s[i]);
        }
        
        char_map[s[j]] = j;
      }

      if (ans < j - i + 1)
      {
        ans = j - i + 1;
      }
    }

    return ans;        
  }
};

int main()
{
  Solution solution;
  string str = {"abba"};

  int ret = solution.lengthOfLongestSubstring(str);
  
  std::cout<<"ret value["<<ret<<"]"<<std::endl;

  return 0;
}