#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true) {
        string line;
        getline(cin, line);
        if(line==".") break;

        stack<char> s;
        string balance = "yes";

        for(char c : line) {
            if (c=='(' || c=='[') s.push(c);

            else if(c==')') {
                if (s.empty() || s.top()!='(') {
                    balance="no";
                    break;
                } else s.pop();
               }

            else if(c==']') {
                if (s.empty() || s.top()!='[') {
                    balance="no";
                    break;
                } else s.pop();
            }
        }

        if (!s.empty()) balance = "no";
        cout << balance << "\n"; 
    }
    return 0;
}