// http://codeforces.com/contest/451/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


int main() { ___

  int n, m;cin>>n>>m;
  int t = 0;
  while (n and m) {
    n--;
    m--;
    t ^= 1;
  }

  if (!t) {
    cout<<"Malvika"<<endl;
  } else
    cout<<"Akshat"<<endl;

  return 0;
}