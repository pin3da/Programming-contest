// http://codeforces.com/contest/253/problem/B

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

vector<int> d;

int check(int w){
    if(w==d.size() and d[0]*2>=d[w-1])return true;
    if(w==1)return true;
    for(int i=0;i < d.size()-w;++i){
        if(d[i]*2>=d[i+w]) return true;
    }
    return false;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin>>n;
    d = vector<int>(n);
    For(i,n)cin>>d[i];
    sort(all(d));
    int lo = 1;
    int hi = n;
    while(lo<hi){
        int mid = (lo +hi)>>1;
        if(lo+1 == hi){
            int c1 = check(lo);
            int c2 = check(hi);
            if(!c2 and c1) hi = lo;
            break;
        }
        if(check(mid)){
            lo = mid;
        }else{
            hi = mid ;
        }
    }
    int ans = (d.size()-hi < 2)? d.size()-hi: d.size()-hi -1;
    cout<<ans<<endl;
    return 0;
}