using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const long long mod = 9999991;

struct node {
  int r, l, val;
  node() {}
  node(int _val) {
    r = -1;
    l = -1;
    val = _val;
  }
};


vector<vector<int>> g;

int insert(vector<node> &tree, int cur, int val) {
  if (tree[cur].val > val) {
    if (tree[cur].l != -1)
      insert(tree, tree[cur].l, val);
    else {
      tree[cur].l = tree.size();
      tree.push_back(node(val));
      return tree.size() - 1;
    }
  } else {
    if (tree[cur].r != -1)
      insert(tree, tree[cur].r, val);
    else {
      tree[cur].r = tree.size();
      tree.push_back(node(val));
      return tree.size() - 1;
    }
  }
}

long long dp[(1 << 20) + 10];
long long popcnt_next(long long n) {
  long long c = (n & -n), r = n+c;
  return (((r ^ n) >> 2) / c) | r;
}


long long run(vector<node> &tree) {
  dp[((1 << tree.size()) - 1)] = 1;

  int mm = ((1 << tree.size()) - 1);
  for (int kk = tree.size() - 1; kk >= 1; --kk) {
    int mask = (1 << kk) - 1;
    while (mask <= mm) {
      dp[mask] = 0;
      for (int i = 0; i < tree.size(); ++i) {
        if ((mask >> i) & 1) {
          if (tree[i].l != -1 && (((mask >> tree[i].l) & 1)) == 0) {
            dp[mask] = (dp[mask] + dp[mask | (1 << (tree[i].l))]) % mod;
          } if (tree[i].r != -1 && (((mask >> tree[i].r) & 1)) == 0)
            dp[mask] = (dp[mask] + dp[mask | (1 << (tree[i].r))]) % mod;
        }
      }
      mask = popcnt_next(mask);
    }
  }

  return dp[1];
}

long long go(vector<node> &tree, int mask) {
  if (mask == ((1 << tree.size()) - 1)) {
    return 1;
  }

  if (dp[mask] != -1) {
    return dp[mask];
  }

  long long ans = 0;
  for (int i = 0; i < tree.size(); ++i) {
    if ((mask >> i) & 1) {
      if (tree[i].l != -1 && (((mask >> tree[i].l) & 1)) == 0) {
        ans = (ans + go(tree, mask | (1 << (tree[i].l)))) % mod;
      } if (tree[i].r != -1 && (((mask >> tree[i].r) & 1)) == 0)
        ans = (ans + go(tree, mask | (1 << (tree[i].r)))) % mod;
    }
  }
  return dp[mask] = ans % mod;
}

void solve() {
  int n;
  cin >> n;
  vector<node> all;
  int cur;
  cin >> cur;
  vector<int> val(n);
  all.push_back(node(cur));
  val[0] = cur;
  for (int i = 1; i < n; ++i) {
    cin >> val[i];
    insert(all, 0, val[i]);
  }

  //memset(dp, -1, sizeof dp);
  cout << run(all) << endl;
  // cout << go(all, 1) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc;
  cin >> tc;
  while (tc--)  {
    solve();
  }
  return 0;
}
