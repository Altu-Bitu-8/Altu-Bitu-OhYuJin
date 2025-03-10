#include <iostream>
#include <cmath>

using namespace std;


struct DietState {
	int weight, bmr;
	
	void dietWithout(int eat, int a, int d) {
		weight += (eat - (bmr + a)) * d;
	}


	void dietWith(int eat, int a, int d, int t) {
		int delta;
		for (int i = 0; i < d; i++) {
			delta = eat - (bmr + a);
			weight += delta;
	
			if (abs(delta) > t) {
				bmr += floor(delta / 2.0);
			}
		}
	}
};



int main() {
	
	int W0, I0, I, A;
	int D, T;

	cin >> W0 >> I0 >> T;
	cin >> D >> I >> A;

	DietState withoutChange = {W0, I0};
	DietState withChange = {W0, I0};

	withoutChange.dietWithout(I, A, D);

	if (withoutChange.weight <= 0) {
		cout << "Danger Diet" << '\n';
	}
	else {
		cout << withoutChange.weight << " " << withoutChange.bmr << '\n';
	}
	
	withChange.dietWith(I, A, D, T);

	if (withChange.weight <= 0 || withChange.bmr<=0) {
		cout << "Danger Diet" << '\n';
		return 0;
	}
	
	cout << withChange.weight << " " << withChange.bmr << " ";
	
	if (I0 - withChange.bmr > 0) cout << "YOYO";
	else cout << "NO";

	return 0;
}