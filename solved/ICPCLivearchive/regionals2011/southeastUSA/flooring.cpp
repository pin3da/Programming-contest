using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define For(i,n) for(int i=0;i<(n);++i)
#define D(x) cout<<#x " = " <<x<<endl
#define rall(x) x.rbegin(),x.rend()

typedef vector <vector <int> > mat;
typedef long long int lli;

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

mat todos;

void divisores(int tengo, vector<int> llevo,int mmax){
    if(tengo == 1) todos.push_back(llevo);
    for(int i = mmax ; i<=tengo;++i){
        if(tengo%i==0){
            llevo.push_back(i);
            divisores(tengo/i,llevo,i);
            llevo.erase(llevo.end()-1);
        }
    }
}


int main(){
    int n;
    while(cin>>n and n){
        todos.clear();
        divisores(n<<1,vector<int> (),2);
        divisores((n<<1)-1,vector<int> (),2);
        lli mm = (1LL << 63) -1;
        For(i,todos.size()) sort(rall(todos[i]));
        For(i,todos.size()){
            lli actual = 1;
            For(j,todos[i].size()){
                actual *= pow(primes[j],todos[i][j]-1);
                if(actual < 0LL){
                    actual = (1LL << 63) -1;
                    break;
                }
            }
            mm = min(mm,actual);
        }
        cout<<mm<<endl;
    }

    return 0;
}

