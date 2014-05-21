using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 111


int p[MN];
int t[MN];

int main() { ___

  int n, r ,a,b;
  while (cin>>n>>r>>a>>b) {
    int c = (n  + (r - 1 ) )/ r;
    int xa = (a + (r - 1 ) )/ r;
    int ya = (a % r) - 1;
    if (ya < 0) ya = r - 1;
    int xb = (b + (r - 1 ) )/ r;
    int yb = (b % r) - 1;
    if (yb < 0) yb = r - 1;

    if (xa == xb) {
      cout<<1<<endl;
      continue;
    }



    int ans = (xb  -1 == xa )? 2 : 3;
    if (ya == 0) ans--;
    if (yb == (r - 1)) ans--;

    if ( ((ya == yb) or ((yb + 1) == ya) or (yb >= ya)) and ans > 1) ans--;
    cout<<ans<<endl;
  }

  return 0;
}
