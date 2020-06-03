//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
示例 2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/missing-number
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
#include <stdint.h>

using namespace std;
class Solution {
public:
  // int missingNumber(vector<int>& nums) 
  // {
  //   int max_value = nums.size();
  //   //nums.push_back(max_value + 1);

  //   int value = 0;
  //   for (int i = 0;i < max_value;i++)
  //   {
  //     nums[i] = (nums[i] << 1);
  //   }

  //   for (int i = 0;i < max_value;i++)
  //   {
  //     value = nums[i] >> 1;
  //     if (value == max_value)
  //     {
  //       continue;
  //     }
  //     nums[value] = nums[value] + 1;
  //   }

  //   for (int i = 0;i < max_value ;i++)
  //   {
  //     if ((nums[i] & 0x00000001) == 0)
  //     {
  //       return i;
  //     }
  //   }

  //   return max_value ;
  // }

  int missingNumber(vector<int>& nums) 
  {
    int res = 0;
    for (int i = 0;i <= nums.size();i++)
    {
      res += i;
    }

    for (auto iter : nums)
    {
      res -= iter;
    }

    return res;
  }
  

};

int main()
{
  Solution solution;
  
  vector<int> candidates = {1,2,0};

  int ret = solution.missingNumber(candidates);
  
  std::cout<<"ret value["<<ret<<"]!"<<std::endl;

  return 0;
}