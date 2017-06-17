#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int h, m;
  scanf("%d:%d", &h, &m);
  int ans = 0;
  while (true) {
    char tmp[10];
    sprintf(tmp, "%02d:%02d", h, m);
    if (tmp[0] == tmp[4] && tmp[1] == tmp[3]) {
      printf("%d\n", ans);
      return 0;
    }
    m++;
    if (m == 60) {
      m = 0;
      h++;
      if (h == 24) h = 0;
    }
    ans++;
  }

  return 0;
}
