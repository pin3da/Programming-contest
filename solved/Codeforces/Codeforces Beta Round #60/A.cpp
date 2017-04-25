// http://codeforces.com/contest/65/problem/A

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


int main(){
    double a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    double x=1;
    x=(b/a);
    x= (x/c)*d;
    x = (x/e)*f;
    if(x > 1.0 or (a==0 and b>a and d!=0) or (c==0 and d>c ))
            cout<<"Ron"<<endl;      
    else

      cout<<"Hermione"<<endl;
    return 0;   

}