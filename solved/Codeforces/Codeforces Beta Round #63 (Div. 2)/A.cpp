// http://codeforces.com/contest/69/problem/A

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'

int main() { ___

  int n;
  while (cin>>n) {
    vector<int> v(3, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 3; ++j ) {
        int f; cin>>f;
        v[j] += f;
      }
    }

    int ok = 1;
    for (int i = 0; i < 3; ++i) {
      ok =  ok and (v[i] == 0);
    }

    if (ok)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;

  }

  return 0;
}