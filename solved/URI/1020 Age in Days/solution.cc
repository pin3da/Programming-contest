#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    cout << n / 356 << " ano(s)" << endl;
    n %= 365;
    cout << n / 30 << " mes(es)" << endl;
    n %= 30;
    cout << n << " dia(s)" << endl;
  }
  return 0;
}
