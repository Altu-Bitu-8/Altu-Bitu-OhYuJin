#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// �ڸ��� �� ��� �Լ�
int sumDigits(const string& s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) { // for (char c : s)�� ����
		if (isdigit(s[i])) {
			sum += s[i]-'0';
			// int�� ����ȯ ����. stoi()�� char�� �ƴ� string ��ȯ�̱� ������ �Ұ�
		}
	} return sum;
}


// ���� ���� �Լ�
bool comp(const string& s1, const string& s2) {
// comp()������ ���� ������ �̷������ ���� �ƴϱ� ������ const ����
	if (s1.size() != s2.size()) {
		return s1.size() < s2.size();
	}

	int sum1 = sumDigits(s1);
	int sum2 = sumDigits(s2);

	if (sum1 != sum2) {
		return sum1 < sum2;
	}

	return s1 < s2;
}

int main() {

	int n;
	cin >> n;
	vector<string> serial(n);

	for (int i = 0; i < n; i++) {
		cin >> serial[i];
	}

	sort(serial.begin(), serial.end(), comp);
	
	for (int i = 0; i < n; i++) {
		cout << serial[i] << '\n';
	}

	return 0;
}