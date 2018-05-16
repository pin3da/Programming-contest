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

int S[MN][MN];
int A[MN][MN];
int dt[MN];

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

  for (int j = 0; j < n; j++) {
    for (int i = 1; i < n - j; i++) {
      A[i][j] = max(A[i][j], A[i - 1][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (auto it : all[i]) {
      int best = 0;
      int len = it.first - i + 1;
      for (int j = 0; j < len; j++) {
        best = max(best, A[it.first - j - i][i + j]);
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

