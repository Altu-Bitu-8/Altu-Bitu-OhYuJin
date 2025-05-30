#include <iostream>
#include <vector>

using namespace std;
const int BOUND = 100;
const int DIR = 4;
int dx[] = {1, 0, -1, 0}; // 오른쪽, 위, 왼쪽, 아래
int dy[] = {0, -1, 0, 1};

void drawDragonCurve(vector<vector<bool>>& graph, int x, int y, int d, int g) {
    vector<int> gen_dir;
    gen_dir.push_back(d); // 0세대

    for(int i=0; i<g; i++) { // 1~g세대 방향 정보
        int size = gen_dir.size();
        for(int j=size-1; j>=0; j--) {
            gen_dir.push_back((gen_dir[j]+1)%DIR); // 90도 회전
        }
    }
    graph[y][x]=true; // x가 col, y가 row

    for(int i=0; i<gen_dir.size(); i++) { // 그리기
        x+=dx[gen_dir[i]];
        y+=dy[gen_dir[i]];

        if(x>=0&&x<=BOUND && y>=0&&y<=BOUND) { // 범위 내에 있을 때만
            graph[y][x]=true;
        }
    }


}

int cntSq(const vector<vector<bool>>& graph) {
    int ans = 0;
    for(int i=0; i<BOUND; i++) {
        for(int j=0; j<BOUND; j++) {
            if(graph[i][j] && graph[i][j+1] && graph[i+1][j] && graph[i+1][j+1]) {
                ans++;
            }
        }   
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,x,y,d,g;
    vector<vector<bool>> graph(BOUND+1, vector<bool>(BOUND+1, false));
    cin >> n;

    while(n--) {
        cin >> x >> y >> d >> g;
        drawDragonCurve(graph, x, y, d, g);
    }

    cout << cntSq(graph);

    return 0;
}