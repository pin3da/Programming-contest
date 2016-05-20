#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    string s1, s2; cin >> s1 >> s2;
    long long a = stoll(s1, 0, 2), b = stoll(s2, 0, 2);
    long long ans = __gcd(a, b);
    cout << "Pair #" << i + 1 << ": ";
    cout << (ans == 1 ? "Love is not all you need!" : "All you need is love!") << endl;
  }
  return 0;
}
