// http://codeforces.com/contest/432/problem/B

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl;
#define endl '\n'

const int MN = 101010;
int h[MN], v[MN];
int f[MN], s[MN];

int main() { ___

  int n; cin >> n;
  int x, y;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    h[x]++; v[y]++;
    f[i] = x;
    s[i] = y;
  }

  for (int i = 0; i < n; ++i) {
    int first  = n - 1 + h[s[i]];
    int second = n - 1 - h[s[i]];
    cout << first << " " << second << endl;
  }


  return 0;
}