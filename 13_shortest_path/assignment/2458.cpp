#include <iostream>
#include <vector>

using namespace std;

void floydWarshall(int n, vector<vector<int>>& graph) {
    for(int k=1; k<=n; k++) { // 중간 정점
        for(int i=1; i<=n; i++) { // 출발 정점
            for(int j=1; j<=n; j++) { // 도착 정점
                if(graph[i][k]&&graph[k][j]) {
                    graph[i][j]=true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m,a,b;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1,false));

    while(m--) {
        cin >> a >> b;
        graph[a][b]=true; // a가 b보다 작음 (우열 존재)
    }

    floydWarshall(n, graph);

    int ans = 0;
    for(int i=1; i<=n; i++) {
        int cnt=0; // 자기보다 크거나 작은 학생 수
        for(int j=1; j<=n; j++) {
            if(i==j) {
                continue;
            }
            if(graph[i][j] || graph[j][i]) {// i와 j의 우열을 알고 있는 경우
                cnt++;
            }
        }
        if(cnt==n-1) { // 자신 제외 나머지와 우열을 모두 아는 경우우
            ans++;
        }
    }

    cout << ans;

    return 0;
}