//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
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
  string longestCommonPrefix(vector<string>& strs) 
  {
    if (strs.empty())
    {
      return {};
    }

    int substr_len = strs[0].length();

    if (strs.size() == 1)
    {
      return strs[0];
    }

    for(int i = 1; i < int(strs.size()); ++i)
    {
      int index = 0;
      int len = strs[i].length();
      //int pre_len = prefix.length();
      while (index < len && index < substr_len ) 
      {
        if (strs[0][index] == strs[i][index])
        {
          ++ index;
        }
        else
        {
          break;
        }
      }
      substr_len = index;
    } 

    return strs[0].substr(0, substr_len);     
  }
};

int main()
{
  Solution solution;
  std::vector<std::string> strs = {"abc","abcde","ab", "ac"};
  
  std::string ret = solution.longestCommonPrefix(strs);
  
  std::cout<<"ret value["<<ret<<"]"<<std::endl;

  return 0;
}