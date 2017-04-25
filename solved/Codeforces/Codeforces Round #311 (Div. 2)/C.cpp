// http://codeforces.com/contest/557/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

struct entry{
  int l, c;
  entry() {}
  bool operator < (const entry &o) const {
    if (l == o.l)
      return c < o.c;
    return l > o.l;
  }
};


int get_min(vector<vector<int>> &cost, int x, int val) {
  int cur = 0, ans = 0;
  if (val <= 0)
    return 0;

  for (int i = 0; i < cost.size(); ++i) {
    vector<int> &t = cost[i];
    if (t.size() == 0)
      continue;
    auto it = lower_bound(t.begin(), t.end(), val);
    it--;
    int p = it - t.begin() + 1;
    if (cur + p <= x) {
      cur += p;
      ans += i * p;
    } else {
      int missing = x - cur;
      return ans + missing * i;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  cin >> n;
  vector<entry> l(n);
  vector<vector<int>> cost_frec(222);
  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i].l;
    pos[i] = l[i].l;
  }

  for (int i = 0; i < n; ++i) {
    cin >> l[i].c;
    cost_frec[l[i].c].push_back(l[i].l);
  }


  sort(l.begin(), l.end());

  int best = (1 << 30);

  for (int i = 0; i < cost_frec.size(); ++i)
    sort(cost_frec[i].begin(), cost_frec[i].end());

  sort(pos.rbegin(), pos.rend());

  vector<int> mio(100010, 0);
  vector<int> cost(100010, 0);
  for (int i = 0; i < l.size(); ++i) {
    cost[l[i].l] += l[i].c;
  }

  for (int i = cost.size() - 1; i >= 0; --i) {
    if (i != cost.size() - 1)
      cost[i] += cost[i + 1];
  }

  for (int i = 0; i < pos.size(); ++i)
    mio[pos[i]]++;

  for (int i = mio.size() - 1; i >= 0; --i)
    if (i != mio.size() - 1)
      mio[i] += mio[i + 1];

  pos.resize(unique(pos.begin(), pos.end()) - pos.begin());

  for (int i = 0; i < pos.size(); ++i) {
    int ans = 0;

    // cout << "max " << pos[i] << " ";
    if (i)
      ans += cost[pos[i - 1]];

    // cout << "ant " << ans << " ";

    int cur = n - mio[pos[i] + 1];
    int m  = mio[pos[i]] - mio[pos[i] + 1];
    int x  = cur - 2 * m + 1;

    // cout << "x " << x << endl;

    if (x > 0) {
      ans += get_min(cost_frec, x, pos[i]);
      // D(get_min(cost_frec, x, pos[i]));
      // D(ans);
    }
    best = min(best, ans);
  }

  cout << best << endl;
  return 0;
}
