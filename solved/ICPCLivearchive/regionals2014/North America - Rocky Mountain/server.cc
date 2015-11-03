using namespace std;
#include <bits/stdc++.h>

int main() {
  int n, T;
  while (cin >> n >> T) {
    int cur = 0;
    int last  = -1;
    int t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      if (cur + t <= T) {
        last = i;
        cur += t;
      } else {
        T = 0;
      }
    }
    cout << last + 1 << endl;
  }
  return 0;
}
