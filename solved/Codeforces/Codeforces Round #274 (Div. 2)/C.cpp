// http://codeforces.com/contest/479/problem/C

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


int main() { ___

  int n;
  cin >> n;
  vector<pair<int, int> > d(n);
  for (int i = 0; i < n; ++i)
    cin >> d[i].first >> d[i].second;


  sort(d.begin(), d.end());

  int cur = 0;
  for (int i = 0; i < n; ++i) {
    if (cur <= d[i].second)
      cur = d[i].second;
    else
      cur = d[i].first;
  }

  cout << cur << endl;

  return 0;
}