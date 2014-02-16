using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 111

string line;

int solve(int index) {
  char cur = line[index];
  int dist = 1;
  int ans = 1;
  while (index + dist < line.size()) {
    if (line[index + dist] == cur and (dist % 2)) {
      ans++;
      index = index + dist;
      dist = 1;
    } else {
      dist ++;
    }
  }
  return ans;
}

int main() { ___

  cin>>line;

  int ans = 1;
  for (int i = 0; i < line.size(); ++i) {
    ans = max(ans, solve(i));
  }
   cout<<ans<<endl;
  return 0;
}
