#include <iostream>
#include <vector>

using namespace std;

int minVelocityGreedy(const vector<int> & v) {
    // v는 int 범위이지만 ans는 배수가 되므로 long long
    long long ans = v[0];
    int size = v.size();
    for(int i=1; i<size; i++) {
        if(v[i]>ans) {
            ans = v[i];
            continue;
        }
        else if(v[i]==ans || ans%v[i]==0) {
            continue;
        }

        // ans가 long long이므로 a도 long long
        long long a = ans/v[i];
        ans = v[i]*(a+1);
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=n-1; i>=0; i--) {
        cin >> v[i];
    }

    cout << minVelocityGreedy(v);

    return 0;
}