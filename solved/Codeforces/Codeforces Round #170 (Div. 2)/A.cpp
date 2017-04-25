// http://codeforces.com/contest/278/problem/A

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
typedef long long int lli;
typedef pair<int , int> pii;

int next(int a,int n){
	if(a<0)return n+a;
	return a;
}

int main(){
    int  n;
    cin>>n;
    vector<int> todos(n+1);
    For(i,n){
    	cin>>todos[i+1];
    }
    todos[0]=todos[n];
    int s,t;
    cin>>s>>t;
    int a=0,b=0;
    if(t<s)swap(s,t);
    for(int i=s; i != t;++i){
		    a+=todos[i];
    }
    for(int i=t;i != s;){
    		b+=todos[i];
    		i++;
    		i%=n;
    }
    
    cout<<min(a,b)<<endl;
    
    
    
  
    return 0;
}
