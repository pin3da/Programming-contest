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
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
const double eps = 1e-9;
typedef long long int lli;
typedef pair<int , int> pii;

int my_cmp(pair<char,int> a,pair<char,int> b){
    return a.second > b.second;
}

int main(){
    int t;cin>>t;
    int n,m;
    For(i,t){
        cin>>n>>m;
        vector<char> L(n);
        vector<pair<int,int> > frecuency(27);
        vector<char> S(m);
        char tt;
        For(j,27)frecuency[j].first = j;
        
        For(j,n)cin>>L[j];
        For(j,m){
            cin>>tt;
            S[j]=tt;
            frecuency[tt-'A'].second++;
        }
        sort(all(frecuency),my_cmp);

//        D((char)(frecuency[0].first+'A'));
        map<char,char> cod;
        For(j,n) cod[frecuency[j].first+'A'] = L[j];
        For(j,m) cout<<cod[S[j]];
        cout<<endl;
    }
    
    return 0;
}
