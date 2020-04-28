//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

 

示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

 

说明：

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode* reverseKGroup(ListNode *head, int k)
  {
    if (k < 2)
    {
      return head;
    }

    if (head == nullptr)
    {
      return head;
    }

    ListNode pre_header(0);
    pre_header.next = head;
    ListNode *p_pre_header = &pre_header;
    ListNode *p_index = head;

    ListNode *tmp = nullptr;
    ListNode *p_header = nullptr;
    ListNode *p_tail = p_index;

    while (p_index != nullptr)
    {
      tmp = nullptr;
      //p_header = nullptr;
      p_pre_header->next = nullptr;
      p_tail = p_index;

      int index = 0;
      for (; index < k; ++index)
      {
        if (p_index == nullptr)
        {
          break;
        }
        
        tmp = p_index->next;
        p_index->next = p_pre_header->next;
        p_pre_header->next = p_index;
        
        p_index = tmp;
      }
      if (index == k)
      {
        p_pre_header = p_tail;
        continue;
      }

      //index != k
      p_index = p_pre_header->next;
      //p_header = nullptr;
      p_pre_header->next = nullptr;
      while(p_index != nullptr)
      {
        tmp = p_index->next;
        p_index->next = p_pre_header->next;
        p_pre_header->next = p_index;
        
        p_index = tmp;
      } 
    }

    return pre_header.next;
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

  ListNode *ret = solution.reverseKGroup(head, 3);
  
  while (ret != nullptr)
  {
    std::cout<<"ret value["<<ret->val<<"]"<<std::endl;
    ret = ret->next;
  }

  return 0;
}