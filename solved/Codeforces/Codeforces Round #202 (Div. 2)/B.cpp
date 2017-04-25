// http://codeforces.com/contest/349/problem/B

using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) (x).begin(),(x).end()
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> string to_str(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x){ stringstream s; s << x; int r; s >> r; return r; }

int d[9];

int mio;
int __index;

string solve(int tengo){
    string ans;
    int cuantos = tengo / mio;
    int necesito = cuantos * mio;
    for (int i = 8; i >= 0; i--) 
        while (tengo - d[i] >= necesito - mio && cuantos > 0) {
            tengo -= d[i]; necesito -= mio;
            cuantos--;
            ans+= ((char)('0'+i+1));
        }
    return ans;
}

int main(){
    int paint;
    while(cin>>paint){
        mio = 1<<30;
        For(i,9){
            cin>>d[i];
            mio =  min(mio,d[i]);
        }
        
        if(paint<mio) 
            cout<<-1<<endl;
        else cout<<solve(paint)<<endl;
    }
    return 0;
}