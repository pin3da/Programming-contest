// http://codeforces.com/contest/248/problem/A

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


int main(){
    int n;cin>>n;
    int d1=0,d2=0,i1=0,i2=0;
    int t1,t2;
    For(i,n){
        cin>>t1>>t2;
        d1+=((t1)?1:0);
        d2+=((!t1)?1:0);
        i1+=((t2)?1:0);
        i2+=((!t2)?1:0);        
    }
    cout<<min(d1,d2)+min(i1,i2)<<endl;
return 0;
}
