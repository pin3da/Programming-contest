#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  cout << fixed << setprecision(2);
  int t; cin >> t;
  while (t--) {
    int s, c; double r;
    cin >> s >> c >> r;
    vector<double> a(s);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    for (int i = 0; i < c; ++i)
      a[i] += r;

    double time = 0;
    for (int i = 0; i < s; ++i)
      time += 1.0 / a[i];

    cout << time << endl;
  }
  return 0;
}
