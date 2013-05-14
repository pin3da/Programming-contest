using namespace std;
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
 
int solve(int cx,int cy, int px, int py, int depth){
    if(depth == 0) return 0;
    int len  = 2*depth + 1;
    int l2 = len>>1;
    int ans = 0;
    if( abs( px - cx) <= l2 and abs( py - cy) <= l2 ) ans++;
    
    return ans + solve(cx + l2 , cy + l2, px, py, depth/2)
               + solve(cx + l2 , cy - l2, px, py, depth/2) 
               + solve(cx - l2 , cy + l2, px, py, depth/2) 
               + solve(cx - l2 , cy - l2, px, py, depth/2);
}
 
int main(){
    int a,b,c;
    while(cin>>c>>a>>b and a+b+c != 0){
        //cout<<solve(1024,1204,a,b,c)<<endl;
        printf("%3d\n",solve(1024,1204,a,b,c));
    }
    return 0;
}
