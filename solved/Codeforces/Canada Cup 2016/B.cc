#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  long long n;
  char s;
  map<char, int> cost;
  cost['a'] = 4;
  cost['b'] = 5;
  cost['c'] = 6;
  cost['d'] = 3;
  cost['e'] = 2;
  cost['f'] = 1;
  while (scanf("%lld%c", &n, &s) == 2) {
    n--;
    long long t = n / 4;
    long long c = t * 16;
    n %= 4;
    n++;
    if (n & 1) {
      c += cost[s];
    } else {
      c += 7;
      c += cost[s];
    }
    cout << c << endl;

  }
  return 0;
}
