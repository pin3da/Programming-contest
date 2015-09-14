#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;

    while(cin >> n >> k){
        priority_queue<int, vector<int>, greater<int> > Q;
        int sum = 0,x;        
        for(int i = 0; i < n; i++ ){
            cin >> x;
            Q.push(x);
            sum += x;
        }
        
        for(int i = 0; i < k; i++){
            x = Q.top();
            Q.pop();
            if(x >= 0)
                sum -= 2*x;    
            else
                sum += abs(2*x);
            
            Q.push(x*-1);
        }
        
        cout << sum << endl;
    }
}
