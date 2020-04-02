//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>

using namespace std;
class Solution
{
public:
  int reverse(int x)
  {
    int result = 0;

    while (x != 0)
    {
      int pop = (x % 10);
      if (result > INT_MAX/10 || (result == INT_MAX / 10 && pop > 7)) return 0;
      if (result < INT_MIN/10 || (result == INT_MIN / 10 && pop < -8)) return 0;
      
      result = result * 10 + pop;
      x = x / 10;
    }

    return result;
  }
    
};

int main()
{
  Solution solution;
  
  int ret = solution.reverse(-89);
  
  std::cout<<"ret value["<<ret<<"]"<<std::endl;

  return 0;
}