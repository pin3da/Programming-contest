// http://codeforces.com/contest/397/problem/B

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define endl '\n'


bool solve2(int n, int l, int r) {

  int lo = 1;
  int hi = (n / r) + 1;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if ((l * mid) <= n and (r * mid) >= n ) {
      return true;
    } else if ( n < (l*mid) ) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return false;
}



int solve(int n, int l, int r) {

  int lo = 1;
  int hi = (n / r) + 1;
  while (lo < hi) {

    if (lo + 1 == hi) {
      return (l * hi) <= n and (r * hi) >= n;
    }

    int mid = (lo + hi) >> 1;
    if ((l * mid) <= n and (r * mid) >= n ) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return 0;
}

int main() { ___

  int t;cin>>t;
  while (t--) {
    int n,r,l;
    cin>>n>>l>>r;
    //cout << solve2(n, l , r) << endl;
    if (solve2(n,l,r))
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;

  }

  return 0;
}