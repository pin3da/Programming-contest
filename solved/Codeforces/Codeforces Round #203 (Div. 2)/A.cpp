// http://codeforces.com/contest/350/problem/A

using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) (x).begin(),(x).end()
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> string to_str(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x){ stringstream s; s << x; int r; s >> r; return r; }



int main(){ ___
    int n,m;cin>>n>>m;
    vector<int> correct(n);
    For(i,n)cin>>correct[i];
    vector<int> wrong(m);
    For(i,m)cin>>wrong[i];
    
    sort(all(correct));
    sort(all(wrong));
    int mmax = max(correct[n-1],2*correct[0]);
    if(wrong[0] <= mmax ) cout<<-1<<endl;
    else cout<<mmax<<endl;

    return 0;   
}