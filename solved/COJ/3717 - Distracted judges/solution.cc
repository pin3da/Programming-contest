#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

int main() {
  int n;
  while (cin >> n) {
    vector<int> a(n);
    vector<bool> b(n);
    b.push_back(true);
    for (auto &i : a) cin >> i;
    for (int i = n - 1; i >= 0; --i) {
      if (i + a[i] + 1 <= n)
        b[i] = b[i + a[i] + 1];
    }

    for (int i = 0; i <= n; ++i) {
      if (b[i]) {
        cout << i << endl;
      }
    }
  }
  return 0;
}
