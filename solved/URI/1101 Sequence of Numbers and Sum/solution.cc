#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n > 0 && m > 0)) {
    if (m < n)
      swap(n, m);
    long long a = 0;
    for (int i = n; i <= m; ++i) {
      cout << i << " ";
      a += i;
    }
    cout << "Sum=" << a << endl;
  }
  return 0;
}
