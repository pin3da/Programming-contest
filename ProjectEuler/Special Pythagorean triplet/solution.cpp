using namespace std;
#include<bits/stdc++.h>

int main(){
    int n = 1001;
    for(int i = 1; i < n; ++i){
        for(int j = i+1; j < n ; ++j){
            int c = 1000 - i - j;
            if(c > j and (i*i + j*j) == c*c)
                cout<<i*j*c<<endl;
        }
    }
    return 0;
}
