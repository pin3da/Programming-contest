// http://codeforces.com/contest/513/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int a, b, c, d;

int main() { ___
  cin >> a >> b >> c >> d;
  if (a <= b)
    cout << "Second" << endl;
  else
    cout << "First" << endl;

  return 0;
}
