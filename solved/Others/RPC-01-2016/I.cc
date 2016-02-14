#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x " = " << (x) << endl

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<set<char> > groups(110);
		vector<vector<int> > run(255);
		
		string let = "bgry", tm;
		
		for(int i = 0; i < n; i++){
			cin >> tm;
			char suit = tm.back();
			tm.pop_back();
			int val = atoi(tm.c_str());
			//cout << suit << " " << val << endl;
			groups[val].insert(suit);
			run[suit].push_back(val);
		}
		
		bool ok = false;
		for(int i = 0; i < let.size();i++){
			sort(run[let[i]].begin(), run[let[i]].end());
			run[let[i]].resize(unique(run[let[i]].begin(), run[let[i]].end()) -  run[let[i]].begin());
			if(run[let[i]].size() < 3) continue;
			for(int j = 0; j < run[let[i]].size() - 2; j++){
				//cout << j << endl;
				if(run[let[i]][j] + 1 == run[let[i]][j + 1] && run[let[i]][j] + 2 == run[let[i]][j + 2])
					ok = true;
			}
		}
		//cout << "pasa" << endl;
		for(int i = 0; i < 110; i++){
			if(groups[i].size() >= 3) ok = true;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
		
	}
}
