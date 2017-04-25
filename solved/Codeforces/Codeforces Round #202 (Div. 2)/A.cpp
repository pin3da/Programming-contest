// http://codeforces.com/contest/349/problem/A

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
    int a = 0,b = 0,c = 0;
    
    int n; cin>>n;
    int paila = 0;
    For(i,n){
        int t;cin>>t;
        if(t==25)a++;
        if(t==50){
            if(!a){
                paila = 1;
                break;
            }else{
                a--;
                b++;
            }
        }if(t==100){
            if(b>=1 and a>=1){
                c++;
                b--;
                a--;
            }else if(a >= 3){
                a-=3;
                c++;
            }else{
                paila =1;
                break;
            }
        }
    }
    
    if(paila)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}