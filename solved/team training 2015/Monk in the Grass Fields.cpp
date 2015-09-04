#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while ( t-- ){
		int n, x, k; cin >> n >> k;
		priority_queue<int,vector<int>, greater<int> > Rows,Cols;
		int sumC[n], sumR[n];
		memset(sumC,0,sizeof sumC);
		memset(sumR,0,sizeof sumR);
		
		for(int i = 0; i < n;i++){
			for (int j = 0; j < n; j++){
				cin >> x;
				sumC[i] += x;
				sumR[j] += x;
			}
		}
		
		
		
		for(int i = 0; i < n; i++){
			Rows.push(sumR[i]);
			Cols.push(sumC[i]);
		}
		
		int sol = 100000000;
		
		int usingRows[k+1],usingCols[k+1];
		usingRows[0] = usingCols[0] = 0;
		
		for(int i = 1; i <= k; i++){
			int rt = Rows.top(); Rows.pop();
			int ct = Cols.top(); Cols.pop();
			usingRows[i] = usingRows[i-1] + rt;
			usingCols[i] = usingCols[i-1] + ct;			 
			Rows.push(rt + n);
			Cols.push(ct + n);
			
		}
		
		
		for(int i =  0; i <= k; i++){
			sol = min(sol, usingRows[i] + usingCols[k-i] + i*(k-i));
		}
		
		cout << sol << endl;	
	}
}
