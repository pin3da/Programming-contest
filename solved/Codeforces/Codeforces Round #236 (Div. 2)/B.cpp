// http://codeforces.com/contest/402/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 1001

int h[MN];

int main() { ___


  int n,k;
  cin>>n>>k;
  for (int i = 0; i < n; ++i) cin>>h[i];


  int best = (1<<30);
  int height;
  for (int j = 1; j < 1001; ++j) {
    int ch = 0;
    for (int i = 0; i < n; ++i) {
      int nh = i*k + j;
      ch += (fabs(h[i] - nh) != 0);
    }
    if( best > ch) {
      best = ch;
      height = j;
    }
  }

  cout<<best<<endl;

  if (best > 0) {
    for (int i = 0; i < n; ++i) {
      if (h[i] > i*k + height) {
        cout<<"- "<<(i+1)<<" "<<fabs((height + i*k) - h[i])<<endl;
      }else if (h[i] < i*k + height) {
        cout<<"+ "<<(i+1)<<" "<<fabs((height + i*k) - h[i])<<endl;
      }
    }
  }


  return 0;
}