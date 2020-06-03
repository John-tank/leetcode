//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,3,2]
输出: 3
示例 2:

输入: [0,1,0,1,0,1,99]
输出: 99

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-ii
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
#include <stdint.h>

using namespace std;
class Solution {
public:
  int singleNumber(vector<int>& nums)
  {
    int res = 0;
    int tmp = 0; //上一次状态

    for (auto iter : nums)
    {
      res = ~tmp & (res ^ iter);
      tmp = ~res & (tmp ^ iter);
    }

    return res;
  }
  

};

int main()
{
  Solution solution;
  
  vector<int> candidates = {1,1,1,0};

  int ret = solution.singleNumber(candidates);
  
  std::cout<<"ret value["<<ret<<"]!"<<std::endl;

  return 0;
}