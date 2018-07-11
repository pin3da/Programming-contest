#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
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

  int n;
  long long k;
  cin >> n >> k;
  deque<int> q(n);
  for (auto &it : q) cin >> it;

  long long r = 3 * n;
  long long c = 0;
  while (r--) {
    int a = q[0], b = q[1];
    q.pop_front(); q.pop_front();
    if (a > b) {
      c++;
      q.push_front(a);
      q.push_back(b);
    } else {
      c = 1;
      q.push_front(b);
      q.push_back(a);
    }

    if (c == k) {
      break;
    }
  }
  cout << q[0] << endl;
  return 0;
}
