// http://codeforces.com/contest/387/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MM 1000000

int main() { ___

  int h1, m1,h2,m2;
  scanf("%d:%d", &h1,&m1);
  scanf("%d:%d", &h2,&m2);

  if (h1 < h2) {
    h1 += 24;
  } else if (h1 == h2 and m1 < m2) {
    h1 += 24;
  }

  int hans = h1 - h2;
  int mans = m1 - m2;
  if ( m1 < m2) {
    mans += 60;
    hans--;
  }

  printf("%02d:%02d\n", hans, mans);
//  cout<<hans<<":"<<mans<<endl;


  return 0;
}