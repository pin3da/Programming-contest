#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct Node {
  int has_zero, parity;
  Node* left, * right;
  Node(int val = 0) : has_zero(val == 0), parity(val < 0),
  left(nullptr),
  right(nullptr)
  {}
};

Node* Combine(Node* left, Node* right) {
  if (left == nullptr) return right;
  if (right == nullptr) return left;
  Node* ans = new Node();
  ans->has_zero = left->has_zero || right->has_zero;
  ans->parity = left->parity ^ right->parity;
  ans->left = left;
  ans->right = right;
  return ans;
}

Node* Build(int b, int e, vector<int> &data) {
  if (b == e)
    return new Node(data[b]);

  int mid = (b + e) >> 1;
  Node* left = Build(b, mid, data);
  Node* right = Build(mid + 1, e, data);
  return Combine(left, right);
}

void Update(Node* &root, int b, int e, int pos, int val) {
  if (b > pos || e < pos)
    return;

  if (b == e) {
    root = new Node(val);
  } else {
    int mid = (b + e) / 2;
    Update(root->left, b, mid, pos, val);
    Update(root->right, mid + 1, e, pos, val);
    root = Combine(root->left, root->right);
  }
}

Node* Query(Node *root, int b, int e, int L, int R) {
  if (b > R || e < L)
    return nullptr;
  if (b >= L && e <= R)
    return root;

  int mid = (b + e) / 2;
  return Combine(
      Query(root->left, b, mid, L, R),
      Query(root->right, mid + 1, e, L, R)
  );
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  while (cin >> n >> q) {
    vector<int> data(n);
    for (auto &it : data)
      cin >> it;
    Node* root = Build(0, n - 1, data);


    while (q--) {
      char t; cin >> t;
      if (t == 'C') {
        int pos, val;
        cin >> pos >> val;
        Update(root, 0, n - 1, pos - 1, val);
      } else {
        int l, r; cin >> l >> r;
        Node* ans = Query(root, 0, n - 1, l - 1, r - 1);
        if (ans->has_zero)
          cout << 0;
        else if (ans->parity)
          cout << "-";
        else
          cout << "+";
      }
    }
    cout << endl;
  }
  return 0;
}
