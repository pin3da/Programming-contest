#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct st {
  int a, b, c;
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  int tid = 1;
  while (tc--) {
    int n, m; cin >> n >> m;
    vector<st> a(m);
    for (int i = 0; i < m; ++i) {
      char tmp;
      cin >> a[i].a >> a[i].b >> tmp;
      a[i].c = tmp == 'T';
    }

    int top = 1 << n;
    int ans = 0;
    for (int mask = 0; mask < top; ++mask) {
      int ok = true;
      for (int i = 0; i < m && ok; ++i) {
        int x = a[i].a, b = a[i].b, c = a[i].c;
        if ((mask >> x) & 1) {
          ok &= (((mask >> b) & 1) && c) || (!((mask >> b) & 1) && !c);
        } else {
          ok &= (((mask >> b) & 1) && !c) || (!((mask >> b) & 1) && c);
        }
      }
      if (ok) ans++;
    }
    cout << "Case #" << (tid++) << ": " << ans << endl;
  }
  return 0;
}
