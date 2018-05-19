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

/*
   int go(int r, int b, int id) {
   if (id == 0) {
   int last = 0;
   for (int i = 1; i <= r; i++) {
   if ((i * (i + 1) / 2) <= r)
   last = i;
   }
   return last;
   }

   int best = go(r, b, id - 1);
   for (int i = 0; i <= r; i++) {
   int need_b = (i + 1) * id;
   int need_r = (i * (i + 1)) / 2;
   if (need_r > r) break;
   if (need_b <= b && need_r <= r) {
   best = max(best, go(r - need_r, b - need_b, id - 1) + i + 1);
   }
   }
   return best;
   }
   */

const int MN = 500;
int dp[MN + 1][MN + 1][3];

void solve(int n) {

  vector<vector<pair<int, int>>> queries(MN + 10);
  vector<int> ans(n);

  for (int i = 0; i < n; i++) {
    int r, b; cin >> r >> b;
    queries[b].emplace_back(r, i);
  }
  // cout << go(R, B, B) << endl;

  int cur = 0;
  for (int r = 0; r <= MN; r++) {
    for (int b = 0; b <= MN; b++) {
      int last = 0;
      for (int i = 1; i <= r; i++) {
        if ((i * (i + 1) / 2) <= r)
          last = i;
      }
      dp[r][b][cur] = last;
    }
  }

  for (auto q : queries[0]) {
    ans[q.second] = dp[q.first][0][0];
  }

  cur ^= 1;
  for (int id = 1; id <= MN; id++) {
    for (int r = 0; r <= MN; r++) {
      for (int b = 0; b <= MN; b++) {
        int best = dp[r][b][cur ^ 1]; //go(r, b, id - 1);
        for (int i = 0; i <= r; i++) {
          int need_b = (i + 1) * id;
          int need_r = (i * (i + 1)) / 2;
          if (need_r > r) break;
          if (need_b <= b && need_r <= r) {
            // best = max(best, go(r - need_r, b - need_b, id - 1) + i + 1);
            best = max(best, dp[r - need_r][b - need_b][cur ^ 1] + i + 1);
          }
        }
        dp[r][b][cur] = best;
      }
    }
    cur ^= 1;
    for (auto q : queries[id]) {
      ans[q.second] = dp[q.first][id][cur ^ 1];
    }
  }

  for (int i = 0; i < n; i++) {
    cout << "Case #" << (i + 1) << ": " << ans[i] << endl;
  }

  // cout << dp[R][B][cur ^ 1] << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  solve(tc);
  /*
     for (int i = 0; i < tc; i++) {
     cout << "Case #" << (i + 1) << ": ";
     solve();
     }
     */
  return 0;
}

