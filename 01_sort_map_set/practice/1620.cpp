#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


int main()
{
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    string input;
    map<string, int> name; // key : 이름, value : 번호
    vector<string> num(n+1); // key가 int일 때는 vector가 빠름
    
    
    for(int i=1; i<=n; i++) { // 도감 번호 1~n
        cin >> input;
        name[input]=i;
        num[i]=input;
    }
    
    while (m--) {
        cin >> input;
        if (isdigit(input[0])) { 
        // 첫번째가 숫자인지 확인. 문자 하나만 검사 가능
        // 헤더 <cctype> 필요
        
            cout << num[stoi(input)] << '\n';
            // stoi : string to int
        }
        else {
            cout << name[input] << '\n';
        }
    }

    return 0;
}