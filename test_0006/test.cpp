//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution
{
public:
  string convert(string s, int numRows) 
  {
    if (numRows == 1)
    {
      return s;
    }

    if (numRows < 1)
    {
      return "";
    }

    std::string result = "";
    int str_len = int(s.size());
    int group_len = numRows * 2 - 2;
    int group_cnt = str_len / group_len;
    if (str_len % group_len)
    {
      ++group_cnt;
    }

    for (int row_index = 0;row_index < numRows;++row_index)
    {
      if (row_index == 0 || row_index == numRows - 1)
      {
        int str_index = row_index - group_len;
        for (int col_index = 0;col_index < group_cnt; ++ col_index)
        {
          str_index += group_len;
          if (str_index < str_len)
          {
            result.push_back(s[str_index]);
          }
        }
      }
      else
      {
        int str_index = row_index - group_len;
        int mid_value_diff = 2 * (numRows - row_index) - 2;
        for (int col_index = 0;col_index < group_cnt ; ++ col_index)
        {
          str_index += group_len;
          if (str_index < str_len)
          {
            result.push_back(s[str_index]);
          }

          int tmp = str_index + mid_value_diff ;
          if (tmp < str_len)
          {
            result.push_back(s[tmp]);
          }
        }
      }
    }
    return result;
  }
    
};

int main()
{
  Solution solution;
  std::string str = {"LEETCODEISHIRING"};
  std::string ret = solution.convert(str, 3);
  
  std::cout<<"ret value["<<ret<<"]"<<std::endl;

  return 0;
}