#include<bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


struct node {
  long long ans, pos;
  node *left, *right;
  node() : ans(0), pos(0), left(NULL), right(NULL) {}
};

typedef node* pnode;

const int MN = 200000 + 10;

void update(pnode cur) {
  assert(cur);
  long long ans = 0;
  if (cur->left)  ans = max(ans, cur->left->ans);
  if (cur->right) ans = max(ans, cur->right->ans);
  cur->ans = ans;
}

pnode modify(pnode res, int b, int e, int l, int r, long long val) {
  // pnode res = copy_node(cur);
  if (!res) res = new node();

  if (b > r || e < l) return res;
  if (l <= b && e <= r) {
    assert(b == e);
    res->ans = val;
    res->pos = b;
    return res;
  }

  int mid = (b + e) >> 1;
  if (l <= mid)
    res->left = modify(res->left, b, mid, l, r, val);
  else
    res->right = modify(res->right, mid + 1, e, l, r, val);

  update(res);

  return res;
}

void query(pnode cur, int b, int e, int l, int r, int x, vector<pnode> &inv) {
  if (!cur) return;
  if (b > r || e < l) return;

  if (l <= b && e <= r) {
    inv.push_back(cur);
    return;
  }
  int mid = (b + e) >> 1;
  query(cur->left, b, mid, l, r, x, inv);
  query(cur->right, mid + 1, e, l, r, x, inv);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  cin.tie(0);
  ios_base::sync_with_stdio(false);
#endif // LOCAL

  int n, q;
  cin >> n >> q;
  pnode root = NULL;
  for (int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    root = modify(root, 0, n - 1, i, i, tmp);
  }

  while (q--) {
    int t, pos, x;
    cin >> t >> pos >> x;
    pos--;
    if (t == 0) {
      root = modify(root, 0, n - 1, pos, pos, x);
    } else {
      vector<pnode> inv;
      query(root, 0, n - 1, pos, n - 1, x, inv);
      int ans = -1;
      for (auto cur : inv) {
        if (cur->ans >= x) {
          while (cur->left || cur->left) {
            if (cur->left && cur->left->ans >= x)
              cur = cur->left;
            else if (cur->right)
              cur = cur->right;
          }
          ans = cur->pos + 1;
          break;
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}

