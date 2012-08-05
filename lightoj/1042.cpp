/**
Sol by Diego A. Martinez, UTP.
*/

#include <iostream>
#define REP(i,n) for(int i=0;i<n;i++)
 
using namespace std;
 
int main(){
  int n;
  cin >> n; 
  REP(i,n){
    unsigned x, ans=0;
    cin >> x;
    bool b = false;
    int cnt = 0;
    REP(j,32){
      unsigned mask = 1 << j;
      if(b && ((x & mask) == 0)){
        x |= mask;
        mask--;
        x &= ~mask;
        cnt--;
        x |= (1<<cnt) - 1;
        break;
      }
      if(x & mask){
        cnt++;
        b = true;
      }
    }
    cout << "Case " << i+1 << ": " << x << endl;
  }
  return 0;
}
