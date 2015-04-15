#include<iostream>
#include<cmath>
#include<stdio.h>
#define endl '\n'

using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a,b,c;
  cin>>c;
  for(int i=0;i<c;i++){
    cin>>a>>b;
    int t;
    if(a==1 || b==1){
      t=a>=b?a:b;
      printf("Case %d: %d\n",(i+1),(t));
    }
    else if((a==2 || b==2)){
      int re;
      float t=((float)a*b)/4;
      int a1=t;
      if(a1>1.0)
        re=ceil((float)a1/2)*4;
      else
        re=4;
      //         printf("%f\n",t);
      if(t-a1 >= .5 && a1%2==0)
        re+=2;

      printf("Case %d: %d\n",(i+1),(re));
    }
    else{
      int t=a*b;
      if(t%2==0){
        printf("Case %d: %d\n",(i+1),((a*b)/2));
      }else
        printf("Case %d: %d\n",(i+1),((a*b)/2+1));
    }
  }
}
