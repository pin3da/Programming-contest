#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

unsigned long long digroot(unsigned long long n) {
  if (n < 10) return n;
  unsigned long long ans = 0;
  while (n > 0) {
    ans += n % 10;
    n /= 10;
  }
  return digroot(ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unsigned long long n;
  while (cin >> n && n) {
    cout << digroot(n) << endl;
  }

  return 0;
}
