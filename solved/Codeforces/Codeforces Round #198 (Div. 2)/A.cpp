// http://codeforces.com/contest/340/problem/A

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for(int i = 0; i< (n); ++i)
#define foreach(it, x) foreach(typeof x.begin() it = x.begin(); it != x.end(); ++it)
#define D(x) cout<< #x " = "<<(x)<<endl

int main(){ ___
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int k = a*b/__gcd(a,b);
    cout<<(d/k) - ((c-1)/k)<<endl;
    return 0;
}