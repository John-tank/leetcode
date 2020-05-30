//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
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
  // vector<int> searchRange(vector<int>& nums, int target) 
  // {
  //   int i = 0, j = nums.size() - 1;
  //   while(i <= j) 
  //   {
  //     int m = (i + j) / 2;
  //     if(nums[m] <= target) i = m + 1;
  //     else j = m - 1;
  //   }
    
  //   int right = i;
  //   // 若数组中无 target ，则提前返回
  //   if(j >= 0 && nums[j] != target) return {-1, -1};
  //   if(j < 0) return {-1, -1};
  //   // 搜索左边界 right
  //   i = 0; j = nums.size() - 1;
  //   while(i <= j) {
  //     int m = (i + j) / 2;
  //     if(nums[m] < target) i = m + 1;
  //     else j = m - 1;
  //   }
  //   int left = j;
  //   return {left + 1, right - 1};
  // }

  // int searchRangeLeft(vector<int>& nums, int target) 
  // {
  //   int left_index = 0;
  //   int right_index = 0;
  //   int index_head = 0;
  //   int index_tail = nums.size() - 1;

  //   if (nums.empty())
  //   {
  //     return -1;
  //   }

  //   //left index
  //   int mid_index = 0;
  //   while (index_head <= index_tail)
  //   {
  //     mid_index = (index_head + index_tail) / 2;
  //     if (nums[mid_index] < target)
  //     {
  //       index_head = mid_index + 1;
  //       continue;
  //     }
  //     else if (nums[mid_index] > target)
  //     {
  //       index_tail = mid_index - 1;
  //       continue;
  //     }
  //     else if (nums[mid_index] == target)
  //     {
  //       index_tail = mid_index; //不去收紧，当然需要特殊处理index index + 1情况
  //       if (index_tail - 1 <= index_head) //出口，特殊情况
  //       {
  //         if (nums[index_head] == target)
  //         {
  //           mid_index --;
  //         }

  //         break;
  //       }
  //     }
  //   }

  //   if (nums[mid_index] == target)
  //   {
  //     left_index = mid_index;
  //   }
  //   else
  //   {
  //     return -1;
  //   }

  //   return left_index;
  // }

  vector<int> searchRange(vector<int>& nums, int target) 
  {
    if (nums.empty())
    {
      return {-1, -1};
    }

    int left_index = 0;
    int right_index = 0;
    int index_head = 0;
    int index_tail = nums.size() - 1;

    //find left index
    int mid_index = 0;
    while (index_head <= index_tail)
    {
      mid_index = (index_head + index_tail) / 2;
      if (nums[mid_index] < target)
      {
        index_head = mid_index + 1;
      }
      else if (nums[mid_index] > target)
      {
        index_tail = mid_index - 1;
      }
      else //==
      {
        index_tail = mid_index;
        if (index_tail - 1 <= index_head) //出口，特殊情况
        {
          if (nums[index_head] == target)
          {
            mid_index = index_head;
          }
          break;
        }
      }
    }

    if (nums[mid_index] == target)
    {
      left_index = mid_index;
    }
    else
    {
      return {-1, -1};
    }

    index_head = left_index;
    index_tail = nums.size() - 1;
    
    while (index_head <= index_tail)
    {
      mid_index = (index_head + index_tail) / 2;
      // if (nums[mid_index] < target) //不可能存在
      // {
      //   index_tail = mid_index - 1;
      // }
      if (nums[mid_index] > target)
      {
        index_tail = mid_index - 1;
      }
      else //==
      {
        index_head = mid_index;
        if (index_tail - 1 <= index_head) //出口，特殊情况
        {
          if (nums[index_tail] == target)
          {
            mid_index=index_tail;
          }
          break;
        }
      }
    }

    right_index = mid_index;

    return {left_index, right_index};
  }

};

int main()
{
  Solution solution;
  
  vector<int> nums = {2,2};

  vector<int> ret = solution.searchRange(nums, 2);
  
  std::cout<<"ret:["<<ret[0] << ", " <<ret[1]<<"]"<<std::endl;

  return 0;
}