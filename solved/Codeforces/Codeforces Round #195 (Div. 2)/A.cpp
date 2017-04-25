// http://codeforces.com/contest/336/problem/A

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ int r; stringstream s; s<<x;s>>r; return r;}


int main(){ ___
    
    int a,b;
    while(cin>>a>>b){
        
        if(a>=0 and b>=0)
        cout<<0<<" "<<a+b<<" "<<a+b<<" 0"<<endl;
        else if(a < 0 and b <0)
            cout<<a+b<<" 0 "<<"0 "<<a+b<<endl;
        else if(a < 0)
            cout<<a-b<<" 0 "<<"0 "<<b-a<<endl;
        else if(b < 0)
            cout<<"0 "<<b-a<<" "<<a-b<<" 0"<<endl;
        
   }
        
    

    return 0;
}