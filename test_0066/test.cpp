//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
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
  // vector<int> plusOne(vector<int>& digits)
  // {
  //   vector<int> res(digits.size() + 1, 0);

  //   digits[digits.size() - 1] += 1;
  //   for (int i = digits.size() - 1;i >= 0;i--)
  //   {
  //     res[i+1] += (digits[i]);
  //     if (res[i+1] == 10)
  //     {
  //       res[i+1] = 0;
  //       res[i] = 1;
  //     }
  //   }

  //   if (res[0] == 0)
  //   {
  //     res.erase(res.begin());
  //   }

  //   return res;
  // }

  vector<int> plusOne(vector<int>& digits)
  {
    //digits.insert(digits.begin, 0);
    ++ digits[digits.size() - 1] ;
    int len = digits.size();
    for (int i = len - 1;i> 0;--i)
    {
      if (digits[i] == 10)
      {
        digits[i] = 0;
        ++ digits[i - 1] ;
        continue;
      }

      break;
    }

    if (digits[0] == 10)
    {
      digits.insert((vector<int>::iterator)digits.begin(), 1);
      digits[1] = 0;
    }

    return digits;
  }

};

int main()
{
  Solution solution;
  
  vector<int> candidates = {9,9};

  vector<int> ret = solution.plusOne(candidates);
  
  std::cout<<"ret value[";
  for (auto &iter : ret)
  {
    std::cout<<iter<<",";
  }

  std::cout<<"]!"<<std::endl;

  return 0;
}