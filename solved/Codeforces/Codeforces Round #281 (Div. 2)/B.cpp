// http://codeforces.com/contest/493/problem/B

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() { ___
  vector<vector<int> > sequence(2);
  int n;
  cin >> n;
  int last, t;
  vector<long long> accum(2, 0);
  for (int i = 0; i < n; ++i) {
    cin >> t;
    int index = (t > 0 ? 0 : 1);
    sequence[index].push_back(fabs(t));
    last = index;
    accum[index] += fabs(t);
  }
  if (accum[0] > accum[1])
    cout << "first" << endl;
  else if (accum[1] > accum[0])
    cout << "second" << endl;
  else {
    int t = min(sequence[0].size(), sequence[1].size());
    for (int i = 0; i < t; ++i) {
      if (sequence[0][i] > sequence[1][i]) {
        cout << "first" << endl;
        return 0;
      }
      if (sequence[1][i] > sequence[0][i]) {
        cout << "second" << endl;
        return 0;
      }
    }
    if (last == 0)
      cout << "first" << endl;
    else
      cout << "second" << endl;
  }
  return 0;
}