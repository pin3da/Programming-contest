#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n,a,b;
  while(cin >> n >> a >> b){
    int solx = 0, soly = 0;
    int tx = 0, ty = 0;
    while( n ){
      if(tx == 0 && ty == 0){
        if( n >= a){
          tx = a;
          n -= a;
        }else{
          tx = n;
          n = 0;
        }

        if( n >= b ){
          ty = b;
          n -= b;
        }else{
          ty = n;
          n = 0;
        }
      }else if( tx == 0 ){
        if( n >= a){
          tx = a;
          n -= a;
        }else{
          tx = n;
          n = 0;
        }
        ty--;
        soly++;
      }else if( ty == 0){
        if( n >= b ){
          ty = b;
          n -= b;
        }else{
          ty = n;
          n = 0;
        }
        tx--;
        solx++;
      }else{
        solx++;
        soly++;
        ty--;
        tx--;
      }
    }

    solx += tx;
    soly += ty;

    cout << solx << " " << soly << endl;
  }
}
