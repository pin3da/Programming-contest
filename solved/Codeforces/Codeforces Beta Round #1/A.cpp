// http://codeforces.com/contest/1/problem/A

using namespace std;
#include<bits/stdc++.h>


int main(){
    double n,m,a;
    cin>>n>>m>>a;
    cout<<(long long)((long long)ceil(n/a)*(long long)ceil(m/a))<<endl;
    return 0;
}
