//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

示例 :

输入: [1,2,1,3,2,5]
输出: [3,5]
注意：

结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-iii
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
  vector<int> singleNumber(vector<int>& nums)
  {
    vector<int> res(2,0);
    int ret = 0;

    for (auto iter : nums)
    {
      ret = ret ^ iter;
    }

    int k = ret & (-ret);
    for(int num : nums)
    {
      if(num & k)
      {
        //第二组
        res[0] ^= num;
      }
      else
      {
        //第一组
        res[1] ^= num;
      }
    }

    return res;
  }
  

};

int main()
{
  Solution solution;
  
  vector<int> candidates = {1,2,1,3,2,5};

  vector<int> ret = solution.singleNumber(candidates);
  
  std::cout<<"ret value["<<ret[0]<<","<<ret[1]<<"]!"<<std::endl;

  return 0;
}