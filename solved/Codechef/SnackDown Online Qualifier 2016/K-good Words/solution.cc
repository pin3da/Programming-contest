#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc; cin >> tc;
  while (tc--) {
    string line;
    int k;
    cin >> line >> k;
    vector<int> frec(30);
    for (auto &i : line) frec[i - 'a']++;
    sort(frec.begin(), frec.end());
    int mmax = frec.back();
    int best = line.size() * 2;
    for (int i = 1; i <= mmax; ++i) {
      int j = i + k;
      int ans = 0;
      for (auto &p : frec) {
        if (p < i) ans += p;
        if (p > j) ans += p - j;
      }
      best = min(ans, best);
    }
    cout << best << endl;
  }
  return 0;
}
