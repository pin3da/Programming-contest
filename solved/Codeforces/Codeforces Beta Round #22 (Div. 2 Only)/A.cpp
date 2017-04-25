// http://codeforces.com/contest/22/problem/A

using namespace std;
#include <bits/stdc++.h>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> string to_str(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x){ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
typedef long long ll;

int main(){
    int n;cin>>n;
    set<int> ans;
    int t;
    For(i,n){
        cin>>t;
        ans.insert(t);
    }
    vector<int> a(all(ans));
    if(a.size()<2)cout<<"NO"<<endl;
    else cout<<a[1]<<endl;
    return 0; 
}