#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    int r1, r2, cx, cy;
    cin >> cx >> cy >> r1 >> r2;
    n *= 2;
    vector<int> in(2);
    vector<int> edge(2);
    int x, y;
    for (int t = 0; t < n; ++t) {
      cin >> x >> y;
      x -= cx;
      y -= cy;
      if (x * x + y * y < r1 * r1) in[t & 1]++;
      else if (x * x + y * y <= r2 * r2) edge[t & 1]++;
    }
    pair<int, int> c(in[0], edge[0]), p(in[1], edge[1]);
    if (c == p)
      cout << "C = P" << endl;
    else if (c < p)
      cout << "P > C" << endl;
    else
      cout << "C > P" << endl;
  }
  return 0;
}
