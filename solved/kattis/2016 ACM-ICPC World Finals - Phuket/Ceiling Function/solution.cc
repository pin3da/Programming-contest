#include <bits/stdc++.h>

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
  int val;
  node *l, *r;
};

typedef node* pnode;

void insert(pnode &cur, int val) {
  if (!cur) {
    cur = new node();
    cur->val = val;
  } else {
    if (val < cur->val)
      insert(cur->l, val);
    else
      insert(cur->r, val);
  }
}

bool equal(pnode a, pnode b) {
  if (!a && !b) return true;
  if (!a) return false;
  if (!b) return false;
  return equal(a->l, b->l) && equal(a->r, b->r);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pnode> roots(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int tmp; cin >> tmp;
      insert(roots[i], tmp);
    }
    int is_new = true;
    for (int j = 0; j < i; j++) {
      if (equal(roots[i], roots[j]))
        is_new = false;
    }
    ans += is_new;
  }
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

