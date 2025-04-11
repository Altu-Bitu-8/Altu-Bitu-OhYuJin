#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef vector<vector<int>> vi;
const int START = 1;

// stack 방식이 recurive보다 코드 길지만 메모리 적음
// bfs 구현 시 같은 코드에서 stack 대신 queue 사용
int stackDfs(const vi& c, vector<bool> &vis) {
    stack<int> s;
    s.push(START);
    vis[START]=true;

    int cnt = 0;

    while(!s.empty()) {
        int now = s.top();
        s.pop();
        cnt++;

        for(int tmp : c[now]) { // for(int i=0; i<c[now].size(); i++)과 동일
            if(!vis[tmp]) {
                vis[tmp] = true;
                s.push(tmp);
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, edge;
    cin >> n >> edge;

    vi com(n+1);

    while(edge--) {
        int a,b;
        cin >> a >> b;
        com[a].push_back(b);
        com[b].push_back(a);
    }

    vector<bool> visited(n+1,false);

    // 1번 컴퓨터 제외하기 위해 -1
    cout << stackDfs(com, visited)-1;
 
    return 0;
}