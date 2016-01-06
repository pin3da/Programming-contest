using namespace std;
#include<iostream>
#include<algorithm>
#include<cmath>

bool point_in_box(double x, double y, double x0, double y0, double x1, double y1){
  return min(x0, x1) <= x && x <= max(x0, x1) && min(y0, y1) <= y && y <= max(y0, y1);
}


int main(){
  int numcas,n;cin>>numcas;
  int cas=0;
  double x0,y0,x1,y1,x,y;
  while(numcas--){
    cin>>x0>>y0>>x1>>y1;
    cin>>n;
    cout<<"Case "<<++cas<<":"<<endl;
    while(n--){
      cin>>x>>y;
      cout<<((point_in_box(x,y,x0,y0,x1,y1))?"Yes":"No")<<endl;
    }
  }
  return 0;
}

