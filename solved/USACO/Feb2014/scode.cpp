using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 222

const int mod = 2000 + 14;
string line;

int z[MN][MN];

vector<int> compute_z(const string &s){
  int n = s.size();
  vector<int> z(n,0);
  int l,r;
  r = l = 0;
  for(int i = 1; i < n; ++i){
    if(i > r) {
      l = r = i;
      while(r < n and s[r - l] == s[r])r++;
      z[i] = r - l;r--;
    }else{
      int k = i-l;
      if(z[k] < r - i +1) z[i] = z[k];
      else {
        l = i;
        while(r < n and s[r - l] == s[r])r++;
        z[i] = r - l;r--;
      }
    }
  }
  z[0] = s.size();
  return z;
}

void fill_z() {

  memset(z, 0, sizeof z);
  for (int start = 0; start < line.size() ; ++start) {
    vector<int> tmp = compute_z(line.substr(start));
    for (int i = 0; i < tmp.size(); ++i)
      z[start][start + i] = tmp[i];
  }

}

int memo[MN][MN];

int dp(int b, int e) {

  if (memo[b][e] != -1) return memo[b][e];

  if ((e - b == 1) or (e - b == 0)) return memo[b][e] = 0;
  int ans = 0;
  for (int i = b; i < e; ++i) {
    if ( (i - b + 1)  ==  (e - i)) continue;
    int len = min(i - b + 1 , e - i);
    if ( (z[b][i + 1] >= len) or z[i - len + 1][e - len + 1]  >= len)
    //if ( (line.substr(b,len) == line.substr(i+1,len)) or (line.substr(i - len + 1, len) == line.substr(e - len + 1, len)))
      ans +=  ( (dp(b, i) + 1) * (dp(i+1, e) + 1) ) % mod;

  }

  return memo[b][e] = ((ans) % mod);
}


int main() {

  freopen("scode.in","r", stdin);
  freopen("scode.out","w", stdout);

  cin>>line;
  fill_z();
  memset(memo, -1 , sizeof memo);
  printf("%d\n", dp(0,line.size() - 1));

  return 0;
}
