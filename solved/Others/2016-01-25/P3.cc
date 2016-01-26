#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
int sim(vector<int> &a, vector<int> &b) {
  int len = 0;
  int i = 0, j = 0, ant = 0;
  while (true) {
    while (i < a.size() && a[i] <= ant)
      i++;

    if (i == a.size())
      break;

    ant = a[i];

    len++;
    while (j < b.size() && b[j] <= ant)
      j++;

    if (j == b.size())
      break;
    ant = b[j];
    len++;
  }
  return len;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a;
  vector<int> b;
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (t > 0)
      a.push_back(t);
    else
      b.push_back(-t);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  cout << max(sim(a, b), sim(b, a)) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int p; cin >> p;
  while (p--) {
    solve();
  }
  return 0;
}
