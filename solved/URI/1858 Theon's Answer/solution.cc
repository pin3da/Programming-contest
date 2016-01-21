#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    int best = 10000, id = -1, t, i = 0;

    while (n--) {
      cin >> t;
      if (t < best) {
        best = t;
        id = i + 1;
      }
      ++i;
    }
    cout << id << endl;
  }
  return 0;
}
