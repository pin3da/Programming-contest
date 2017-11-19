#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

long long sim_r(deque<int> &d) {
  long long missing = 0, cost = 0;
  int n = d.size();
  deque<int> used(n);
  for (int i = 0; i < n; i++) {
    int next = (i + 1) % n;
    int prev = (i + n - 1) % n;
    if (d[i] == 1) {
      if (d[next] == 2 && !used[next]) {
        cost++;
        used[next] = 1;
      } else {
        if (d[prev] == 2 && !used[prev]) {
          cost++;
          used[prev] = 1;
        } else
          missing++;
      }
    }
  }
  return cost + missing * 2;
}

long long sim_l(deque<int> &d) {
  long long missing = 0, cost = 0;
  int n = d.size();
  deque<int> used(n);
  for (int i = n - 1; i >= 0; i--) {
    int next = (i + 1) % n;
    int prev = (i + n - 1) % n;
    if (d[i] == 1) {
      if (d[prev] == 2 && !used[prev]) {
        cost++;
        used[prev] = 1;
      } else {
        if (d[next] == 2 && !used[next]) {
          cost++;
          used[next] = 1;
        } else
          missing++;
      }
    }
  }
  return cost + missing * 2;
}

long long get_best(deque<int> &d) {
  auto r = sim_r(d);
  auto l = sim_l(d);
  return min(l, r);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, k;
  cin >> n >> k;
  deque<int> all(n);
  for (int i = 0; i < k; i++) {
    int t; cin >> t;
    all[t - 1] = 1;
  }
  for (int i = 0; i < k; i++) {
    int t; cin >> t;
    all[t - 1] = 2;
  }

  cout << get_best(all) << endl;
  return 0;
}
