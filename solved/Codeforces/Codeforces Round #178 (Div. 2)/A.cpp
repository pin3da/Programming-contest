// http://codeforces.com/contest/294/problem/A

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

int main(){
    int cables;cin>>cables;
    vector<int> cuantos(cables);
    For(i,cables)
        cin>>cuantos[i];
    int tiros;cin>>tiros;
    
    For(i,tiros){
        int x,y;cin>>x>>y;
        x--;
      //  if(cuantos[x]<=y and y>0){
            if(x>0){
                cuantos[x-1]+= y -1;
            }
            if(x<cables-1){
                cuantos[x+1]+= cuantos[x] -y;
            }
            cuantos[x]=0;
        //}
    }
    
    For(i,cables){
        cout<<cuantos[i]<<endl;
    }
    
    return 0;
}   
