#include <bits/stdc++.h>

using namespace std;

const int MN = 1e5 + 100;
int a[2 * MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i + n] = a[i];
    }
  }
  return 0;
}
