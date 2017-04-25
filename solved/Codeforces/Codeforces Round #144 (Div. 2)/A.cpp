// http://codeforces.com/contest/233/problem/A

using namespace std;
#include<iostream>

int main(){
    int n;cin>>n;
    if(n%2!=0){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=n-2;i+=2){
        cout<<i+1<<" "<<i<<" ";
    }
    cout<<n<<" "<<n-1<<endl;
    
}
