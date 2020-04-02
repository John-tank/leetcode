//
//  test.cpp
//  
//
//  Created by John  .
//
/*
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。
你可以假设字符串中只包含大小写英文字母（a至z）。
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution 
{
 public:
  string compressString(string S) 
  {
    if (S.empty())
    {
      return S;
    }    

    std::string ans = {""};
    char cur_char = S[0];
    int cnt = 1;

    for (int index = 1;index < S.length();++index)
    {
      if (S[index] != cur_char)
      {
        ans += cur_char + to_string(cnt);
        cur_char = S[index];
        cnt = 1;
      }
      else
      {
        cnt ++;
      }
    }
    
    ans += cur_char + to_string(cnt);

    if (ans.size() >= S.size())
    {
        return S;
    }

    return ans;
  }
};

int main()
{
  std::string str_val = {"aabcccccaa"};

  Solution solution;
  std::string str_compress = solution.compressString(str_val);

  std::cout<< "str_compress [" << str_compress <<"]"<<std::endl;

  return 0;
}