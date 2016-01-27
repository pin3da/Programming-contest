#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct entry{
  int c, b;
};

typedef pair<pair<long long, int>, int> tt;

tt dp[100005][55];
bool seen[100005][55];

tt go(vector<entry> &a, int i, int cap) {
  if (a.size() == i)
    return make_pair(make_pair(0, 0), cap);

  if (seen[i][cap])
    return dp[i][cap];

  seen[i][cap] = true;
  tt best = go(a, i + 1, cap);
  if (cap + a[i].c <= 50) {
    tt other = go(a, i + 1, cap + a[i].c);
    other.first.first += a[i].b;
    other.first.second += 1;
    best = max(other, best);
  }
  return dp[i][cap] = best;
}

void solve() {
  int n;
  cin >> n;
  vector<entry> a(n);
  for (auto &i: a)
    cin >> i.b >> i.c;


  memset(seen, 0, sizeof seen);
  tt ans = go(a, 0, 0);
  cout << ans.first.first << " brinquedos" << endl;
  cout << "Peso: " << + ans.second << " kg" << endl;
  cout << "sobra(m) " << n - ans.first.second << " pacote(s)" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  int first = false;
  while (tc--) {
    first = false;
    solve();
    cout << endl;
  }
  return 0;
}
