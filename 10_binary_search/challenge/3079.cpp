#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll cntPass(const vector<ll>& t, ll sec) {
    ll sum=0;
    for(ll i=0; i<t.size(); i++) {
        sum += (sec/t[i]);
    }
    return sum;
}

ll minTime(const vector<ll>& t, ll m) {

    ll left = 1;
    ll right = m*t[0];
    while(left <= right) {
        ll mid = (left+right)/2;
        ll cnt = cntPass(t, mid);

        if(cnt>=m) { // m보다 더 많은 인원처리 가능하면 시간 줄임
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n,m;
    cin >> n >> m;
    vector<ll> time(n);
    for(ll i=0; i<n; i++) {
        cin >> time[i];
    }
    sort(time.begin(), time.end());

    cout << minTime(time, m);

    return 0;
}