#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    double best = 7.99, t;
    int id = -1, i = 0;

    while (n--) {
      cin >> i >> t;
      if (t > best) {
        best = t;
        id = i;
      }
    }
    if (id < 0)
      cout << "Minimum note not reached" << endl;
    else
      cout << id << endl;
  }
  return 0;
}
