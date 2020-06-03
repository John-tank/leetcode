//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。

给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。

 

示例 1：

输入：A = [1,2,0,0], K = 34
输出：[1,2,3,4]
解释：1200 + 34 = 1234
示例 2：

输入：A = [2,7,4], K = 181
输出：[4,5,5]
解释：274 + 181 = 455
示例 3：

输入：A = [2,1,5], K = 806
输出：[1,0,2,1]
解释：215 + 806 = 1021
示例 4：

输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1
输出：[1,0,0,0,0,0,0,0,0,0,0]
解释：9999999999 + 1 = 10000000000
 

提示：

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
如果 A.length > 1，那么 A[0] != 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-to-array-form-of-integer
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
  vector<int> addToArrayForm(vector<int>& A, int K) 
  {
    if (K == 0)
    {
      return A;
    }

    int index = A.size() - 1;
    while (K > 0 || index >= 0)
    {
      int tmp = K % 10;
      K = K / 10;

      if (index <= 0)
      {
        A.insert((vector<int>::iterator)A.begin(), 0);
        A[1] += tmp;
        if (A[1] > 9)
        {
          A[0] = 1;
          A[1] -= 10;
        } 
        index --;
        continue;
      }
      else
      {
        A[index] += tmp;
        if (A[index] > 9)
        {
          A[index - 1] += 1;
          A[index] -= 10;
        } 
        index --;
      }
    }

    if (A[0] == 0)
    {
      A.erase(A.begin());
    }

    return A;
  }

};

int main()
{
  Solution solution;
  
  vector<int> vec = {9,9,9};

  vector<int> ret = solution.addToArrayForm(vec, 1);
  
  std::cout<<"ret value[";
  for (auto &iter : ret)
  {
    std::cout<<iter<<",";
  }

  std::cout<<"]!"<<std::endl;
  return 0;
}