#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    long long best = 1LL << 45;
    string line, t;
    int a, b;
    while (n--) {
      cin >> line;
      cin >> a >> b;
      a -= b;
      if (a < best) {
        best = a;
        t = line;
      }
    }
    cout << t << endl;
  }
  return 0;
}
