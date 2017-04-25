// http://codeforces.com/contest/237/problem/A

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

const double pi=acos(-1);

struct point{
    int x,y;
    point() {}
    point(int X, int Y) : x(X), y(Y) {}
};


int main(){
    int numcas;cin>>numcas;
    int h,m;
    map<int,int> todos;
    For(i,numcas){
        cin>>h>>m;
        todos[h*60+m]++;
    }
    int ans=-1;
    foreach(it,todos){
        if(it->second>ans)ans=it->second;
    }
    cout<<ans<<endl;
    return 0;
}
