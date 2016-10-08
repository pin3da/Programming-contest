#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x  " = " << (x) << endl

const int MN = 5 * 1e5 + 100;
int a[MN];
int b[MN];

int main () {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    sort(a, a + n);
    memset(b, 0, sizeof b);
    int i = 0, j = (n + 1) >> 1;
    while (j < n) {
      if (2 * a[i] <= a[j]) {
        i++;
        b[i] = 1;
      }
      j++;
    }
    cout << n - accumulate(b, b + n, 0) << endl;
  }
  return 0;
}
