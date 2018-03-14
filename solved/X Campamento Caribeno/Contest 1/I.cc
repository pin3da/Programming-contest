#include<bits/stdc++.h>

using namespace std;

struct node {
  int gcd;
  node *left, *right;
};

typedef node* pnode;

int gcd(int x, int y) {
  if (x == 0 && y == 0) return 0;
  return __gcd(x, y);
}

void update(pnode cur) {
  int ans = 0;
  if (cur->left) ans = gcd(ans, cur->left->gcd);
  if (cur->right) ans = gcd(ans, cur->right->gcd);
  cur->gcd = ans;
}

pnode modify(pnode cur, int b, int e, int pos, int val) {
  if (!cur) {
    cur= new node();
  }

  if (b == e) {
    cur->gcd = val;
  } else {
    int mid = (b + e) >> 1;
    if (pos <= mid)
      cur->left = modify(cur->left, b, mid, pos, val);
    else
      cur->right = modify(cur->right, mid + 1, e, pos, val);

    update(cur);
  }
  return cur;
}

int query(pnode cur, int b, int e, int l, int r) {
  if (!cur) return 0;
  if (b > r || e < l) return 0;
  if (l <= b && e <= r) return cur->gcd;
  int mid = (b + e) >> 1;
  return gcd(query(cur->left, b, mid, l, r), query(cur->right, mid + 1, e, l, r));
}

int main() {
#ifdef LOCAL
  freopen("i1.in", "r", stdin);
#else
  #define endl '\n'
  cin.tie(0);
  ios_base::sync_with_stdio(false);
#endif // LOCAL

  int n; cin >> n;
  pnode root = NULL;

  for (int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    root = modify(root, 0, n - 1, i, tmp);
  }

  int q; cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << query(root, 0, n - 1, l - 1, r - 1) << endl;
  }
  return 0;
}
