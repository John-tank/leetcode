//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <cstring>
#include <limits.h>
#include <algorithm>

using namespace std;
class Solution {
public:
  int strStr(string haystack, string needle)
  {
    if (needle.empty())
    {
      return 0;
    }

    if (haystack.empty())
    {
      return -1;
    }

    //next 数组
    vector<int> v_next(needle.size() + 1, -1);
    int index = 0;
    int needle_len = needle.length();
    int k = -1;
    while (index < needle_len)
    {
      if (k == -1 || needle[index] == needle[k])
      {
        index++;
        k++;
        if (needle[index] == needle[k])
        {
          v_next[index] = v_next[k];
        }
        else
        {
          v_next[index] = k;
        }
      }
      else
      {
        k = v_next[k];
      }
    }

    //比较 
    int i = 0;
    int j = 0;

    while (i < haystack.size() && j < needle_len)
    {
      if (j == -1 || haystack[i] == needle[j])
      {
        i++;
        j++;
      }
      else
      {
        j = v_next[j];
      }
    }

    if (j == needle_len)
    {
      return i - j;
    }
    
    return -1;
  }


};

int main()
{
  Solution solution;
  
  int ret = solution.strStr({"hello"}, "ll");
  
  std::cout<<"ret:["<<ret<<"]"<<std::endl;

  return 0;
}