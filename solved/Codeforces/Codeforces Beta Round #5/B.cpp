// http://codeforces.com/contest/5/problem/B

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

void ps(int n){
    while(n-->0)cout<<" ";
}
void px(int n){
    while(n-->0)cout<<"*";
}

int main(){
    vector<string> ans;
    string line;
    size_t mmax = 0 ;
    while(getline(cin,line)){
        ans.push_back(line);
        mmax = max(mmax,line.size());
    }
    
    px(mmax+2);cout<<endl;
    int lado = 0;
    For(i,ans.size()){
        int paila = 0;
        int missing = mmax - ans[i].size();
        if((missing>>1)*2 != missing) paila = 1;
        cout<<"*";
        if(paila){
            if(lado)ps(missing - (missing>>1));
            else ps((missing>>1));
        }else{
            ps((missing>>1));
        }
        cout<<ans[i];
        if(paila){
            if(!lado)ps(missing - (missing>>1));
            else ps((missing>>1));
        }else{
            ps((missing>>1));
        }
        if(paila)lado = !lado;
        cout<<"*"<<endl;
        
    }
    px(mmax+2);cout<<endl;

    return 0; 
}