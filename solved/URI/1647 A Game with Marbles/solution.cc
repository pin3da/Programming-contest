#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<int> a(n);
    for (int &i : a)
      cin >> i;

    long long debt = 0;
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      long long cur = debt + a[i];
      ans += cur;
      debt += cur;
    }
    cout << ans << endl;
  }
  return 0;
}

