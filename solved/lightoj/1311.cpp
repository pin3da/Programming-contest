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


int main(){
	int numcas;cin>>numcas;
	for(int cid=1;cid<=numcas;++cid){
    double v1, v2, v3, a1, a2;
    scanf("%lf%lf%lf%lf%lf", &v1, &v2, &v3, &a1, &a2);

    double t1 = v1/a1, t2 = v2/a2;
    double bird = max(t1, t2) * v3;
    double d = (t1*v1 + t2*v2) / 2;

    printf("Case %d: %.8lf %.8lf\n", cid, d, bird);
	}
	return 0;
}
