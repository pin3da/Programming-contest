// http://codeforces.com/contest/159/problem/D

using namespace std;
#include<iostream>
#include<cstring>
#include<string>

int dp[2005][2005];
int start[2005];
int iimage[2005];
string cad;

int palindrome(int i,int j){
    if(dp[i][j] != -1) return dp[i][j];
    if(i>=j) return dp[i][j] = true;
    return dp[i][j] = (cad[i]==cad[j] and palindrome(i+1,j-1));
}

int main(){
    cin>>cad;
    memset(dp,-1,sizeof(dp));
    
    for(int i = 0; i< cad.size(); ++i)
        for(int j = i; j < cad.size(); ++j)
            if(palindrome(i,j)) start[i]++;
                
    for(int i = cad.size() -1 ; i>= 0; --i)
        iimage[i] = iimage[i+1] + start[i];
    
    long long ans = 0;
    for(int i = 0; i< cad.size() -1; ++i)
        for(int j = i; j< cad.size(); ++j)
            if(palindrome(i,j))
                ans += iimage[j+1];
    
    cout<<ans<<endl;
    return 0; 
}