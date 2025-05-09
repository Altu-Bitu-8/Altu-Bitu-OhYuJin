#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    cin >> m;
    while(m--) {
        int x, ans;
        cin >> x;
        if(binary_search(v.begin(), v.end(), x)) {
            ans=1;
        }
        else {
            ans = 0;
        }
        cout << ans << " ";
    }

    return 0;
}