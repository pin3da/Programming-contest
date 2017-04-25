// http://codeforces.com/contest/387/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MM 1000000

string line;

int cmp(int a,int b, int c, int d) {
  int i;
  for (i = 0; i <= (b - a) and line[i + a] == line[i + c]; ++i) ;
  if (i == (b - a) + 1) return 1;
  return line[i + a ] >= line[i + c];
}

int main() { ___

  cin>>line;

  int i = line.size() - 1;
  int ans = 0;
  while (i >= 0) {
    int j = i;
    while (j >= 0 and line[j] == '0')
      j--;

    if (j > (i - j) + 1 ) {
      ans++;
    }else if (j  == (i - j) + 1 ) {

      if (cmp(0,j-1,j,i)) ans++;
      else break;
    } else {
      break;
    }
    i = j - 1;

  }
  cout<<ans+1<<endl;
  return 0;
}