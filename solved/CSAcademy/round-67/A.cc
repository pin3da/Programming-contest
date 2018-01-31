#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#endif


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  cin >> n;
  deque<int> a(n);
  for (auto &i : a) cin >> i;
  int best = 0;
  while (n--) {
    int cur = 0;
    for (int i = 0; i < int(a.size()); i++) {
      if ((a[i] - 1) == i) cur++;
    }
    best = max(best, cur);
    a.push_back(a.front()); a.pop_front();
  }
  cout << best << endl;
  return 0;
}
