// http://codeforces.com/contest/266/problem/B

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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
typedef long long int lli;

struct point{
    int x,y;
    point() {}
    point(int X, int Y) : x(X), y(Y) {}
    point sub(point a){
		return point(x - a.x,y - a.y);
	}
	point add(point a){
		return point(x + a.x,y + a.y);
	}
	int cross(point a){
		return x*a.y - y*a.x;
	}
	point multbyscalar(int ua) {
		return point(ua*x,ua*y);
	}
	double angle(){
	    double ans = atan2(y,x);
	    if(ans<0)ans+= 2.0*pi;
	    return ans;
	}
};

int main(){
    int n,m;cin>>n>>m;
    string cad;cin>>cad;
    string cad2 = cad;
    For(j,m){
        For(i,n-1){
            if(cad[i]=='B' and cad[i+1]=='G'){
                cad2[i]='G';
                cad2[i+1] = 'B';
            }
        }
        cad=cad2;
    }
    cout<<cad<<endl;
  
    return 0;
}
