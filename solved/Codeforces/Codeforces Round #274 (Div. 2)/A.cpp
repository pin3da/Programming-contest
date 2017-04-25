// http://codeforces.com/contest/479/problem/A

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


int solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (b == 1) {
    int d = b + min(a, c);
    if (max(a, c) == 1)
      return d + 1;
    return d * max(a, c);
  }

  if (a == 1) {
    b = a + b;
    if (c == 1)
      return b + c;
    return b * c;
  }

  if (c == 1) {
    b = c + b;
    if (a == 1)
      return a + b;
    return a * b;
  }
  return a * b * c;
}

int main() {

  cout << solve() << endl;

  return 0;
}