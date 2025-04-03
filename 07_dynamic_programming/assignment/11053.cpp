#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, ans=1;
    cin >> n;
    vector<int> seq(n);
    vector<int> sublen(n,1);

    for(int i=0; i<n; i++) {
        cin >> seq[i];
        int len=1;
        for(int j=0; j<i; j++) {
            if(seq[j]<seq[i]) {
                len = max(sublen[j]+1, len);
            }
        }
        sublen[i]=len;

        if(ans<len) {
            ans = len;
        }
    }

    cout << ans;
    return 0;
}