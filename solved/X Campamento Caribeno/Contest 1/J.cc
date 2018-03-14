#include<bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct node {
  long long ans_min, ans_max;
  node *left, *right;
  node() : ans_min(numeric_limits<long long>::max()), ans_max(numeric_limits<long long>::min()) {}
};

typedef node* pnode;

void update(pnode cur) {
  long long mmin = numeric_limits<long long>::max();
  long long mmax = numeric_limits<long long>::min();
  if (cur->left) {
    mmin = min(mmin, cur->left->ans_min);
    mmax = max(mmax, cur->left->ans_max);
  }

  if (cur->right) {
    mmin = min(mmin, cur->right->ans_min);
    mmax = max(mmax, cur->right->ans_max);
  }
  cur->ans_max = mmax;
  cur->ans_min = mmin;
}

pnode modify(pnode cur, int b, int e, int l, int r, long long val) {
  if (!cur) cur= new node();

  if (b > r || e < l) return cur;
  if (l <= b && e <= r) {
    cur->ans_min = val;
    cur->ans_max = val;
    return cur;
  }

  int mid = (b + e) >> 1;
  cur->left = modify(cur->left, b, mid, l, r, val);
  cur->right = modify(cur->right, mid + 1, e, l, r, val);

  update(cur);

  return cur;
}

long long query_min(pnode cur, int b, int e, int l, int r) {
  if (!cur) return numeric_limits<long long>::max();

  if (b > r || e < l) return numeric_limits<long long>::max();
  if (l <= b && e <= r) return cur->ans_min;
  int mid = (b + e) >> 1;
  long long left = query_min(cur->left, b, mid, l, r);
  long long right = query_min(cur->right, mid + 1, e, l, r);
  return min(left, right);
}

long long query_max(pnode cur, int b, int e, int l, int r) {
  if (!cur) return numeric_limits<long long>::min();

  if (b > r || e < l) return numeric_limits<long long>::min();
  if (l <= b && e <= r) return cur->ans_max;
  int mid = (b + e) >> 1;
  long long left = query_max(cur->left, b, mid, l, r);
  long long right = query_max(cur->right, mid + 1, e, l, r);
  return max(left, right);
}

int main() {
#ifdef LOCAL
  freopen("j1.in", "r", stdin);
#else
  #define endl '\n'
  cin.tie(0);
  ios_base::sync_with_stdio(false);
#endif // LOCAL

  int n = 100000 + 100;
  pnode root = NULL;

  for (long long i = 1; i < n; i++) {
    long long cur = (i * i) % 12345 + (((i * i) % 23456) * i) % 23456;
    root = modify(root, 0, n - 1, i - 1, i - 1, cur);
  }

  int q; cin >> q;
  while (q--) {
    int x; cin >> x;
    int y; cin >> y;
    if (x > 0) {
      long long mmin = query_min(root, 0, n - 1, x - 1, y - 1);
      long long mmax = query_max(root, 0, n - 1, x - 1, y - 1);
      cout << mmax - mmin << endl;
    } else {
      x *= -1;
      root = modify(root, 0, n - 1, x - 1, x - 1, y);
    }
  }
  return 0;
}
