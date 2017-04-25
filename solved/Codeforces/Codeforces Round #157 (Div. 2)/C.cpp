// http://codeforces.com/contest/259/problem/C

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
    string cad;cin>>cad;
    For(i,cad.size()){
        if(cad[i]=='0'){
            cad.erase(i,1);
            cout<<cad<<endl;
            return 0;
        }
    }
    cad.erase(cad.size()-1,1);
    cout<<cad<<endl;
	
	
	return 0;
}
