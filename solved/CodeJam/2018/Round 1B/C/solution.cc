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

int best;

void bg(vector<pair<int, int>> &rec, vector<int> &frec, int cur, int seen) {
  int pos = min(frec[rec[cur].first], frec[rec[cur].second]);
  for (int i = 0; i <= pos; i++) {
    frec[cur] += i; best = max(best, frec[0]);
    frec[rec[cur].first] -= i;
    frec[rec[cur].second] -= i;
    for (int j = 0; j < int(frec.size()); j++) {
      if ((seen >> j) & 1) continue;
      bg(rec, frec, j, seen | (1 << j));
    }
    frec[cur] -= i;
    frec[rec[cur].first] += i;
    frec[rec[cur].second] += i;
  }
}

void solve() {
  int m; cin >> m;
  vector<pair<int, int>> rec(m);
  for (auto &it : rec) {
    cin >> it.first >> it.second;
    it.first--;
    it.second--;
  }
  vector<int> frec(m);
  for (auto &i : frec) cin >> i;

  best = 0;
  for (int i = 0; i < m; i++)
    bg(rec, frec, i, 1 << i);
  cout << best << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  srand(time(0));
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}

