//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。

形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) 
    {
        int index = 0;

        if (candividedEvenlyByThree(A) == false)
        {
            return false;
        }

        if (findSumIndex(A, index, A.size() - 2) == false)
        {
            return false;
        }

        return findSumIndex(A, index, A.size() - 1);
    }
private:
    int sum_ = 0;
    bool candividedEvenlyByThree(vector<int>& A) 
    {
        for (int i = 0; i < A.size(); i++)
        {
            sum_ += A[i];
        }

        if (sum_ % 3 == 0)
        {
            sum_ = sum_ / 3;
            return true;
        }
        else
        {
            return false;
        }
    }

    int findSumIndex(vector<int>& A, int &index, int end)
    {
        int sum = 0;

        for (; index < end;index++)
        {
            sum += A[index];
            if (sum == sum_ )
            {
                ++index;
                return true;
            }
        }

        return false;
    }
};

int main()
{
  std::vector<int> v_number = {0,2,1,-6,6,-7,9,1,2,0,1};

  Solution solution;
  bool ret = solution.canThreePartsEqualSum(v_number);

  if (ret)
  {
    std::cout<< "true" <<std::endl;
  }
  else
  {
    std::cout<< "false" <<std::endl;
  }
}