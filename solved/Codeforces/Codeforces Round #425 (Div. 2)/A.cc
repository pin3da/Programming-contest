#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  long long n, k;
  cin >> n >> k;
  long long t = (n / k) & 1;
  puts(t ? "YES" : "NO");
  return 0;
}
