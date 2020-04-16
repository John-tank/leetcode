//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
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

  bool isValid(string s) 
  {
    int str_len = s.length();
    if (str_len == 0)
    {
      return true;
    }

    if (str_len % 2 == 1)
    {
      return false;
    }

    std::stack<char> stack_character;
    stack_character.push(s[0]);
    for (int i = 1;i < str_len;++ i)
    {
      if (s[i] - stack_character.top() == 1 || s[i] - stack_character.top() == 2)
      {
        stack_character.pop();
      }
      else
      {
        stack_character.push(s[i]);
      }
    }

    return stack_character.empty();
  }
};

int main()
{
  Solution solution;
  
  bool ret = solution.isValid("())");
  
  std::cout<<"ret value["<<ret<<"]"<<std::endl;

  return 0;
}