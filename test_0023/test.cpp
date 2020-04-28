//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
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
/**
 * Definition for singly-linked list.
 
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }
    
    ListNode pre_head(0);
    pre_head.next = head;

    ListNode* p_pre_head = &pre_head;
    ListNode* p_start_head = pre_head.next;
    ListNode* p_end = p_start_head->next;
    while (p_start_head != nullptr && p_end != nullptr)
    {
      p_pre_head->next = p_end;
      p_start_head->next = p_end->next;
      p_end->next = p_start_head;

      p_pre_head = p_start_head;
      p_start_head = p_start_head->next;
      if (p_start_head != nullptr)
      {
        p_end = p_start_head->next;
      }
      else
      {
        p_end = nullptr;
      }
    }

    return pre_head.next;
  }
};

int main()
{
  Solution solution;
  
  ListNode *head = new ListNode(10);

  //ListNode * tmp = head;
  for (int i = 0;i < 10;i ++)
  {
    head[i].val = i;
    if (i != 9)
    {
      head[i].next = head + i + 1;
    }
    else
    {
      head[i].next = nullptr;
    }
  }

  ListNode *ret = solution.swapPairs(head);
  
  while (ret != nullptr)
  {
    std::cout<<"ret value["<<ret->val<<"]"<<std::endl;
    ret = ret->next;
  }

  return 0;
}