#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m, c;
  while (cin >> n >> m >> c && (n + m + c)) {
    cout << (((n - 7) * (m - 7) + c) >> 1) << endl;
  }
  return 0;
}
