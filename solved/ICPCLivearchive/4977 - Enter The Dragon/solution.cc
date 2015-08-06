using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void solve() {

  int n, k;
  cin >> n >> k;
  vector<int> f(n, true);
  vector<int> d(k);
  vector<int> used(k, 0);
  for (int i = 0; i < k; ++i) {
    cin >> d[i];
  }

  set<pair<int, int> > s;
  int zeroes = 0;
  vector<int> ans(k);
  vector<int> last(n + 10, -1);

  for (int i = 0; i < k; ++i) {
    if (d[i] == 0) {
      ans[zeroes] = 0;
      s.insert(make_pair(i, zeroes));
      zeroes++;
    } else {
      auto it = s.lower_bound(make_pair(last[d[i]], 0));
      if (it == s.end()) {
        cout << "NO" << endl;
        return;
      }

      ans[it->second] = d[i];
      last[d[i]] = i;
      s.erase(it);
    }
  }


  cout << "YES" << endl;
  for (int i = 0; i < zeroes; ++i) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}

