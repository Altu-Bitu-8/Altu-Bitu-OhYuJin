#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct member {
    int num, day, hurry, line;
};

struct cmp {
    bool operator() (const member& p, const member& c) {

        if(p.day!=c.day) {
            return p.day < c.day;
        }
        else if(p.hurry!=c.hurry) {
            return p.hurry < c.hurry;
        }
        else return p.line > c.line;
    }
};

typedef priority_queue<member, vector<member>, cmp> prior_q;

int findTurn(prior_q &pq, vector<queue<member>> members, int m, int k) {
    int ans=0;
    while(pq.top().num!=k+1) {
        int tmp = pq.top().line;
        pq.pop();
        
        if(!(members[tmp].empty())) {
            pq.push(members[tmp].front());
            members[tmp].pop();
        }
        ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k, d, h;
    cin >> n >> m >> k;

    prior_q pq;
    vector<queue<member>> members(m);    

    for(int i=1; i<=n; i++) {
        cin >> d >> h;
        int l = (i-1)%m; // i%m 시 m번째가 0이 되며 오히려 작아짐
        if(i<=m) {
            pq.push({i, d, h, l});
        }
        else {
            members[l].push({i, d, h, l});
        }
    }

    cout << findTurn(pq, members, m, k);

    return 0;
}