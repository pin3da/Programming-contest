// http://codeforces.com/contest/622/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    int a = (line[0] - '0') * 10 + line[1] - '0';
    int b = (line[3] - '0') * 10 + line[4] - '0';
    int x;
    cin >> x;
    int d = a * 60 + b;
    d += x;
    d %= 24 * 60;
    cout << setw(2) << setfill('0') << d / 60;
    cout << ":";
    cout << setw(2) << setfill('0') << d % 60 << endl;
  }
  return 0;
}
