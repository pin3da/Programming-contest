// http://codeforces.com/contest/412/problem/B

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'

int main() { ___

  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin>>a[i];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  cout<<a[k - 1]<<endl;

  return 0;
}