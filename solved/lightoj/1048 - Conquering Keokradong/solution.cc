using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int inf = 3210123;

bool check(vector<int> &dist, int tar, int k) {
  int accum = 0;
  for (int i = 0; i < dist.size(); ++i) {
    if (accum + dist[i] <= tar) {
      accum += dist[i];
    } else {
      if (dist[i] > tar)
        return false;
      accum = dist[i];
      k--;
    }
  }
  return k >= 0;
}

void gen_ans(vector<int> &dist, int tar, int k) {
  printf("%d\n", tar);
  int accum = 0;
  deque<int> ans;
  ans.push_back(0);
  for (int i = 0; i < dist.size(); ++i) {
    if (accum + dist[i] <= tar) {
      accum += dist[i];
    } else {
      accum = dist[i];
      ans.push_back(i);
      k--;
    }
  }
  ans.push_back(dist.size());

  int i = ans.size() - 1;
  while (k > 0) {
    if (ans[i] - ans[i - 1] > 1) {
      ans.insert(ans.begin() + i, ans[i] - 1);
      k--;
    } else {
      i--;
    }
  }

  vector<int> pref(dist.size(), 0);
  pref[0] = dist[0];
  for (int i = 1; i < dist.size(); ++i)
    pref[i] = pref[i - 1] + dist[i];

  for (int i = 1; i < ans.size(); ++i) {
    if (i == 1)
      printf("%d\n", pref[ans[i] - 1]);
    else
      printf("%d\n", pref[ans[i] - 1] - pref[ans[i - 1] - 1]);
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> dist(n + 1);
  for (int i = 0; i < n + 1; ++i) {
    cin >> dist[i];
  }
  int lo = 1, hi = inf;
  while (lo < hi) {
    int mid = (lo  + hi) >> 1;
    if (check(dist, mid, k))
      hi = mid;
    else
      lo = mid + 1;
  }

  gen_ans(dist, lo, k);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
}
