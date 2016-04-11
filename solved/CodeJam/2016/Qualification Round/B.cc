#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

using namespace std;

void clean(deque<int> &q) {
  while (q.size() && q.back() == 0)
    q.pop_back();
}

void solve() {
  string line;
  cin >> line;
  deque<int> q;
  for (auto &i : line) {
    if (i == '-')
      q.push_back(1);
    else
      q.push_back(0);
  }

  int ans = 0;
  clean(q);
  while (q.size()) {
    if (q.front() == 0) {
      for (int i = 0; i < q.size() && q[i] == 0; ++i)
        q[i] = 1;
    } else {
      reverse(q.begin(), q.end());
      for (auto &i : q)
        i ^= 1;
    }
    clean(q);
    ans++;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }

  return 0;
}
