#include <bits/stdc++.h>

using namespace std;

const int CASES = 100;
int main() {
  for (int i = 0; i < CASES; ++i) {
    int n = (random() % 254) + 3;
    cout << n << endl;
    for (int j = 0; j < n; ++j) {
      cout << random() % 256 + 1 << endl;
    }
  }
  return 0;
}
