//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
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
  void Quick(vector<int>& a, int start, int end)
  {
    if (start >= end) return;
    int i = start;
    int j = end;
    int temp = a[i];
    while (i < j)
    {
      while (i < j && a[j] >= temp) j--;
      while (i < j && a[i] <= temp) i++;
      swap(a[i],a[j]);
    }

    swap(a[i],a[start]);
    Quick(a,start,i-1);
    Quick(a,i+1,end);
  }

  void nextPermutation(vector<int>& nums) 
  {
    int N = nums.size();
    int i = N - 1;
    //找到num[i] > nums[i - 1]的索引i
    while (i > 0)
    {
      if (nums[i] <= nums[i-1]) i--;
      else break;
    }
    //如果i指向了第一个元素，则证明此时是字典排序的最后一个，也证明此时数组是降序排列，应该输出整体升序排列
    if (i == 0)
    {
      int p = 0;
      int q = N - 1;
      //这里利用双指针交换，快速完成升序排列
      while (p <= q) swap(nums[p++],nums[q--]);
      return;
    }
    int j = i;
    int SELECT = nums[i-1];
    //找到比nums[i-1]大的，最小的值并跟nums[i-1]进行交换
    while (nums[j] >= SELECT) {
    j++;
    if (j == N) break;
    }
    while (nums[j - 1] == SELECT) j--;
    swap(nums[i-1],nums[j-1]);
    //i以后进行升序排列。
    Quick(nums,i,N-1);
  }
};
int main()
{
  Solution solution;
  
  vector<int> words = {1,3,2};

  solution.nextPermutation(words);
  
  for (auto iter: words)  
  {
    std::cout<<"ret:["<<iter<<"]"<<std::endl;
  }

  return 0;
}