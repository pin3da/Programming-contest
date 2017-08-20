#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

struct data{
  int to, x, y;
  data() {}
  data(int a, int b, int c): to(a), x(b), y(c) {}
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m, a, b, x, y;
  while (cin >> n >> m) {
    vector<pair<int, int> > ans(n);
    vector<bool> chk(n);
    vector<data> info[n];
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> x >> y;
      a--; b--;
      info[a].push_back(data(b, x, y));
      info[b].push_back(data(a, -x, -y));
    }
    queue<data> Q;
    Q.push(data(0, 0, 0));
    chk[0] = true;
    ans[0] = make_pair(0, 0);


    while (!Q.empty()) {
      data cur = Q.front(); Q.pop();
      for (int i = 0; i < info[cur.to].size(); i++) {
        int v = info[cur.to][i].to;
        int xt = cur.x + info[cur.to][i].x;
        int yt = cur.y + info[cur.to][i].y;

        if (chk[v]) continue;
        chk[v] = true;
        ans[v] = make_pair(xt, yt);
        Q.push(data(v, xt, yt));
      }
    }
    for (int i = 0; i < n; i++)
      cout << ans[i].first << " " << ans[i].second <<endl;
  }

}
