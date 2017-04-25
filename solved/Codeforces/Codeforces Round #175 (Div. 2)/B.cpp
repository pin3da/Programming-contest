// http://codeforces.com/contest/285/problem/B

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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;

struct point{
    double x,y;
    point() {}
    point(double X, double Y) : x(X), y(Y) {}
    point sub(point a){
        return point(x - a.x,y - a.y);
    }
    point add(point a){
        return point(x + a.x,y + a.y);
    }
    double cross(point a){
        return x*a.y - y*a.x;
    }
    point multbyscalar(double ua) {
        return point(ua*x,ua*y);
    }
};


int main(){
    int n,s,t;cin>>n>>s>>t;
    vector<int> pos(n+1);
    vector<int> vis(n+1,0);
    For(i,n)cin>>pos[i+1];
    
    queue<int> Q;
    Q.push(s);
    int ans = 0;
    while(!Q.empty()){
        int act = Q.front();Q.pop();
        if(vis[act])continue;
        vis[act]=true;
        if(act == t) break;
        Q.push(pos[act]);
        ans++;
    }
    
    if(vis[t])cout<<ans<<endl;
    else cout<<-1<<endl;
    
    return 0;
}
