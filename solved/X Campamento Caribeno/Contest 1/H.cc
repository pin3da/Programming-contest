#include<bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct node {
  long long ans, pending;
  node *left, *right;
  node() : ans(0), pending(0) {}
};

typedef node* pnode;

void push_down(pnode cur) {
  if (cur) {
    if (cur->pending) {
      cur->ans += cur->pending;
      if (cur->left) cur->left->pending += cur->pending;
      if (cur->right) cur->right->pending += cur->pending;
      cur->pending = 0;
    }
  }
}

void update(pnode cur) {
  push_down(cur);
  long long ans = 0;
  if (cur->left) {
    push_down(cur->left);
    ans = max(ans, cur->left->ans);
  }
  if (cur->right) {
    push_down(cur->right);
    ans = max(ans, cur->right->ans);
  }
  cur->ans = ans;
}

pnode modify(pnode cur, int b, int e, int l, int r, long long val) {
  if (!cur) cur= new node();

  push_down(cur);

  if (b > r || e < l) return cur;
  if (l <= b && e <= r) {
    cur->pending += val;
    if (b < e) // non-leaf
      update(cur);
    return cur;
  }

  int mid = (b + e) >> 1;
  cur->left = modify(cur->left, b, mid, l, r, val);
  cur->right = modify(cur->right, mid + 1, e, l, r, val);

  update(cur);

  return cur;
}

long long query(pnode cur, int b, int e, int l, int r) {
  if (!cur) return 0;

  push_down(cur);

  if (b > r || e < l) return 0;
  if (l <= b && e <= r) return cur->ans;
  int mid = (b + e) >> 1;
  long long left = query(cur->left, b, mid, l, r);
  long long right = query(cur->right, mid + 1, e, l, r);
  return max(left, right);
}

int main() {
#ifdef LOCAL
  freopen("h1.in", "r", stdin);
#else
  #define endl '\n'
  cin.tie(0);
  ios_base::sync_with_stdio(false);
#endif // LOCAL

  int n; cin >> n;
  pnode root = NULL;

  for (int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    root = modify(root, 0, n - 1, i, i, tmp);
  }
  int first = true;
  int q; cin >> q;
  while (q--) {
    char m; cin >> m;
    int l, r;
    cin >> l >> r;
    if (m == 'm') {
      if (!first) cout << " ";
      first = false;
      cout << query(root, 0, n - 1, l - 1, r - 1);
    } else {
      long long a; cin >> a;
      root = modify(root, 0, n - 1, l - 1, r - 1, a);
    }
  }
  cout << endl;
  return 0;
}
