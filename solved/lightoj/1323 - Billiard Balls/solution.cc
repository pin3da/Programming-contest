using namespace std;
#include <bits/stdc++.h>

void solve() {
  int l, w, n, k;
  cin >> l >> w >> n >> k;
  int x, y;
  char v, h;
  vector<pair<int, int> > pos;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y >> h >> v;
    if (v == 'E')
      x = k + x;
    else
      x = fabs(x - k);
    if (h == 'N')
      y = y + k;
    else
      y = fabs(y - k);

    if ((x / l) & 1)
      x = l - (x % l);
    else
      x = x % l;

    if ((y / w) & 1)
      y = w - (y % w);
    else
      y = (y % w);

    pos.push_back(make_pair(x, y));
  }


  sort(pos.begin(), pos.end());
  for (int i = 0; i < pos.size(); ++i)
    cout << pos[i].first << " " << pos[i].second << endl;


}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case " << (i + 1) << ":" << endl;
    solve();
  }

  return 0;
}
