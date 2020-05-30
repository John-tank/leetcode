//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
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
private:
  vector<int> candidates;
  vector<vector<int>> res;
  vector<int> path;
public:
  void DFS(int start, int target) 
  {
    if (target == 0) 
    {
      res.push_back(path);
      return;
    }

    for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) 
    {
      if (i > start && candidates[i] == candidates[i - 1])
      {
        continue;
      }
      path.push_back(candidates[i]);
      DFS(i + 1, target - candidates[i]);
      path.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) 
  {
    std::sort(candidates.begin(), candidates.end());
    this->candidates = candidates;
    DFS(0, target);

    return res;
  }

};

int main()
{
  Solution solution;
  
  vector<int> candidates = {10,1,2,7,6,1,5};

  vector<vector<int>> ret = solution.combinationSum(candidates, 8);
  
  for (auto &iter : ret)
  {
    
    for (auto &num : iter)
    {
      std::cout<<num<<",";
    }
    std::cout<<std::endl;
  }

  return 0;
}