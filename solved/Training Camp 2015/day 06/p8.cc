using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
//#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n,m;
  while(cin>> n >> m){
    n--;m--;
    if(n == 0 || m == 0){
      cout<< 0 << endl;
    }else{
      int x = min(n,m);
      int y = max(n,m);

      int last = 0;
      int sol = 0;
      for(int i = 1; i<= y; i++){
        sol++;
        if((i*x)/y != last){
          last = (i*x)/y;
          sol += (((i*x)%y) != 0);
        }
      }
      cout<< sol << endl;
    }
  }
  return 0;
}
