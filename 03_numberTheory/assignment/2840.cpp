#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, tmp, step;
    bool error=false;
    char s;
    cin >> n >> k;

    vector<char> cycle(n, '?');

    cin >> tmp >> cycle[0];
    --k;
    tmp = 0;

    while (k--) {
        cin >> step >> s;
        tmp+=step;
        tmp%=n;

        if(cycle[tmp]!=s && cycle[tmp]!='?') {
            error=true;
            break;
        }

        cycle[tmp]=s;

    }

    for(int i=0; i<n; i++) { // 중복 확인
        for(int j=i+1; j<n; j++) {
            if(cycle[i]!='?' && cycle[i]==cycle[j]) {
                error = true;
            }
        }
    }

    if (error) {
        cout << "!";
    }

    else {
        for(int i=0; i<n; i++) {
            cout << cycle[(tmp-i+n)%n];
        }

    }

    return 0;
}