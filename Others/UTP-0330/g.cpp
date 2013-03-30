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

int dist_next[] = {4, 3, 37, 3, 27, 3, 367, 3, 27, 3, 267, 3, 27, 3, 3667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 36667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 366667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 266667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 3666667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 266667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 2666667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 266667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 36666667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 266667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 2666667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 266667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26666667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 266667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 2666667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 266667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3, 26667, 3, 27, 3, 267, 3, 27, 3, 2667, 3, 27, 3, 267, 3, 27, 3};

bool is_lucky(int n){
	while(n!=4 and n!=7){
		int d = n%10;
		if(d!=7 and d!=4)return false;
		n/=10;
	}
	return true;
}

int main(){
	/*int t=0;
	int ant = 0;
	For(i,100000001){
		if(is_lucky(i)){
			cout<<(i-ant)<<", ";
			ant=i;
			t++;
		}
	}
	//cout<<t<<endl;*/
	
	
    return 0;
}
