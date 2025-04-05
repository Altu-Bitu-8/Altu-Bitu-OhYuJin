#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int CNT = 9;

void select(vector<int>& h) {
    int sum=0;
    int tmp;
    for(int i=0; i<CNT; i++) {
        sum+=h[i];
    }
    for(int i=0; i< CNT-1; i++) {
        for(int k=i+1; k<CNT; k++) {
            if(sum-(h[i]+h[k])==100) {
                // 지울 때 큰 원소부터 해야함
                h.erase(h.begin()+k);
                h.erase(h.begin()+i);
                return;
            }
        }

    }
}

int main() {
    vector<int> height(CNT);

    for(int i=0; i<CNT; i++) {
        cin >> height[i];
    }

    select(height);

    sort(height.begin(), height.end());

    for(int i=0; i<CNT-2; i++) {
        cout << height[i] << "\n";
    }

    // for (auto it : height) {
    //     cout << it << "\n"
    // }



    return 0;
}