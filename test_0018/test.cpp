//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstring>
#include <limits.h>
#include <algorithm>

using namespace std;
class Solution
{
public:

  vector<vector<int>> fourSum(vector<int>& nums, int target)
  {
    vector<vector<int>> result;
    int num_size = nums.size();

    if (num_size < 4)
    {
      return result;
    }
    sort(nums.begin(), nums.end());    

    int first_last_num = INT_MAX;
    
    for (int i = 0;i < num_size - 3;++ i)
    {
      if (nums[i] == first_last_num)
      {
        continue;
      }

      if (nums[i] + nums[i + 1] + nums[i + 3] + nums[i + 2] >  target 
            || nums[i] + nums[num_size - 3] + nums[num_size - 1] + nums[num_size - 2] < target)
      {
        continue;
      }

      first_last_num = nums[i];
      int second_last_num = INT_MAX;
      for (int j = i + 1;j < num_size - 2;++ j)
      {
        if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] >  target 
            || nums[i] + nums[j] + nums[num_size - 1] + nums[num_size - 2] < target)
        {
            continue;
        }
        if (nums[j] == second_last_num)
        {
          continue;
        }
        second_last_num = nums[j];

        twoSum(nums, j + 1, nums[i], nums[j], target, result);
      }
    }

    return result;
  }

  void twoSum(vector<int>& nums, int start_index, int val1, int val2, int target_val, vector<vector<int>>& res)
  {
    int end_index = nums.size() - 1;
    int target = target_val - val2 - val1;

    while (end_index > start_index)
    {
      if (nums[start_index] + nums[end_index] == target)
      {
        res.push_back({val1, val2, nums[start_index], nums[end_index]});
        int val = nums[start_index];
        while (end_index > start_index && nums[start_index] == val)
        {
          ++ start_index;
        }
        
        val = nums[end_index];
        while (end_index > start_index && nums[end_index] == val)
        {
          -- end_index;
        }
      }
      else if (nums[start_index] + nums[end_index] > target)
      {
        -- end_index;
      }
      else if (nums[start_index] + nums[end_index] < target)
      {
        ++ start_index;
      }
    }

    return ;
  }
};

int main()
{
  Solution solution;
  std::vector<int> nums = {1, -2, -5, -4, -3, 3, 3, 5};
  
  vector<vector<int>> ret = solution.fourSum(nums, -11);
  
  for (auto &v_ret : ret)
  {
    std::cout<<"[";
    for (auto &ret_val:v_ret)
    {
      std::cout<<ret_val<<",";
    }
    std::cout<<"]"<<std::endl;
  }
}