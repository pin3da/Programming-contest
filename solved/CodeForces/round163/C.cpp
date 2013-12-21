using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

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
typedef long long int lli;

struct ans{
    int a,b,c;
    ans(){};
    ans(int A,int B,int C):a(A),b(B),c(C){};
};

int mat[1001][1001];
int ocu[1001][2];
int n,posm;
vector<ans> mio;

void funx(){
    int i=0,j=n-1;
    while(i<n and j>=0){
        if(ocu[i][0] == 1 and ocu[j][0]==0){
            ocu[j][0]=1;
            ocu[i][0]=0; 
            mio.push_back(ans(1,i+1,j+1));
        }else if(ocu[i][0]==0 and ocu[j][0]==0){
            i++;
        }else if(ocu[i][0]==1 and ocu[j][0]==1){
            j--;
        }else{
            j--;
        }
        
    }
}

void funy(){
    int i=n-1;
    int j=0;
    while(i>=0 and j< n){
    
        if(ocu[i][1]== 0 and ocu[j][1]==1){
            ocu[j][1]=0;
            ocu[i][1]=1; 
            mio.push_back(ans(2,i+1,j+1));
        }else if(ocu[i][1]==0 and ocu[j][1]==0){
            j++;
        }else if(ocu[i][1]==1 and ocu[j][1]==1){
            i--;
            j++;
        }else{
            i=j;
        }
        
    }
}


bool dia(){
    For(i,n)
        if(ocu[i][0]==1 and ocu[i][1]==1){
            D(ocu[i][0]);
            D(ocu[i][1]);
            posm = i;   
            return true;
        }
    return false;

}

void fundia(){
    int i=0,j,pin=0;
    for(int k=n-1;k>=0;--k)
        if(ocu[k][0]==1 and ocu[k][1]==1){
          j=k;
          pin=true;
        }
    if(!pin) return;
    if(ocu[j+1][1]==0){
        mio.push_back(ans(1,j+1,j+2));
        ocu[j][0]=0;
        ocu[j+1][0]=1;
    }else if(j>0 and ocu[j-1][0]==0){
        mio.push_back(ans(2,j,j+1));
        ocu[j][0]=0;
        ocu[j-1][0]=1;
    }
    fundia();
    
}
int main(){
    cin>>n;
    int x,y;
    memset(ocu,0,sizeof(ocu));
    For(i,n-1){
        cin>>x>>y;
        ocu[x-1][0]=1;
        ocu[y-1][1]=1;
    }
    mio.clear();
    funx();
    funy();
    fundia();
    cout<<mio.size()<<endl;
    For(i,mio.size()){
        cout<<mio[i].a<<" "<<mio[i].b<<" "<<mio[i].c<<endl;
    }
    
    return 0;
}

