#include <iostream>
#include <stack>

using namespace std;

int main() {
    string input;
    cin >> input;
    stack<char> s;

    for(char c : input) {
        if(c>='A' && c<='Z') cout << c;
        else if (c=='(') s.push(c);
        else if (c==')') {
            while(!s.empty() && s.top()!='(') {
                cout << s.top();
                s.pop();
            } s.pop();
        }
        else if (c=='*'||c=='/') {
            while(!s.empty() && (s.top()=='*'||s.top()=='/')) {
                cout << s.top();
                s.pop();
            } s.push(c);
        }
        else if (c=='+'||c=='-') {
            while (!s.empty() && s.top()!='(') {
                cout << s.top();
                s.pop();
            } s.push(c);
        }
    }

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }


    return 0;
}