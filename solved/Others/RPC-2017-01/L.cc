#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

long long pascal(long long n){
  if(n==1 || n==2)
    return(n-1);
  else{
    long long lg,pot,lim,k,lgk,potk;
    lg= log2(n);
    pot= pow(2,lg);
    lim= (3*pot)/2;
    if(n>=lim)
      return(pascal(n-pot));
    else{
      k= n+1-pot;
      lgk= log2(k);
      potk= pow(2,lgk);
      if(k==potk)
        return(pot/2);
      else
        return(pascal(n-(pot/2)));
    }
  }
}

long long last2pascal(long long n){
  return(n+1-pascal(n));
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(NULL);
  long long q,n,x,i,j,k,p,m,result;
  cin>>q;
  for(i=0; i<q; i++){
    cin>>x>>n;
    if(x%4==0)
      cout<<0<<endl;
    else if(x%4==2){
      if(n%2==0)
        cout<<0<<endl;
      else
        cout<<3<<endl;
    }
    else{
      k= log2(n);
      k++;
      if(n+1==pow(2,k))
        cout<<0<<endl;
      else{
        k=n;
        for(j=0; k>0; j++){
          p= log2(k);
          k-= pow(2,p);
        }
        result= pow(2,j-1);
        result= result*(n+2);
        m= last2pascal(n);
        result+= m;

        cout<<result<<endl;
      }
    }
  }
}
