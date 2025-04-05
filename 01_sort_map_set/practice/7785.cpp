#include <iostream>
#include <set>

using namespace std;


int main()
{
    int n;
    cin >> n;
    
    string name, state;
    
    set<string> s; // 크기 설정 안해도 됨
    
    for(int i=0; i<n; i++) { // while(n--) 도 가능
        cin >> name >> state;
        if (state == "enter") {
            s.insert(name);
        }
        else { 
            s.erase(name);
            // set은 중복 허용하지 않으므로 기존에 존재하지 않으면 아무 일도 일어나지 않음.
            //따라서 존재하는지 확인할 필요없음
        }
    }
    
    set<string>::reverse_iterator iter;
    // 반대로 순회하려면 reverse_iterator 써야함
    for (iter = s.rbegin(); iter != s.rend(); iter++) {
        cout << *iter << '\n';
    }
    // 또는 for (auto iter ~) 하면 선언 필요 없음


    return 0;
}