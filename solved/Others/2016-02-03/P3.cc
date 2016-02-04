#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  /*for (int i = 1; i < 30; ++i) {
    vector<int> s(i + 1);

    for (int j = 1; j <= i; ++j) {
      int k = j;
      while (k < s.size()) {
        s[k] ^= 1;
        k += j;
      }
    }

    for (auto &i : s)
      cout << i << " ";
    cout << endl;
  }*/
  long long n;
  while (cin >> n && n) {
    for (long long i = 1; i * i <= n; ++i) {
      if (i > 1) cout << " ";
      cout << i * i;
    }
    cout << endl;
  }
  return 0;
}
