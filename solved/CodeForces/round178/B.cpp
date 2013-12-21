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
    int x,y;
    point() {}
    point(int X, int Y) : x(X), y(Y) {}
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
    bool operator < (const point &o) const{
        if(y==o.y) return x > o.x;
        return y > o.y;
    }
};

int main(){
    int libros;cin>>libros;
    vector<point> todos(libros);
    For(i,libros){
        int x, y;cin>>x>>y;
        todos[i] = point(x,y);
    }
    int ans = (1<<30);
    sort(all(todos));
    int w[libros];
    int h[libros];
    w[0]=todos[0].x;
    For(i,libros-1){
        w[i+1] = w[i] + todos[i+1].x;
    }
    For(i,libros){
        int act = 0;
        for(int j=i+1;j<libros;++j)act += todos[j].y;
        D(w[i]);
        D(act);
        if(w[i]>=act){
            cout<<w[i]<<endl;
            return 0;
        }
    }
       
    cout<<w[libros-1]<<endl;
    return 0;
}   
