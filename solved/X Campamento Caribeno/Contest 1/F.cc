#include<bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl;

struct node {
  long long ans, pending;
  node *left, *right;
  node() : ans(0), left(NULL), right(NULL), pending(0) {}
};

typedef node* pnode;

void push_down(pnode cur) {
  if (cur && cur->pending) {
    cur->ans = cur->pending;
    if (cur->left) cur->left->pending = cur->pending;
    if (cur->right) cur->right->pending = cur->pending;
    cur->pending = 0;
  }
}

pnode modify(pnode cur, int b, int e, int l, int r, long long val) {
  push_down(cur);

  if (!cur) cur = new node();
  if (b > r || e < l) return cur;

  if (l <= b && e <= r) {
    cur->pending = val;
    push_down(cur);
    return cur;
  }

  int mid = (b + e) >> 1;
  cur->left = modify(cur->left, b, mid, l, r, val);
  cur->right = modify(cur->right, mid + 1, e, l, r, val);

  return cur;
}

int dfs(pnode cur, vector<long long> &frec, int b, int e) {
  if (!cur) return 0;

  push_down(cur);

  // cerr << b << " " << e << " " << cur->ans << endl;

  if (cur->left || cur->right) {
    int mid = (b + e) >> 1;
    int sz_left = dfs(cur->left, frec, b, mid);
    int sz_right = dfs(cur->right, frec, mid + 1, e);
    if (cur->ans) {
      frec[cur->ans] += (e - b + 1) - sz_left - sz_right;
      return (e - b + 1);
    } else {
      return sz_left + sz_right;
    }
  } else { // leaf
    if (cur->ans) {
      frec[cur->ans] += (e - b + 1);
      return (e - b + 1);
    } else {
      return 0;
    }
  }
}

int main() {
#ifdef LOCAL
  freopen("f2.in", "r", stdin);
#else
  #define endl '\n'
  cin.tie(0);
  ios_base::sync_with_stdio(false);
#endif // LOCAL

  long long n, k;
  cin >> n >> k;
  int m; cin >> m;
  pnode root = NULL;

  while (m--) {
    int col, l, r;
    cin >> col >> l >> r;
    l--, r--;
    // cerr << "pinta " << col << " from " << l << " to " << r << endl;
    root = modify(root, 0, n - 1, l, r, col);
  }

  vector<long long> frec(k + 1);
  dfs(root, frec, 0, n - 1);

  for (int i = 1; i < k + 1; i++) {
    if (i > 1) cout << " ";
    cout << frec[i];
  }
  cout << endl;
  return 0;
}
