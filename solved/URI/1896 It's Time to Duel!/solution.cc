#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
struct card {
  int x, y, z;
};
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  card exodia;
  cin >> n >> exodia.x >> exodia.y >> exodia.z;
  vector<card> deck(n);
  for (card &d : deck)
    cin >> d.x >> d.y >> d.z;

  int seen = 0;
  for (int i = 0; i < (1 << n) && ! seen; ++i) {
    if (__builtin_popcount(i) < 2)
      continue;

    int a = 0, b = 0, c = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        a += deck[j].x;
        b += deck[j].y;
        c += deck[j].z;
      }
    }
    if (a == exodia.x && b == exodia.y && c == exodia.z) {
      seen = true;
    }
  }

  if (seen)
    cout << "Y" << endl;
  else
    cout << "N" << endl;
  return 0;
}

