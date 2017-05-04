#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  char c[] = {'a', 'b'};
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    if (i + 1 < n) {
      printf("%c", c[cur]);
      printf("%c", c[cur]);
      cur ^= 1;
      i++;
    } else {
      printf("%c", c[cur]);
    }
  }
  puts("");

  return 0;
}
