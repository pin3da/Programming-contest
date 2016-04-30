#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int mindiff = 10000;
int mina = 10000;
int minb = 10000;

void solve(string &a, string &b, int id) {
  if (id == a.size()) {
    int va = atoi(a.c_str()),
        vb = atoi(b.c_str());

    if (abs(va - vb) < mindiff) {
      mindiff = abs(va - vb);
      mina = va;
      minb = vb;
    } else if (abs(va - vb) == mindiff) {
      if (va < mina)  {
        mina = va;
        minb = vb;
      } else if (va == mina) {
        if (vb < minb)
          minb = vb;
      }
    }
    return;
  }
  if ((a[id] != '?') && (b[id] != '?')) {
    solve(a, b, id + 1);
    return;
  }

  if ((a[id] == '?') && (b[id] == '?')) {
    for (char i = '0'; i <= '9'; ++i) {
      for (char j = '0'; j <= '9'; ++j) {
        a[id] = i;
        b[id] = j;
        solve(a, b, id + 1);
        a[id] = b[id] = '?';
      }
    }
    return;
  }
  if (a[id] == '?') {
    for (char i = '0'; i <= '9'; ++i) {
      a[id] = i;
      solve(a, b, id + 1);
    }
    a[id] = '?';
    return;
  }

  assert(b[id] == '?');
  for (char i = '0'; i <= '9'; ++i) {
    b[id] = i;
    solve(a, b, id + 1);
  }
  b[id] = '?';
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    string a, b; cin >> a >> b;
    cout << "Case #" << (i + 1) << ": ";
    mina = minb = mindiff = 10000;
    solve(a, b, 0);
    int len = a.size();
    a = to_string(mina);
    b = to_string(minb);
    while (a.size() < len) a = '0' + a;
    while (b.size() < len) b = '0' + b;

    cout << a << ' ' << b << endl;
  }

  return 0;
}
