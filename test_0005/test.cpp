//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution
{
public:
  string longestPalindrome(string s)
  {
    int len = s.length();

    if (len < 2)
    {
      return s;
    }

    std::vector<int> v_even_palindrome_start_index; //偶数
    std::vector<int> v_odd_palindrome_start_index; //奇数

    int even_palindrome_start_index = 0;
    int even_palindrome_len = 0;
    int odd_palindrome_start_index = 0;
    int odd_palindrome_len = 1;

    for (int i = 0;i < len ; ++i)
    {
      v_odd_palindrome_start_index.push_back(i);
    }

    v_even_palindrome_start_index = v_odd_palindrome_start_index;

    while (! v_even_palindrome_start_index.empty())
    {
      GetEvenLongerPalindromeSubstr(s, v_even_palindrome_start_index, even_palindrome_len, len);
      if (! v_even_palindrome_start_index.empty())
      {
        even_palindrome_len +=2;
        even_palindrome_start_index = v_even_palindrome_start_index[0];
      }
    }

    while (! v_odd_palindrome_start_index.empty())
    {
      GetOddLongerPalindromeSubstr(s, v_odd_palindrome_start_index, odd_palindrome_len, len);
      if (! v_odd_palindrome_start_index.empty())
      {
        odd_palindrome_len +=2;
        odd_palindrome_start_index = v_odd_palindrome_start_index[0];
      }
    }

    if (even_palindrome_len > odd_palindrome_len)
    {
      return s.substr(even_palindrome_start_index - even_palindrome_len / 2 + 1, even_palindrome_len);
    }
    else
    {
      return s.substr(odd_palindrome_start_index - odd_palindrome_len / 2, odd_palindrome_len);
    }
  }

  void GetOddLongerPalindromeSubstr(const string &s, std::vector<int> &v_substr_index, int substr_len, int str_len)
  {
    int prefix_len = substr_len / 2;
    if (v_substr_index.empty())
    {
      return;
    }

    for (std::vector<int>::iterator iter = v_substr_index.begin();iter != v_substr_index.end();)
    {
      if ((*iter) - prefix_len - 1 < 0 || (*iter) + prefix_len + 1 > str_len)
      {
        iter = v_substr_index.erase(iter);
        continue;
      }

      if (s[(*iter) - prefix_len - 1] != s[(*iter) + prefix_len + 1])
      {
        iter = v_substr_index.erase(iter);
        continue;
      }

      ++ iter;
    }

    return;
  }

  void GetEvenLongerPalindromeSubstr(const string &s, std::vector<int> &v_substr_index, int substr_len, int str_len)
  {
    int prefix_len = substr_len / 2;
    if (v_substr_index.empty())
    {
      return;
    }

    for (std::vector<int>::iterator iter = v_substr_index.begin();iter != v_substr_index.end();)
    {
      if ((*iter) - prefix_len < 0 || (*iter) + prefix_len + 1 > str_len)
      {
        iter = v_substr_index.erase(iter);
        continue;
      }

      if (s[(*iter) - prefix_len] != s[(*iter) + prefix_len + 1])
      {
        iter = v_substr_index.erase(iter);
        continue;
      }

      ++iter;
    }

    return;
  }
};

int main()
{
  Solution solution;
  std::string str = {"babad"};
  std::string ret = solution.longestPalindrome(str);
  
  std::cout<<"ret value["<<ret<<"]"<<std::endl;

  return 0;
}