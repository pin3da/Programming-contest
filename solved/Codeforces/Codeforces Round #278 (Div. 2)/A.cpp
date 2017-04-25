// http://codeforces.com/contest/488/problem/A

using namespace std;
#include <bits/stdc++.h>

bool cool(int n) {
  n = abs(n);
  while (n) {
    if (n % 10 == 8) return true;
    n /= 10;
  }
  return false;
}

int main() {

  int n;
  while (cin >> n) {
    int ans = 1;
    while (!cool(++n)) ans++;
    cout << ans << endl;
  }
  return 0;
}