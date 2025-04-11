#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef vector<vector<int>> vi;

int dfs(const vi& fam, int p1, int p2) {
    vector<int> vis(fam.size(),-1); // 방문 안했으면 -1
    stack<int> s;
    s.push(p1);
    vis[p1]=0; // p1 기준 촌수 vis에 저장

    while(!s.empty()) {
        int now = s.top();
        s.pop();

        for(int tmp : fam[now]) {
            if(vis[tmp]==-1) {
                // 현재 기준에서 하나 차이이므로 1촌 더함
                vis[tmp] = vis[now]+1;
                s.push(tmp);

            }
        }
    }
    return vis[p2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, p1, p2;
    cin >> n >> p1 >> p2 >> m;

    vi fam(n+1);
    vector<int> chil_par(n+1,0);

    while(m--) {
        int a,b;
        cin >> a >> b;
        fam[a].push_back(b);
        fam[b].push_back(a);
    }

    cout << dfs(fam, p1, p2);
 
    return 0;
}