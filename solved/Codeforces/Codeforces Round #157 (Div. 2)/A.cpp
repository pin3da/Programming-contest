// http://codeforces.com/contest/259/problem/A

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
	char mat[8][8];
	int pin=true;
	For(i,8){
	    For(j,8){
	        cin>>mat[i][j];
	        if(j>0) if(mat[i][j]==mat[i][j-1]){pin =0;}
	    }
	}
	if (pin) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	
	return 0;
}
