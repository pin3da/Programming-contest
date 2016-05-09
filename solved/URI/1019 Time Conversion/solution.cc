#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    cout << n / (60 * 60) << ":";
    n %= 60 * 60;
    cout << n / (60) << ":";
    n %= 60;
    cout << n << endl;
  }
  return 0;
}
