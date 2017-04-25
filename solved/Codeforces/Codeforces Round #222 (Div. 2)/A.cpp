// http://codeforces.com/contest/378/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

template<typename T> void cmin(T& a, T b) { if (b < a) a = b; }
template<typename T> void cmax(T& a, T b) { if (a < b) a = b; }

int main(){ ___

  int a,b;
  while(cin>>a>>b){
    int a1 = 0, a2 = 0, a3 = 0;
    for(int i = 1; i < 7; ++i){
        int x = fabs(i-a);
        int y = fabs(i-b);
        if(x < y) a1++;
        else if(y < x) a3++;
        else a2++;
    }
    cout<<a1<<" "<<a2<<" "<<a3<<endl;

  }
  return 0;
}