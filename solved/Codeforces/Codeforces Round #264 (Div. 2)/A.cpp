// http://codeforces.com/contest/463/problem/A

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'

int main() { ___

  int n, s;

  while (cin>>n>>s) {
    int best = -1;
    s *= 100;
    int a,b,c;
    while (n--) {
      cin >> a >> b;
      c = a * 100 + b;
      if (c <= s) {
        if (b == 0)
          best = max (best, 0);
        else
          best = max (best, 100 - b);
      }
    }
    cout<<best<<endl;

  }
  return 0;
}