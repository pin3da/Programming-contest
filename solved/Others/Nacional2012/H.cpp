#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) rep(i,0,n)

typedef vector<int> vi;

int main(){
  vi A(181,0);

  int angle = 360 / 60;

  REP(m,720){
    int pm = m % 60;
    int ph = ((m / 12) % 12) * 5;
    int x = abs(pm - ph);
    int y = 60 - x;
    int ai = min(x,y) * angle;
    A[ai]++;
  }

  int a;
  while(cin >> a){
    if(A[a]) cout << "Y" << endl;
    else cout << "N" << endl;
  }

  return 0;
}
