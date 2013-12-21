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
    	if(x == o.x)return  y < o.y;
    	return x < o.x;
    }
};


bool visited[101][100001];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;cin>>n;
	vector<int> mat(n);
	For(i,n)cin>>mat[i];
	point s,t;
	cin>>s.x>>s.y>>t.x>>t.y;
	s.x--;
	s.y--;
	t.x--;
	t.y--;
	memset(visited,0,sizeof(visited));
	queue<point> Q;
	Q.push(s);
	int ans = 0;
	while(!Q.empty()){
		point act = Q.front();Q.pop();
		if(visited[act.x][act.y])continue;
		visited[act.x][act.y] = true;
		D(act.x);
		D(act.y);
		if(act.x == t.x and act.y == t.y) break;
		if(act.x > 0) {
			if(mat[act.x -1] < act.y)
				Q.push(point(act.x-1,mat[act.x-1]-1));
			else
				Q.push(point(act.x-1,act.y));
		}
		if(act.x < n-1){
			if(mat[act.x +11] < act.y)
				Q.push(point(act.x+1,mat[act.x-1]-1));
			else
				Q.push(point(act.x+1,act.y));
		}
		if(act.y > 0) Q.push(point(act.x,act.y-1));
		if(act.y < mat[act.x]-1) Q.push(point(act.x,act.y+1));
		ans++;
	}
	cout<<ans<<endl;
    return 0;
}
