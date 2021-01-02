#include <bits/stdc++.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (cloned == nullptr) {
      return nullptr;
    }
    if (cloned->val == target->val) {
      return cloned;
    }
    TreeNode* left = getTargetCopy(original, cloned->left, target);
    if (left != nullptr) {
      return left;
    }
    return getTargetCopy(original, cloned->right, target);
  }
};
