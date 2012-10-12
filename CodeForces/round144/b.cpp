using namespace std;
#include<iostream>
#include<cmath>
#include<cassert>
#include<limits>
#include<map>


#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000
const double EPS = 1e-7;

typedef long long int lli;

int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int f2(lli x){
    int ans=0;
    while(x){
        ans+= x%10;
        x/=10;
    }
    return ans;
}

lli fun(lli x){
    return x*x + (f2(x))*x;
}

lli ant = -100;
lli ant2 = -1;
    
lli binary_search(lli key, lli imin, lli imax){

  while (imin < imax){
      lli imid = (imin+ imax)/2;
      if (fun(imin) < key)
        imin = imid + 1;
      else
        imax = imid;
  }
/*  
  D(imax);
  D(imin);
  D(fun(imin));
  */
  lli d1 = ant2-ant;
  lli d2 = imin-ant;
  if ((imax == imin) ){
    if(fun(imin) == key)
        return imin;
    if(d1==1 or d2==1) return -1;
    ant2=ant;
    ant=imin;
    return binary_search(key,1,imin-1);
  }
  else{
    return -1;
   }
}


int main(){
    lli n;cin>>n;
   
    lli si,un,f,e,mid,ans;
    si=0;
   // D(fun(10));
    un= n;
    cout<<binary_search(n,1,un)<<endl;
    
}

