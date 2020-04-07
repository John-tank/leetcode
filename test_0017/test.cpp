//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstring>
#include <limits.h>
#include <algorithm>

using namespace std;
class Solution
{
public:
  // vector<string> letterCombinations(string digits)
  // {
  //   vector<string> result ;
  //   if (digits.empty())
  //   {
  //     return result;
  //   }

  //   result.push_back("");
    
  //   const char* str_arrs[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};

  //   int index = 0;
  //   while (index < digits.size())
  //   {
  //     vector<string> tmp;
  //     result.swap(tmp);
  //     char num = digits[index] - '2';
  //     if (num < 0 || num > 7)
  //     {
  //       return {};
  //     }

  //     int str_len = strlen(str_arrs[num]);
  //     result.reserve(tmp.size() * str_len);
  //     int offset_pos = 0;
  //     for (int i = 0;i < str_len ; ++i)
  //     {
  //       for (int j = 0;j < tmp.size();++j)
  //       {
  //         result.push_back(tmp[j] + str_arrs[num][i]);
  //         ++ offset_pos;
  //       }
  //     }
  //     ++ index;
  //   }

  //   return result;
  // }

  vector<string> letterCombinations(string digits)
  {
    vector<string> result ;
    if (digits.empty())
    {
      return result;
    }
    
    const char* str_arrs[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};

    int index = 0;
    int size = 1;
    while (index < digits.size())
    {
      char num = digits[index ++] - '2';
      if (num < 0 || num > 7)
      {
        return {};
      }

      size = size * strlen(str_arrs[num]);
    }

    std::string tmp;
    tmp.assign(digits.size(), ' ');
    result.assign(size, tmp);
    
    index = 0;
    int result_num = size;
    while (index < digits.size())
    {
      int num = digits[index] - '2';
      if (num < 0 || num > 7)
      {
        return {};
      }

      int str_len = strlen(str_arrs[num]);
      
      size = size / str_len;
      int result_index = 0;
      int str_index = 0;
      while (result_index < result_num)
      {
        
        for (int i = 0;i < size;++i)
        {
          result[result_index ++][index] = str_arrs[num][str_index];
        }
        ++ str_index;
        if (str_index == str_len)
        {
          str_index = 0;
        }
      }
      ++ index;

    }
  
    return result;
  }

};

int main()
{
  Solution solution;
  std::vector<string> ret;
  
  ret = solution.letterCombinations("23");
  
  for (auto &v_ret : ret)
  {
    std::cout<<"[";
    for (auto &ret_val:v_ret)
    {
      std::cout<<ret_val<<",";
    }
    std::cout<<"]"<<std::endl;
  }

  return 0;
}