#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 125*125*9;
typedef pair<int, pair<int,int>> pi; // 루피 개수, {row,col} 좌표
const int DIR = 4;
int r[] = {-1, 1, 0, 0}; // 상하좌우
int c[] = {0, 0, -1, 1};


int minRupee(const vector<vector<int>>& cave, int n) {
    vector<vector<int>> dist(n, vector<int>(n, INF));
    priority_queue<pi, vector<pi>, greater<>> pq;

    dist[0][0] = cave[0][0]; // 시작점
    pq.push({cave[0][0], {0,0}});

    while(!pq.empty()) {
        int rup = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if(rup>dist[row][col]) { // 더 적은 루피로 이미 방문
            continue;
        }

        for(int i=0; i<DIR; i++) {
            int nr = row + r[i]; // 다음 칸 좌표 설정
            int nc = col + c[i];

            if(nr<0 || nr>=n || nc<0 || nc>=n) { // 범위 외
                continue;
            }

            int nrup = rup + cave[nr][nc];

            if(nrup<dist[nr][nc]) { // 더 적은 루피일 경우만 갱신
                dist[nr][nc] = nrup;
                pq.push({nrup, {nr,nc}});
            }
        }
    }
    return dist[n-1][n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, t=1;
    cin >> n;

    while(n!=0) {
        vector<vector<int>> cave(n, vector<int>(n,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> cave[i][j];
            }
        }
        cout <<  "Problem " << t << ": " << minRupee(cave, n) << "\n";
        t++;
        cin >> n;
    }

    return 0;
}