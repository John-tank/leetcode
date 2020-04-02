//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

 



图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

 

示例：

输入：[1,8,6,2,5,4,8,3,7]
输出：49

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
* 想用暴力法解题，即计算每一种可能的值，找到最大值，复杂度为O（n^2）,后面考虑优化问题假设ai 与aj（i < j）是目前面积最大的，假定ai < aj,那么将aj 想ai方向移动，所有值均小于等于ai 与aj面积（推论1）
  ，那么我们可以认为这种情况下，aj不需要向ai移动。对于是否存在ak 和aq，ak在ai之前，aq在ai与aj之间，如果我们从i=0，j为末尾开始推断，根据推论1得到不可能存在这种情况
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;
class Solution
{
public:
  int maxArea(vector<int>& height) 
  {
    int areaSize = 0;
    int left_index = 0, right_index = height.size() - 1;

    if (right_index <= 0)
    {
      return 0;
    }

    while (left_index < right_index)
    { 
      if (height[left_index] < height[right_index])
      {
        int tmp = height[left_index] * (right_index - left_index);
        areaSize = (tmp > areaSize)? tmp:areaSize;
        ++ left_index; 
      }
      else
      {
        int tmp = height[right_index] * (right_index - left_index);
        areaSize = (tmp > areaSize)? tmp:areaSize;
        -- right_index; 
      }
    }

    return areaSize;
  }

};

int main()
{
  Solution solution;
  std::vector<int > height = {1,2,3,4,5,6,7,8,8,7,6,5,4,3,2,1};
  
  int ret = solution.maxArea(height);
  
  std::cout<<"ret value["<<ret<<"]"<<std::endl;

  return 0;
}