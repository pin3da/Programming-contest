using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cctype>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long int ll;

struct point3d{
    ll x,y,z;
 
    point3d(){}
   
    point3d(ll xx,ll yy,ll zz): x(xx),y(yy),z(zz){}
   
};

int main(){
    

    int n;
    while(cin>>n and n){
        point3d ans(0,0,0);
        point3d ans2(1LL<<60,1LL<<60,1LL<<60);
        point3d tmp;
        int k;
        while(n--){
            cin>>tmp.x>>tmp.y>>tmp.z>>k;
            ans.x=max(ans.x,tmp.x);
            ans.y=max(ans.y,tmp.y);
            ans.z=max(ans.z,tmp.z);
            ans2.x=min(ans2.x,tmp.x+k);
            ans2.y=min(ans2.y,tmp.y+k);
            ans2.z=min(ans2.z,tmp.z+k);
        }
        if(ans2.x-ans.x<0 or ans2.y-ans.y < 0 or ans2.z-ans.z<0)
            cout<<"0"<<endl;
        else cout<<(ans2.x-ans.x)*(ans2.y-ans.y)*(ans2.z-ans.z)<<endl;
    }
 
    
    return 0;
}
