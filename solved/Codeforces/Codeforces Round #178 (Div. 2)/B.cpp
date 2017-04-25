// http://codeforces.com/contest/294/problem/B

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
    bool operator < (const point &o) const{
        if(x==o.x) return y < o.y;
        return x < o.x;
    }
};

vector<point> todos;

int solve(int i, int w,int h){
   if(i==todos.size()){
        
   }
   return min(solve(i+1,w+todos[i].x,h), solve(i+1,w,todos[i].y+h));

}

int main(){
    int libros;cin>>libros;
    todos.resize(libros);
    int w=0;
    For(i,libros){
        int x, y;cin>>x>>y;
        todos[i] = point(x,y);
        w+=x;
    }
    
    map<pii,int> visited;
    map<pii,set<int> > paila;
    queue<pii> Q;
    Q.push(make_pair(w,0));
    int ans = 1<<30;
    while(!Q.empty()){
        pii act = Q.front();Q.pop();
        if(visited[act])continue;
        visited[act]=true;
        ans = min(ans,act.first);
        For(i,todos.size()){
            if(act.first - todos[i].x >= act.second + todos[i].y and paila[act].count(i)==0){
                Q.push(make_pair(act.first - todos[i].x, act.second + todos[i].y));
                paila[make_pair(act.first - todos[i].x, act.second + todos[i].y)]= paila[act];
                paila[make_pair(act.first - todos[i].x, act.second + todos[i].y)].insert(i);
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}   