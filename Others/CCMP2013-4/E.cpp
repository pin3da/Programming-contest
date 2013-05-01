using namespace std;
#include<iostream>

typedef long long int ll;
ll a[510],b[510],c[510];

void fill(){
    a[1] = 1;b[1] = 1; c[1] = 3;
    for(int i=2,j=3,k=4;i<510;++i,j+=2,k+=2){
        a[i] = a[i-1] + (i*(i+1))/2;
        b[i] = b[i-1] + (j*(j+1))/2;
        c[i] = c[i-1] + (k*(k+1))/2;
    }
}

int main(){
    fill();
    int n;
    while(cin>>n)
        cout<<(a[n] + ((n&1)?c[(n-1)>>1]:b[n>>1]))<<endl;
    return 0;
}
