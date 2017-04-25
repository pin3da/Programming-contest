// http://codeforces.com/contest/368/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define MP 100010

int ii[MP][3];

int _count(int i, int j, int let){
    if(i == 0) return ii[j][let];
    return ii[j][let] - ii[i-1][let];
}


int check(int i,int j){
    int a = _count(i,j,0);
    int b = _count(i,j,1);
    int c = _count(i,j,2);
    /*
    D(a);
    D(b);
    D(c);
    */
    if(a == c and b == c) return true;
    
    int d = a-1;
    if(d == c and b == c) return true;
    d = b-1;
    if(a == c and d == c) return true;
    d = c-1;
    if(a == d and b == d) return true;
    d = a +1;
    if(d == c and b == c) return true;
    d = b+1;
    if(a == c and d == c) return true;
    d = c+1;
    if(a == d and b == d) return true;
    return false;
}

void solve(){
    int m;
    cin>>m;
    while(m--){
        int i,j;
        cin>>i>>j;
        i--;
        j--;
        if((j-i + 1) < 3) cout<<"YES"<<endl;
        else if(check(i,j)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int main(){ ___

    string cad;
    cin>>cad;
    for(int i = 0; i < cad.size(); ++i){
        ii[i][0] = (cad[i] == 'z');
        ii[i][1] = (cad[i] == 'x');
        ii[i][2] = (cad[i] == 'y');
    }
    
    for(int i = 1; i < cad.size(); ++i){
        ii[i][0] += ii[i-1][0];
        ii[i][1] += ii[i-1][1];
        ii[i][2] += ii[i-1][2];
    }
    
    solve();
    
    return 0;
}