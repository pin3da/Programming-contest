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

long long my_gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

bool make_line(vector<long long> &x, vector<long long> &y, long long start, vector<long long> &alive) {
  long long n = x.size();
  map<pair<long long, long long>, vector<long long>> frec;
  for (long long i = 0; i < n; i++) {
    if (i == start) continue;
    if (alive[i] == 0) continue;
    pair<long long, long long> cur(y[i] - y[start], x[i] - x[start]);
    long long g = my_gcd(cur.first, cur.second);
    cur.first /= g;
    cur.second /= g;
    frec[cur].push_back(i);
  }
  pair<long long, long long> best = frec.begin()->first;
  for (auto it : frec) {
    if (it.second.size() >= frec[best].size()) {
      best = it.first;
    }
  }
  alive[start] = false;
  for (auto it : frec[best]) alive[it] = false;
  debug(frec[best][0]);
  return (frec[best].size() > 1);
}


void solve() {
  int n; cin >> n;
  vector<long long> x(n), y(n), alive(n, 1);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  if (n <= 4) {
    puts("YES");
    return;
  }

  int ok = false;

  for (int i = 0; i < n; i++) {
    if (make_line(x, y, i, alive)) {
      debug(i);
      long long start = 0;
      for (int i = 0; i < n; i++) if (alive[i]) start = i;
      make_line(x, y, start, alive);
      ok = accumulate(alive.begin(), alive.end(), 0) == 0;
      break;
    } else {
      alive.assign(n, 1);
    }
  }
  puts(ok ? "YES" : "NO");
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

