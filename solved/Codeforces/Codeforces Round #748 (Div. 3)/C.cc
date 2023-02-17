#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> dist(k);
    for (auto &d : dist) {
      int tmp;
      cin >> tmp;
      d = (n - tmp);
    }
    sort(dist.begin(), dist.end());
    long long total = 0;
    int last = 0;
    for (int i = 0; i < k; i++) {
      total += dist[i];
      if (total < n) {
        last = i + 1;
      }
    }
    cout << last << endl;
  }
  return 0;
}