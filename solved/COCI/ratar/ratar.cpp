using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl
#define For(i,n) for(int i = 0; i < (n); ++i)
#define For_(i,a,n) for(int i = a+1; i < (n); ++i)
#define MP 55

int plot[MP][MP];
int iimage[MP][MP];
int iimage2[MP][MP];
int n;

int v(int x, int y){
    return x>=0 and y>=0 and x < n and y < n;
}


int solve(){
    iimage[0][0] = plot[0][0];
    for(int i = 1; i< n; ++i){
        iimage[i][0] =  iimage[i-1][0] + plot[i][0];
        iimage[0][i] =  iimage[0][i-1] + plot[0][i];
    }
    
    for(int i = 1; i< n; ++i)
        for(int j = 1; j< n; ++j)
            iimage[i][j] = plot[i][j] + iimage[i][j-1] + iimage[i-1][j] - iimage[i-1][j-1];



    int ans = 0;
    for(int i = 0; i< n; ++i){
        for(int j = 0; j< n; ++j){
            for(int k = i+1; k < n; ++k){
                for(int m = j+1; m < n; ++m){

                    int a = iimage[i][j];
                    int b = iimage[i][m] - a;
                    int c = iimage[k][j] - a;
                    int d = iimage[k][m] - b - c -a;
                    if(i==0 and j == 1 and k==1 and m==2){
                        printf("Critical: %d %d %d %d\n",a,b,c,d);
                    }
                    if(b==c or a==d){
                        printf("From (%d,%d) to (%d,%d)\n",i,j,k,m);
                        ans++;
                    }
    
                }
            }
        }
    }
    
    iimage2[0][n-1] =  plot[0][n-1];
    for(int i = 1; i< n; ++i){
        iimage2[i][n-1] = iimage2[i-1][n-1] + plot[i][n-1];
        iimage2[0][n-i-1] = iimage2[0][n-i] + plot[0][n-i-1];
    }
    
    for(int i = 1; i< n; ++i){
        for(int j = n - 2; j >= 0; --j){
            iimage2[i][j] = iimage2[i][j+1] + iimage2[i-1][j] - iimage2[i-1][j+1] + plot[i][j];
        }    
    }
    cout<<endl;    
    for(int i = 0; i< n; ++i){
        for(int j = n-1; j >= 0; --j){
            for(int k = i+1; k < n; ++k){
                for(int m = j-1; m >= 0; --m){
                    int a = iimage2[i][j];
                    int b = iimage2[i][m] - a;
                    int c = iimage2[k][j] - a;
                    int d = iimage2[k][m] - b - c -a;
                    if(b==c or a==d){
                        printf("From (%d,%d) to (%d,%d)\n",i,j,k,m);
                        ans++;
                    }
                }
            }
        }
    }
    For(i,n){
        For(j,n){
            cout<<iimage[i][j]<<" ";
        }
        cout<<endl;
    }
    For(i,n){
        For(j,n){
            cout<<iimage2[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return ans;
}

int main(){
    cin>>n;
    for(int i = 0; i< n; ++i)
        for(int j = 0; j< n; ++j)
            cin>>plot[i][j];
            
    cout<<solve()<<endl;
    return 0;
}
