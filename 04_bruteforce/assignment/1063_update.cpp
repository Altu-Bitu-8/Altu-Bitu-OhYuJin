#include <iostream>

using namespace std;

const char MIN_COL = 'A';
const char MAX_COL = 'H';
const int MIN_ROW = 1;
const int MAX_ROW = 8;

typedef pair<char,int> pa;

pa move(string in, const pa& p) { // 위치 변경
    char x = p.first;
    int y = p.second;
    for(char mov : in) {
        if(mov == 'R') {
            x++;
        }
        else if(mov == 'L') {
            x--;
        }
        else if(mov == 'B') {
            y--;
        }
        else { // T인 경우
            y++;
        }
    }
    return {x,y};
}

bool isSame(pa k, pa s) {
    return (k.first == s.first && k.second == s.second);
}

bool checkRange(pa p) {
    if(p.first < MIN_COL || p.first > MAX_COL || p.second < MIN_ROW || p.second > MAX_ROW) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    pa king;
    pa stone;

    int n;
    string input;
    cin >> king.first >> king.second >> stone.first >> stone.second >> n;
    // 공백 없어도 pair<char,int>이므로 가능

    while(n--) {
        cin >> input;

        pa tmp_k, tmp_s;
        
        tmp_k = move(input, king); // king 이동

        if(isSame(tmp_k, stone)) { // 이동한 king과 stone 위치 같으면
            tmp_s = move(input, stone); // king만큼 stone 이동
        }
        else {
            tmp_s = stone;
        }

        if(checkRange(tmp_k) && checkRange(tmp_s)) {
        // 이동 후 범위 이내인 경우만 변경사항 반영
            king = tmp_k;
            stone = tmp_s;
        }

    }
    
    cout << king.first << king.second << "\n";
    cout << stone.first << stone.second;

    return 0;
}