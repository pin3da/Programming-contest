using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define MP 11


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int solve(string cad,char c){
    int i = 0, j = cad.size()-1;
    int ans =0;
    while(i<j){
        int dis = (1<<30);
        if(cad[i]!=c){
            int k = i+1; 
            while(k < j){
                if(cad[k]==c){
                    swap(cad[i],cad[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }else{
            i++;
        }
        if(cad[j]!=c){
            int k = j-1;
            while(k > i){
                if(cad[k]==c){
                    swap(cad[i],cad[k]);
                    ans++;
                    break;
                }
                k--;
             }
        }else{
            j--;
        }
    }
    return ans;

}

int main(){ ___
   
    int n;cin>>n;
    string cad;cin>>cad;
    
    cout<<min(solve(cad,'H'),solve(cad,'T'))<<endl;
    
}
