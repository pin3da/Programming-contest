// http://codeforces.com/contest/2/problem/A

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


int lucky(string cad){
    For(i,cad.size())
        if(cad[i]!='4' and cad[i]!='7')
            return 0;
        
    return 1;
}

int main(){
    int n;cin>>n;
    map<string,int> puntos;
    map<string,int> puntos2;
    vector<string> m(n);
    vector<int> d(n);
    string win;
    set<string> posibles;
    int ma = -1000000000;
    For(i,n){
        cin>>m[i];
        cin>>d[i];
        puntos[m[i]]+=d[i];
/*        if(puntos[m[i]] > ma){
            win = m[i];
            ma = puntos[m[i]];
        }*/
    }
    
    foreach(x,puntos){
        if(x->second == ma){
            posibles.insert(x->first);
        }else if(x->second > ma){
            ma = x->second;
            posibles.clear();
            posibles.insert(x->first);
        }
        
    }
    
    For(i,n){
        puntos2[m[i]]+=d[i];
        if(puntos2[m[i]] >= ma and posibles.count(m[i])){
            cout<<m[i]<<endl;
            return 0;
        }
    }
    
    return 0;
}