//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits.h>
#include <algorithm>

using namespace std;
class Solution
{
public:
  int threeSumClosest(vector<int>& nums, int target)
  {

    vector<vector<int>> result;

    sort(nums.begin(), nums.end());    

    int num_size = nums.size();
    if (num_size < 3)
    {
      return 0;
    }

    int min_diss = INT_MAX; //最小值

    for (int index = 0;index < num_size - 2;++ index)
    {
      int diss = nums[index] + twoSumClosest(nums, index + 1, target - nums[index]) - target;
      if (abs(min_diss) > abs(diss))
      {
        min_diss = diss;
      }

      while (index < num_size - 2 && nums[index] == nums[index + 1])
      {
        ++ index;
      }
    }

    return target + min_diss;
  }

  int twoSumClosest(vector<int>& nums, int start_index, int target)
  {
    int end_index = nums.size() - 1;
    int value = 0;
    int min_diss = INT_MAX;

    while (end_index > start_index)
    {
      value = nums[start_index] + nums[end_index];
      if (value == target)
      {
        return value;
      }
      else if (abs(value - target) < abs(min_diss))
      {
        min_diss = value - target;
      }
      
      if (value - target > 0)
      {
        -- end_index;
      }
      else
      {
        ++ start_index;
      }

    }

    return min_diss + target;
  }
};

int main()
{
  Solution solution;
  std::vector<int> nums = {-1, -3, 1, 2, 3};
  
  int ret = solution.threeSumClosest(nums, 1);
  
  std::cout<<"ret value["<<ret<<"]"<<std::endl;

  return 0;
}