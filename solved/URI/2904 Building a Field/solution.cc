#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


bool canSplit(vector<int> &a, int i, const int target) {
    int extra = i ? a[i - 1] : 0;
    return (binary_search(a.begin() + i + 1, a.end(), target + extra));
}

int getEnd(vector<int> &a, int i, const int target) {
    int extra = i ? a[i - 1] : 0;
    return (lower_bound(a.begin() + i + 1, a.end(), target + extra)) - a.begin();
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
  }

  const int total = a[n - 1];

  if (total & 1) {
    cout << "N" << endl;
    return;
  }

  const int target = total / 2;

  for (int i = 0; i < n; i++) {
    if (canSplit(a, i, target)) {
      int max_j = getEnd(a, i, target);
      for (int j = i + 1; j < max_j; j++) {
        if (canSplit(a, j, target)) {
          cout << "Y" << endl;
          return;
        }
      }
      cout << "N" << endl;
      return;
    }
  }
  cout << "N" << endl;
}


int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  solve();
  return 0;
}
