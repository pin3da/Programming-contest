using namespace std;
#include <bits/stdc++.h>
#define endl '\n'


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n; cin  >> n;
  vector<pair<int, int> > p(n);
  int mmax = 0;
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
    mmax = max(mmax, p[i].first);
  }

  sort(p.begin(), p.end());

  int last = - 1;
  for (int i = 0; i < n; ++i) {
    if (p[i].second >= last)
      last = p[i].second;
    else
      last = p[i].first;
  }

  cout << last << endl;
  return 0;
}
