using namespace std;
#include<iostream>
#include<cmath>

int main(){
    long long int a,b,c;
    while(cin>>a>>b>>c){
        long long int k = 0;
        for(; ( 2*(a+(k*b)) > k*(k+1)) or ( 2*(k)*c > (k)*(k+1) );++k);
        cout<<((a==0)?0:k)<<endl;
    }
    
    return 0;
}
