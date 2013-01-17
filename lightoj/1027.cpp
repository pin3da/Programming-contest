using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

const double pi=acos(-1);

struct point{
  int x,y;
  point() {}
  point(int X, int Y) : x(X), y(Y) {}
};

int gcd(int a,int b){
    int tmp;
    while(b){
        tmp=b;
        b=a%tmp;
        a=tmp;
    }
    return a;
}

int main(){
  int numcas;cin>>numcas;
  int n,tmp,total,c;
  for(int cid=1;cid<=numcas;++cid){
    cin>>n;
    c=0;
    total=0;
    for(int i=0;i<n;++i){
        cin>>tmp;
        if(tmp<0){
            total+= -tmp;
            c++;
        }else
            total+=tmp;
        
    }
    cout<<"Case "<<cid<<": ";
    if(c==n){
        cout<<"inf\n";
        continue;
    }
    int num = total;
    int den = n - c;
    int mio = gcd(num,den);
    num/=mio;
    den/=mio;
    cout<<num<<"/"<<den<<endl;
    
  }
  return 0;
}
