#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100001;

int findSubseq(const vector<int>& seq, int k) {
    vector<int> cnt(MAX,0);
    int left=0, right=0, ans=0, tmp=0;

    while(right<seq.size()) {
        cnt[seq[right]]++;
        
        while (cnt[seq[right]] > k) {
            cnt[seq[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
        right++;
    }

    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,k;
    cin >> n >> k;
    vector<int> seq(n);
    for(int i=0; i<n; i++) {
        cin >> seq[i];
    }

    cout << findSubseq(seq, k);

    return 0;
}