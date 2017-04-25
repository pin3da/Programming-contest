// http://codeforces.com/contest/44/problem/B

using namespace std;
#include<bits/stdc++.h>


int main(){
    int n,a,b,c;
    while(cin>>n>>a>>b>>c){
        int tmp = 0;
        for(int i = 0; i<= c; ++i){
            for(int j = 0; j<= b; ++j){
                int k = (n - 2*i - j);
                int ok = 1;
                k*=2;
                if(k < 0 or k>a)ok = 0;
                tmp += ok;
            }
        }
        cout<<tmp<<endl;
    }

    return 0;
}