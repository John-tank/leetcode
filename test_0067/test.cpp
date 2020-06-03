//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

 

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
 

提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
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
  // string addBinary(string a, string b)
  // {
  //   int a_index = a.length() - 1;
  //   int b_index = b.length() - 1;

  //   int res_len = max(a_index, b_index) + 2;

  //   std::string res(res_len, '0');
    

  //   for (int index = res_len - 1;index >0;index--)
  //   {
  //     char a_val = '0';
  //     char b_val = '0';
  //     if (a_index >= 0)
  //     {
  //       a_val = a[a_index --];
  //     }

  //     if (b_index >= 0)
  //     {
  //       b_val = b[b_index --];
  //     }

  //     char tmp =  res[index] - '0' + a_val - '0' + b_val; 
  //     if (tmp == '3')
  //     {
  //       res[index] = '1';
  //       res[index - 1] = '1';
  //     }
  //     else if (tmp == '2')
  //     {
  //       res[index] = '0';
  //       res[index - 1] = '1';
  //     }
  //     else
  //     {
  //       res[index] = tmp;
  //     }
  //   }

  //   if (res[0] == '0')
  //   {
  //     return res.substr(1);
  //   }

  //   return res;
  // }

  string addBinary(string a, string b)
  {
    int a_index = a.length() - 1;
    int b_index = b.length() - 1;

    int res_len = max(a_index, b_index) + 2;

    std::string res(res_len, '0');
    

    for (int index = res_len - 1;index >0;index--)
    {
      char a_val = '0';
      char b_val = '0';
      if (a_index >= 0)
      {
        a_val = a[a_index --];
      }

      if (b_index >= 0)
      {
        b_val = b[b_index --];
      }

      char tmp =  res[index] - '0' + a_val - '0' + b_val - '0'; 
      res[index] = (tmp &0x01) + '0';
      res[index - 1] = (tmp >> 1) + '0';
    }

    if (res[0] == '0')
    {
      return res.substr(1);
    }

    return res;
  }

};

int main()
{
  Solution solution;
  
  string a = "101101";
  string b = "101101";

  string ret = solution.addBinary(a, b);
  
  std::cout<<"ret value[" << ret <<"]!"<<std::endl;
  return 0;
}