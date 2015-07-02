using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN = 1111;

int count(vector<vector<int> > &pos, int val, int b, int e) {
  vector<int>::iterator lo = lower_bound(pos[val].begin(), pos[val].end(), b);
  vector<int>::iterator hi = upper_bound(pos[val].begin(), pos[val].end(), e);
  return hi - lo;
}

void solve() {
  int n, q, t;
  cin >> n >> q;
  vector<vector<int> > pos(MN);
  for (int i = 0; i < n; ++i) {
    cin >> t;
    pos[t].push_back(i);
  }

  int b, e;
  while (q--) {
    cin >> b >> e;
    int last = -1;
    int ans = MN;
    for (int i = 1; i < 1001; ++i) {
      int frec = count(pos, i, b, e);
      if (frec > 1) {
        ans = 0;
        break;
      }
      if (frec > 0 && last > 0) {
        ans = min(ans, i - last);
      }
      if (frec > 0)
        last = i;
    }
    printf("%d\n", ans);

  }

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d:\n", i + 1);
    solve();
  }
  return 0;
}
