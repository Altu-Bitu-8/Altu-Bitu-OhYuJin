#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test;
    cin >> test;

    while(test--) {
        int n;
        string name, type;
        map <string, int> clothes;
        cin >> n;

        while(n--) {
            cin >> name >> type;
            clothes[type]++;
        }

        int cnt =1;
        for(auto it = clothes.begin(); it !=clothes.end(); it++) {
            // for(const auto& it : clothes) 도 가능. const & 없으면 값 복사해서 가져옴.
            // auto it = begin() 방법은 복사하는 것 아님. 직접 가져옴.
            cnt *= (it->second+1);
        }
        cout << cnt-1 << "\n";
    }

    return 0;
}