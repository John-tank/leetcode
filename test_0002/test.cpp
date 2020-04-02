//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
/*

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

#include <iostream>
#include <vector>
using namespace std;
//可以考虑hash算法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int advancement = 0;
        ListNode* rigth = l2;
        ListNode* left = l1;
        ListNode* result = nullptr;
        ListNode* tmp = nullptr;

        while (rigth != nullptr || left != nullptr)
        {
            if (result == nullptr)
            {
                result = new ListNode(0);
                tmp = result;
            }
            else
            {
                result->next = new ListNode(0);
                result = result->next;
            }
            if (rigth != nullptr && left != nullptr)
            {
                result->val = (rigth->val + left->val + advancement) % 10;
                advancement = (rigth->val + left->val + advancement) / 10;
                rigth = rigth->next;
                left = left->next;
            }
            else if (rigth == nullptr && left != nullptr)
            {
                result->val = (left->val + advancement) % 10;
                advancement = (left->val + advancement) / 10;
                left = left->next;
            }
            else if (rigth != nullptr && left == nullptr)
            {
                result->val = (rigth->val + advancement) % 10;
                advancement = (rigth->val + advancement) / 10;
                rigth = rigth->next;
            }

        }

        if (advancement == 1)
        {
            result->next = new ListNode(1);
            result = result->next;            
        }

        return tmp;
    }
};

int main()
{

  Solution solution;

  
  return 0;
}