#include <iostream>
#include <vector>

using namespace std;

const int OPERATOR=4;

int ans[2]={-1000000001,1000000001}; //최대, 최소

void calSeq(int idx, int n, const vector<int>& s, vector<int>& op, int re) {
    if(idx==n) {
        ans[0] = (ans[0]<re) ? re : ans[0];
        ans[1] = (ans[1]>re) ? re : ans[1];
        return;
    }

    for(int i=0; i<OPERATOR; i++) {
        if(op[i]<=0) {
            continue;
        }
        op[i]--;
        switch(i) {
            case (0) :
                calSeq(idx+1, n, s, op, re+s[idx]);
                break;
            case (1) :
                calSeq(idx+1, n, s, op, re-s[idx]);
                break;
            case (2) :
                calSeq(idx+1, n, s, op, re*s[idx]);
                break;
            case (3) :
                calSeq(idx+1, n, s, op, re/s[idx]);
                break;
        }
        op[i]++;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> seq(n);
    vector<int> oper(OPERATOR);

    for(int i=0; i<n; i++) {
        cin >> seq[i];
    }

    for(int i=0; i<OPERATOR; i++) {
        cin >> oper[i];
    }

    int result = seq[0];
    calSeq(1, n, seq, oper, result);

    cout << ans[0] << "\n" << ans[1];

    return 0;
}