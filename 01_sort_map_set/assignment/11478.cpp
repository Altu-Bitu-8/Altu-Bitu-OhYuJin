#include <iostream>
#include <string>
#include <set>

using namespace std;

int subString(const string& s) {
	set<string> sub;

	for (int i = 0; i < s.size(); i++) {
		for (int j = 1; j <= s.size()-i; j++) {
			sub.insert(s.substr(i, j));
		}
	} return sub.size();
}

int main() {

	string input;
	cin >> input;

	cout << subString(input);

	return 0;
}