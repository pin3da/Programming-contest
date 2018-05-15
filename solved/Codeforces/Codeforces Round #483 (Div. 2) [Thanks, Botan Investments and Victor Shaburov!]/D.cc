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


const int MN = 5001;
const int ML = 13; // ceil(log2(MN));


int S[MN][MN];
int A[MN][MN];
int dt[MN];

struct st {
  int dt[MN];
  int M[MN][ML];
  int n;

  void init(int col, int len) {
    n = len;
    for (int i = 0; i < n; ++i)
      dt[i] = A[i][col];
    build();
  }

  void build() {
    for (int i = 0; i < n; ++i)
      M[i][0] = dt[i];
    for (int j = 1, p = 2, q = 1; p <= n; ++j, p <<= 1, q <<= 1)
      for (int i = 0; i + p - 1 < n; ++i)
        M[i][j] = max(M[i][j - 1], M[i + q][j - 1]);
  }
  int query(int b, int e) {
    int k = log2(e - b + 1);
    return max(M[b][k], M[e + 1 - (1<<k)][k]);
  }
};



st rmq[MN];

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> dt[i];

  int q; cin >> q;
  map<int, vector<pair<int, int>>> all;
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    l--; r--;
    all[l].emplace_back(r, i);
  }

  for (auto &it : all) {
    sort(it.second.begin(), it.second.end());
  }

  vector<int> ans(q);

  A[0][0] = dt[0];
  for (int i = 1; i < MN; i++) {
    A[i][0] = dt[0];
    for (int j = 1; j <= i; j++) {
      if (S[i][j]) {
        A[i][0] ^= dt[j];
      }
    }
  }

  for (int j = 1; j < n; j++) {
    for (int i = 0; i < n - j; i++) {
      A[i][j] = A[i][j - 1] ^ A[i + 1][j - 1];
    }
  }

  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cerr << A[i][j] << "\t";
    }
    cerr << endl;
  }
  */

  for (int i = 0; i < n; i++) {
    rmq[i].init(i, n);
  }

  for (int i = 0; i < n; i++) {
    for (auto it : all[i]) {
      int best = 0;
      int len = it.first - i + 1;
      for (int j = 0; j < len; j++) {
        best = max(best, rmq[i + j].query(0, it.first - j - i));
      }
      ans[it.second] = best;
    }
  }

  for (auto it : ans) {
    cout << it << endl;
  }

}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  S[0][0] = 1;
  for (int i = 1; i < MN; i++) {
    S[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      S[i][j] = S[i - 1][j - 1] ^ S[i - 1][j];
    }
  }

  solve();
  return 0;
}

