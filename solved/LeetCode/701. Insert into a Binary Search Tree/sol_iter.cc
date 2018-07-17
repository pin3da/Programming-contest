#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            root = new TreeNode(val);
        } else {
            TreeNode* cur = root, * prev;
            while (cur != NULL) {
                prev = cur;
                if (val < cur->val) cur = cur->left;
                else            cur = cur->right;
            }
            cur = new TreeNode(val);
            if (prev->val < val) prev->right = cur;
            else prev->left = cur;
        }
        return root;
    }
};
