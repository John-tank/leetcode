//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
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

 struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;
class Solution
{
public:

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
  {
    ListNode node;
    ListNode *p_merge_list = &node;

    while (l1 != nullptr && l2 != nullptr)
    {
      if (l1->val < l2->val)
      {
        p_merge_list->next = l1;
        p_merge_list = l1;
        l1 = l1->next;
      }
      else
      {
        p_merge_list->next = l2;
        p_merge_list = l2;
        l2 = l2->next;
      }
    }

    if (l1 != nullptr)
    {
      p_merge_list->next = l1;
    }
    else if (l2 != nullptr)
    {
      p_merge_list->next = l2;
    }

    return node.next;
  }
};

int main()
{
  Solution solution;
  
  bool ret = solution.isValid("())");
  
  std::cout<<"ret value["<<ret<<"]"<<std::endl;

  return 0;
}