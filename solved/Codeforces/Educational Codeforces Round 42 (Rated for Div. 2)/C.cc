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

const int MN = 100000;

bool test(set<long long> &sq, string &l, int mask) {
  string cur;
  for (int i = 0; i < int(l.size()); i++) {
    if ((mask >> i) & 1) cur.push_back(l[i]);
  }
  if (cur[0] == '0') return false;
  long long n = stoll(cur);
  return sq.count(n);
}

void solve() {
  long long n; cin >> n;
  set<long long> sq;
  for (long long i = 1; i < MN; i++) {
    sq.insert(i * i);
  }
  string l = to_string(n);
  int S = l.size();
  int top = 1 << S;
  int cost = 1000;
  for (int mask = 1; mask < top; mask++) {
    if (test(sq, l, mask)) {
      cost = min(cost, S - __builtin_popcount(mask));
    }
  }
  if (cost < 1000) {
    cout << cost << endl;
  } else {
    cout << -1 << endl;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

