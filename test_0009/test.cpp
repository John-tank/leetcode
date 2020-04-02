//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？

最简单的就是将它转换为字符串，再反序输出，在此基础上对比两字符串是否相等即可
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
  bool isPalindrome(int x) 
  {
    int64_t origin_value = x;
    int64_t reserve_value = 0;

    if (x < 0)
    {
      return false;
    }

    while (origin_value > 0)
    {
      reserve_value = ((reserve_value << 3) + (reserve_value << 1)) + origin_value % 10;
      origin_value = origin_value / 10;
    } 

    if (reserve_value == x)
    {
      return true;
    }

    return false;       
  }
};

int main()
{
  Solution solution;
  
  int ret = solution.isPalindrome(10);
  
  std::cout<<"ret value["<<ret<<"]"<<std::endl;

  return 0;
}