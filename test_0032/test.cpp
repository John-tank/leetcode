//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-valid-parentheses
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
  int search(vector<int>& nums, int target)
  {
    if (nums.empty())
    {
      return -1;
    }

    if (nums.size() == 0)
    {
      if (nums[0] == target)
      {
        return 0;
      }

      return -1;
    }

    int start_index = 0;
    int end_index = nums.size() - 1;
    int mid_index = 0;

    while (start_index <= end_index)
    {
      mid_index = (start_index + end_index) >> 1;
      if (nums[mid_index] == target) 
      {
        return mid_index;
      }      

      // //表明顺序
      // if (nums[start_index] <= nums[mid_index])
      // {
      //   if (nums[start_index] <= target && target < nums[mid_index])
      //   {
      //     end_index = mid_index - 1;
      //   }
      //   else
      //   {
      //     start_index = mid_index + 1;
      //   }
      // }
      // else
      // {
      //   //右侧顺序
      //   if (nums[mid_index] < target && target <= nums[end_index])
      //   {
      //     start_index = mid_index + 1;
      //   }
      //   else
      //   {
      //     end_index = mid_index - 1;
      //   }
      // }
      //比较顺序部位，非顺序部分作为else分支，即只有顺序部分不满足时，才会进行非顺序部分

      if (nums[start_index] <= nums[mid_index]) //左部顺序
      {
        if (nums[start_index] <= target && target < nums[mid_index])
        {
          end_index = mid_index - 1;
        }
        else
        {
          start_index = mid_index + 1;
        }
      }
      else //右部顺序
      {
        if (nums[end_index] >= target && target < nums[mid_index])
        {
          start_index = mid_index - 1;
        }
        else
        {
          end_index = mid_index + 1;
        }
      }
      // else
      // {
      //   //右侧顺序
      //   if (nums[mid_index] < target && target <= nums[end_index])
      //   {
      //     start_index = mid_index + 1;
      //   }
      //   else
      //   {
      //     end_index = mid_index - 1;
      //   }
      // }
    }

    return -1;
  }



};

int main()
{
  Solution solution;
  
  vector<int> nums = {1,3};

  int ret = solution.search(nums, 2);
  
  std::cout<<"ret:["<<ret<<"]"<<std::endl;

  return 0;
}