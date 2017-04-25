// http://codeforces.com/contest/376/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

int main(){ ___

  string cad;
  while(cin>>cad){
    int p = 0;
    while(cad[p] != '^')p++;
    long long left = 0;
    for(int i  = p-1, j = 1;i >= 0; --i,++j)
      if(isdigit(cad[i]))
        left += (cad[i] - '0') * j;

    long long right = 0;
    for(int i = p+1, j = 1; i < cad.size(); ++i,++j)
       if(isdigit(cad[i]))
        right += (cad[i] - '0') * j;

    if(right > left)
      cout<<"right"<<'\n';
    else if(left > right)
      cout<<"left"<<'\n';
    else
      cout<<"balance"<<'\n';

  }

  return 0;
}