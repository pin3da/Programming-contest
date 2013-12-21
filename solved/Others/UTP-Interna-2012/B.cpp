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
const double eps = 1e-9;
typedef long long int lli;
typedef pair<int , int> pii;

int my_cmp(pair<char,int> a,pair<char,int> b){
    return a.second > b.second;
}

int main(){
    int c,q,k,tcid=0;
    int first = 1;
    while(cin>>c>>q>>k and c+q+k){
        string name;
        int cuantas;
        vector<int> colors;
        For(i,c){
            cin>>name>>cuantas;
            For(j,cuantas) colors.push_back(i);
        }
       // For(i,colors.size()){
       //     cout<<i<<" : "<<colors[i]<<endl;
       // }
        
        cout<<"Caso #"<<++tcid<<":"<<endl;
        For(i,q){
            vector<int> used(max(7,k));
            int tt;
            For(j,max(7,k)){
                cin>>tt;
                tt--;
                used[j]=tt;
            }
            vector<int> ans;
            For(j,colors.size()){
                int pin = 1;
                for(int jj = 0; jj<k and jj<used.size();++jj){
                    pin &= (j != used[used.size()-jj-1] );
                }
                pin &= used[used.size()-7] != j;
                pin &= colors[j]!= colors[used[used.size()-1]];
                if(pin) ans.push_back(j);
            }
            if(ans.size()==0){
                cout<<"Comprar otra blusa"<<endl;
            }else{
                For(j,ans.size()) cout<<(ans[j]+1)<<((j==ans.size()-1)?"\n":" ");
            }
        }
        cout<<endl;
    
    }
    
    
    return 0;
}
