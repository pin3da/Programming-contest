#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int t, x, y; cin >> t;
  while(t--) {
    int n; cin >> n;
    priority_queue<pii, vector<pii>, greater<pii> > PQ;
    for(int i = 0; i < n; i++) {
      cin >> x >> y;
      PQ.push({x, y});
    }
    int ans = 0, cur = 0;
    while(!PQ.empty()) {
      pii c = PQ.top();
      PQ.pop();
      if(cur < c.first) {
        ans += c.first - cur;
        cur = c.first;
      }
      cur += (c.second == -1) ? 2 : 1;
      if(c.second != -1)
        PQ.push({c.second, -1});

    }
    cout << ans << endl;
  }
}
