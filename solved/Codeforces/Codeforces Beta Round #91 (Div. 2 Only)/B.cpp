// http://codeforces.com/contest/122/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define MP 100010


int main (){ ___

    string cad;cin>>cad;
    int a=0,b=0;
    for(int i = 0; i< cad.size(); ++i){
        a += (cad[i] == '4');
        b += (cad[i] == '7');
    }

    int ans = max(a,b);
    if(ans == 0) {
      cout<<-1<<endl;
      return 0;
    }
    if(a >= b)
      cout<<4<<endl;
    else
      cout<<7<<endl;

    return 0;
}