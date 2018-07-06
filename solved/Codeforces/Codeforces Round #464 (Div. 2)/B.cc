#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

long long H;

long long hamsters(long long cap) {
  return (H / cap) * cap;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n;
  cin >> H >> n;
  vector<long long> all(n);
  int best = 0;
  for (int i = 0; i < n; i++) {
    cin >> all[i];
    if (hamsters(all[best]) < hamsters(all[i]))
      best = i;
  }
  cout << best + 1 << " " << hamsters(all[best]) / all[best] << endl;
  return 0;
}
