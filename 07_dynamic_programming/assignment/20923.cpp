#include <iostream>
#include <deque>

using namespace std;

const int CONDITION = 5;

string playGame(deque<int>& d, deque<int>& s, int m) {

    deque<int> gr_d;
    deque<int> gr_s;
    bool doTurn = true;

    while(m--) { // 한 명이 낼 때마다 turn 감소하는 것

        // 가장 처음 turn에는 무조건 둘다 카드 있으므로 empty 검사x
        if(doTurn) { 
            gr_d.push_front(d.back());
            d.pop_back();
        }
        else {
            gr_s.push_front(s.back());
            s.pop_back();
        }

        // 카드 내고 난 이후에 empty 확인
        if(d.empty()) {
            return "su";
        }
        else if(s.empty()) {
            return "do";
        }

        // 도도가 종 치는 경우
        if((!gr_d.empty()&&gr_d.front()==CONDITION)||(!gr_s.empty()&&gr_s.front()==CONDITION)) {
            while(!gr_s.empty()) {
                d.push_front(gr_s.back());
                gr_s.pop_back();
            }
            while(!gr_d.empty()) {
                d.push_front(gr_d.back());
                gr_d.pop_back();
            }
        }
        // 수연이 종 치는 경우
        else if(!gr_d.empty()&&!gr_s.empty()&&gr_d.front()+gr_s.front()==CONDITION) {
            while(!gr_d.empty()) {
                s.push_front(gr_d.back());
                gr_d.pop_back();
            }
            while(!gr_s.empty()) {
                s.push_front(gr_s.back());
                gr_s.pop_back();
            }
        }

        doTurn = !doTurn; // 차례 변경
    }

    int d_card = d.size();
    int s_card = s.size();

    if(d_card>s_card) {
        return "do";
    }
    else if(d_card<s_card) {
        return "su";
    }

    return "dosu";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    deque<int> dodo;
    deque<int> su;

    while(n--) {
        int a,b;
        cin >> a >> b;
        // 면이 보이는 쪽 front, 안 보이는 쪽 back
        dodo.push_back(a);
        su.push_back(b);
    }

    cout << playGame(dodo, su, m);

    return 0;
}