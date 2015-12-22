using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void solve(long long s, long long d) {
  long long cur = s;
  while (cur < d) {
    s++;
    cur += s;
  }
  cout << s << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long s, d;
  while (cin >> s >> d) {
    solve(s, d);
  }
  return 0;
}
