#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int OFFBOARD = 0;
const int ONBOARD = 1;
const int APPLE = 2;
const int TURNLEFT = -1;
const int TURNRIGHT = 1;
const int DIRECT = 4;

bool gameOver(const vector<vector<int>>& board, int row, int col) {
    int size = board.size(); // n+1
    return (row<=0 || row>=size || col<=0 || col>=size || board[row][col]==ONBOARD);
    // 벽이나 자신과 부딪히면 game over
}


int snakeGame(vector<vector<int>>& board, queue<pair<int,int>>& change_dir) {
    int time=0, row=1, col=1; // 처음 시작 시간과 위치
    int rd[] = {0, 1, 0, -1}; // 동(오른쪽), 남, 서, 북 
    int cd[] = {1, 0, -1, 0};
    int dir = 0;
    queue<pair<int, int>> snake_on_b;
    // 뱀이 있는 보드 저장. 꼬리 줄이기에 사용

    board[row][col]=ONBOARD; // 첫 번째 칸 설정
    snake_on_b.push({row, col});

    while(true) {
        if(!change_dir.empty() && change_dir.front().first==time) { // 방향 바꿔야하면
            dir = (dir+change_dir.front().second+DIRECT)%DIRECT;
            change_dir.pop();
        }

        if(gameOver(board, row+rd[dir], col+cd[dir])) {
            time++; // 마지막 시도도 포함해야 함
            break;
        }
        row = row+rd[dir]; // 머리 위치 변경
        col = col+cd[dir];

        if(board[row][col]!=APPLE) { // 사과 아닌 경우 꼬리 칸 비움
            board[snake_on_b.front().first][snake_on_b.front().second]=OFFBOARD;
            snake_on_b.pop();
        }

        board[row][col]=ONBOARD; // 새로 도달한 칸 설정
        snake_on_b.push({row, col});
        time++; // 시간 증가
    }
    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, l;
    cin >> n >> k;
    vector<vector<int>> board(n+1, vector<int>(n+1,0));

    for(int i=0; i<k; i++) {
        int row, col;
        cin >> row >> col;
        board[row][col] = APPLE;
    }

    cin >> l;
    queue<pair<int,int>> change_dir;
    while(l--) {
        int x, tmp;
        char c;
        cin >> x >> c;

        // snakeGame 함수에서 direct 설정 시 숫자로 더해주기 위해 변경하여 저장
        if(c=='L') { // 방향 L로 틀어야하면
            tmp=TURNLEFT;
        }
        else { // 방향 R로 틀어야하면
            tmp=TURNRIGHT;
        }

        change_dir.push({x,tmp});
    }

    cout << snakeGame(board, change_dir);

    return 0;
}