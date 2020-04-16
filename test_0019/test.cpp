//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
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

  ListNode* removeNthFromEnd(ListNode* head, int n)
  {
    ListNode pre_header(0);
    pre_header.next = head;
    int index = 1;
    ListNode * pre_n_step_node = &pre_header;
    ListNode * index_node = head;
    for (int i = 0;i < n;++i)
    {
      index_node = index_node->next;
    }

    while (index_node != nullptr)
    {
      index_node = index_node->next;
      pre_n_step_node = pre_n_step_node->next;
    }

    if (pre_n_step_node->next == nullptr)
    {
      return nullptr;
    }
    else 
    {
      pre_n_step_node->next = pre_n_step_node->next->next;
    }
    
    return pre_header.next;
  }

 
};

int main()
{
  Solution solution;
}