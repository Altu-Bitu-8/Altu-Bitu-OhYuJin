#include <iostream>

using namespace std;

void calSet(int m) {
    int s=0, x;
    string input;

    while(m--) { // 비트마스킹 시 +, - 대신 |, & ~ 사용 해야함
        cin >> input;

        if (input=="add") {
            cin >> x;
            s |= 1 << (x-1); 
        }

        else if (input=="remove") {
            cin >> x;
            s &= ~(1 << (x-1));
        }

        else if (input=="check") {
            cin >> x;
            if(s & (1 << (x-1))) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }

        else if (input=="toggle") {
            cin >> x;
            if(s & (1 << (x-1))) {
                s &= ~(1<< (x-1));
            }
            else {
                s |= 1<<(x-1);
            }
        }

        else if (input=="all") {
            s = (1 << 20)-1;
        }

        else { // empty
            s = 0;
        }
    }
}

int main() {

    // 시간 초과 방지
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m;
    cin >> m;

    calSet(m);

    return 0;
}