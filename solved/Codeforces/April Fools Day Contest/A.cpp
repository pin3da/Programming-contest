// http://codeforces.com/contest/171/problem/A

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'

int main() { ___

  string a,b;
  cin>>a>>b;
  reverse(b.begin(), b.end());
  stringstream ss(a);
  stringstream s(b);
  long long x,y;
  ss>>x;s>>y;
  cout<<(x+y)<<endl;

  return 0;
}