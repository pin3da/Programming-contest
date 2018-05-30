#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {

  struct SegTree {
    long long sum;
    SegTree* left, *right;
    SegTree() : sum(0), left(nullptr), right(nullptr) {}
  };

  long long getSum(SegTree *root) {
    if (root == nullptr)
      return 0;
    return root->sum;
  }

  void increase(SegTree* &root, long long b, long long e, long long pos) {
    if (root == nullptr) {
      root = new SegTree();
    }

    if (b == e) {
      root->sum++;
    } else {
      long long mid = (b + e) >> 1;
      if (pos <= mid)
        increase(root->left, b, mid, pos);
      else
        increase(root->right, mid + 1, e, pos);

      root->sum = getSum(root->left) + getSum(root->right);
    }
  }

  long long get(SegTree* root, long long b, long long e, long long L, long long R) {
    if (root == nullptr)
      return 0;

    if (e < L || b > R)
      return 0;

    if (b >= L && e <= R)
      return getSum(root);

    long long mid = (b + e) >> 1;
    return get(root->left, b, mid, L, R) + get(root->right, mid + 1, e, L, R);
  }

  public:
  int reversePairs(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;

    SegTree *tree = nullptr;
    long long MAX_VAL = 2LL * (*max_element(nums.begin(), nums.end())) + 1;
    long long offset = 1LL << 33;
    MAX_VAL += offset + 100;

    long long ans = 0;
    for (int i = 0; i < int(nums.size()); i++) {
      long long lower = offset + 2LL * nums[i] + 1LL;
      ans += get(tree, 0, MAX_VAL, lower, MAX_VAL);
      increase(tree, 0, MAX_VAL, offset + nums[i]);
    }

    return ans;
  }
};

int main() {

  Solution sol;
  vector<int> data = {1, 3, 2, 3, 1};
  assert(sol.reversePairs(data) == 2);

  data = {2, 4, 3, 5, 1};
  assert(sol.reversePairs(data) == 3);

  data = {};
  assert(sol.reversePairs(data) == 0);

  data = {-5, -5};
  assert(sol.reversePairs(data) == 1);

  data = {2147483647, 2147483647, -2147483647, -2147483647, -2147483647, 2147483647};
  assert(sol.reversePairs(data) == 9);

  data = {2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647};
  assert(sol.reversePairs(data) == 0);

  return 0;
}
