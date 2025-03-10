#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    int n, input;
    cin >> n;

    pair<int, int> p;
    stack<pair<int, int>> s;
    vector<int> v(n, -1);

    for(int i=0; i<n; i++) {
        p.first=i;
        cin >> p.second;
        while(!s.empty()&& s.top().second<p.second) {
            v[s.top().first] = p.second;
            s.pop();
        }
        s.push(p);
    }

    for(int i=0; i<n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}