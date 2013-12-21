using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

int main(){
    int numcas;
    int array[5];
    int tmp;
    while(cin>>numcas && numcas){
        while(numcas--){
            For(i,5){
                cin>>tmp;
                array[i]= (tmp<=127)?1:0;
            }
            int pin=0,ans=0;

            For(i,5){
                if(pin && array[i]){
                    pin=2;
                    break;
                }else if (array[i]) {
                    pin=1;
                    ans=i;
                }
            }

            if(pin==2 or pin==0)cout<<"*\n";
            else{
                switch (ans){
                    case 0:
                      cout<<"A\n";
                      break;
                    case 1:
                      cout<<"B\n";
                      break;
                    case 2:
                      cout<<"C\n";
                      break;
                    case 3:
                      cout<<"D\n";
                      break;
                    case 4:
                      cout<<"E\n";
                      break;
                }

            }
        }

    }

    return 0;
}
