#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, x;
  while (cin >> n >> x) {
    int b = (1 << n) - 1;
    cout << abs(b - x) << endl;
  }
  return 0;
}
