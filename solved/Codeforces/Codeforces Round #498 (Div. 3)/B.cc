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

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a.rbegin(), a.rend());

  vector<int> choosen;
  int profit = 0;
  for (int i = 0; i < k; i++) {
    choosen.push_back(a[i].second);
    profit += a[i].first;
  }
  cout << profit << endl;

  sort(choosen.begin(), choosen.end());

  int last = -1;
  for (int i = 0; i < k - 1; i++) {
    int t = choosen[i];
    cout << t - last << " ";
    last = t;
  }
  cout << n - 1 - last << endl;
  return 0;
}
