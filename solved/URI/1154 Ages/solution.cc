#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long ans = 0;
  int t, tot = 0;
  while (cin >> t && t > 0) {
    ans += t;
    tot++;
  }
  cout << fixed << setprecision(2) << (double)ans / (double) tot << endl;
  return 0;
}
