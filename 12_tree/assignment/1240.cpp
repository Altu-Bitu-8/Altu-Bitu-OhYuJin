#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dfsDistance(const vector<vector<int>>& tree, vector<bool>& visited, int cur, int dest, int ans) {
    if(cur==dest) { // 현재와 목표가 같으면 도달한 것. 지금까지의 거리 return (아래 코드의 tmp가 됨)
        return ans;
    }

    visited[cur]=true; // 현재 노드 방문처리

    for(int next=1; next<tree.size(); next++) { // 인접 노드 순차 탐색
        if(!visited[next] && tree[cur][next]!=0) { // 다음노드 아직 방문하지 않았고, 현재와 다음 사이 이어져있는 경우
            int tmp = dfsDistance(tree, visited, next, dest, ans+tree[cur][next]); // 다음 노드로 dfs 시도
            if(tmp!=-1) { // 시도하여 나온 값이 -1 아니면 tmp 값이 최종 거리
                return tmp;
            }
        }
    }
    return -1; // 경로 없음
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> tree(n+1, vector<int>(n+1,0));
    
    for(int i=1; i<n; i++) {
        int n1, n2, d;
        cin >> n1 >> n2 >> d;
        tree[n1][n2]=tree[n2][n1]=d;
    }

    while(m--) {
        int t1, t2;
        vector<bool> visited(n+1,false);
        cin >> t1 >> t2;
        cout << dfsDistance(tree, visited, t1, t2, 0) << "\n";
    }


    return 0;
}