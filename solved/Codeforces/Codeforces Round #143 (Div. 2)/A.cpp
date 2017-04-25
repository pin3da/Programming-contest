// http://codeforces.com/contest/231/problem/A

using namespace std;
#include<iostream>

int main(){
    int n;cin>>n;
    int ans=0,a,b,c;
    for(int i=0;i<n;++i){
        cin>>a>>b>>c;
        if(a+b+c>=2)ans++;
    }
    cout<<ans<<endl;
}
