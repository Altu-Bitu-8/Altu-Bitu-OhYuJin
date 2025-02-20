#include <iostream>
#include <string>
#include <set>


int subString(const std::string& s) {
	std::set<std::string> sub;

	for (int i = 0; i < s.size(); i++) {
		for (int j = 1; j <= s.size()-i; j++) {
			sub.insert(s.substr(i, j));
		}
	} return sub.size();
}

int main() {

	std::string input;
	std::cin >> input;

	std::cout << subString(input);

	return 0;
}