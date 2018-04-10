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

void make_move(string &line) {
  for (int i = line.size() - 1; i >= 1; i--) {
    if (line[i - 1] == 'C' && line[i] == 'S') {
      swap(line[i - 1], line[i]);
      return;
    }
  }
}

long long score(string &line) {
  long long total = 0, cur = 1;
  for (auto c : line) {
    if (c == 'C') cur <<= 1;
    else total += cur;
  }
  return total;
}

void solve() {
  long long d;
  cin >> d;

  string line;
  cin >> line;

  int tot_s = 0;
  for (auto c : line)
    tot_s += (c == 'S');

  if (d < tot_s) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  int ans = 0;
  while (score(line) > d) {
    make_move(line);
    ans++;
  }
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}

