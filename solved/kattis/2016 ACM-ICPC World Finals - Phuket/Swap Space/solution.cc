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


void solve() {
  int n; cin >> n;
  vector<pair<int, pair<int, int>>> pos, neg;
  const int inf = numeric_limits<int>::max();
  for (int i = 0; i < n; i++) {
    int in, out;
    cin >> in >> out;
    if (out > in) pos.emplace_back(in, make_pair(in, out));
    else pos.emplace_back(inf - out, make_pair(in, out));
  }

  sort(pos.begin(), pos.end());

  long long cur = 0, cost = 0;
  for (int i = 0; i < int(pos.size()); i++) {
    if (pos[i].second.first > cur) {
      cost += pos[i].second.first - cur;
      cur = pos[i].second.first;
    }
    cur -= pos[i].second.first;
    cur += pos[i].second.second;
  }
  cout << cost << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  solve();
  return 0;
}

