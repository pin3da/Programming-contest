// http://codeforces.com/contest/109/problem/A

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

string dp[1000001];

string solve(int n){
    if(dp[n]!= "")return dp[n];
    if(n<7 and n>=4) return dp[n] = "4"+solve(n-4);
    if(n<4 and n!=0) return dp[n] = "-1";
    if(n==0) return dp[n]="0";
    string c1 = "4"+solve(n-4);
    string c2 = "7"+solve(n-7);
    if(c1.find("-")==string::npos) dp[n]= c1;
    if(c2.find("-")==string::npos) dp[n]= (dp[n]!="")?min(dp[n],c2):c2;
    return dp[n];
}



string mmin(string a,string b){
    if(a.size()==b.size()){
        int i=0;
        while(a[i]==b[i])++i;
        return (a[i]<b[i])?a:b;
    }
    return (a.size()<b.size())?a:b;
}

int main(){
    int n;cin>>n;
    /*dp[0] = "";
    for(int i = 1;i<4;++i)dp[i]="-1";
    for(int i = 4;i<7;++i)dp[i]="4"+dp[i-4];
    for(int i = 7;i<=n;++i){
        string c1 = "4"+dp[i-4];
        string c2 = "7"+dp[i-7];
        if(c1.find("-")==string::npos) dp[i]= c1;
        if(c2.find("-")==string::npos) dp[i]= (dp[i]!="")?mmin(dp[i],c2):c2;
    }
    
//  For(i,20)cout<<i<<" "<<dp[i]<<endl;
    string ans = dp[n];//solve(sum);
    //ans = ans.substr(0,ans.size()-1);

    For(i,ans.size())
        if(ans[i]=='-'){
            cout<<-1<<endl;
            return 0;
        }
*/  
    int ans = 3000000;
    int c,s;
    For(cuatros,n+1){
        int queda = n - cuatros*4;
        if(queda < 0 or queda%7 != 0) continue;
        int sietes = queda/7;
        if(ans > cuatros + sietes){
            ans =  cuatros + sietes;
            c = cuatros;
            s = sietes;
        }
    }
    if(ans==3000000)cout<<-1<<endl;
    else{
        For(i,c)cout<<"4";
        For(i,s)cout<<"7";
        cout<<endl;
    }
    
    
    return 0;
}