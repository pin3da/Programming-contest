#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

int main() {
  int n, b;
  while (cin >> n >> b && (n + b)) {
    long long total = 0;
    for (int i = 0; i < n; ++i) {
      int t; cin >> t;
      total += t;
    }
    cout << b / total << endl;
  }
  return 0;
}
