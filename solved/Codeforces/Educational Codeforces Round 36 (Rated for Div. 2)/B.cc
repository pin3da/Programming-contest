#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int del_left(int n, int pos, int l, int r) {
  if (l - 1 == 0) return 0;
  return abs(l - pos) + 1;
}

int del_right(int n, int pos, int l, int r) {
  if (r == n) return 0;
  return abs(r - pos) + 1;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, pos, l, r;

  cin >> n >> pos >> l >> r;

  int moved = del_left(n, pos, l, r) != 0;
  int a = del_left(n, pos, l, r) + del_right(n, moved ? l : pos, l, r);
  moved = del_right(n, pos, l, r) != 0;
  int b = del_right(n, pos, l, r) + del_left(n, moved ? r : pos, l, r);

  cout << min(a, b) << endl;
  return 0;
}
