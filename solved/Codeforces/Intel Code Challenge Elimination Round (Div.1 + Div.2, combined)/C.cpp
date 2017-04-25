// http://codeforces.com/contest/722/problem/C

#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 1000000 + 100;

int cool[MN];
long long a[MN];
long long acc[MN];

long long get_sum(int i, int j) {
  long long ans = acc[j];
  if (i) return ans - acc[i - 1];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      acc[i] = a[i];
      if (i) acc[i] += acc[i - 1];
    }
    for (int i = 0; i < n; ++i) {
      cin >> cool[i];
      cool[i]--;
    }
    set<pair<int, int> > seg;
    seg.insert(make_pair(0, n - 1));
    map<pair<int, int>, long long> best;
    long long total = get_sum(0, n - 1);
    best[make_pair(0, n - 1)] = total;
    map<long long, int> ans;
    ans[total]++;

    for (int i = 0; i < n; ++i) {
      pair<int, int> q(cool[i], cool[i]);
      set<pair<int,int> >::iterator it2 = seg.lower_bound(q);
      if (it2 == seg.end()) it2--;
      while (it2->first > cool[i]) it2--;
      pair<int, int> it = *it2;
      seg.erase(it);

      long long last = best[it];
      ans[last]--;
      if (ans[last] == 0) ans.erase(last);

      if (cool[i] - 1 - it.first >= 0) {
        seg.insert(make_pair(it.first, cool[i] - 1));
        long long cur = get_sum(it.first, cool[i] - 1);
        best[make_pair(it.first, cool[i] - 1)] = cur;
        ans[cur]++;
      }

      if (it.second - cool[i] - 1 >= 0) {
        seg.insert(make_pair(cool[i] + 1, it.second));
        long long cur = get_sum(cool[i] + 1, it.second);
        best[make_pair(cool[i] + 1, it.second)] = cur;
        ans[cur]++;
      }

      if (ans.size()) {
        map<long long, int>::iterator x = ans.end();
        x--;
        cout << (x-> first) << endl;
      } else {
        cout << 0 << endl;
      }

    }

  }
  return 0;
}
