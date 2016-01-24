#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int BLOCK_SIZE = 316; //sqrt(1e5)

struct Query {
    int left, right, number;

    bool operator < (const Query other) const {
        return right < other.right;
    }
};

int cnt[1 << 20];
long long result = 0;
int favourite;

void add(int v) {
    result += cnt[v ^ favourite];
    cnt[v]++;
}

void del(int v) {
    cnt[v]--;
    result -= cnt[v ^ favourite];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m >> favourite;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] ^ a[i - 1];
    }

    vector< vector<Query> > blocks(n / BLOCK_SIZE + 2, vector<Query>());
    for (int i = 0; i < m; i++) {
        int left, right;
        cin >> left >> right;
        left--; right++;
        blocks[left / BLOCK_SIZE].push_back(Query{left, right, i});
    }
    for (auto &i: blocks) {
        sort(i.begin(), i.end());
    }

    vector<long long> answer(m);
    for (int i = 0; i < blocks.size(); i++) {
        int left, right;
        left = right = i * BLOCK_SIZE;
        for (auto &q: blocks[i]) {
            while (right < q.right) {
                add(pref[right]);
                right++;
            }
            while (left < q.left) {
                del(pref[left]);
                left++;
            }
            while (left > q.left) {
                left--;
                add(pref[left]);
            }
            answer[q.number] = result;
        }
        for (int j = left; j < right; j++) {
            del(pref[j]);
        }
    }

    for (auto i: answer) {
        cout << i << '\n';
    }
}
