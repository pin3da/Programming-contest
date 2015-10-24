using namespace std;
#include <bits/stdc++.h>

int main() {
  int tc; cin >> tc;
  while (tc--) {
    long long a, b;
    cin >> a >> b;
    if (a == 0 || b == 0) {
      cout << "First" << endl;
      continue;
    }

    long long m = a + b - 2;
    if (m & 1) {
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
  }
  return 0;
}
