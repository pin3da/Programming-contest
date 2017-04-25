// http://codeforces.com/contest/678/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b;
  while (cin >> a >> b) {
    long long m = b - (a % b);
    cout << a + m << endl;
  }
  return 0;
}
