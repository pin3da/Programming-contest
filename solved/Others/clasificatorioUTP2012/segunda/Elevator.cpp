//Accepted
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
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

const double pi=acos(-1);

struct point{
    double x,y;
    point() {}
    point(double X, double Y) : x(X), y(Y) {}
};


double dist(point a,point b){
	double x= a.x - b.x;
	double y = a.y - b.y;
	return sqrt( x*x + y*y);
}

int main(){
    double a,b,c,d;
    while(true){
        cin>>a>>b>>c>>d;
        if(a==0 and b==0 and c ==0 and d ==0)break;
        point p1(c,c);
        point p2(a-d,b-d);
        if ( (dist(p1,p2)>=(c+d)) and 2*c<=a and 2*c<=b and 2*d<=a and 2*d<=b)
        	cout<<"S\n";
        else cout<<"N\n";
    }
    return 0;
}
