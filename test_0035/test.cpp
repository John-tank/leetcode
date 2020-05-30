//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-insert-position
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
  int searchInsert(vector<int>& nums, int target)
  {
    if (nums.empty())
    {
      return 0;
    }

    int start_index = 0;
    int end_index = nums.size() - 1;

    if (target <= nums[0])
    {
      return 0;
    }

    if (target > nums[end_index])
    {
      return end_index + 1;
    }

    int mid_index = 0;
    while (start_index <= end_index)
    {
      mid_index = (start_index + end_index) / 2;

      if (nums[mid_index] == target)
      {
        return mid_index;
      }
      else if (nums[mid_index] < target )
      {
        start_index = mid_index + 1;
      }
      else
      {
        end_index = mid_index - 1;
      }
    }

    return start_index;
  }

};

int main()
{
  Solution solution;
  
  vector<int> nums = {1,3,5,6};

  int ret = solution.searchInsert(nums, 7);
  
  std::cout<<"ret:["<<ret<<"]"<<std::endl;

  return 0;
}