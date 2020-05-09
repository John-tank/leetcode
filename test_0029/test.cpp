//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

 

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
解释: 7/-3 = truncate(-2.33333..) = -2
 

提示：

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-two-integers
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
    int divide(int dividend, int divisor) {
        int64_t abs_dividend = abs(dividend);
    int64_t abs_divisor = abs(divisor);

    int64_t tail_divisor = abs_divisor;
    int64_t tail_quotient = 1;
    int sign = 0;
    int64_t res = 0;

    if (tail_divisor > abs_dividend)
    {
      return 0;
    }

    if ((abs_dividend != dividend && abs_divisor != divisor) || (abs_dividend == dividend && abs_divisor == divisor) )
    {
      sign = 1;
    }

    while (tail_divisor < abs_dividend)
    {
      tail_divisor = tail_divisor << 1;
      tail_quotient = tail_quotient << 1;
    }

    while (abs_dividend >= abs_divisor)
    {
      if (tail_divisor > abs_dividend)
      {
        tail_divisor = tail_divisor >> 1;
        tail_quotient = tail_quotient >> 1;
        continue;
      }

      abs_dividend -= tail_divisor;
      res += tail_quotient;
    }

    if(sign == 0)
    {
      if(-res < INT_MIN) return INT_MIN;
        else return -res;
    }
    else
    {
      if(res > INT_MAX) return INT_MAX;
        else return res;
    }
    }
};

int main()
{
  Solution solution;
  
  int ret = solution.divide(1, 1);
  
  std::cout<<"ret:["<<ret<<"]"<<std::endl;

  return 0;
}