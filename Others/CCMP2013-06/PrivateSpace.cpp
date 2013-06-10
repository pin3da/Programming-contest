using namespace std;
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cmath>
#include<cassert>
#include<cstring>
#define For(i,n) for(int i = 0; i<(n) ; ++i)
#define D(x) cout<< #x " = "<<(x)<<endl

vector<int> limits;

struct state{
    vector<int> groups;
    int sum;
    state(vector<int> a){
        groups = a;
        sum = 0;
        for(int i = 0; i< a.size();++i)
            sum += a[i]*(i+1);
    }
    state(const state &a){
        groups = a.groups;
        sum = a.sum;
    }
    
    bool operator <(const state &o)  const{
        if(groups == o.groups) return sum < o.sum;
        return groups < o.groups;
    }
   
    bool operator==(const state &o) const{
        if( (*this)< o or o < (*this)) return false;
        return true;
    }
};

struct dps{
    state a;
    int b,c;
    dps(state x,int y, int z): a(x),b(y),c(z){}
    bool operator<(const dps &o) const{
        if(a == o.a and b == o.b) return c < o.c;
        if(a == o.a ) return b < o.b;
        return a < o.a;
    }

};

map<dps,int> dp;

int solve(state act,int row,int col){
    if(act.sum == 0) return 1;
    if(row == 0) return 0;
    if(col >= row) return solve(act,row-1,0);
    int queda = row - col;
    if(act.sum > limits[row - 1] + queda) return false;

    if(dp.count(dps(act,row,col)) > 0) return dp[dps(act,row,col)];
    
    for(int i = 1; i <= queda; i++){
		if(act.groups.size() >= i and act.groups[i-1] != 0){
		    act.groups[i-1]--;
			if(solve(state(act.groups), row, col + i + 1))
				return dp[dps(act,row,col)] = 1;
			
		    act.groups[i-1]++;
		}
	}
	return dp[dps(act,row,col)] = 0;

}

int main(){
    int g;
    int st=0;
    limits.assign(13,0);
    for(int i = 1; i< 13 ; ++i){
        limits[i] = limits[i-1]+i;
    }
    while(cin>>g and g){
        vector<int> groups(g);
        For(i,g)
            cin>>groups[i];

        int ans = (1<<30);
        
        dp.clear();
        For(i,12){
            if(solve(state(groups),i+1,0)){
                ans = i;
                break;
            }
        }

        if(ans == (1<<30))
            cout<<"impossible"<<endl;
        else
            cout<<ans+1<<endl;
    }
    return 0;
}
