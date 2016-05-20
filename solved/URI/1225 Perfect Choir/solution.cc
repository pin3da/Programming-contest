#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> a(n);
    long long total = 0;
    for (auto &i : a) {
      cin >> i;
      total += i;
    }
    if (total % n) {
      cout << -1 << endl;
      continue;
    }
    int tar = total / n;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += abs(a[i] - tar);
    }
    cout << 1 + (ans >> 1) << endl;
  }
  return 0;
}
