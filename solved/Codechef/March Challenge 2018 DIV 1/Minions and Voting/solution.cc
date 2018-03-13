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

const int MN = 1e5 + 10;  // limit for array size

struct seg_tree {
  int n;  // array size
  int t[2 * MN];

  seg_tree(int _n) : n(_n) {}

  void clear() {
    memset(t, 0, sizeof t);
  }

  void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
  }

  void modify(int l, int r, int value) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) t[l++] += value;
      if (r&1) t[--r] += value;
    }
  }

  void push() {
    for (int i = 1; i < n; ++i) {
      t[i<<1] += t[i];
      t[i<<1|1] += t[i];
      t[i] = 0;
    }
  }
};

long long get(vector<long long> &sum, int b, int e) {
  long long ans = sum[e];
  if (b) return ans - sum[b - 1];
  return ans;
}

int find_left(vector<long long> &sum, int pos, int val) {
  int lo = 0, hi = max(pos, 0);

  if (get(sum, hi, pos) > val) return hi;

  while (lo < hi) {
    int mid = (lo + hi + 1) >> 1;
    if (get(sum, mid, pos) > val)
      lo = mid;
    else
      hi = mid - 1;
  }

  return lo;
}

int find_right(vector<long long> &sum, int pos, int val) {
  int lo = pos, hi = sum.size() - 1;

  if (get(sum, pos, lo) > val) return lo;


  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (get(sum, pos, mid) > val)
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}

seg_tree tree(MN);

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  read(a);

  tree.clear();

  vector<long long> sum(n);
  for (int i = 0; i < n; i++) {
    sum[i] = a[i];
    if (i) sum[i] += sum[i - 1];
  }



  for (int i = 0; i < n; i++) {
    int le = find_left(sum, i - 1, a[i]);
    int ri = find_right(sum, i + 1, a[i]);

    if (le <= ri)
      tree.modify(le, ri + 1, 1);
  }

  tree.push();

  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << tree.t[MN + i] - 1;
  }
  cout << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}

