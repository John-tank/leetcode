//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*

寻找两个有序数组的中位数

给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution
{
public:

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
  {
    int medianIndex = (nums1.size() + nums2.size()) / 2 + (nums1.size() + nums2.size()) % 2 - 1;
    int medianRange = (nums1.size() + nums2.size() + 1) % 2 + 1;
    int first_len = nums1.size();
    int second_len = nums2.size();
    double result = 0;
    int first_index = 0;
    int second_index = 0;

    for (int i = 0; i < medianIndex; ++i)
    {
      if (first_index < first_len && second_index < second_len)
      {
        if (nums1[first_index] < nums2[second_index] )
        {
          first_index ++;
        }
        else
        {
          second_index ++;
        }
      }
      else if (first_index >= first_len && second_index < second_len)
      {
        second_index ++;
      }
      else if (first_index < first_len && second_index >= second_len)
      {
        first_index ++;
      }
    }

    if (first_index < first_len && second_index < second_len)
    {
      if (nums1[first_index] < nums2[second_index] )
      {
        result = nums1[first_index ++];
      }
      else
      {
        result = nums2[second_index ++];
      }
    }
    else if (first_index >= first_len && second_index < second_len)
    {
      result = nums2[second_index ++];
    }
    else if (first_index < first_len && second_index >= second_len)
    {
      result = nums1[first_index ++];
    }

    if (medianRange == 1)
    {
      return result;
    }

    if (first_index < first_len && second_index < second_len)
    {
      if (nums1[first_index] < nums2[second_index] )
      {
        result += nums1[first_index ++];
      }
      else
      {
        result += nums2[second_index ++];
      }
    }
    else if (first_index >= first_len && second_index < second_len)
    {
      result += nums2[second_index ++];
    }
    else if (first_index < first_len && second_index >= second_len)
    {
      result += nums1[first_index ++];
    }

    return (result / 2);

  }
};

int main()
{
  Solution solution;
  std::vector<int > nums1 = {1,2,3,4,5,6};
  std::vector<int > nums2 = {1,2,3,4,5,6};

  double ret = solution.findMedianSortedArrays(nums1, nums2);
  
  std::cout<<"ret value["<<ret<<"]"<<std::endl;

  return 0;
}