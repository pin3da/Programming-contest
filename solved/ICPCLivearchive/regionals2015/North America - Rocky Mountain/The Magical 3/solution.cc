#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  long long n;
  while (cin >> n) {
    if (n < 3) {
      cout << "No such base" << endl;
    } else {
      if (n == 3) {
        cout << 4 << endl;
      } else {
        set<long long> p;
        n -= 3;
        for (long long i = 1; i * i <= n; ++i) {
          if ((n % i) == 0) {
            p.insert(i);
            p.insert(n / i);
          }
        }
        int seen = false;
        for (auto &i : p) {
          if (i > 3) {
            cout << i << endl;
            seen = true;
            break;
          }
        }
        if (!seen)
          cout << "No such base" << endl;
      }
    }
  }

  return 0;
}
