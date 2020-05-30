//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

 

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
 

提示：

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-missing-positive
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
  // int firstMissingPositive(vector<int>& nums) 
  // {
  //   int max_value=nums.size();
  //   vector<int> tmp(max_value , -1);

  //   for (int i = 0; i < max_value;i++)
  //   {
  //     if (nums[i] > max_value || nums[i] <= 0)
  //     {
  //       nums[i] = -1;
  //       continue;
  //     }

  //     tmp[nums[i] - 1] = 1;
  //   }

  //   for (int i = 0;i < tmp.size();i ++)
  //   {
  //     if (tmp[i] == -1)
  //     {
  //       return i + 1;
  //     }
  //   }

  //   return max_value + 1;
  // }

  int firstMissingPositive(vector<int>& nums) 
  {
    int max_value = nums.size();

    for (int i = 0; i < max_value;i++)
    {
      if (nums[i] > max_value || nums[i] <= 0)
      {
        nums[i] = 0;
        continue;
      }

      nums[i] = nums[i] << 1;
    }

    for (int i = 0; i < max_value;i++)
    {
      int pos = nums[i] >> 1;
      if (pos == 0)
      {
        continue;
      }

      nums[pos - 1] = (nums[pos - 1] | 0x00000001);
    }

    for (int i = 0;i < max_value;i++)
    {
      int value = (nums[i] & 0x00000001);
      if (value == 0)
      {
        return i + 1;
      }
    }

    return max_value + 1;
  }

};

int main()
{
  Solution solution;
  
  vector<int> candidates = {1,2,0};

  int ret = solution.firstMissingPositive(candidates);
  
  std::cout<<"ret value["<<ret<<"]!"<<std::endl;

  return 0;
}