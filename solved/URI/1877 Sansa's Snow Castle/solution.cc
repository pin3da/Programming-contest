#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1000 + 100;
int a[MN];
int b[MN];

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int n, k;
  while (cin >> n >> k) {
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    for (int i = 1; i < n; ++i) {
      if (a[i - 1] < a[i])
        b[i] = 1;
      else
        b[i] = -1;
    }

    int ant = 0;
    int flips = 0;
    for (int i = 1; i < n; ++i) {
      if (b[i] != ant) {
        flips++;
        ant = b[i];
      }
    }
    int ok = (k + k) == flips;
    puts(ok ? "beautiful" : "ugly");
  }

  return 0;
}
