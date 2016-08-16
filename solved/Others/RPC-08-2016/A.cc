#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;
int check(vector<int> &a, int dist, int loco, int N) {
  int pos = 0, i = 0, ans = 0;
  while (pos < N) {
    if (i >= a.size()) {
      ans++; // go to net
      break;
    }
    int last = i;
    while (i < a.size() && a[i] <= pos + dist) i++;
    ans++; // go to lux
    if (last == i) { // can't take any ):
      pos = max(pos + dist, a[i] - 1); // go to net
    } else {
      pos += dist; // go to Lux
    }
  }
  return ans <= loco;
}

void solve() {
  long long n, w, l;
  cin >> n >> w >> l;
  vector<int> pos(w);
  for (int i = 0; i < w; ++i)
    cin>> pos[i];

  long long lo = 1, hi = n;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (check(pos, mid, l, n))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
