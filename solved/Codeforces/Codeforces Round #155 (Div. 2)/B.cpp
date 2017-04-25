// http://codeforces.com/contest/254/problem/B

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

const int maxn = 101;
const int days[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int months[12];

int n, m[maxn], d[maxn], p[maxn], t[maxn];
map<int, int> mp;


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    months[0]=31;
    memset(months,0,sizeof(months));
    For(i,11){
        months[i+1]=months[i]+days[i+1];
    }
    cin>>n;
    For(i,n){
        cin >>m[i]>>d[i]>>p[i]>>t[i];
        for (int j = months[m[i]-1] + d[i]; j > months[m[i]-1] + d[i] - t[i]; j--)
            mp[j] += p[i];
    }
    int ans = 0;
    foreach(it,mp)
        ans = max(ans, it->second);

    cout<<ans<<endl;
    return 0;
}