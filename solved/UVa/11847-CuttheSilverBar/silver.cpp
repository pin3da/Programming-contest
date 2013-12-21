using namespace std;
#include <iostream>

int mlog_2(int n){
    int i = 0;
    while(n){i++;n>>=1;}
    return i;
}

int main(){
    int n;
    while(cin>>n and n){
        cout<<mlog_2(n)-1<<endl;
    }
    return 0;
}
