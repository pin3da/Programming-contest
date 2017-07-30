#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

char a[] = {'^', '>','v', '<'};

int get_pos(char c) {
  for (int i = 0; i < 4; ++i) {
    if (c == a[i]) return i;
  }
  assert(false);
  return -1;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  string s(2, '0');
  cin >> s[0] >> s[1];
  int n; cin >> n;
  n %= 4;
  int i = get_pos(s[0]);
  char end_cw = a[(i + n) % 4];
  char end_ccw = a[(i - n + 4) % 4];

  if ((end_cw == end_ccw) || (end_cw != s[1] && end_ccw != s[1])) {
    puts("undefined");
  } else if (end_cw == s[1]) {
    puts("cw");
  } else if (end_ccw == s[1]) {
    puts("ccw");
  } else {
    puts("undefined");
  }

  return 0;
}
