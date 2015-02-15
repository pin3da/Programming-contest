using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl


string convert(string &cad, int off) {
	string ans = cad;
	for (int i = 0; i < cad.size(); ++i) {
		if (cad[i] != ' ')
			ans[i] = (((cad[i] - 'A') + off) % 26) + 'A';
	}
	return ans;
}

char countl(string &cad) { 
	vector<int> ans(26, 0);
	for (int i = 0; i < cad.size(); ++i) {
		if (cad[i] != ' ')
			ans[cad[i] - 'A']++;
	}

	for (int i = 0; i < ans.size(); ++i) 	{
		// D(ans[i]);
	}
	int id = 0, best = 0;
	for (int i = 0; i < ans.size(); ++i) {
		if (ans[i] > best) {
			id = i;
			best = ans[i];
		}
	}
	// D(id);
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	if (ans[0] == ans[1]) return '$';
	return id + 'A';

}

int next() {
	string line;
	getline(cin, line);
	return atoi(line.c_str());
}

int main() {
	string tt = "MY OLDER BROTHERS DIARY ENTRIES USE A SIMPLE ENCRYPTION TECHNIQUE";
	countl(tt);

	// return 0;
	int n =  next();
	while (n--) {
		string line;
		getline(cin, line);
		int seen = false;
		for (int i = 26; i >= 1 and !seen; --i) {
			string cad = convert(line, i);
			char frec = countl(cad);
			if (frec == 'E') {
				cout << (26 - i) << " " << cad << endl;
				seen = true;
			}
		}
		if (!seen) {
			cout << "NOT POSSIBLE" << endl;
		}
	}	
  return 0;
}