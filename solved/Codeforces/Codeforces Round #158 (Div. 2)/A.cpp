// http://codeforces.com/contest/260/problem/A

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
template <class T> string toStr(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x){ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
//const long long int mod = 1000000007;

struct point{
    int x,y;
    point() {}
    point(int X, int Y) : x(X), y(Y) {}
};


int main(){
  int a,b,c;cin>>a>>b>>c;
  string cad=toStr(a);
  string cad2=toStr(b);
  int mod = pow(10,cad2.size());
  int pin=true;
    For(j,10){
      int tmp= (a*10) +j;
      if(tmp%b==0){
        a=tmp;
        cad+=(j+'0');
        pin=false;
        break;
      }
    }
    if(pin){
      cout<<-1<<endl;
      return 0;
    }
  For(i,c-1)cad+='0';
  cout<<cad<<endl;
    return 0;
}