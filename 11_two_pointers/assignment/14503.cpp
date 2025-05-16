#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> vv;
const int CLEAN = -1;
const int dir = 4;
const int ROW[] = {-1, 0, 1, 0}; // 북, 동, 남, 서 
const int COL[] = {0, 1, 0, -1};

bool checkBound(vv& state, int n, int m, int r, int c) {
    return (r>=0 && r <n && c>=0 && c<m);
}

int cleanWithRobot(vv& state, int n, int m, int r, int c, int d) {
    int cnt=0;
    while(true) {
        if(state[r][c]==0) {
            state[r][c]=CLEAN;
            cnt++;
            continue;
        }

        bool not_clean = false;
        for(int i=0; i<dir; i++) {
            int tmp_r = r+ROW[i];
            int tmp_c = c+COL[i];
            if(!checkBound(state, n, m, tmp_r, tmp_c)) {
                continue;
            }
            
            if(state[r+ROW[i]][c+COL[i]]==0) {
                not_clean = true;
                break;
            }
        }

        if(!not_clean) {
            int tmp_r = r-ROW[d];
            int tmp_c = c-COL[d];

            if(!checkBound(state, n, m, tmp_r, tmp_c)) {
                break;
            }
            if(state[tmp_r][tmp_c]==1) {
                break;
            }
            r = tmp_r;
            c = tmp_c;
            continue;
        }
        
        while(true) {
            d  = (d-1+dir)%dir;
            int tmp_r = r+ROW[d];
            int tmp_c = c+COL[d];

            if(!checkBound(state, n, m, tmp_r, tmp_c)) {
                continue;
            }
            if(state[tmp_r][tmp_c]==0) {
                r = tmp_r;
                c = tmp_c;
                break;
            }
        }
    }
    return cnt;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, r, c, d;
    cin >> n >> m >> r >> c >> d;
    vv state(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> state[i][j];
        }
    }

    cout << cleanWithRobot(state, n, m, r, c, d);

    return 0;
}