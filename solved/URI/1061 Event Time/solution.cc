#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string t;
  long long d,  h  , m,  s,
            dd, hh, mm, ss;
  cin >> t >>  d >>  h >> t >>  m >> t >>  s;
  cin >> t >> dd >> hh >> t >> mm >> t >> ss;
  long long ans = (dd - d) * 3600 * 24 + (hh - h) * 3600 + (mm - m) * 60 + (ss - s);
  cout << ans / (3600 * 24) << " dia(s)" << endl;
  ans %= 3600 * 24;
  cout << ans / 3600 << " hora(s)" << endl;
  ans %= 3600;
  cout << ans / 60 << " minuto(s)" << endl;
  ans %= 60;
  cout << ans << " segundo(s)" << endl;
  return 0;
}
