#include<bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

struct node {
  long long ans;
  node *left, *right;
  node() : ans(0) {}
};

typedef node* pnode;

void update(pnode cur) {
  long long ans = 0;
  if (cur->left)  ans += cur->left->ans;
  if (cur->right) ans += cur->right->ans;
  cur->ans = ans;
}

pnode modify(pnode cur, int b, int e, int l, int r, long long val) {
  if (!cur) cur= new node();

  if (b > r || e < l) return cur;
  if (l <= b && e <= r) {
    assert(b == e);
    cur->ans += val;
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

  if (b > r || e < l) return 0;
  if (l <= b && e <= r) return cur->ans;
  int mid = (b + e) >> 1;
  long long left = query(cur->left, b, mid, l, r);
  long long right = query(cur->right, mid + 1, e, l, r);
  return (left + right);
}

int main() {
#ifdef LOCAL
  freopen("d1.in", "r", stdin);
#else
  #define endl '\n'
  cin.tie(0);
  ios_base::sync_with_stdio(false);
#endif // LOCAL

  int n; cin >> n;
  vector<int> data(n);
  for (long long i = 0; i < n; i++) {
    cin >> data[i];
  }

  vector<long long> greater_left(n);
  pnode root = NULL;
  const int MAX_VAL = 100000 + 100;

  for (int i = 0; i < MAX_VAL; i++)
    root = modify(root, 0, MAX_VAL - 1, i, i, 0);

  for (int i = 0; i < n; i++) {
    greater_left[i] = query(root, 0, MAX_VAL - 1, data[i], MAX_VAL);
    root = modify(root, 0, MAX_VAL - 1, data[i], data[i], 1);
  }

  root = NULL;

  vector<long long> less_right(n);
  for (int i = n - 1; i >= 0; i--) {
    less_right[i] = query(root, 0, MAX_VAL - 1, 0, data[i]);
    root = modify(root, 0, MAX_VAL - 1, data[i], data[i], 1);
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += greater_left[i] * less_right[i];
  }
  cout << ans << endl;
  return 0;
}
