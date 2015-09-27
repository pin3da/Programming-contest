using namespace std;
#include <bits/stdc++.h>
#define D(x)  cout << #x " = " << (x) << endl

int main() {
  int n, s, j, d;
  cin >> n >> s >> j >> d;
  string l; cin >> l;

  int ga = 0, gb = 0, sa = 0, sb = 0;
  for (int i = 0; i < n; i++) {
    if (l[i] == 'A')
      ga++;
    else
      gb++;

    if (ga >= j || gb >= j) {
      if (abs(ga - gb) < d) continue;
      if (ga > gb) {
        sa++;
        ga = gb = 0;
      } else {
        sb++;
        ga = gb = 0;
      }
      if (sa == s || sb == s) break;
    }
  }

  cout << sa << " " << sb << endl;

  return 0;
}
