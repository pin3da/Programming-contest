using namespace std;
#include <bits/stdc++.h>

int main() {
  int n, k;
  while (cin >> n >> k) {
    vector<int> b(111);
    int t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      b[t / 1000]++;
    }
    
    int best = 0;
    for (int i = 0; i < b.size(); ++i) {
      best = max(best, (b[i] + k - 1) / k);
    }
    cout << best << endl;
  }
  return 0;
}
