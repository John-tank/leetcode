//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
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
  vector<vector<int>> threeSum(vector<int>& nums) 
  {

    vector<vector<int>> result;

    sort(nums.begin(), nums.end());    

    int num_size = nums.size();
    if (num_size < 3)
    {
      return result;
    }

    int last_num = 1; //> 0即可

    for (int index = 0;index < num_size - 2;++ index)
    {
      if (nums[index] > 0)
      {
        break;
      }

      if (nums[index] == last_num)
      {
        continue;
      }
      last_num = nums[index];

      twoSum(nums, index + 1, -last_num, result);
    }

    return result;
  }

  void twoSum(vector<int>& nums, int start_index, int target, vector<vector<int>>& res)
  {
    int end_index = nums.size() - 1;

    while (end_index > start_index)
    {
      if (nums[start_index] + nums[end_index] == target)
      {
        res.push_back({-target, nums[start_index], nums[end_index]});
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
  std::vector<int> nums = {-1, -3, 1, 2, 3};
  
  vector<vector<int>> ret = solution.threeSum(nums);
  
  for (auto &v_ret : ret)
  {
    std::cout<<"[";
    for (auto &ret_val:v_ret)
    {
      std::cout<<ret_val<<",";
    }
    std::cout<<"]"<<std::endl;
  }

  return 0;
}