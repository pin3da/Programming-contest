// http://codeforces.com/contest/36/problem/B

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
typedef long long int lli;
typedef pair<int , int> pii;


int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

set<lli> lucky;
void gen_lucky(lli a=0){
    if(a>1000000000L) return;
    lli x = (a*10) + 4;
    lli y = (a*10) + 7;
    lucky.insert(x);
    lucky.insert(y);
    gen_lucky(x);
    gen_lucky(y);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a,b;
    cin>>a>>b;
    vector<vector<char> > mat(a,vector<char>(a));
    For(i,a)For(j,a)cin>>mat[i][j];
    int mio = b;
    b--;
    while(b--){
        vector<vector<char> > nuevo(mat.size()*a, vector<char>(mat.size()*a));
        For(j,a){
            For(k,a){
                int delta = mat.size()/a;
                int pinta = 1;
                For(mm,delta)
                    For(nn,delta)
                        pinta &= mat[j*delta+mm][k*delta+nn]=='*';
                if(pinta){
                    for(int m=0;m<mat.size();++m){
                        for(int n=0;n<mat.size();++n){
                            nuevo[j*mat.size()+m][k*mat.size()+n] = '*';
                        }
                    }
                }else{
                    for(int m=0;m<mat.size();++m){
                        for(int n=0;n<mat.size();++n){
                            nuevo[j*mat.size()+m][k*mat.size()+n] = mat[m][n];
                        }
                    }
                }
            }
        }
        
        mat = nuevo;
    }
    
    For(i,mat.size()){
        For(j,mat.size()){
            //cout<<mat[mat.size()-i-1][j];
            cout<<mat[i][j];
        }
        cout<<endl;
    }
        
    return 0;
}