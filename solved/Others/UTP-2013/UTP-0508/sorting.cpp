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
#include<cctype>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

long long int ans;


int data[10000];

int bubblesort(int tam){
      
      int temp=0;
      int cont= 0;
      
      for (int i=1; i<tam; i++){
          for (int j=0 ; j<tam - 1; j++){
              if (data[j] > data[j+1]){
                   cont++; 
                   temp = data[j];
                   data[j] = data[j+1];
                   data[j+1] = temp;
              }
          }      
      }
      return cont;
}




int main(){
    int n;
    while(cin>>n){
        For(k,n)cin>>data[k];
        cout<<"Minimum exchange operations : "<<bubblesort(n)<<endl;
    }
    return 0;
}
