// http://codeforces.com/contest/228/problem/B

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

typedef long long int ll;


int main(){

    int a,b;
    while(cin>>a>>b){
        int mat[a][b];
        string cad;
        For(i,a){
            cin>>cad;
            For(j,cad.size())
                mat[i][j] = cad[j] - '0';
        }
                
        int c,d;
        cin>>c>>d;
        int mat2[c][d];
        For(i,c){
            cin>>cad;
            For(j,cad.size())
                mat2[i][j] = cad[j] - '0';
        }
                
        int mmax = -(1<<30);
        int ax, ay;
        int primero,segundo;
        for(int x = -60; x< 60 ; x++){
            for(int y = -60; y< 60 ; y++){
                int ans = 0;
                int encontro = 0;
                For(i,a){
                    For(j,b){
                        if(i+x < 0 or i+x >= c) continue;
                        if(j+y < 0 or j+y >= d) continue;
                        ans += mat[i][j]*mat2[i+x][y+j];
                        encontro = 1;
                    }
                }
                
                if(ans > mmax and encontro){
                    mmax = ans;
                    primero = x;
                    segundo = y;
                }
            }
        }
        
        cout<<primero<<" "<<segundo<<endl;        
    }
    
    
    return 0;
}