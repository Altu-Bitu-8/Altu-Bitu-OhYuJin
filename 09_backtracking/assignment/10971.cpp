#include <iostream>
#include <vector>

using namespace std;

int ans=10000000;

void tspBacktracking(int cnt, int n, int start, int now, const vector<vector<int>>& c, vector<bool>& v, int t) {
    if(t>ans) {
    // 이미 기존 최솟값보다 total이 크면 종료
        return;
    }

    if(cnt==n) { // 모든 마을 지난 경우
        if(c[now][start]==0) {
        // 마지막 위치에서 처음 마을 가지 못하는 경우 종료
            return;
        }
        t += c[now][start];
        ans=min(ans,t);
        return;
    }

    for(int i=1; i<=n; i++) {
        if(v[i]||c[now][i]==0) {
        // i 마을 이미 방문 했거나, 현재 위치에서 못 가는 경우
            continue;
        }
        v[i]=true;
        tspBacktracking(cnt+1, n, start, i, c, v, t+c[now][i]);
        v[i]=false;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> cost(n+1,vector<int>(n+1,0));
    vector<bool> visited(n+1, false);
    vector<int> seq(n);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> cost[i][j];
        }
    }

    for(int i=1; i<=n; i++) {
        visited[i]=true;
        int total=0;
        // 출발 어디서 했는지 기억해야함
        tspBacktracking(1, n, i, i, cost, visited, total);
        visited[i]=false;
    }

    cout << ans;

    return 0;
}