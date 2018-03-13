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

const int MAXN = 100000 + 100;

struct node {
  long long sum;
  node *left, *right;
};

typedef node* pnode;

pnode copy_node(pnode cur) {
  pnode ans = new node();
  if (cur) *ans = *cur;
  return ans;
}

void update(pnode cur) {
  if (cur) {
    cur->sum = 0;
    if (cur->left) cur->sum += cur->left->sum;
    if (cur->right) cur->sum += cur->right->sum;
  }
}

pnode modify(pnode cur, int b, int e, int pos, int val) {
  pnode ans = copy_node(cur);
  if (b == e) {
    ans->sum = val;
  } else {
    int mid = (b + e) >> 1;
    if (pos <= mid)
      ans->left = modify(ans->left, b, mid, pos, val);
    else
      ans->right = modify(ans->right, mid + 1, e, pos, val);
    update(ans);
  }
  return ans;
}

long long query(pnode cur, int b, int e, int l, int r) {
  if (cur == nullptr) return 0;
  if (e < l || b > r) return 0;
  if (b >= l && e <= r) return cur-> sum;
  int mid = (b + e) >> 1;
  return query(cur->left, b, mid, l, r) +
    query(cur->right, mid + 1, e, l, r);
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, k;
  cin >> n >> k;

  vector<pnode> roots;
  vector<deque<int>> last(MAXN);

  roots.emplace_back(nullptr);
  for (int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    last[tmp].emplace_back(i + 1);
    pnode cur = modify(roots.back(), 0, MAXN, i + 1, 1);
    if (int(last[tmp].size()) > k) {
      cur = modify(cur, 0, MAXN, last[tmp].front(), 0);
      last[tmp].pop_front();
    }
    roots.push_back(cur);
  }


  int q; cin >> q;
  int prev = 0;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int l = ((x + prev) % n) + 1;
    int r = ((y + prev) % n) + 1;
    if (l > r) swap(l, r);

    prev = query(roots[r], 0, MAXN, l, r);
    cout << prev << endl;
  }

  return 0;
}

