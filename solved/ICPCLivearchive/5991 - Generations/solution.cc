using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int N = 1e5 + 10;  // limit for array size
int n = N;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

// Single modification, range query.
void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(t[--r], res);
  }
  return res;
}

int ts;

void fill_g(vector<vector<int>> &g, vector<int> &id, int node, int depth) {
  id[node] = ts;
  t[n + ts] = depth;
  ts++;
  for (int i = 0; i < g[node].size(); ++i) {
    fill_g(g, id, g[node][i], depth + 1);
  }
}

int b[N];
bool cmp(int a, int c) {
    return b[a] < b[c];
}

int find_right(vector<vector<int>> &g, int node, int val) {
  int best = node;
  for (int i = g[node].size() - 1; i >= 0; --i) {
    int to = g[node][i];
    if (b[to] <= val) {
      best = max(best, find_right(g, to, val));
      // break;
    }
  }
  return best;
}

void solve() {
  cin >> n;
  vector<vector<int>> g(n);
  vector<int> e(n), data(n), id(n);
  int pi;
  for (int i = 0; i < n; ++i) {
    cin >> pi >> b[i] >> e[i];
    if (pi >= 0)
      g[pi].push_back(i);
  }

  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end(), cmp);
  }

  ts = 0;
  fill_g(g, id, 0, 0);

  build();




  for (int i = 0; i < n; ++i) {
    int r = find_right(g, i, e[i]);
    if (i) cout << " ";
    // cout << id[i] << " - " << id[r] << endl;
    cout << max(0, query(id[i], id[r] + 1) - t[n + id[i]]);
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}

