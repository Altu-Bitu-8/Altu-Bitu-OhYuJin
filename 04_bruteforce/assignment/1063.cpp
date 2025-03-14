#include <iostream>

using namespace std;

const char MIN_COL = 'A';
const char MAX_COL = 'H';
const char MIN_ROW = 1;
const int MAX_ROW = 8;

typedef pair<char,int> p;

void chess(p& k, p& s, int n) {

    string input;
    p tmp_k;
    p tmp_s;

    while(n--) {

        tmp_k.first = k.first;
        tmp_k.second = k.second;
        tmp_s.first = s.first;
        tmp_s.second = s.second;


        cin >> input;

        if(input == "R") {
            if(k.first!=MAX_COL) {
                ++k.first;
            }
        }

        else if (input == "L") {
            if(k.first!=MIN_COL) {
                --k.first;
            }
        }

        else if (input == "B") {
            if(k.second!=MIN_ROW) {
                --k.second;
            }
        }
        else if (input == "T") {
            if(k.second!=MAX_ROW) {
                ++k.second;
            }
        }
        else if (input == "RT") {
            if(k.first!=MAX_COL && k.second!=MAX_ROW) {
                ++k.first;
                ++k.second;
            }
        }

        else if (input == "LT") {
            if(k.first!=MIN_COL && k.second!=MAX_ROW) {
                --k.first;
                ++k.second;
            }
        }

        else if (input == "RB") {
            if(k.first!=MAX_COL && k.second!=MIN_ROW) {
                ++k.first;
                --k.second;
            }
        }
        
        else if (input == "LB") {
            if(k.first!=MIN_COL && k.second!=MIN_ROW) {
                --k.first;
                --k.second;
            }
        }

        if (k.first==tmp_k.first && k.second==tmp_k.second) {
            // 변화가 없는 경우
            continue;
        }

        if (k.first==s.first && k.second==s.second) {
           // 킹과 돌의 위치가 같은 경우
            s.first += (k.first-tmp_k.first);
            s.second += (k.second-tmp_k.second);

            if(s.first>MAX_COL || s.first<MIN_COL || s.second>MAX_ROW || s.second<MIN_ROW) {
                // 만약 바뀐 돌의 위치가 범위를 벗어나면 다시 되돌림
                s.first = tmp_s.first;
                s.second = tmp_s.second;
                k.first = tmp_k.first;
                k.second = tmp_k.second;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string k0, s0;
    int N;
    cin >> k0 >> s0 >> N;

    p king;
    p stone;

    king.first = k0[0];
    king.second = k0[1] - '0';
    stone.first = s0[0];
    stone.second = s0[1] - '0';

    chess(king, stone, N);
    
    cout << king.first << king.second << "\n";
    cout << stone.first << stone.second;

    return 0;
}