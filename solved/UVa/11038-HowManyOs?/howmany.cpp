/**
* Manuel Pineda. Accepted
*/
using namespace std;
#include <iostream>
#include <sstream>
#include <cstring>
#define D(x) cout<< #x " = "<<(x)<<endl
template<class T>
string to_str(T o){stringstream ss; ss<<o; return ss.str();}

long long dp[40][40][2][2];

long long solve(int index,int howmany,int leading,int tope, string &num){
    if(index==num.size()) return (!leading)? howmany : 0;
    if(dp[index][howmany][leading][tope] != -1) return dp[index][howmany][leading][tope];
    int mmax = (tope)? num[index]-'0':9;
    long long ans = 0;
    for(int i = 0; i<= mmax; ++i)
        ans += solve(index+1,howmany + (i==0 and !leading), (i==0) and leading, (i==mmax) and tope, num);
    
    return dp[index][howmany][leading][tope] = ans;
}

int main(){
    long long a,b;
    while(cin>>a>>b and a!=-1 and b!=-1){
        memset(dp,-1,sizeof(dp));
        string tmp = to_str(a-1);
        long long uno = (a==0)?-1:solve(0,0,1,1,tmp);
        memset(dp,-1,sizeof(dp));
        tmp = to_str(b);
        long long dos = (b==0)?-1:solve(0,0,1,1,tmp);
//        D(uno);
//        D(dos);
        cout<<dos-uno<<endl;
    }
    return 0;
}
