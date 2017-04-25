// http://codeforces.com/contest/401/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 4004


int d1[MN], d2[MN];

int zeros, ones;
string ans;
int id;


int solve2(int z, int o, int oa, int za) {

  int change = 1;
  while (id < (zeros + ones) and change) {
    change = 0;
    if (oa < 1) {
      if (o) {
        ans[id++] = '1';
        za = 0;
        o--;
        change = 1;
        oa++;
        continue;
      }
    }

    if (za < 1) {
      if (z) {
        ans[id++] = '0';
        oa = 0;
        z--;
        za++;
        change = 1;
      }
    }
  }

  return id == (zeros + ones);
}

int solve(int z, int o) {

  while ((o - z > 1)) {
    if (!o or !z) break;
    ans[id++] = '1';
    ans[id++] = '1';
    o -= 2;
    ans[id++] = '0';
    z--;
  }
  if (o - z <= 1)
    return solve2(z,o,0,1);
  else{
    if (o < 3){
      while(o) {
        ans[id++] = '1';
        o--;
      }
    }

    return id == (zeros + ones);
  }
}




int main() { ___

  cin>>zeros>>ones;
  ans = string(zeros+ones,'0');
  id = 0;
  if (solve(zeros, ones)) {
    cout<<ans<<endl;
  } else {
    id = 0;
    ans[id++] = '0';
    if(solve(zeros-1,ones)) {
      cout<<ans<<endl;
    }
    else cout<<-1<<endl;
  }

  return 0;
}