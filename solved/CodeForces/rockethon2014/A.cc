using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 111

int main() { ___

  string line;
  cin>>line;

  char ant = 'm';
  int ans = 0, tmp = 1;

  for (int i = 0; i < line.size(); ++i ) {
    if (ant == line[i]) {
      tmp++;
    } else {
      if (tmp % 2 == 0) {
        ans++;
      }
      tmp = 1;
    }
    ant = line[i];
  }

  if (tmp % 2 == 0) {
    ans++;
  }

  cout<<ans<<endl;

  return 0;
}
