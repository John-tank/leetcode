/*
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

class Solution 
{
public:
  int majorityElement(std::vector<int>& nums) 
  {
    std::unordered_map<int, int> element_cnt;

    int majority = 0, cnt = 0;
    for (auto num : nums)
    {
      ++ element_cnt[num]; //初始值设置为0 
      if (cnt  < element_cnt[num])
      {
        cnt = element_cnt[num];
        majority = num;
      } 
    }

    return majority;
  }
};

int main()
{
  std::vector<int> vec_nums = {1,2,3,4,4,4,4,4,4,4,6,7};
  Solution solution;

  std::cout<<"Solution.majorityElement return["<< solution.majorityElement(vec_nums) <<"]" <<std::endl;

  return 0;
}