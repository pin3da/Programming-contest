#include <iostream>
#include <vector>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) rep(i,0,n)

typedef vector<int> vi;

bool isrepeat(int n){
  vi digits(10,0);
  while(n){
    int d = n % 10;
    n /= 10;
    digits[d]++;
  }
  REP(i,10){
    if(digits[i] > 1)
      return true;
  }
  return false;
}


int main(){
  int n, m;
  while(cin >> n >> m){
    int ans = 0;
    rep(i,n,m+1){
      if(isrepeat(i) == false){
	ans++;
      }
    }
    cout << ans << endl;
  }
    
  return 0;
}
