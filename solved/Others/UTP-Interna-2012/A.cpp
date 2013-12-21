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

lli primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

int main(){
    int n;
    while(cin>>n and n){
        lli ans = 1;
        for(int i=0;primes[i]<=n;++i){
            ans*= primes[i];
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
