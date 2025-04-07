#include <iostream>
#include <vector>

using namespace std;
const int GEAR_MAX = 8;
const int FIND_RIGHT = 6;
const int FIND_LEFT = 2;
typedef vector<vector<int>> vv;

bool needLeftRotate(const vv& g, const vector<int>& p, int n) {
    // 기준 톱니의 왼쪽 톱니가 회전이 필요한지 확인
    int r = (p[n]+FIND_RIGHT)%GEAR_MAX;
    int l = (p[n-1]+FIND_LEFT)%GEAR_MAX;

    return g[n-1][l]!=g[n][r];   
}

bool needRightRotate(const vv& g, const vector<int>& p, int n) {
    // 기준 톱니의 오른쪽 톱니가 회전이 필요한지 확인
    int l = (p[n]+FIND_LEFT)%GEAR_MAX;
    int r = (p[n+1]+FIND_RIGHT)%GEAR_MAX;

    return g[n][l]!=g[n+1][r];    
}

void rotateGear(vector<int>& p, int n, int d) {
    if(d==1) { // 시계방향
        p[n] = (p[n] - 1 + GEAR_MAX) % GEAR_MAX;
    }
    else { // direct == -1, 반시계 방향
        p[n] = (p[n] + 1 + GEAR_MAX) % GEAR_MAX;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, k;
    cin >> t;
    
    // vector<string> v; 로도 가능
    // v[i][j] -> 벡터의 i번째 문자열 -> 문자열의 j번째 문자
    vv gear(t, vector<int>(GEAR_MAX));
    vector<int> start_p(t,0);
    vector<int> rot(t,0);

    for(int i=0; i<t; i++) {
        for(int j=0; j<GEAR_MAX; j++) {
            char tmp;
            cin >> tmp;
            gear[i][j] = tmp -'0';
        }
    }

    cin >> k;

    while(k--) {
        int num;
        cin >> num >> rot[--num];

        for(int i=num; i>0 ;i--) {
            if(needLeftRotate(gear, start_p, i)) {
                rot[i-1]= - rot[i];
            }
            else {
                break;
            }
        }

        for(int i=num; i<t-1; i++) {
            if(needRightRotate(gear, start_p, i)) {
                rot[i+1]= - rot[i];
            }
            else {
                break;
            }
        }

        for(int i=0; i<t; i++) {
            if(rot[i]!=0) {
                rotateGear(start_p, i, rot[i]);
                rot[i]=0;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<t; i++) {
        if(gear[i][start_p[i]]==1) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}