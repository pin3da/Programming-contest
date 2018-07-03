#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  long long n;
  cin >> n;
  set<int> all;
  all.insert(0);
  long long top = min(15LL, n);
  for (int i = 0; i < top; i++) {
    set<int> nxt;
    for (auto it : all) {
      nxt.insert(it + 1);
      nxt.insert(it + 5);
      nxt.insert(it + 10);
      nxt.insert(it + 50);
    }
    all = nxt;
  }
  cout << all.size() + 49LL * (n - top) << endl;
  return 0;
}
