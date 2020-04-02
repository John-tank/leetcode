//
//  test.cpp
//  mirror tree
//
//  Created by John  on 13.03.16.
//
#include <queue>

 struct TreeNode 
 {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution 
{
public:
    bool isSymmetric(TreeNode* root) 
    {
      return isMirror(root, root);        
    }

    bool isMirror(TreeNode* left, TreeNode* right)
    {
      //exit code 
      if (left == nullptr && right == nullptr)
      {
        return true;
      }
      else if (left == nullptr || right == nullptr)
      {
        return false;
      }

      return ((left->val == right->val) 
              && isMirror(left->left, right->right) 
              && isMirror(left->right, right->left));
    }
};


class SolutionQueue 
{
public:
    bool isSymmetric(TreeNode* root) 
    {
      std::queue<TreeNode *> nodeQueue;
      nodeQueue.push_back(root->left);
      nodeQueue.push_back(root->right);

      while (!nodeQueue.empty())
      {
        TreeNode *node1 = nodeQueue.pop_front();
        TreeNode *node2 = nodeQueue.pop_front();

        if (node1 == nullptr && node2 == nullptr)
        {
          continue;
        }
        else if (node1 == nullptr || node2 == nullptr)
        {
          return false;
        }
        else if (node1->val != node2->val)
        {
          return false;
        }

        nodeQueue.push_back(node1->left);
        nodeQueue.push_back(node2->right);
        nodeQueue.push_back(node1->right);
        nodeQueue.push_back(node2->left);
      }

      return true;
    }

};
