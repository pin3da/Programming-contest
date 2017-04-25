// http://codeforces.com/contest/63/problem/A

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
#include<cctype>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 100

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long ll;
typedef pair<int , int> pii;
typedef vector<int> vi;


int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

set<ll> lucky;
void gen_lucky(ll a=0){
    if(a>1000000000L) return;
    ll x = (a*10) + 4;
    ll y = (a*10) + 7;
    lucky.insert(x);
    lucky.insert(y);
    gen_lucky(x);
    gen_lucky(y);
}

int p[1000];
int find(int x){ return (p[x]==x)? x: p[x] = find(x) ;}

int main(){
    int n;cin>>n;
    vector<string> rats;
    vector<string> women;
    vector<string> men;
    vector<string> capitan;    
    For(i,n){
        string name,team;
        cin>>name>>team;
        if(team == "rat") rats.push_back(name);
        else if(team == "woman" or team== "child") women.push_back(name);
        else if(team == "man") men.push_back(name);
        else capitan.push_back(name);
    }
    foreach(x,rats) cout<<(*x)<<endl;
    foreach(x,women) cout<<(*x)<<endl;
    foreach(x,men) cout<<(*x)<<endl;
    foreach(x,capitan) cout<<(*x)<<endl;
    
    return 0;
    
}
