// http://codeforces.com/contest/122/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 1000001


set<int> nums;

int gen(int n) {
  if (n <= 1000) {
    nums.insert(n*10 + 4);
    nums.insert(n*10 + 7);
    gen(n*10 + 4);
    gen(n*10 + 7);
  }
}

int main() { ___


  gen(0);
  int n;cin>>n;
  foreach(it, nums) {
    if ((*it) > 0 and (n%(*it) == 0)){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
   return 0;
}