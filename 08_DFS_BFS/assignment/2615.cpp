#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef vector<vector<int>> vi;
const int MAX = 19;
const int DIRECT = 4;
const int WIN = 5;

bool onBoard(int x, int y) { // 범위 내에 있는지 확인
    if(x<0 || x>=MAX || y<0 || y>=MAX) {
        return false;
    }
    return true;
}

tuple<int, int, int> findWinner(const vi& bo) {
    //왼쪽 위부터 순차적으로 탐색하므로 방향은 오른쪽, 아래, 오른쪽 위, 오른쪽 아래만 탐색
    int dx[]={1, 0, 1, -1};
    int dy[]={0, 1, 1, 1};

    for(int i=0; i<MAX; i++) {
        for(int j=0; j<MAX; j++) {

            if(bo[i][j]==0) { // 아무 돌도 없으면 넘어감
                continue;
            }

            int now = bo[i][j]; // 기준 돌의 색

            for(int d=0; d<DIRECT; d++) {
                bool isWIN = false;

                for(int k=1; k<=WIN; k++) {
                // 기준 돌 제외 5개 탐색
                    int x = i+dx[d]*k;
                    int y = j+dy[d]*k;

                    if(!onBoard(x,y) || now!=bo[x][y]) {
                    // 범위 내에 있지 않거나 색이 다르면 해당 방향 탐색 종료
                        break;
                    }

                    if(k==WIN-1) {
                    // 현재 돌 포함 5개 같으면 true로 설정
                        isWIN = true;
                    }
                    else if(k==WIN) {
                    // 6번째 돌도 같으면 다시 false로 설정
                        isWIN = false;
                    }
                }

                if(isWIN && onBoard(i-dx[d], j-dy[d]) && now==bo[i-dx[d]][j-dy[d]]) {
                // true인데 이전 돌 역시 색 같은 경우 6개 연속이므로 false
                    isWIN = false;
                }

                if(isWIN) {
                    // 모든 과정 거쳤을 때 true이면 win
                    return make_tuple(now, i+1, j+1);
                }
            }
        }
    }
    return make_tuple(0,0,0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vi board(MAX, vector<int>(MAX));

    for(int i=0; i<MAX; i++) {
        for(int j=0; j<MAX; j++) {
            cin >> board[i][j];
        }
    }

    tuple<int, int,int> ans = findWinner(board);

    if(get<0>(ans)==0) {
        cout << "0";
    }
    else {
        cout << get<0>(ans) << "\n";
        cout << get<1>(ans) << " " << get<2>(ans);
    }

    return 0;
}