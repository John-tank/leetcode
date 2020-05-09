//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

 

示例 1：

输入：
  s = "barfoothefoobarman",
  words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2：

输入：
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
输出：[]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words
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
public:
  vector<int> findSubstring(string s, vector<string>& words)
  {
    if (words.empty())
    {
      return {};
    }

    int str_len = s.length();
    int word_len = words[0].length();
    int words_len = word_len * words.size();

    if (words_len > str_len)
    {
      return {};
    }
        
    unordered_map<string, int> map_words_cnt_bak;
    for (auto &iter : words)
    {
      map_words_cnt_bak[iter] ++;
    }

    vector<int> res;
    int index = 0;
    unordered_map<string, int> map_words_cnt;
    string sub_words = "";
    while (index < word_len)
    {
      int start_pos = index;
      index ++;
      int cmp_cnt = 0;
      int offset_size = 0;
      map_words_cnt.clear();
      while (start_pos + words_len <= str_len)
      {
        //int cmp_index = 0;
        while (cmp_cnt < words.size())
        {
          sub_words = s.substr(start_pos + offset_size, word_len);
          if (map_words_cnt_bak.find(sub_words) == map_words_cnt_bak.end() || map_words_cnt[sub_words] >= map_words_cnt_bak[sub_words])
          {
            break;
          }

          map_words_cnt[sub_words] ++;
          cmp_cnt++;
          offset_size += word_len;
        }

        if (map_words_cnt == map_words_cnt_bak)
        {
          res.push_back(start_pos);
        }

        if (map_words_cnt_bak.find(sub_words) == map_words_cnt_bak.end())
        {
          map_words_cnt.clear();
          start_pos += (offset_size + word_len);
          cmp_cnt = 0;
          offset_size = 0;
        }
        else
        {
          sub_words = s.substr(start_pos, word_len);
          map_words_cnt[sub_words] --;
          start_pos += word_len;
          offset_size -= word_len;
          cmp_cnt --;
        }
      }
    }
    return res;      
  }
};

int main()
{
  Solution solution;
  
  vector<string> words = {"word", "good", "best", "good"};

  vector<int> ret = solution.findSubstring("wordgoodgoodgoodbestword", words);
  
  for (auto iter: ret)  
  {
    std::cout<<"ret:["<<iter<<"]"<<std::endl;
  }

  return 0;
}