#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 505;

int a[MN];

int n;
bool next_move(int &i) {
  i = 0;
  for (; i < n; ++i) {
    if (a[i] == (i + 1))
      return true;
  }
  return false;
}

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  while (cin >> n && n > 0) {
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    int i = 0;
    while (next_move(i)) {
      a[i] = 0;
      for (int j = 0; j < i; ++j)
        a[j]++;
    }
    int ok = accumulate(a, a + n, 0) == 0;
    puts(ok ? "S" : "N");
  }
  return 0;
}
