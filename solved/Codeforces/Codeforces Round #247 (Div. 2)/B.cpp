// http://codeforces.com/contest/431/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


const int MN = 10001;

int h[5][5];

int main() { ___

  For(i,5) For (j,5) cin>>h[i][j];

  vector<int> cur;
  For(i,5) cur.push_back(i);

  int ans = 0;

  do {

    int tmp = 0;
    for (int i = 0 ; i < 5; ++i) {
      for (int j = i; j + 1 < 5; j += 2) {
        tmp += h[cur[j]][cur[j+1]] + h[cur[j+1]][cur[j]] ;
      }
    }

    ans = max(ans, tmp);
  } while (next_permutation(cur.begin(), cur.end()));

  cout<<ans<<endl;
  return 0;
}

