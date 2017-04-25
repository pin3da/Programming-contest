// http://codeforces.com/contest/111/problem/B

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


void divisors(vector<int> &primes,vector<int> &exp,int i,int acum,vector<int> &ans){
    if(i == primes.size()){
        ans.push_back(acum);
        return;
    }
    for(int j = 0; j <= exp[i]; j++){
        divisors(primes, exp, i + 1,acum,ans);
        acum *= primes[i];
    }
}

vector<int> gen_div(int x){
    vector<int> prime;
    vector<int> exp;
    int tope = sqrt(x);
    for(int i = 2 ;i<=tope; ++i){
        if(x%i)continue;
        int e = 0; for (; x % i == 0; e++, x /= i);
        prime.push_back(i);
        exp.push_back(e);
        tope = sqrt(x);
    }
    if(x > 1){
        prime.push_back(x);
        exp.push_back(1);
    }

    vector<int> ans;
    divisors(prime,exp,0,1,ans);
    return ans;
}

int main(){
    int n;cin>>n;
    map<int,int> appear;
    For(i,n){
        int x;cin>>x;
        int y;cin>>y;
        vector<int> divs = gen_div(x);
        int ans = 0;
        For(j,divs.size()){
            if(!appear.count(divs[j]) || appear[divs[j]] < i - y)
                ans++;
            appear[divs[j]] =  i;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}