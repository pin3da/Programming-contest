// http://codeforces.com/contest/440/problem/A

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'

int main() { ___

  int n;

  while (cin>>n) {
    vector<int> all(n, 1);
    for (int i = 0; i < n - 1; ++i) {
      int tmp;cin>>tmp;
      all[tmp - 1] = 0;
    }

    for (int i = 0; i < n; ++i) {
      if (all[i])
        cout<<(i+1)<<endl;
    }
  }
  return 0;
}