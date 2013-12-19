// Wrong answer

using namespace std;
#include<bits/stdc++.h>

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define MP 100010


int main(){ ___

  long long n,m,i,j,a,b;
  while(cin>>n>>m>>i>>j>>a>>b){
      long long dx = fabs(i - 1);
      long long dy = fabs(j - 1);

      long long ans = 1<<30;
      if((dx % a == 0) and (dy %b == 0)and ((dx/a + dy/b) %2 == 0) ){
        ans = min(ans,max(dx/a,dy/b));
      }
      dx = fabs(i - 1);
      dy = fabs(j - m);
      if((dx % a == 0) and (dy %b == 0) and ((dx/a + dy/b) %2 == 0)){
        ans = min(ans,max(dx/a,dy/b));
      }
      dx = fabs(i - n);
      dy = fabs(j - m);
      if((dx % a == 0) and (dy %b == 0)and ((dx/a + dy/b) %2 == 0) ){
        ans = min(ans,max(dx/a,dy/b));
      }
      dx = fabs(i - n);
      dy = fabs(j - 1);
      if((dx % a == 0) and (dy %b == 0)and ((dx/a + dy/b) %2 == 0) ){
        ans = min(ans,max(dx/a,dy/b));
      }
      if(ans != (1<<30))
         cout<<ans<<endl;
      else
         cout<<"Poor Inna and pony!"<<endl;
   }

  return 0;
}
