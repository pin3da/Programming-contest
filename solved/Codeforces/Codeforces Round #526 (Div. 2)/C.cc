#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


const long long MOD = 1e9 + 7;

long long add(long long x, long long y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  return x;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  string line;
  cin >> line;
  int n = line.size();

  long long total = 0;
  long long in_front = 0;
  long long pending = 0;

  for (int i = n - 1; i >= 0; i--) {
    if (line[i] == 'a') {
      long long c = add(1, in_front);
      pending = add(pending, c);
      total = add(total, c);
    } else if (line[i] == 'b') {
      in_front = add(in_front, pending);
      pending = 0;
    }
  }

  cout << total << endl;

  return 0;
}
