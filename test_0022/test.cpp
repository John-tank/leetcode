//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
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
class Solution
{
public:

  vector<string> generateParenthesis(int n) 
  {
    std::vector<std::string> result;

    
  }
};

int main()
{
  Solution solution;
  
  bool ret = solution.isValid("())");
  
  std::cout<<"ret value["<<ret<<"]"<<std::endl;

  return 0;
}