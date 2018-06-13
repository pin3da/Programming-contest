#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct Node {
  long long left_sum, mid_sum, right_sum, total;
  Node* left;
  Node* right;
  Node(long long val = 0) : left_sum(val), mid_sum(val), right_sum(val), total(val),
  left(nullptr), right(nullptr) {}
  long long Best() {
    return max(left_sum, max(mid_sum, right_sum));
  }
};

Node* combine(Node* l, Node* r) {
  if (l == nullptr) return r;
  if (r == nullptr) return l;
  Node* ans = new Node();
  ans->mid_sum = max(max(l->mid_sum, r->mid_sum), l->right_sum + r->left_sum);
  ans->left_sum = max(l->left_sum, l->total + r->left_sum);
  ans->right_sum = max(r->right_sum, r->total + l->right_sum);
  ans->total = r->total + l->total;
  ans->left = l;
  ans->right = r;
  return ans;
}

Node* build(int b, int e, vector<long long> &data) {
  if (b == e) {
    Node* node = new Node(data[b]);
    return node;
  }
  int mid = (b + e) / 2;
  Node* left = build(b, mid, data);
  Node* right = build(mid + 1, e, data);
  return combine(left, right);
}

void update(Node* &root, int b, int e, int pos, long long val) {
  if (b > pos || e < pos)
    return;
  if (b == e) {
    root = new Node(val);
  } else {
    int mid = (b + e) >> 1;
    update(root->left, b, mid, pos, val);
    update(root->right, mid + 1, e, pos, val);
    root = combine(root->left, root->right);
  }
}

Node* query(Node* root, int b, int e, int L, int R) {
  if (b > R || e < L)
    return nullptr;
  if (b >= L && e <= R)
    return root;

  int mid = (b + e) / 2;
  return combine(
      query(root->left, b, mid, L, R),
      query(root->right, mid + 1, e, L, R)
      );
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<long long> data(n);
  for (auto &it : data)
    cin >> it;

  Node* root = build(0, n - 1, data);

  int m;
  cin >> m;
  while (m--) {
    int t; cin >> t;
    int l, r; cin >> l >> r;
    if (t) {
      l--; r--;
      cout << query(root, 0, n - 1, l, r)->Best() << "\n";
    } else {
      l--;
      update(root, 0, n - 1, l, r);
    }
  }

  return 0;
}
