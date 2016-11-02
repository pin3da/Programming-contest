#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int cost(int a, int b) {
  return min(abs(a - b), 24 - abs(a - b));
}

int sim(vector<int> &b, int start) {

  int ans = 0;
  for (int a = 0; a < (int)b.size(); a += 2) {
    int i = (a + start) % b.size();
    int j = (a + start + 1) % b.size();
    ans += cost(b[i], b[j]);
  }
  return ans;
}

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  while (cin >> n) {
    vector<int> a(25);
    for (int i = 0; i < n; ++i) {
      int t; cin >> t;
      a[t + 11] ^= 1;
    }
    vector<int> b;
    for (int i = 0; i < 25; ++i)
      if (a[i]) b.push_back(i - 11);

    if (b.size() == 0) {
      cout << 0 << endl;
      continue;
    }
    int best = 10000;
    for (int i = 0; i < (int)b.size(); ++i) {
      best = min(sim(b, i), best);
    }
    cout << best << endl;
  }
  return 0;
}
