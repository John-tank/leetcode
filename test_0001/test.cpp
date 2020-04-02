//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
*/

#include <iostream>
#include <vector>
using namespace std;
//可以考虑hash算法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int first_index = 0;
        int second_index = 1;
        int length = nums.size();
        for (;first_index < length - 1;++first_index)
        {
            second_index=first_index + 1;
            for (;second_index < length ;++second_index)
            {
                if (target == nums[first_index] + nums[second_index])
                {
                    return {first_index, second_index};
                }
            }
        }

        return {};
    }
};

int main()
{
  std::vector<int> v_number = {2,7,11,15};

  Solution solution;

  std::vector<int> result = solution.twoSum(v_number, 9);

  if (!result.empty())
  {
    std::cout<<"result first index["<<result[0]<<"] second index["<<result[1]<<"];"<<std::endl;
  }
  else
  {
    std::cout<<"ret null"<<std::endl;  
  }
  
  return 0;
}